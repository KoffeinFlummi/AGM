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
#define PAINLOSS 0.005

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
null = [_unit, damage _unit, (_unit getVariable "BWA3_Pain")] spawn {
  _unit = _this select 0;
  _damageold = _this select 1;
  _painold = _this select 2;

  sleep 0.001;

  _armdamage = (_unit getHitPointDamage "HitLeftShoulder") + (_unit getHitPointDamage "HitLeftArm") + (_unit getHitPointDamage "HitLeftForeArm") + (_unit getHitPointDamage "HitRightShoulder") + (_unit getHitPointDamage "HitRightArm") + (_unit getHitPointDamage "HitRightForeArm");
  _legdamage = (_unit getHitPointDamage "HitLeftUpLeg") + (_unit getHitPointDamage "HitLeftLeg") + (_unit getHitPointDamage "HitLeftFoot") + (_unit getHitPointDamage "HitRightUpLeg") + (_unit getHitPointDamage "HitRightLeg") + (_unit getHitPointDamage "HitRightFoot");

  // Reset "unused" hitpoints.
  _unit setHitPointDamage ["HitLegs", 0];
  _unit setHitPointDamage ["HitHands", 0];
  
  // Handle death and unconsciousness
  if (damage _unit > UNCONSCIOUSNESSTHRESHOLD and damage _unit < 1 and !(_unit getVariable "BWA3_Unconscious")) then {
    [_unit] call BWA3_Medical_fnc_knockOut;
  };

  // Handle leg damage symptoms
  if (_legdamage >= LEGDAMAGETHRESHOLD1) then {
    // lightly wounded, limit walking speed
    _unit setHitPointDamage ["HitLegs", 1];
  };
  /* DEAL WITH THIS LATER
    if (_legdamage >= LEGDAMAGETHRESHOLD2) then {
      // heavily wounded, stop unit from walking alltogether
      if !(_unit getVariable "BWA3_NoLegs") then {
        _unit setVariable ["BWA3_NoLegs", true, true];
        _unit spawn {
          _unit = _this;
          _unit setUnitPos "DOWN";
          [_unit] call BWA3_Medical_fnc_forceProne;
          while {true} do {
            _legdamage = (_unit getHitPointDamage "HitLeftUpLeg") + (_unit getHitPointDamage "HitLeftLeg") + (_unit getHitPointDamage "HitLeftFoot") + (_unit getHitPointDamage "HitRightUpLeg") + (_unit getHitPointDamage "HitRightLeg") + (_unit getHitPointDamage "HitRightFoot");
            if (_legdamage < LEGDAMAGETHRESHOLD2) exitWith {
              _unit setUnitPos "AUTO";
              _unit setVariable ["BWA3_NoLegs", false, true];
            };
            if (stance _unit != "PRONE") then {
              [_unit] call BWA3_Medical_fnc_forceProne;
            };
            sleep 1;
          };
        };
      };
    };

    // Handle arm damage symptoms
    if (_armdamage >= ARMDAMAGETHRESHOLD) then {
      if !(_unit getVariable "BWA3_NoArms") then {
        _unit setVariable ["BWA3_NoArms", true, true];
        _unit spawn {
          _unit = _this;
          _unit setUnitPos "DOWN";
          [_unit] call BWA3_Medical_fnc_dropWeapon;
          while {true} do {
            _armdamage = (_unit getHitPointDamage "HitLeftShoulder") + (_unit getHitPointDamage "HitLeftArm") + (_unit getHitPointDamage "HitLeftForeArm") + (_unit getHitPointDamage "HitRightShoulder") + (_unit getHitPointDamage "HitRightArm") + (_unit getHitPointDamage "HitRightForeArm");
            if (_armdamage < ARMDAMAGETHRESHOLD) exitWith {
              _unit setVariable ["BWA3_NoArms", false, true];
            };
            if (currentWeapon player != "") then {
              [_unit] call BWA3_Medical_fnc_dropWeapon;
            };
            sleep 3;
          };
        };
      };
    };
  */

  if (damage _unit * (_unit getVariable "BWA3_Painkiller") > _unit getVariable "BWA3_Pain") then {
    _unit setVariable ["BWA3_Pain", (damage _unit) * (_unit getVariable "BWA3_Painkiller"), true];
  };

  // Pain
  if (_unit == player and !(_unit getVariable "BWA3_InPain")) then {
    _unit setVariable ["BWA3_InPain", true, true];
    _unit spawn {
      "chromAberration" ppEffectEnable true;
      _time = time;
      while {(_this getVariable "BWA3_Pain") > 0} do {
        "chromAberration" ppEffectAdjust [0.02 * (_this getVariable "BWA3_Pain"), 0.02 * (_this getVariable "BWA3_Pain"), false];
        "chromAberration" ppEffectCommit 1;
        sleep (1.5 - (_this getVariable "BWA3_Pain"));
        "chromAberration" ppEffectAdjust [0.2 * (_this getVariable "BWA3_Pain"), 0.2 * (_this getVariable "BWA3_Pain"), false];
        "chromAberration" ppEffectCommit 1;
        sleep 0.15;
        
        _pain = ((_this getVariable "BWA3_Pain") - PAINLOSS * ((time - _time) / 1)) max 0;
        _this setVariable ["BWA3_Pain", _pain];
        _time = time;
      };
      "chromAberration" ppEffectEnable false;
      _this setVariable ["BWA3_InPain", false];
    };
  };

  // Bleeding
  if !(_unit getVariable "BWA3_Bleeding") then {
    _unit setVariable ["BWA3_Bleeding", true, true];
    _unit spawn {
      while {_this getVariable "BWA3_Blood" > 0 and (_this getVariable "BWA3_Bleeding")} do {
        if (_this == player) then {[(damage _this) * 500] call BIS_fnc_bloodEffect;};
        _blood = _this getVariable "BWA3_Blood";
        _blood = _blood - BLOODLOSSRATE * damage _this;
        _this setVariable ["BWA3_Blood", _blood, true];
        if (_blood <= BLOODTHRESHOLD1 and !(_this getVariable "BWA3_Unconscious")) then {
          [_this] call BWA3_Medical_fnc_knockOut;
        };
        if (_blood <= BLOODTHRESHOLD2) then {
          _this setDamage 1;
        };

        sleep 10;
      };
    };
  };

};