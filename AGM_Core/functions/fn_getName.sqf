/*
 * Author: commy2
 *
 * Returns the name of the object. Used to prevent issues with the name command.
 *
 * Argument:
 * 0: Object (Object)
 *
 * Return value:
 * The name.
 */

private ["_unit", "_name"];

_unit = _this select 0;

_name = "";

if (_unit isKindOf "CAManBase") then {
  _name = _unit getVariable ["AGM_Name", localize "STR_AGM_Core_Unknown"];
};

_name
