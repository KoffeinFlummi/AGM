/*
  Name: AGM_InventoryInteraction_fnc_actionButton
  
  Author: Pabst Mirror
  
  Description:
    Handles clicking on an action from the info pane
  
  Parameters:
    0: CODE - statement
    1: BOOL - close inventory display before running code
    2: STRING - classname
    3: NUMBER - IDC 
    
  Returns:
    NONE
  
  Example:
    internal use
*/
#include "\AGM_InventoryInteraction\scriptDefines.sqf"

[] call AGM_InventoryInteraction_fnc_closeItemInfoBox;
_this spawn {
  private ["_statement", "_closeInventory", "_classname", "_idc", "_player"];
  
  _statement = _this select 0;
  _closeInventory = _this select 1;
  _classname = _this select 2;
  _idc = _this select 3;

  if (_closeInventory) then {
    DISPLAY_INVENTORY closeDisplay 1;
    waitUntil {isNull DISPLAY_INVENTORY};
  };
  
  _player = call AGM_Core_fnc_player;
  [_classname, _idc, _player] call _statement;
};

