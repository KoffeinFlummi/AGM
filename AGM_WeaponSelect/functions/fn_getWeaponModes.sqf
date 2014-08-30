/*
 * Author: commy2
 *
 * Get the available firing modes of a weapon. Will ignore the ai helper modes.
 * 
 * Argument:
 * 0: A weapon in cfgWeapons (String)
 * 
 * Return value:
 * All firing modes (Array)
 */

private ["_weapon", "_modes"];

_weapon = _this select 0;

_modes = [];
{
	if (getNumber (configFile >> "CfgWeapons" >> _weapon >> _x >> "showToPlayer") == 1) then {
		_modes pushBack _x;
	};
	if (_x == "this") then {
		_modes pushBack _weapon;
	};
} forEach getArray (configfile >> "CfgWeapons" >> _weapon >> "modes");
_modes
