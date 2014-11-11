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
 * 2: Locked status (Array)
 */

private ["_vehicle", "_positions", "_positionsUnits", "_driver", "_gunner", "_commander", "_turrets", "_coPilot", "_ffvPositions", "_cargo", "_coDrivers"];

_vehicle = _this select 0;

_positions = [_vehicle] call AGM_Core_fnc_getVehiclePositionsUnits;

_positionsUnits = _positions select 1;
_positions = _positions select 0;

_driver = lockedDriver _vehicle;
_gunner = _vehicle lockedTurret (_positions select 1);
_commander = _vehicle lockedTurret (_positions select 2);
_coPilot = _vehicle lockedTurret (_positions select 3);

_turrets = + _positions select 4;
{
	_turrets set [_forEachIndex, _vehicle lockedTurret _x];
} forEach _turrets;

_ffvPositions = + _positions select 5;
{
	_ffvPositions set [_forEachIndex, _vehicle lockedTurret _x];
} forEach _ffvPositions;

_cargo = + _positions select 6;
{
	_cargo set [_forEachIndex, _vehicle lockedCargo _x];
} forEach _cargo;

_coDrivers = + _positions select 7;
{
	_coDrivers set [_forEachIndex, _vehicle lockedCargo _x];
} forEach _coDrivers;

[_positions, _positionsUnits, [_driver, _gunner, _commander, _coPilot, _turrets, _ffvPositions, _cargo, _coDrivers]]
