/*
Name: AGM_InventoryInteraction_fnc_openItemInfoBox

Author: Pabst Mirror

Description:
Opens the item info box

Parameters:
0: CONFIG - item's full path (could be CfgMagazines or CfgWeapons)
1: ARRAY - position of mouse
2: NUMBER - IDC

Returns:
NONE

Example:
internal use
*/
#include "\AGM_InventoryInteraction\scriptDefines.sqf"
#define FACTOR_POUND_TO_KILOGRAMM 1/2.2046

private ["_pathToItemConfig", "_mousePos", "_idc", "_classname", "_player", "_mass", "_index", "_displayName", "_condition", "_statement", "_closeInventory", "_classnameActions", "_actionPath", "_parents", "_variableName", "_actionsVar", "_shownActions", "_height", "_positionY", "_itemInfoBoxPos"];

_pathToItemConfig = _this select 0;
_mousePos = _this select 1;
_idc = _this select 2;

_classname = configName _pathToItemConfig;
_player = call AGM_Core_fnc_player;

//Set classname text [1st row] (just classname for now, (as mission maker I kinda like))
(DISPLAY_INVENTORY displayCtrl IDC_ACTION_HEADERTEXT) ctrlSetText format ["%1", _classname];

//Set mass text [2nd row]
_mass = switch (true) do {
case (isNumber (_pathToItemConfig >> "mass")): {getNumber (_pathToItemConfig >> "mass")};
case (isNumber (_pathToItemConfig >> "ItemInfo" >> "mass")): {getNumber (_pathToItemConfig >> "ItemInfo" >> "mass")};
case (isNumber (_pathToItemConfig >> "WeaponSlotsInfo" >> "mass")): {getNumber (_pathToItemConfig >> "WeaponSlotsInfo" >> "mass")};
  default {-1};
};
if (profileNamespace getVariable ["AGM_useImperial", false]) then {  //Freedom units setting from AGM_movement (optional)
  _mass = format ["%1lb", (round (_mass * 10)) / 100];
} else {
  _mass = format ["%1kg", (round (_mass * FACTOR_POUND_TO_KILOGRAMM * 10)) / 100];
};
(DISPLAY_INVENTORY displayCtrl IDC_ACTION_MASSTEXT) ctrlSetText format ["%1 %2", (localize "STR_AGM_InventoryInteraction_Mass"), _mass];

//remove old actions, won't be seen, but could possibly be tabbed to, better to just clean up everytime
for "_index" from 0 to (MAX_ACTIONS - 1) do {
  (DISPLAY_INVENTORY displayCtrl (IDC_ACTION_ACTION_BASE + _index)) ctrlRemoveAllEventHandlers "ButtonClick";
  (DISPLAY_INVENTORY displayCtrl (IDC_ACTION_ACTION_BASE + _index)) ctrlSetText "";
};

//Find actions  - format: [STRING:_displayName, CODE:_condition, CODE:_statement, BOOL:_closeInventory]
_classnameActions = [];

//Add Actions from configFile
for "_index" from 0 to ((count (_pathToItemConfig >> "AGM_InventoryActions")) - 1) do {
  _actionPath = (_pathToItemConfig >> "AGM_InventoryActions") select _index;
  _displayName = getText (_actionPath >> "displayName");
  _condition = getText(_actionPath >> "condition");
  _statement = getText(_actionPath >> "statement");
  _closeInventory = getNumber (_actionPath >> "closeInventory");
  if (_condition == "") then {_condition = "true"};  

  _condition = compile _condition;
  _statement = compile _statement;
  _closeInventory = (_closeInventory == 1);

  _classnameActions pushBack [_displayName, _condition, _statement, _closeInventory];
};

//Adds Custom Actions from AGM_InventoryInteraction_fnc_addItemAction (including parents)
_parents = [_pathToItemConfig, true] call BIS_fnc_returnParents;
{
  _variableName = format ["AGM_InventoryInteractions_Actions_%1", _x];
  _actionsVar = missionNameSpace getVariable [_variableName, [-1, [], []]];
  _classnameActions = _classnameActions + (_actionsVar select 2);
} forEach _parents;

// systemChat format ["debug: %1", _classnameActions];

//Process Actions (test condition, add to menu)
_shownActions = 0;
{
  _displayName = _x select 0;
  _condition = _x select 1;
  _statement = _x select 2;
  _closeInventory = _x select 3;
  if ([_classname, _idc, _player] call _condition) then {
    if (_shownActions >= MAX_ACTIONS) exitWith {["AGM_InventoryActions - Too many actions for %1", _classname] call bis_fnc_error;};
    _statement = format ["[%1, %2, '%3', %4] call AGM_InventoryInteraction_fnc_actionButton;", _statement, _closeInventory, _classname, _idc];
    (DISPLAY_INVENTORY displayCtrl (IDC_ACTION_ACTION_BASE + _shownActions)) ctrlSetText _displayName;
    (DISPLAY_INVENTORY displayCtrl (IDC_ACTION_ACTION_BASE + _shownActions)) ctrlAddEventHandler ["ButtonClick", _statement];
    _shownActions = _shownActions + 1;
  };
} forEach _classnameActions;

//Set Position of controlGroup
_height = 0.7 * (2 + _shownActions);  //Two Header rows + number of actions
_positionY = (_mousePos select 1) min (safeZoneH -  (_height *   ((safeZoneH / 1.2) / 25)));  //if list is too tall, move up to top

_itemInfoBoxPos = [];
_itemInfoBoxPos pushBack (26.6 *   (safeZoneH / 40) + (safezoneX + (safezoneW - safeZoneH)/2));
_itemInfoBoxPos pushBack (_positionY);
_itemInfoBoxPos pushBack (6 *     (safeZoneH / 40));
_itemInfoBoxPos pushBack (_height *   ((safeZoneH / 1.2) / 25));

(DISPLAY_INVENTORY displayCtrl IDC_ACTION_CONTROLGROUP) ctrlSetPosition _itemInfoBoxPos;
(DISPLAY_INVENTORY displayCtrl IDC_ACTION_CONTROLGROUP) ctrlCommit TIME_COMMIT;
