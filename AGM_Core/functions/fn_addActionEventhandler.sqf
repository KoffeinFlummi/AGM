/*
 * Author: commy2
 *
 * Add an addAction event to a unit. Used to handle multiple addAction events. Global arguments, local effects. Does only work for player controlled units.
 *
 * Argument:
 * 0: Unit the action should be assigned to (Object)
 * 1: Name of the action, e.g. "DefaultAction" (String)
 * 2: Condition (Code or String)
 * 3: Code to execute (Code or String)
 *
 * Return value:
 * ID of the action (used to remove it later).
 */

private ["_unit", "_action", "_condition", "_statement", "_name", "_actionsVar", "_actionID", "_actions", "_id", "_addAction"];

_unit = _this select 0;
_action = _this select 1;
_condition = _this select 2;
_statement = _this select 3;

if (typeName _statement == "STRING") then {
	_statement = compile _statement;
};

_name = format ["AGM_Action_%1", _action];

_actionsVar = _unit getVariable [_name, [-1, []]];		// AGM_Action_DefaultAction => [ID, [action1, action2, ...]]

_actionID = _actionsVar select 0;
_actions = _actionsVar select 1;

_id = count _actions;
_actions set [_id, [_condition, _statement]];

// first action to add, unit needs addAction command
if (_actionID == -1) then {
	_addAction = compile format [
		"[
			'',
			{{if (call (_x select 0)) then {_this call (_x select 1)}} forEach (((_this select 0) getVariable 'AGM_Action_%1') select 1)},
			'',
			0,
			false,
			true,
			%1,
			'_actions = ((_this select 0) getVariable 'AGM_Action_%1') select 1; _count = count _actions; _index = 0; _return = false; while {_index < _count && {!_return}} do {_return = call ((_actions select _index) select 0); _index = _index + 1}; _return'
		]",
		_action
	];

	_actionID = _unit addAction _addAction;
};

_unit setVariable [_name, [_actionID, _actions], false];

_id
