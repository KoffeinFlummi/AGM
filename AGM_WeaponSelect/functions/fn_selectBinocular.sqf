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

private "_binocular";

_binocular = [player] call AGM_Core_fnc_getBinocular;
[_binocular] call AGM_WeaponSelect_fnc_selectWeaponMode;
