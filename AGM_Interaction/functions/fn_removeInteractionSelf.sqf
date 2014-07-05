/*
 * Author: commy2
 *
 * Remove an AGM self action from the player.
 * 
 * Argument:
 * 0: ID of the action (Number)
 * 
 * Return value:
 * None.
 */

private ["_id", "_actions"];

_id = _this select 0;

_actions = player getVariable ["AGM_InteractionsSelf", []];

if (_id > count _actions - 1) exitWith {};

_actions set [_id, ["", {false}, {}, false, 0]];

player setVariable ["AGM_InteractionsSelf", _actions, false];
