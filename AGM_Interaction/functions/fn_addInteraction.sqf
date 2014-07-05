/*
 * Author: commy2
 *
 * Add an AGM action to an object. Note: This function is global.
 * 
 * Argument:
 * 0: Object the action should be assigned to (Object)
 * 1: Name of the action shown in the menu (String)
 * 2: Distance the player can be away from the object (String)
 * 3: Condition (Code or String)
 * 4: Statement (Code or String)
 * 5: Show the action even if the conditon is not met (Bool or Number)
 * 6: Priority (Number, optional default: 0)
 * 
 * Return value:
 * ID of the action (used to remove it later).
 */

private ["_object", "_displayName", "_distance", "_condition", "_statement", "_showDisabled", "_priority", "_actions", "_id"];

_object = _this select 0;
_displayName = _this select 1;
_distance = _this select 2;
_condition = _this select 3;
_statement = _this select 4;
_showDisabled = _this select 5;
_priority = _this select 6;

if (typeName _condition == "STRING") then {
	_condition = compile _condition;
};

if (typeName _statement == "STRING") then {
	_statement = compile _statement;
};

if (typeName _showDisabled == "SCALAR") then {
	_showDisabled = _showDisabled > 0;
};

if (isNil "_priority") then {
	_priority = 0;
};

_actions = _object getVariable ["AGM_Interactions", []];

_id = count _actions;
_actions set [_id, [_displayName, _distance, _condition, _statement, _showDisabled, _priority]];

_object setVariable ["AGM_Interactions", _actions, true];
_id
