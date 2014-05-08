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

_vehicle = vehicle player;
if (player getVariable ["AGM_Unconscious", false]) exitWith {};

player action ["SwitchWeapon", _vehicle, _vehicle, 99];
