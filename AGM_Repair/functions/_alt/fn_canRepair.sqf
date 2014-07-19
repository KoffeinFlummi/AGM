// by commy2

private ["_vehicle", "_part", "_config", "_turrets", "_classes", "_turretConfig", "_isClass"];

_vehicle = _this select 0;
_part = format ["Hit%1", _this select 1];

_config = configFile >> "CfgVehicles" >> typeOf _vehicle;
_turrets = [typeOf _vehicle] call AGM_Core_fnc_getTurrets;

_classes = [_config];
{
	_turretConfig = [_config] call AGM_Core_fnc_getTurretConfigPath;
	_classes set [_forEachIndex + 1, _turretConfig];
} forEach _turrets;

_isClass = false;
{
	if (isClass (_x >> "HitPoints" >> _part)) then {
		_isClass = true;
	};
} forEach _classes;

alive player &&
{alive _vehicle} &&
{_isClass} &&
{_vehicle getHitPointDamage _part > 0}
