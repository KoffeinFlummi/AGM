/*
 * Author: commy2
 *
 * The player will select the binocular.
 * 
 * Argument:
 * None.
 * 
 * Return value:
 * None.
 */

_weapons = weapons player - [handgunWeapon player] - [primaryWeapon player] - [secondaryWeapon player];
_binocular = (
	if (count _weapons == 1) then {_weapons select 0} else {""}
);
[_binocular] call AGM_WeaponSelect_fnc_selectWeaponMode;
