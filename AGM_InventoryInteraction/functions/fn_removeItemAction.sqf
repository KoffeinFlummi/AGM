/*
Name: AGM_InventoryInteraction_fnc_removeItemAction

Author: Pabst Mirror

Description:
  Opens the item info box

Parameters:
  0: STRING - classname of item/weapon/magazine
  1: NUMBER - ID of previously added action
  
Returns:
  NONE

Example:
  ["ItemMap", 5] call AGM_InventoryInteraction_fnc_removeItemAction;
*/
#include "\AGM_InventoryInteraction\scriptDefines.sqf"

private ["_classname", "_variableName", "_actionsVar", "_currentID", "_actionIDs", "_actions"];

_classname = [_this, 0, "", [""]] call bis_fnc_param;
_id = [_this, 1, -1, [0]] call bis_fnc_param;

_variableName = format ["AGM_InventoryInteractions_Actions_%1", _classname];
_actionsVar = missionNameSpace getVariable [_variableName, [-1, [], []]];

_currentID = _actionsVar select 0;
_actionIDs = _actionsVar select 1;
_actions = _actionsVar select 2;

_id = _actionIDs find _id;
if (_id == -1) exitWith {};

_actionIDs deleteAt _id;
_actions deleteAt _id;

missionNameSpace setVariable [_variableName, [_id, _actionIDs, _actions]];
