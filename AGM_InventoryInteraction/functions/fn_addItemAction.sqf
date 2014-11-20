/*
Name: AGM_InventoryInteraction_fnc_addItemAction

Author: Pabst Mirror

Description:
  Adds an action to a classname that can be used in the inventory.  An item will use all of it's parents's actions.

Parameters:
  0: STRING - classname of item/weapon/magazine
  1: STRING - Display Name to be shown in the menu
  2: STRING or CODE - Condition
  3: STRING or CODE - Statement
  4: BOOL or NUMBER (Optional) - Close the inventory dialog before processing action
  
Returns:
  NONE

Note:
  Both condition and statement are passed _this = [_classname, _idc, _player, _vehicle]
  
Example:
  ["ItemMap", "Open Map", {"ItemMap" in (assignedItems _player)}, {openMap true}, true] call AGM_InventoryInteraction_fnc_addItemAction;
  ["ItemRadio", "Show Radio Info", {!isNil "TFAR_fnc_ShowRadioInfo"}, {[_classname, false] call TFAR_fnc_ShowRadioInfo;}, false] call AGM_InventoryInteraction_fnc_addItemAction;
  ["TFAR_Bag_Base", "Show Radio Info", {(_idc == 6191) && (!isNil "TFAR_fnc_ShowRadioInfo")}, {[[(unitBackpack _player), "radio_settings"], true] call TFAR_fnc_ShowRadioInfo;}, false] call AGM_InventoryInteraction_fnc_addItemAction;
  ["G_Shades_Black", "Deal With It", {true}, {_player unassignItem (goggles _player); _player assignItem _classname;}, false] call AGM_InventoryInteraction_fnc_addItemAction;
*/
#include "\AGM_InventoryInteraction\scriptDefines.sqf"

private ["_classname", "_displayName", "_condition", "_statement", "_closeInventory", "_variableName", "_actionsVar", "_actionIDs", "_actions"];

_classname = [_this, 0, "", [""]] call bis_fnc_param;
_displayName = [_this, 1, "", [""]] call bis_fnc_param;
_condition = [_this, 2, {false}, ["", {}]] call bis_fnc_param;
_statement = [_this, 3, {false}, ["", {}]] call bis_fnc_param;
_closeInventory = [_this, 4, false, [false, 0]] call bis_fnc_param;

if (typeName _condition == "STRING") then {
  _condition = compile _condition;
};

if (typeName _statement == "STRING") then {
  _statement = compile _statement;
};

if (typeName _closeInventory == "SCALAR") then {
  _closeInventory = (_closeInventory == 1)
};

_variableName = format ["AGM_InventoryInteractions_Actions_%1", _classname];
_actionsVar = missionNameSpace getVariable [_variableName, [-1, [], []]];

_id = (_actionsVar select 0) + 1;
_actionIDs = _actionsVar select 1;
_actions = _actionsVar select 2;

_actionIDs pushBack _id;
_actions pushBack [_displayName, _condition, _statement, _closeInventory];

missionNameSpace setVariable [_variableName, [_id, _actionIDs, _actions]];

_id
