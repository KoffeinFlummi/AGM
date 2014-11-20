/*
Name: AGM_InventoryInteraction_fnc_actionButton

Author: Pabst Mirror

Description:
  Handles clicking on an action from the ItemInfoBox

Parameters:
  0: CODE - condition
  1: CODE - statement
  2: BOOL - close inventory display before running code
  3: STRING - classname
  4: NUMBER - IDC

Returns:
  NONE

Example:
  internal use
*/
#include "\AGM_InventoryInteraction\scriptDefines.sqf"

[] call AGM_InventoryInteraction_fnc_closeItemInfoBox;
_this spawn {
  private ["_statement", "_closeInventory", "_classname", "_idc", "_exceptions", "_player", "_vehicle"];

  _condition = _this select 0;
  _statement = _this select 1;
  _closeInventory = _this select 2;
  _classname = _this select 3;
  _idc = _this select 4;

  _player = call AGM_Core_fnc_player;
  _vehicle = vehicle _player;

  if ([_classname, _idc, _player, _vehicle] call _condition) then {

    if (_closeInventory) then {
      DISPLAY_INVENTORY closeDisplay 1;
      waitUntil {isNull DISPLAY_INVENTORY};
    };

    [_classname, _idc, _player, _vehicle] call _statement;
  };
};

