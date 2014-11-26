// by commy2

private ["_unit", "_target", "_vehicle", "_objects"];

_unit = _this select 0;
_target = _this select 1;
_vehicle = _this select 2;

if (isNull _target) then {
  _objects = attachedObjects _unit;
  _objects = [_objects, {_this getVariable ["AGM_isCaptive", false]}] call AGM_Core_fnc_filter;
  _target = _objects select 0;
};

if (isNull _vehicle) then {
  _objects = nearestObjects [_unit, ["Car_F", "Tank_F", "Helicopter_F", "Boat_F", "Plane_F"], 10];
  _vehicle = _objects select 0;
};

if (!isNil "_target" && {!isNil "_vehicle"}) then {
  _unit setVariable ["AGM_isEscorting", false];
  [[_target, _vehicle, "Cargo"], "AGM_Core_fnc_getInPosition", _target] call AGM_Core_fnc_execRemoteFnc;
};
