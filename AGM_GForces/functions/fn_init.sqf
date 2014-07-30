#define AVERAGEDURATION 6
#define INTERVAL 0.25

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
    if !((vehicle player isKindOf "Air") or ((getPos player select 2) > 5)) then {
      AGM_GForces = [];
      AGM_GForces_Index = 0;
      waitUntil {sleep 5; (vehicle player isKindOf "Air") or ((getPos player select 2) > 5)};
    };

    _oldVel = [velocity (vehicle player), vectorDir (vehicle player)] call AGM_Core_fnc_hadamardProduct;

    sleep INTERVAL;

    _newVel = [velocity (vehicle player), vectorDir (vehicle player)] call AGM_Core_fnc_hadamardProduct;
    _accel = [
      ((_newVel select 0) - (_oldVel select 0)) / INTERVAL,
      ((_newVel select 1) - (_oldVel select 1)) / INTERVAL,
      ((_newVel select 2) - (_oldVel select 2)) / INTERVAL - 9.8
    ];

    _angle = velocity (vehicle player) vectorDotProduct vectorUp (vehicle player);
    _gForce = (vectorMagnitude _accel) / 9.8;
    if (((_angle > 0) and (vehicle player isKindOf "Air")) or ((_newVel select 2 < 0) and !(vehicle player isKindOf "Air"))) then {
      _gForce = _gForce * -1;
    };

    AGM_GForces set [AGM_GForces_Index, _gForce];
    AGM_GForces_Index = (AGM_GForces_Index + 1) % round (AVERAGEDURATION / INTERVAL);
  };
};


/*
 * source: http://en.wikipedia.org/wiki/G-LOC
 * untrained persons without gsuit will fall unconscious between 4 and 6G
 * pilots in gsuits will sustain up to 9G
 * a person is for average 12 seconds unconscious
 * after being unconscious, a person is unable to do simple tasks for average 15 seconds
 *
 * _upTolerance converts the effective 9G of a pilot to virtual 5.4G (= 0.8*0.75*9G)
 * pilots with gsuit will get unconscious at an _average of 9G
 * normal men without gsuit will get unconscious at an _average of 5.4G
 */

0 spawn {
  _maxVirtualG = 5.4;
  while {True} do {
    sleep INTERVAL;

    _average = 0;
    if (count AGM_GForces > 0) then {
      _sum = 0;
      {
        _sum = _sum + _x;
      } forEach AGM_GForces;
      _average = _sum / (count AGM_GForces);
    };

    _upTolerance = getNumber (configFile >> "CfgVehicles" >> (typeOf player) >> "AGM_GForceCoef") * getNumber (configFile >> "CfgWeapons" >> (uniform player) >> "AGM_GForceCoef");
    _downTolerance = getNumber (configFile >> "CfgVehicles" >> (typeOf player) >> "AGM_GForceCoef");

    if (((_average * _upTolerance) > _maxVirtualG) and {isClass (configFile >> "CfgPatches" >> "AGM_Medical")}) then {
      [player, (12 - 2 + floor(random 5))] call AGM_Medical_fnc_knockOut;
    };

    if ((abs _average > 2) and !(player getVariable ["AGM_Unconscious", false])) then {
      if (_average > 0) then {
        _strength = 1.2 - (((_average - 2) * _upTolerance) / (_maxVirtualG - 2));
        AGM_GForces_CC ppEffectAdjust [1,1,0,[0,0,0,1],[0,0,0,0],[1,1,1,1],[_strength,_strength,0,0,0,0.1,0.5]];
        addCamShake [((abs _average) - 2) / 3, 1, 15];
      } else {
        _strength = 1.2 - ((((-1 * _average) - 2) * _downTolerance) / (_maxVirtualG - 2));
        AGM_GForces_CC ppEffectAdjust [1,1,0,[1,0.2,0.2,1],[0,0,0,0],[1,1,1,1],[_strength,_strength,0,0,0,0.1,0.5]];
        addCamShake [((abs _average) - 2) / 5, 1, 15];
      };
    } else {
      AGM_GForces_CC ppEffectAdjust [1,1,0,[0,0,0,1],[0,0,0,0],[1,1,1,1],[10,10,0,0,0,0.1,0.5]];
    };

    AGM_GForces_CC ppEffectCommit 0.25;
  };
};
