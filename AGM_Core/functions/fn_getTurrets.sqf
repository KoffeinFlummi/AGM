/*
 * Author: commy2
 *
 * Get all turret indicies of a vehicle.
 * 
 * Argument:
 * 0: Vehicle (Object)
 * 
 * Return value:
 * All turret index arrays of the vehicle. E.g: [[0], [0,0]] (Array)
 */

private ["_vehicle", "_config", "_turrets", "_fnc_addTurret"];

_vehicle = _this select 0;
_config = configFile >> "CfgVehicles" >> typeOf _vehicle;

_turrets = [];
_fnc_addTurret = {
	private ["_config", "_path", "_count", "_index"];

	_config = _this select 0;
	_path = _this select 1;

	_config = _config >> "Turrets";
	_count = count _config;

	for "_index" from 0 to (_count - 1) do {
		_turrets set [count _turrets, _path + [_index]];
		[_config select _index, _path + [_index]] call _fnc_addTurret;
	};
};

[_config, []] call _fnc_addTurret;

_turrets
