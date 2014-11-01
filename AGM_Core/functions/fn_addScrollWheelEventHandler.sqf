/*
 * Author: commy2
 *
 * Add an event handler that executes every time the scroll wheel is used. This is needed, because adding a MouseZ display event handler to display 46 will break in save games. Argument will be [Interval] where 'Interval' is a number.
 *
 * Argument:
 * 0: Code to execute (Code or String)
 *
 * Return value:
 * ID of the event script (used to remove it later).
 */

private ["_statement", "_actionsVar", "_id", "_actionIDs", "_actions"];

_statement = _this select 0;

if (typeName _statement == "STRING") then {
  _statement = compile _statement;
};

_actionsVar = missionNamespace getVariable ["AGM_EventHandler_ScrollWheel", [-1, [], []]];

_id = (_actionsVar select 0) + 1;
_actionIDs = _actionsVar select 1;
_actions = _actionsVar select 2;

_actionIDs pushBack _id;
_actions pushBack _statement;

missionNamespace setVariable ["AGM_EventHandler_ScrollWheel", [_id, _actionIDs, _actions]];

_id
