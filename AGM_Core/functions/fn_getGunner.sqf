/*
 * Author: commy2
 *
 * Get the gunner of a vehicle who uses the given weapon type. Requires every turret to have a different weapons.
 *
 * Argument:
 * 0: The vehicle (Object)
 * 1: weapon of the vehicle (String)
 *
 * Return value:
 * The turret gunner with this weapon (Object)
 */

private ["_vehicle", "_weapon"];

_vehicle = _this select 0;
_weapon = _this select 1;

private ["_turrets", "_gunner"];
_turrets = [typeOf _vehicle] call AGM_Core_fnc_getTurrets;

_gunner = objNull;
{
	if (_gunner in (_vehicle weaponsTurret _x)) exitWith {
		_gunner = _vehicle turretUnit _x;
	};
} forEach _turrets;
_gunner
