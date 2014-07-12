// by commy2

private ["_vehicle", "_turret"];

_vehicle = _this select 0;
_turret = _this select 1;

//WIP

_turret in ([typeOf _vehicle] call AGM_Core_fnc_getTurrets) && {isNull (_vehicle turretUnit _turret)} && {!(_vehicle lockedTurret _turret)} && {getNumber (configFile >> "CfgVehicles" >> typeOf _vehicle >> "isUav") != 1}
