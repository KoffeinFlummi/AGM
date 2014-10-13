/*
 * Author: jodav
 *
 * Checks if a unit is a player / curator controlled unit.
 *
 * Arguments:
 * 0: unit to be checked (object)
 *
 * Return Value:
 * Bool: is unit a player?
 */

private "_unit";
_unit = _this select 0;

(isPlayer _unit) || (cameraOn == vehicle (call AGM_Core_fnc_player))
