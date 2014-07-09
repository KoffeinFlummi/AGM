// by commy2

private ["_vehicle", "_turret"];

_vehicle = _this select 0;

_turret = [typeOf _vehicle] call AGM_Core_fnc_getTurretCommander;

!(_turret isEqualTo []) && {isNull (commander _vehicle)} && {!(_vehicle lockedTurret _turret)}
