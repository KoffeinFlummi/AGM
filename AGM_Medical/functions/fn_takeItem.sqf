/*
 * Author: KoffeinFlummi
 *
 * Takes an item, preferrably from the cursorTarget first.
 *
 * Arguments:
 * 0: The unit being treated.
 * 1: The desired item (classname).
 *
 * Return Value:
 * True if item was successfully take, false otherwise.
 */

_unit = _this select 0;
_item = _this select 1;
_displayName = getText (configFile >> "CfgWeapons" >> _item >> "displayName");

if ((_unit == player) and (_item in items player)) exitWith {
  player removeItem _item;
  true
};

if (_item in (items _unit)) exitWith {
  systemChat format [localize "STR_AGM_Medical_TakingItemPatient", _displayName];
  _unit removeItem _item;
  if (!(local _unit) and isPlayer _unit) then {
    [[player, _item, _displayName, _unit], "{systemChat format [localize 'STR_AGM_Medical_TakingYourItem', ((_this select 0) getVariable ['AGM_Name', (name (_this select 0))]), (_this select 2)];}", _unit] call AGM_Core_fnc_execRemoteFnc;
  };
  true
};

if (_item in (items player)) exitWith {
  player removeItem _item;
  systemChat format [localize "STR_AGM_Medical_TakingItemSelf", _displayName];
  true
};

[localize "STR_AGM_Medical_NoItem"] call AGM_Core_fnc_displayTextStructured;
false
