/*
By: KoffeinFlummi

Called when some dude gets shot. Or stabbed. Or blown up. Or pushed off a cliff. Or hit by a car. Or burnt. Or poisoned. Or gassed. Or cut. You get the idea.

Arguments:
0: Unit that got hit (Object)
1: Name of the selection that was hit (String); "" for structural damage
2: Amount of damage inflicted (Number)
3: Shooter (Object); Null for explosion damage, falling, fire etc.
4: Projectile (Object)

Return value:
Damage value to be inflicted (optional)
*/

#define REVIVETRESHOLD 0.7;
#define LEGDAMAGETRESHOLD1 0.4;
#define LEGDAMAGETRESHOLD2 0.6;
#define PRONEANIMATION "abcdefg";
#define ARMDAMAGETRESHOLD 0.7;
#define PAINKILLERTRESHOLD 0.1;
#define PAINTRESHOLD 0.1;
#define BLOODTRESHOLD1 0.4; // Treshold for unconsciousness
#define BLOODTRESHOLD2 0.2; // Treshold for death
#define BLOODLOSSRATE 0.02;

_unit = _this select 0;
_selectionName = _this select 1;
_damage = _this select 2;
_source = _this select 3;
_projectile = _this select 4;

// Code to be executed AFTER damage was dealt
_unit spawn {
  sleep 0.001;

  // Reset "unused" hitpoints.
  _this setHitPointDamage ["HitLegs", 0];
  _this setHitPointDamage ["HitHands", 0];

  _this setVariable ["BWA3_Diagnose", false];

  if (damage _this * _this getHitPointDamage "BWA3_Painkiller" > _this getVariable "BWA3_Pain") then {
    _this setVariable ["BWA3_Pain", damage _this * _this getHitPointDamage "BWA3_Painkiller"];
  };

  // Check if unit is already dead
  if (damage _this > REVIVETRESHOLD) then {
    // Determine if unit is revivable.
    if (_this getHitPointDamage "HitHead" < 0.5 and _this getHitPointDamage "HitBody" < 1 and _this getVariable "BWA3_Blood" > 0.2) then {
      _this setVariable ["BWA3_Dead", 1];
    } else {
      _this setDamage 1;
    };
  };

  // Handle leg damage symptoms
  if (_this getHitPointDamage "HitLeftUpLeg" > LEGDAMAGETRESHOLD2 or
      _this getHitPointDamage "HitLeftLeg" > LEGDAMAGETRESHOLD2 or
      _this getHitPointDamage "HitLeftFoot" > LEGDAMAGETRESHOLD2 or
      _this getHitPointDamage "HitRightUpLeg" > LEGDAMAGETRESHOLD2 or
      _this getHitPointDamage "HitRightLeg" > LEGDAMAGETRESHOLD2 or
      _this getHitPointDamage "HitRightFoot" > LEGDAMAGETRESHOLD2) then {

    // Force the unit to the ground.
    _this switchMove PRONEANIMATION;
    _this spawn {
      while (_this getHitPointDamage "HitLeftUpLeg" > LEGDAMAGETRESHOLD2 or
            _this getHitPointDamage "HitLeftLeg" > LEGDAMAGETRESHOLD2 or
            _this getHitPointDamage "HitLeftFoot" > LEGDAMAGETRESHOLD2 or
            _this getHitPointDamage "HitRightUpLeg" > LEGDAMAGETRESHOLD2 or
            _this getHitPointDamage "HitRightLeg" > LEGDAMAGETRESHOLD2 or
            _this getHitPointDamage "HitRightFoot" > LEGDAMAGETRESHOLD2) do {
        waitUntil {stance _this != "PRONE"};
        _this switchMove PRONEANIMATION;
      };
    };
  } else {
    if (_this getHitPointDamage "HitLeftUpLeg" > LEGDAMAGETRESHOLD1 or
        _this getHitPointDamage "HitLeftLeg" > LEGDAMAGETRESHOLD1 or
        _this getHitPointDamage "HitLeftFoot" > LEGDAMAGETRESHOLD1 or
        _this getHitPointDamage "HitRightUpLeg" > LEGDAMAGETRESHOLD1 or
        _this getHitPointDamage "HitRightLeg" > LEGDAMAGETRESHOLD1 or
        _this getHitPointDamage "HitRightFoot" > LEGDAMAGETRESHOLD1) then {

      // Force unit to walk slowly
      //_this forceWalk true; // disable sprinting ?
      _this setHitPointDamage ["HitLegs", 1];
    };
  };

  // Handle arm damage symptoms
  if (_this getHitPointDamage "HitLeftShoulder" > ARMDAMAGETRESHOLD or
      _this getHitPointDamage "HitLeftArm" > ARMDAMAGETRESHOLD or
      _this getHitPointDamage "HitLeftForeArm" > ARMDAMAGETRESHOLD or
      _this getHitPointDamage "HitRightShoulder" > ARMDAMAGETRESHOLD or
      _this getHitPointDamage "HitRightArm" > ARMDAMAGETRESHOLD or
      _this getHitPointDamage "HitRightForeArm" > ARMDAMAGETRESHOLD) then {

    // Drop weapon
    0 spawn {
      while {true} do {
        waitUntil {currentWeapon _this != ""};
        _weapon = currentWeapon _this;
        if (currentWeapon _this == primaryWeapon _this) then {
          _attachments = primaryWeaponItems _this;
        } else {
          if (currentWeapon _this == handGunWeapon _this) then {
            _attachments = handGunWeaponItems _this;
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

  // Pain
  _this spawn {
    while {_this getVariable "BWA3_Pain" > PAINTRESHOLD and _this getVariable "BWA3_Painkiller" > PAINKILLERTRESHOLD} do {
      //Pain RSC (later)
      hintSilent format ["Pain: %1 \n Painkillers: %2", _this getVariable "BWA3_Pain", _this getVariable "BWA3_Painkiller"];
      sleep 5;
    };
  };

  // Bleeding
  _this spawn {
    while {_this getVariable "BWA3_Blood" > 0} do {
      _blood = _this getVariable "BWA3_Blood";
      _blood = _blood - BLOODLOSSRATE * damage _this;
      _this setVariable ["BWA3_Blood", _blood];
      if (_blood < BLOODTRESHOLD1) then {
        [_this] call BWA3_Medical_fnc_knockOut;
      };
      if (_blood < BLOODTRESHOLD2) then {
        _this setDamage 1;
      };
      sleep 10;
    };
  };

};