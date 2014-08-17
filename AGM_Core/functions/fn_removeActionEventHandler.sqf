/*
 * Author: commy2
 *
 * Remove an addAction event from a unit.
 *
 * Argument:
 * 0: Unit the action is assigned to (Object)
 * 1: Name of the action, e.g. "DefaultAction" (String)
 * 1: ID of the action (Number)
 *
 * Return value:
 * None.
 */

private ["_unit", "_action", "_id", "_name", "_actionsVar", "_actionID", "_actions", "_count"];

_unit = _this select 0;
_action = _this select 1;
_id = _this select 2;
if (_id == -1) exitWith{};

_name = format ["AGM_Action_%1", _action];

_actionsVar = _unit getVariable [_name, [-1, []]];		// AGM_Action_DefaultAction => [ID, [action1, action2, ...]]

_actionID = _actionsVar select 0;
_actions = _actionsVar select 1;

if (_id >= count _actions) exitWith {};

_actions set [_id, [{false}, {}]];

_count = 0;
if ({_count = _count + 1; _x isEqualTo [{false}, {}]} count _actions == _count) then {
	_unit removeAction _actionID;
	_actionID = -1;
};

_unit setVariable [_name, [_actionID, _actions], false];
