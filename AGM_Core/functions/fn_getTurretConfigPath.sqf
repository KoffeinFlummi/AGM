/*
 * Author: commy2
 *
 * Get the config path of a vehicles turret.
 * 
 * Argument:
 * 0: vehicles config (Config)
 * 1: Turret index (Array)
 * 
 * Return value:
 * Turret config (Config)
 */

private ["_config", "_turretIndex", "_index", "_offset", "_config2"];

_config = _this select 0;
_turretIndex = _this select 1;

for "_index" from 0 to (count _turretIndex - 1) do {
	_config = _config >> "Turrets";

	_offset = 0;
	_config2 = _config select (_turretIndex select _index);
	while {!isClass _config2} do {
		_offset = _offset + 1;
		_config2 = _config select (_turretIndex select _index) + _offset;
	};
	_config = _config2;
};
_config
