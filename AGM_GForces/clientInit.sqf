#define AVERAGEDURATION 6
#define INTERVAL 0.20
#define MAXVIRTUALG 5.0
#define MINVIRTUALG 2.5

if !(hasInterface) exitWith {};

AGM_GForces = [];
AGM_GForces_Index = 0;

AGM_GForces_CC = ppEffectCreate ["ColorCorrections", 4215];
AGM_GForces_CC ppEffectEnable true;
AGM_GForces_CC ppEffectForceInNVG true;
AGM_GForces_CC ppEffectAdjust [1,1,0,[0,0,0,1],[0,0,0,0],[1,1,1,1],[10,10,0,0,0,0.1,0.5]];
AGM_GForces_CC ppEffectCommit 0.4;

0 spawn {
  while {True} do {
    _player = AGM_player;

    if !((vehicle _player isKindOf "Air") or ((getPos _player select 2) > 5)) then {
      AGM_GForces = [];
      AGM_GForces_Index = 0;
      waitUntil {sleep 5; (vehicle _player isKindOf "Air") or ((getPos _player select 2) > 5)};
    };

    _oldVel = velocity (vehicle _player);
    sleep INTERVAL;
    _newVel = velocity (vehicle _player);

    _accel = ((_newVel vectorDiff _oldVel) vectorMultiply (1 / INTERVAL)) vectorAdd [0, 0, 9.8];
    AGM_GForce_Current = (_accel vectorDotProduct vectorUp (vehicle _player)) / 9.8;

    // Cap maximum G's to +- 10 to avoid g-effects when the update is low fps.
    AGM_GForce_Current = (AGM_GForce_Current max -10) min 10;

    AGM_GForces set [AGM_GForces_Index, AGM_GForce_Current];
    AGM_GForces_Index = (AGM_GForces_Index + 1) % round (AVERAGEDURATION / INTERVAL);
  };
};


/* Source: https://github.com/KoffeinFlummi/AGM/issues/1774#issuecomment-70341573
*
* For untrained people without g-suits:
* GLOC: 5G for 6 s
* RedOut: 2.5G for 6 s
*
* For trained jet pilots without g-suits:
* GLOC: 9G for 6 s
* RedOut: 4.5G
*
* For trained jet pilots with g-suits:
* GLOC: 10.5G for 6 s
* RedOut: 4.5G
*
* Effects and camera shake start 30% the limit value, and build gradually
*/

0 spawn {
  while {True} do {
    sleep INTERVAL;

    AGM_GForces_CC ppEffectAdjust [1,1,0,[0,0,0,1],[0,0,0,0],[1,1,1,1],[10,10,0,0,0,0.1,0.5]];

    if !(isNull AGM_player) then {

      _average = 0;
      if (count AGM_GForces > 0) then {
        _sum = 0;
        {
          _sum = _sum + _x;
        } forEach AGM_GForces;
        _average = _sum / (count AGM_GForces);
      };

      _classCoef = AGM_player getVariable ["AGM_GForceCoef",
          getNumber (configFile >> "CfgVehicles" >> (typeOf AGM_player) >> "AGM_GForceCoef")];
      _suitCoef = getNumber (configFile >> "CfgWeapons" >> (uniform AGM_player) >> "AGM_GForceCoef");

      if (_classCoef == 0) then {_classCoef = 1;};
      if (_suitCoef == 0) then {_suitCoef = 1;};

      _gBlackOut = MAXVIRTUALG / _classCoef + MAXVIRTUALG / _suitCoef - MAXVIRTUALG;
      _gRedOut = MINVIRTUALG / _classCoef;

      ["GForces", [], {format ["_g _gBO _coef: %1, %2, %3", _average, _gBlackOut, 2 * ((1.0 - ((_average - 0.30 * _gBlackOut) / (0.70 * _gBlackOut)) ^ 2) max 0) ]}] call AGM_Debug_fnc_log;

      if ((_average > _gBlackOut) and {isClass (configFile >> "CfgPatches" >> "AGM_Medical") and {!(AGM_player getVariable ["AGM_isUnconscious", false])}}) then {
        [AGM_player, (10 + floor(random 5))] call AGM_Medical_fnc_knockOut;
      };

      AGM_GForces_CC ppEffectAdjust [1,1,0,[0,0,0,1],[0,0,0,0],[1,1,1,1],[10,10,0,0,0,0.1,0.5]];

      if !(AGM_player getVariable ["AGM_isUnconscious", false]) then {
        if (_average > 0.30 * _gBlackOut) then {
          _strength = ((_average - 0.30 * _gBlackOut) / (0.70 * _gBlackOut)) max 0;
          AGM_GForces_CC ppEffectAdjust [1,1,0,[0,0,0,1],[0,0,0,0],[1,1,1,1],[2*(1-_strength),2*(1-_strength),0,0,0,0.1,0.5]];
          addCamShake [_strength, 1, 15];
        } else {
          if (_average < -0.30 * _gRedOut) then {
            _strength = ((abs _average - 0.30 * _gRedOut) / (0.70 * _gRedOut)) max 0;
            AGM_GForces_CC ppEffectAdjust [1,1,0,[1,0.2,0.2,1],[0,0,0,0],[1,1,1,1],[2*(1-_strength),2*(1-_strength),0,0,0,0.1,0.5]];
            addCamShake [_strength / 1.5, 1, 15];
          };
        };
      };
    };

    AGM_GForces_CC ppEffectCommit INTERVAL;
  };
};
