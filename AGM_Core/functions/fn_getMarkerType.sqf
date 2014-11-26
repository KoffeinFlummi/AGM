/*
 * Author: KoffeinFlummi
 *
 * Get the apropriate marker for a group.
 *
 * Arguments:
 * 0: Group
 *
 * Return Value:
 * Marker Type (string)
 */

_group = _this select 0;
_leader = leader _group;
_vehicle = vehicle _leader;
_side = side _leader;

if (_vehicle == _leader) exitWith {
  if (
      (getNumber (configFile >> "CfgVehicles" >> (typeOf _leader) >> "detectSkill") > 20) or
      (getNumber (configFile >> "CfgVehicles" >> (typeOf _leader) >> "camouflage") < 1)
      ) then {
    ["n_recon", "b_recon", "o_recon"] select ((["GUER", "WEST", "EAST"] find (str _side)) max 0)
  } else {
    ["n_inf", "b_inf", "o_inf"] select ((["GUER", "WEST", "EAST"] find (str _side)) max 0)
  };
};

if (getNumber (configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "attendant") == 1) exitWith {
  ["n_med", "b_med", "o_med"] select ((["GUER", "WEST", "EAST"] find (str _side)) max 0)
};
if (
    (getNumber (configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "transportRepair") > 0) or
    (getNumber (configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "transportFuel") > 0) or
    (getNumber (configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "AGM_canRepair") > 0) or
    (getNumber (configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "AGM_fuelCapacityCargo") > 0)
    ) exitWith {
  ["n_maint", "b_maint", "o_maint"] select ((["GUER", "WEST", "EAST"] find (str _side)) max 0)
};

if (_vehicle isKindOf "Plane") exitWith {
  ["n_plane", "b_plane", "o_plane"] select ((["GUER", "WEST", "EAST"] find (str _side)) max 0)
};
if (_vehicle isKindOf "Air") exitWith {
  ["n_air", "b_air", "o_air"] select ((["GUER", "WEST", "EAST"] find (str _side)) max 0)
};

if (_vehicle isKindOf "StaticMortar") exitWith {
  ["n_mortar", "b_mortar", "o_mortar"] select ((["GUER", "WEST", "EAST"] find (str _side)) max 0)
};
if (getNumber (configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "artilleryScanner") == 1) exitWith {
  ["n_art", "b_art", "o_art"] select ((["GUER", "WEST", "EAST"] find (str _side)) max 0)
};

if (_vehicle isKindOf "Car") exitWith {
  ["n_motor_inf", "b_motor_inf", "o_motor_inf"] select ((["GUER", "WEST", "EAST"] find (str _side)) max 0)
};
if ((_vehicle isKindOf "Tank") and (getNumber (configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "transportSoldier") > 0)) exitWith {
  ["n_mech_inf", "b_mech_inf", "o_mech_inf"] select ((["GUER", "WEST", "EAST"] find (str _side)) max 0)
};
if (_vehicle isKindOf "Tank") exitWith {
  ["n_armor", "b_armor", "o_armor"] select ((["GUER", "WEST", "EAST"] find (str _side)) max 0)
};

if (_vehicle isKindOf "Ship") exitWith {
  ["n_naval", "b_naval", "o_naval"] select ((["GUER", "WEST", "EAST"] find (str _side)) max 0)
};

// generic marker
["n_unknown", "b_unknown", "o_unknown"] select ((["GUER", "WEST", "EAST"] find (str _side)) max 0)
