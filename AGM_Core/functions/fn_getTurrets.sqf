/*
 * Author: commy2
 *
 * Get all turret indicies of a vehicle.
 * 
 * Argument:
 * 0: Vehicle type (String)
 * 
 * Return value:
 * All turret index arrays of the vehicle. E.g: [[0], [0,0]] (Array)
 */

private ["_vehicle", "_config", "_turrets", "_fnc_addTurret"];

_vehicle = _this select 0;
_config = configFile >> "CfgVehicles" >> _vehicle;

_turrets = [];
_fnc_addTurret = {
	private ["_config", "_path", "_count", "_offset", "_index", "_path2", "_config2"];

	_config = _this select 0;
	_path = _this select 1;

	_config = _config >> "Turrets";
	_count = count _config;

	_offset = 0;
	for "_index" from 0 to (_count - 1) do {
		_path2 = _path + [_index - _offset];
		_config2 = _config select _index;

		if (isClass _config2) then {
			_turrets pushBack _path2;
			[_config2, _path2] call _fnc_addTurret;
		} else {
			_offset = _offset + 1;
		};
	};
};

[_config, []] call _fnc_addTurret;

_turrets
