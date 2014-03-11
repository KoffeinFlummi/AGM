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

#define REVIVETHRESHOLD 0.8
#define UNCONSCIOUSNESSTHRESHOLD 0.65
#define LEGDAMAGETHRESHOLD1 0.4
#define LEGDAMAGETHRESHOLD2 0.6
#define PRONEANIMATION "abcdefg"
#define ARMDAMAGETHRESHOLD 0.7
#define PAINKILLERTHRESHOLD 0.1
#define PAINLOSS 0.005
#define BLOODTHRESHOLD1 0.4
#define BLOODTHRESHOLD2 0.2
#define BLOODLOSSRATE 0.005

_unit = _this select 0;
_selectionName = _this select 1;
_damage = _this select 2;
_source = _this select 3;
_projectile = _this select 4;

// Prevent unnecessary processing
if (damage _unit == 1) exitWith {};

// Code to be executed AFTER damage was dealt
null = _unit spawn {
  sleep 0.001;

  // Reset "unused" hitpoints.
  _this setHitPointDamage ["HitLegs", 0];
  _this setHitPointDamage ["HitHands", 0];

  if (damage _this > UNCONSCIOUSNESSTHRESHOLD and !(_this getVariable "BWA3_Unconscious")) then {
    //[_this] call BWA3_Medical_fnc_knockOut;
  };
  if (damage _this > REVIVETHRESHOLD) then {
    // Determine if unit is revivable.
    if (_this getHitPointDamage "HitHead" < 0.5 and _this getHitPointDamage "HitBody" < 1 and _this getVariable "BWA3_Blood" > 0.2) then {
      _this setVariable ["BWA3_Dead", 1];
    } else {
      _this setDamage 1;
    };
  };

  // Handle leg damage symptoms
  if (_this getHitPointDamage "HitLeftUpLeg" > LEGDAMAGETHRESHOLD2 or
      _this getHitPointDamage "HitLeftLeg" > LEGDAMAGETHRESHOLD2 or
      _this getHitPointDamage "HitLeftFoot" > LEGDAMAGETHRESHOLD2 or
      _this getHitPointDamage "HitRightUpLeg" > LEGDAMAGETHRESHOLD2 or
      _this getHitPointDamage "HitRightLeg" > LEGDAMAGETHRESHOLD2 or
      _this getHitPointDamage "HitRightFoot" > LEGDAMAGETHRESHOLD2) then {

    // Force the unit to the ground.
    _this switchMove PRONEANIMATION;
    _this spawn {
      while (_this getHitPointDamage "HitLeftUpLeg" > LEGDAMAGETHRESHOLD2 or
            _this getHitPointDamage "HitLeftLeg" > LEGDAMAGETHRESHOLD2 or
            _this getHitPointDamage "HitLeftFoot" > LEGDAMAGETHRESHOLD2 or
            _this getHitPointDamage "HitRightUpLeg" > LEGDAMAGETHRESHOLD2 or
            _this getHitPointDamage "HitRightLeg" > LEGDAMAGETHRESHOLD2 or
            _this getHitPointDamage "HitRightFoot" > LEGDAMAGETHRESHOLD2) do {
        waitUntil {stance _this != "PRONE"};
        _this switchMove PRONEANIMATION;
      };
    };
  } else {
    if (_this getHitPointDamage "HitLeftUpLeg" > LEGDAMAGETHRESHOLD1 or
        _this getHitPointDamage "HitLeftLeg" > LEGDAMAGETHRESHOLD1 or
        _this getHitPointDamage "HitLeftFoot" > LEGDAMAGETHRESHOLD1 or
        _this getHitPointDamage "HitRightUpLeg" > LEGDAMAGETHRESHOLD1 or
        _this getHitPointDamage "HitRightLeg" > LEGDAMAGETHRESHOLD1 or
        _this getHitPointDamage "HitRightFoot" > LEGDAMAGETHRESHOLD1) then {

      // Force unit to walk slowly
      //_this forceWalk true; // disable sprinting ?
      _this setHitPointDamage ["HitLegs", 1];
    };
  };

  // Handle arm damage symptoms
  if (_this getHitPointDamage "HitLeftShoulder" > ARMDAMAGETHRESHOLD or
      _this getHitPointDamage "HitLeftArm" > ARMDAMAGETHRESHOLD or
      _this getHitPointDamage "HitLeftForeArm" > ARMDAMAGETHRESHOLD or
      _this getHitPointDamage "HitRightShoulder" > ARMDAMAGETHRESHOLD or
      _this getHitPointDamage "HitRightArm" > ARMDAMAGETHRESHOLD or
      _this getHitPointDamage "HitRightForeArm" > ARMDAMAGETHRESHOLD) then {

    // Drop weapon
    _this spawn {
      while {true} do {
        waitUntil {currentWeapon _this != ""};
        _weapon = currentWeapon _this;
        if (currentWeapon _this == primaryWeapon _this) then {
          _attachments = primaryWeaponItems _this;
        } else {
          if (currentWeapon _this == handGunWeapon _this) then {
            _attachments = handGunItems _this;
          } else {
            _attachments = secondaryWeaponItems _this;
          };
        };
        _magazine = currentMagazine _this;
        _rounds = 1; // later

        _this removeWeapon (currentWeapon _this);
        _this addMagazine [_magazine, _rounds];
        _weaponVehicle = _weapon createVehicle (eyePos player);
        {_weaponVehicle addItem _x} forEach _attachments; // Does this work?
      };
    };
  };

  if (damage _this * (_this getVariable "BWA3_Painkiller") > _this getVariable "BWA3_Pain") then {
    _this setVariable ["BWA3_Pain", (damage _this) * (_this getVariable "BWA3_Painkiller")];
  };

  // Pain
  if (_this == player) then {
    _this spawn {
      if (_this getVariable "BWA3_InPain") exitWith {};
      _this setVariable ["BWA3_InPain", true];
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
  if !(_this getVariable "BWA3_Bleeding") then {
    _this setVariable ["BWA3_Bleeding", true];
    _this spawn {
      while {_this getVariable "BWA3_Blood" > 0 and (_this getVariable "BWA3_Bleeding")} do {
        _blood = _this getVariable "BWA3_Blood";
        _blood = _blood - BLOODLOSSRATE * damage _this;
        _this setVariable ["BWA3_Blood", _blood];
        if (_blood < BLOODTHRESHOLD1 and !(_this getVariable "BWA3_Unconscious")) then {
          [_this] call BWA3_Medical_fnc_knockOut;
        };
        if (_blood < BLOODTHRESHOLD2) then {
          _this setDamage 1;
        };
        sleep 10;
      };
    };
  };

};