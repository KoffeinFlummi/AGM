/*
 * Author: commy2
 *
 * Get all vehicle positions
 * 
 * Argument:
 * 0: Vehicle (Object)
 * 
 * Return value:
 * 0: Vehicle positions (Array)
 * 1: Units in these positions (Array)
 */

private ["_vehicle", "_positions", "_driver", "_gunner", "_commander", "_turrets", "_coPilot", "_ffvPositions", "_cargo", "_coDrivers"];

_vehicle = _this select 0;

_positions = [typeOf _vehicle] call AGM_Core_fnc_getVehiclePositions;

_driver = driver _vehicle;
_gunner = gunner _vehicle;
_commander = commander _vehicle;

_coPilot = _vehicle turretUnit (_positions select 3);
_turrets = _positions select 4;
{
	_turrets set [_forEachIndex, _vehicle turretUnit _x];
} forEach _turrets;

_ffvPositions = _positions select 5;
{
	_ffvPositions set [_forEachIndex, _vehicle turretUnit _x];
} forEach _ffvPositions;

_cargo = _positions select 6;
_coDrivers = _positions select 7;
{
	private ["_cargoIndex", "_index"];
	_cargoIndex = _vehicle getCargoIndex _x;

	if (_cargoIndex != -1) then {
		_index = _cargo find _cargoIndex;

		if (_index != -1) then {
			_cargo set [_index, _x];
		} else {
			_index = _coDrivers find _cargoIndex;

			if (_index != -1) then {
				_coDrivers set [_index, _x];
			};
		};
	};
} forEach crew _vehicle;

{
	if (typeName _x == "SCALAR") then {
		_cargo set [_forEachIndex, objNull];
	};
} forEach _cargo;

{
	if (typeName _x == "SCALAR") then {
		_coDrivers set [_forEachIndex, objNull];
	};
} forEach _coDrivers;

[_positions, [_driver, _gunner, _commander, _coPilot, _turrets, _ffvPositions, _cargo, _coDrivers]]
