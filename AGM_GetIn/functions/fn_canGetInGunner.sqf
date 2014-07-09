// by commy2

private ["_vehicle", "_turret"];

_vehicle = _this select 0;

_turret = [typeOf _vehicle] call AGM_Core_fnc_getTurretGunner;

!(_turret isEqualTo []) && {isNull (gunner _vehicle)} && {!(_vehicle lockedTurret _turret)} && {getNumber (configFile >> "CfgVehicles" >> typeOf _vehicle >> "isUav") != 1}
