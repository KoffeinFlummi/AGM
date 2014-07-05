/*
 * Author: commy2
 *
 * Remove an AGM action from an object. Note: This function is global.
 * 
 * Argument:
 * 0: Object (Object)
 * 1: ID of the action (Number)
 * 
 * Return value:
 * None.
 */

private ["_object", "_id", "_actions"];

_object = _this select 0;
_id = _this select 1;

_actions = _object getVariable ["AGM_Interactions", []];

if (_id > count _actions - 1) exitWith {};

_actions set [_id, ["", 0, {false}, {}, false, 0]];

_object setVariable ["AGM_Interactions", _actions, true];
