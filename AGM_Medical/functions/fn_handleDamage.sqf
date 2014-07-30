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
if (damage _unit == 1) exitWith {};

_hitSelections = [
  "head",
  "body",
  "hand_l",
  "hand_r",
  "leg_l",
  "leg_r"
];
_hitPoints = [
  "HitHead",
  "HitBody",
  "HitLeftArm",
  "HitRightArm",
  "HitLeftLeg",
  "HitRightLeg"
];

// If the damage is being weird, we just tell it to fuck off.
if !((_selectionName in _hitSelections) or (_selectionName == "")) exitWith {0};

// Calculate change in damage.
_newDamage = _damage - (damage _unit);
if (_selectionName in _hitSelections) then {
  _newDamage = _damage - (_unit getHitPointDamage (_hitPoints select (_hitSelections find _selectionName)));
};

// Exclude falling damage to anything other than legs, reduce overall fall damage.
if (((velocity _unit) select 2 < -10) and (vehicle player == player)) then {
  AGM_Medical_IsFalling = true;
};
if (AGM_Medical_IsFalling and !(_selectionName in ["", "leg_l", "leg_r"])) exitWith {
  if (_selectionName in _hitSelections) then {
    _unit getHitPointDamage (_hitPoints select (_hitSelections find _selectionName))
  } else {
    0
  };
};
if (AGM_Medical_IsFalling and (_selectionName == "")) then {
  _damage = _damage - _newDamage / 2; // half structural fall damage
};

// Prevent multiple damages by same hit.
if !(AGM_Medical_IsFalling or (_selectionName == "")) then {
  _found = false;
  for "_i" from 0 to (count AGM_Medical_Hits - 1) do {
    if (((AGM_Medical_Hits select _i) select 2) == _projectile) then {
      _found = true;
      if (((AGM_Medical_Hits select _i) select 1) < _newDamage) then {
        AGM_Medical_Hits set [_i, [_hitPoints select (_hitSelections find _selectionName), _newDamage, _projectile]];
      };
    };
  };
  if !(_found) then {
    AGM_Medical_Hits = AGM_Medical_Hits + [[(_hitPoints select (_hitSelections find _selectionName)), _newDamage, _projectile]];
  };
};

// Code to be executed AFTER damage was dealt
if ((count AGM_Medical_Hits > 0) or AGM_Medical_IsFalling or (_selectionName == "")) then {
  null = [_unit, damage _unit, (_unit getVariable "AGM_Pain")] spawn {
    _unit = _this select 0;
    _damageold = _this select 1;
    _painold = _this select 2;

    sleep 0.00001;

    _preventDeath = false;
    if (!(_unit getVariable "AGM_Unconscious") and {AGM_Medical_PreventInstaDeath > 0}) then {
      _preventDeath = true;
    };
    if ((_unit getVariable "AGM_Unconscious") and {AGM_Medical_PreventDeathWhileUnconscious > 0}) then {
      _preventDeath = true;
    };

    if !(AGM_Medical_IsFalling) then {
      {
        if (_preventDeath and ((_x select 0) in ["HitHead", "HitBody"])) then {
          _unit setHitPointDamage [(_x select 0), ((_x select 1) min 0.89)];
        } else {
          _unit setHitPointDamage [(_x select 0), (_x select 1)];
        };
      } count AGM_Medical_Hits;
    };

    // reset things.
    AGM_Medical_Hits = [];
    AGM_Medical_IsFalling = false;

    _unit setVariable ["AGM_Diagnosed", false, true];

    _armdamage = (_unit getHitPointDamage "HitLeftArm") + (_unit getHitPointDamage "HitRightArm");
    _legdamage = (_unit getHitPointDamage "HitLeftLeg") + (_unit getHitPointDamage "HitRightLeg");

    // Reset "unused" hitpoints.
    [_unit, "HitHands", 0, true] call AGM_Medical_fnc_setHitPointDamage;

    // Account for unassigned structural damage, like when you crash into something with a vehicle
    if ((damage _unit > 0) and (_unit getHitPointDamage "HitHead" < 0.01) and (_unit getHitPointDamage "HitBody" < 0.01) and (_unit getHitPointDamage "HitLeftArm" < 0.01) and (_unit getHitPointDamage "HitRightArm" < 0.01) and (_unit getHitPointDamage "HitLeftLeg" < 0.01) and (_unit getHitPointDamage "HitRightLeg" < 0.01)) then {
      [_unit, "HitBody", (damage _unit), true] call AGM_Medical_fnc_setHitPointDamage;
    };

    // Handle death and unconsciousness
    if (damage _unit > UNCONSCIOUSNESSTHRESHOLD and damage _unit < 1 and !(_unit getVariable "AGM_Unconscious")) then {
      [_unit] call AGM_Medical_fnc_knockOut;
    };

    // Handle leg damage symptoms
    if (_legdamage >= LEGDAMAGETHRESHOLD1) then {
      // lightly wounded, limit walking speed
      [_unit, "HitLegs", 1, true] call AGM_Medical_fnc_setHitPointDamage;
    } else {
      [_unit, "HitLegs", 0, true] call AGM_Medical_fnc_setHitPointDamage;
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
          _strength = player getVariable "AGM_Pain";
          _strength = _strength * AGM_Medical_CoefPain;
          "chromAberration" ppEffectAdjust [0.035 * _strength, 0.035 * _strength, false];
          "chromAberration" ppEffectCommit 1;
          sleep (1.5 - (player getVariable "AGM_Pain"));
          "chromAberration" ppEffectAdjust [0.35 * _strength, 0.35 * _strength, false];
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

          if !([_this] call AGM_Medical_fnc_isInMedicalVehicle) then {
            if (_this == player) then {[(damage _this) * 500] call BIS_fnc_bloodEffect;};
            _blood = _this getVariable "AGM_Blood";
            _blood = _blood - BLOODLOSSRATE * AGM_Medical_CoefBleeding * (damage _this);
            _blood = _blood max 0;
            _this setVariable ["AGM_Blood", _blood, true];
            if (_blood <= BLOODTHRESHOLD1 and !(_this getVariable "AGM_Unconscious")) then {
              [_this] call AGM_Medical_fnc_knockOut;
            };
            if (_blood <= BLOODTHRESHOLD2 and {AGM_Medical_PreventDeathWhileUnconscious == 0}) then {
              _this setDamage 1;
            };
          };

          sleep 10;
        };
        _this setVariable ["AGM_Bleeding", false, true];
      };
    };

  };
};

_preventDeath = false;
if (!(_unit getVariable "AGM_Unconscious") and {AGM_Medical_PreventInstaDeath > 0}) then {
  _preventDeath = true;
};
if ((_unit getVariable "AGM_Unconscious") and {AGM_Medical_PreventDeathWhileUnconscious > 0}) then {
  _preventDeath = true;
};

if (_preventDeath and vehicle _unit != _unit and damage (vehicle _unit) >= 1) exitWith {
  _unit setPosATL [(getPos _unit select 0) + (random 3) - 1.5, (getPos _unit select 1) + (random 3) - 1.5, 0];
  [_unit, "HitBody", 0.89, true] call AGM_Medical_fnc_setHitPointDamage;
  [_unit] call AGM_Medical_fnc_knockOut;
  _unit allowDamage false;
  _unit spawn {
    sleep 1;
    _this allowDamage true;
  };
};

if (_preventDeath) then {
  _damage = _damage min 0.89;
};

if (AGM_Medical_IsFalling or (_selectionName == "")) then {
  _damage
} else {
  _damage - _newDamage
};
