// by commy2

private ["_unit", "_vehicle", "_cargo", "_target"];

_unit = _this select 0;
_vehicle = _this select 1;

_cargo = crew _vehicle;	// Can also unload from driver, gunner, commander, turret positions. They shouldn't be there anyway.

_cargo = [_cargo, {_this getVariable ["AGM_isCaptive", false]}] call AGM_Core_fnc_filter;

if (count _cargo == 0) exitWith {};

_target = _cargo select 0;

moveOut _target;	//global?
[_target, "{unassignVehicle _this}", _target] call AGM_Core_fnc_execRemoteFnc;
