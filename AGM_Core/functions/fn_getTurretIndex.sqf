/*
 * Author: commy2
 *
 * Get the turret index of a units current turret.
 * 
 * Argument:
 * 0: Unit, not the vehicle (as in not a car but the player) (Object)
 * 
 * Return value:
 * Turret index array or config path. E.g: [0] for gunner or [0,0] for commander. Returns empty array if unit is not in a turret. (Array)
 */

private ["_unit", "_vehicle", "_turrets", "_units", "_index"];

_unit = _this select 0;
_vehicle = vehicle _unit;

_turrets = [typeOf _vehicle] call AGM_Core_fnc_getTurrets;

_units = [];
{
	_units pushBack (_vehicle turretUnit _x);
} forEach _turrets;

_index = _units find _unit;

if (_index == -1) exitWith {[]};

_turrets select _index;
