/*
 * Author: bux578, commy2
 *
 * Checks if a unit is a player / curator controlled unit.
 * Currently returns false for non-local remote controlled zeus units. (Remotes from another zeus machine)
 *
 * Arguments:
 * 0: unit to be checked (object)
 *
 * Return Value:
 * Bool: is unit a player?
 */

isPlayer (_this select 0) || {_this select 0 == call AGM_Core_fnc_player}
