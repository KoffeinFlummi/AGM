// by commy2

private ["_unit", "_name"];

_unit = _this select 0;

if (!alive _unit) exitWith {};

_name = [name _unit, true] call AGM_Core_fnc_sanitizeString;

_unit setVariable ["AGM_Name", _name, true];
