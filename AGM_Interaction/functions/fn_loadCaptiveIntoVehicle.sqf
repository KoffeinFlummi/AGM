// by commy2

private ["_unit", "_objects", "_target", "_vehicle"];

_unit = _this select 0;

_objects = attachedObjects _unit;
_objects = [_objects, {_this getVariable ["AGM_isCaptive", false]}] call AGM_Core_fnc_filter;

if (count _objects == 0) exitWith {};

_target = _objects select 0;
_vehicle = nearestObject [_unit, "AllVehicles"];

if (isNull _vehicle) exitWith {};

[[_target, _vehicle], "{(_this select 0) moveInCargo (_this select 1)}", _target] call AGM_Core_fnc_execRemoteFnc;
