/*
 * Author: commy2
 *
 * Add an AGM action to an object. Note: This function is global.
 * 
 * Argument:
 * 0: Object the action should be assigned to (Object)
 * 1: Name of the action shown in the menu (String)
 * 2: Distance the player can be away from the object (Number)
 * 3: Condition (Code or String)
 * 4: Statement (Code or String)
 * 5: Show the action even if the conditon is not met (Bool or Number)
 * 6: Priority (Number, optional default: 0)
 * 
 * Return value:
 * ID of the action (used to remove it later).
 */

private ["_object", "_displayName", "_distance", "_condition", "_statement", "_showDisabled", "_priority", "_actionsVar", "_id", "_actionIDs", "_actions"];

_object = [_this, 0, objNull, objNull] call BIS_fnc_param;
_displayName = [_this, 1, "", ""] call BIS_fnc_param;
_distance = [_this, 2, 0, 0] call BIS_fnc_param;
_condition = [_this, 3, "", ""] call BIS_fnc_param;
_statement = [_this, 4, "", ""] call BIS_fnc_param;
_showDisabled = [_this, 5, 0, 0] call BIS_fnc_param;
_priority = [_this, 6, 0, 0] call BIS_fnc_param;

_condition = compile _condition;
_statement = compile _statement;
_showDisabled = _showDisabled > 0;

_actionsVar = _object getVariable ["AGM_Interactions", [-1, [], []]];

_id = (_actionsVar select 0) + 1;
_actionIDs = _actionsVar select 1;
_actions = _actionsVar select 2;

_actionIDs pushBack _id;
_actions pushBack [_displayName, _distance, _condition, _statement, _showDisabled, _priority];

_object setVariable ["AGM_Interactions", [_id, _actionIDs, _actions], true];
_id
