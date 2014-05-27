/*
 * Author: KoffeinFlummi
 * 
 * Called when some dude gets shot. Or stabbed. Or blown up. Or pushed off a cliff. Or hit by a car. Or burnt. Or poisoned. Or gassed. Or cut. You get the idea.
 * 
 * Arguments:
 * 0: Unit that got hit (Object)
 * 1: Name of the selection that was hit (String); "" for structural damage
 * 2: Amount of damage inflicted (Number)
 * 3: Shooter (Object); Null for explosion damage, falling, fire etc.
 * 4: Projectile (Object)
 * 
 * Return value:
 * Damage value to be inflicted (optional)
 */

#define UNCONSCIOUSNESSTHRESHOLD 0.5

#define LEGDAMAGETHRESHOLD1 1
#define LEGDAMAGETHRESHOLD2 2
#define ARMDAMAGETHRESHOLD 2

#define PAINKILLERTHRESHOLD 0.1
#define PAINLOSS 0.0001

#define BLOODTHRESHOLD1 0.35
#define BLOODTHRESHOLD2 0
#define BLOODLOSSRATE 0.02

_unit = _this select 0;
_selectionName = _this select 1;
_damage = _this select 2;
_source = _this select 3;
_projectile = _this select 4;

// Prevent unnecessary processing
if (damage _unit == 1) exitWith {_unit enableSimulation true;};

