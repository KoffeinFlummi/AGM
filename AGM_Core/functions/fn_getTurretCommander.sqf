/*
 * Author: commy2
 *
 * Get the turret index of a vehicles commander.
 * 
 * Argument:
 * 0: Vehicle type (String)
 * 
 * Return value:
 * Turret index of the vehicles commander. Empty array means no observer position. (Array)
 */

private ["_vehicle", "_turrets", "_turret", "_config", "_index"];

_vehicle = _this select 0;

_turrets = [_vehicle] call AGM_Core_fnc_getTurrets;

_turret = [];
{
	_config = configFile >> "CfgVehicles" >> _vehicle;

	for "_index" from 0 to (count _x - 1) do {
		_config = (_config >> "Turrets") select (_x select _index);
	};

	if (getNumber (_config >> "primaryObserver") == 1) exitWith {
		_turret = _x;
	};
} forEach _turrets;
_turret
