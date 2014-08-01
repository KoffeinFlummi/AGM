// by commy2

private ["_unit", "_objects", "_target", "_vehicle"];

_unit = _this select 0;

_objects = attachedObjects _unit;
_objects = [_objects, {_this getVariable ["AGM_isCaptive", false]}] call AGM_Core_fnc_filter;

_target = _objects select 0;
_vehicle = nearestObject [_unit, "AllVehicles"];

_unit getVariable ["AGM_isEscorting", false]
&& {count _objects > 0}
&& {!isNull _vehicle}
&& {_unit distance _vehicle < 5}
&& {_vehicle emptyPositions "Cargo" < 1}
&& {!(_vehicle lockedCargo 0)}
