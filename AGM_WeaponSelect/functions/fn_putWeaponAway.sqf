/*
 * Author: commy2
 *
 * The unit will put its current weapon away.
 * 
 * Argument:
 * 0: What unit should put the current weapon on back? (Object)
 * 
 * Return value:
 * None.
 */

private "_vehicle";

_vehicle = vehicle player;

if (currentWeapon player != "" && {currentWeapon player == primaryWeapon player} && {weaponLowered player} && {stance player == "STAND"}) then {
	player playMove "amovpercmstpsraswrfldnon";
};

player action ["SwitchWeapon", _vehicle, _vehicle, 99];
