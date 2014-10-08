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

private ["_player", "_binocular"];

_player = _this select 0;

_binocular = [_player] call AGM_Core_fnc_getBinocular;
[_player, _binocular] call AGM_WeaponSelect_fnc_selectWeaponMode;