// Code to be executed AFTER damage was dealt
null = [_unit, damage _unit, (_unit getVariable "AGM_Pain")] spawn {
  _unit = _this select 0;
  _damageold = _this select 1;
  _painold = _this select 2;

  sleep 0.001;

  _armdamage = (_unit getHitPointDamage "HitLeftArm") + (_unit getHitPointDamage "HitRightArm");
  _legdamage = (_unit getHitPointDamage "HitLeftLeg") + (_unit getHitPointDamage "HitRightLeg");

  // Reset "unused" hitpoints.
  [_unit, "HitLegs", 0] call AGM_Medical_fnc_setHitPointDamage;
  [_unit, "HitHands", 0] call AGM_Medical_fnc_setHitPointDamage;

  // Account for unassigned structural damage, like when you crash into something with a vehicle
  if ((damage _unit > 0) and (_unit getHitPointDamage "HitHead" < 0.01) and (_unit getHitPointDamage "HitBody" < 0.01) and (_unit getHitPointDamage "HitLeftArm" < 0.01) and (_unit getHitPointDamage "HitRightArm" < 0.01) and (_unit getHitPointDamage "HitLeftLeg" < 0.01) and (_unit getHitPointDamage "HitRightLeg" < 0.01)) then {
    [_unit, "HitBody", (damage _unit)] call AGM_Medical_fnc_setHitPointDamage;
  };
  
  // Handle death and unconsciousness
  if (damage _unit > UNCONSCIOUSNESSTHRESHOLD and damage _unit < 1 and !(_unit getVariable "AGM_Unconscious")) then {
    [_unit] call AGM_Medical_fnc_knockOut;
  };

  // Handle leg damage symptoms
  if (_legdamage >= LEGDAMAGETHRESHOLD1) then {
    // lightly wounded, limit walking speed
    [_unit, "HitLegs", 1] call AGM_Medical_fnc_setHitPointDamage;
  };
  /* DEAL WITH THIS LATER
    if (_legdamage >= LEGDAMAGETHRESHOLD2) then {
      // heavily wounded, stop unit from walking alltogether
      if !(_unit getVariable "AGM_NoLegs") then {
        _unit setVariable ["AGM_NoLegs", true, true];
        _unit spawn {
          _unit = _this;
          _unit setUnitPos "DOWN";
          [_unit] call AGM_Medical_fnc_forceProne;
          while {true} do {
            _legdamage = (_unit getHitPointDamage "HitLeftUpLeg") + (_unit getHitPointDamage "HitLeftLeg") + (_unit getHitPointDamage "HitLeftFoot") + (_unit getHitPointDamage "HitRightUpLeg") + (_unit getHitPointDamage "HitRightLeg") + (_unit getHitPointDamage "HitRightFoot");
            if (_legdamage < LEGDAMAGETHRESHOLD2) exitWith {
              _unit setUnitPos "AUTO";
              _unit setVariable ["AGM_NoLegs", false, true];
            };
            if (stance _unit != "PRONE") then {
              [_unit] call AGM_Medical_fnc_forceProne;
            };
            sleep 1;
          };
        };
      };
    };

    // Handle arm damage symptoms
    if (_armdamage >= ARMDAMAGETHRESHOLD) then {
      if !(_unit getVariable "AGM_NoArms") then {
        _unit setVariable ["AGM_NoArms", true, true];
        _unit spawn {
          _unit = _this;
          _unit setUnitPos "DOWN";
          [_unit] call AGM_Medical_fnc_dropWeapon;
          while {true} do {
            _armdamage = (_unit getHitPointDamage "HitLeftShoulder") + (_unit getHitPointDamage "HitLeftArm") + (_unit getHitPointDamage "HitLeftForeArm") + (_unit getHitPointDamage "HitRightShoulder") + (_unit getHitPointDamage "HitRightArm") + (_unit getHitPointDamage "HitRightForeArm");
            if (_armdamage < ARMDAMAGETHRESHOLD) exitWith {
              _unit setVariable ["AGM_NoArms", false, true];
            };
            if (currentWeapon player != "") then {
              [_unit] call AGM_Medical_fnc_dropWeapon;
            };
            sleep 3;
          };
        };
      };
    };
  */

  if (damage _unit * (_unit getVariable "AGM_Painkiller") > _unit getVariable "AGM_Pain") then {
    _unit setVariable ["AGM_Pain", (damage _unit) * (_unit getVariable "AGM_Painkiller"), true];
  };

  // Pain
  if (_unit == player and !(_unit getVariable "AGM_InPain")) then {
    player setVariable ["AGM_InPain", true, true];
    0 spawn {
      _time = time;
      "chromAberration" ppEffectEnable true;
      while {(player getVariable "AGM_Pain") > 0} do {
        "chromAberration" ppEffectAdjust [0.035 * (player getVariable "AGM_Pain"), 0.035 * (player getVariable "AGM_Pain"), false];
        "chromAberration" ppEffectCommit 1;
        sleep (1.5 - (player getVariable "AGM_Pain"));
        "chromAberration" ppEffectAdjust [0.35 * (player getVariable "AGM_Pain"), 0.35 * (player getVariable "AGM_Pain"), false];
        "chromAberration" ppEffectCommit 1;
        sleep 0.15;
        
        _pain = ((player getVariable "AGM_Pain") - PAINLOSS * ((time - _time) / 1)) max 0;
        player setVariable ["AGM_Pain", _pain, true];
        _time = time;
      };
      "chromAberration" ppEffectEnable false;
      player setVariable ["AGM_InPain", false, true];
    };
  };

  // Bleeding
  if !(_unit getVariable "AGM_Bleeding") then {
    _unit setVariable ["AGM_Bleeding", true, true];
    _unit spawn {
      while {_this getVariable "AGM_Blood" > 0 and (_this getVariable "AGM_Bleeding") and damage _this > 0 and damage _this < 1} do {
        if (_this == player) then {[(damage _this) * 500] call BIS_fnc_bloodEffect;};
        _blood = _this getVariable "AGM_Blood";
        _blood = _blood - BLOODLOSSRATE * (damage _this);
        _this setVariable ["AGM_Blood", _blood, true];
        if (_blood <= BLOODTHRESHOLD1 and !(_this getVariable "AGM_Unconscious")) then {
          [_this] call AGM_Medical_fnc_knockOut;
        };
        if (_blood <= BLOODTHRESHOLD2) then {
          _this setDamage 1;
        };

        sleep 10;
      };
      _this setVariable ["AGM_Bleeding", false, true];
    };
  };

};