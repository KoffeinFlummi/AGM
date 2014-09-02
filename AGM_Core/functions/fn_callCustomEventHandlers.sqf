/*
 * Author: commy2
 *
 * Execute all custom event script assigned to this object.
 *
 * Argument:
 * 0: Object the event handlers are assigned to (Object)
 * 1: Name of the event (String)
 *
 * Return value:
 * ID of the event script (used to remove it later).
 */

private ["_object", "_type", "_name", "_actions"];

_object = _this select 0;
_type = _this select 1;

_name = format ["AGM_CustomEventHandlers_%1", _type];

_actions = (_object getVariable [_name, [-1, [], []]]) select 2;

{
	[_object] call _x;
} forEach _actions;
