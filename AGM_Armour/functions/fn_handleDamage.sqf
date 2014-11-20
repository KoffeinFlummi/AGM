/*
 * Author: KoffeinFlummi
 *
 * Handles all incoming damage for vehicles.
 *
 * Arguments:
 * HandleDamage EH
 *
 * Return Value:
 * Damage to be inflicted.
 */

_vehicle       = _this select 0;
_selectionName = _this select 1;
_damage        = _this select 2;
_source        = _this select 3;
_projectile    = _this select 4;

// It's already dead, who cares?
if (damage _vehicle >= 1) exitWith {};

// Determine type of vehicle.
_type = "";
if (_vehicle isKindOf "Car_F") then {
  if (_vehicle isKindOf "Wheeled_APC_F") then {
    _type = "tank";
  } else {
    _type = "car";
  };
};
if (_vehicle isKindOf "Tank_F") then {
  _type = "tank";
};
if (_vehicle isKindOf "Helicopter") then {
  _type = "heli";
};
if (_vehicle isKindOf "Plane") then {
  _type = "plane";
};
if (_vehicle isKindOf "Ship_F") then {
  _type = "ship";
};
if (_vehicle isKindOf "StaticWeapon") then {
  _type = "static";
};

// Are we doing anything with this type of vehicle?
if !(_type in ["tank", "car"]) exitWith {};

// Do nothing for uncritical parts (wheels, gun, etc.)
_critical = True; // @todo
if !(_critical) exitWith {};

// Change in damage
_newDamage = _damage - (_vehicle getHit _selectionName);

// Prevent total destruction of car unless round used is explosive
if (_type == "car") exitWith {
  _explosive = True; // @todo
  if (_explosive) then {
    _damage
  } else {
    _damage min 0.89
  };
};

// Prevent total destruction of tank unless ammo storage is hit
if (_type == "tank") exitWith {

  // Check if ammo storage was hit.
  _target = getText (configFile >> "CfgVehicles" >> typeOf _vehicle >> "AGM_Armour_AmmoLocation");
  if (isClass (configFile >> "CfgVehicles" >> typeOf _vehicle >> "HitPoints" >> _target)) then {
    _target = getText (configFile >> "CfgVehicles" >> typeOf _vehicle >> "HitPoints" >> _target >> "name");
  } else {
    // @todo: more complex turret structures?
    _target = getText (configFile >> "CfgVehicles" >> typeOf _vehicle >> "Turrets" >> "MainTurret" >> "HitPoints" >> _target >> "name");
  };

  // Trigger cook-off
  if (_target == _selectionName and _newDamage > 0.3) then {
    [_vehicle] call AGM_Armour_fnc_cookOff;
  };

  // Prevent destruction, let cook-off handle it if necessary
  _damage min 0.89
};

// this shouldn't happen, but who knows
_damage