/*
 * Author: KoffeinFlummi
 *
 * Opens the interaction menu.
 *
 * Arguments:
 * None
 *
 * Return Values:
 * None
 */

private ["_target"];

_target = cursorTarget;

// PLAYER IS IN VEHICLE
if (vehicle player != player) exitWith {

};

// PLAYER IS NOT IN VEHICLE, POINTS AT SOMETHING
if !(isNull _target) exitWith {
  AGM_getActions = {
  };

  _path = configFile >> "CfgVehicles" >> typeOf (_target) >> "AGM_Actions";
  if (isNull _path) exitWith {};

  _menuItems = [];
  _i = 0;
  while {_i < count(_path)} do {
    _text = getText ((_path select _i) >> "displayName");
    _condition = getText ((_path select _i) >> "condition");
    _statement = getText ((_path select _i) >> "statement");

    if (call compile _condition) then {
      _menuItems = _menuItems + [[_text, _statement]];
    };
  };

  [_menuItems] call AGM_Core_fnc_openMenu;
};

// PLAYER IS NOT IN VEHICLE, POINTS AT NOTHING/GROUND
