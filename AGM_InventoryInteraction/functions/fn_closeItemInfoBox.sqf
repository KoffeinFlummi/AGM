/*
Name: AGM_InventoryInteraction_fnc_closeItemInfoBox

Author: Pabst Mirror

Description:
  Closes the item info box

Parameters:
  NONE
  
Returns:
  NONE

Example:
  internal use
*/
#include "\AGM_InventoryInteraction\scriptDefines.sqf"

private ["_index", "_itemInfoBoxPos"];

//remove old actions, won't be seen, but could possibly be tabbed to, better to just clean up everytime
for "_index" from 0 to (MAX_ACTIONS - 1) do {
  (DISPLAY_INVENTORY displayCtrl (IDC_ACTION_ACTION_BASE + _index)) ctrlRemoveAllEventHandlers "ButtonClick";
  (DISPLAY_INVENTORY displayCtrl (IDC_ACTION_ACTION_BASE + _index)) ctrlSetText "";
};

_itemInfoBoxPos = ctrlPosition (DISPLAY_INVENTORY displayCtrl IDC_ACTION_CONTROLGROUP);
if ((_itemInfoBoxPos select 2) > 0) then {
  _itemInfoBoxPos set [2, 0];
  _itemInfoBoxPos set [3, 0];
  (DISPLAY_INVENTORY displayCtrl IDC_ACTION_CONTROLGROUP) ctrlSetPosition _itemInfoBoxPos;
  (DISPLAY_INVENTORY displayCtrl IDC_ACTION_CONTROLGROUP) ctrlCommit TIME_COMMIT;
};