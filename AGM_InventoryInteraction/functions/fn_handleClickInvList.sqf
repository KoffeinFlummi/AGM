/*
Name: AGM_InventoryInteraction_fnc_handleClickInvList

Author: Pabst Mirror

Description:
  Handles mouse button going up inside a listbox

Parameters:
  Mouse Up Event

Returns:
  BOOL - handeled, always false

Example:
  internal use
*/

#include "\AGM_InventoryInteraction\scriptDefines.sqf"

private ["_mouseButton", "_mouseX", "_mouseY"];

_mouseButton = _this select 1;
_mouseX = _this select 2;
_mouseY = _this select 3;

if (_mouseButton == 1) then {  //Right clicks will close menu
  [] call AGM_InventoryInteraction_fnc_closeItemInfoBox;
} else {
  AGM_InventoryInteraction_mouseUpEvent = [diag_tickTime, (_this select 2), (_this select 3)];
};

false
