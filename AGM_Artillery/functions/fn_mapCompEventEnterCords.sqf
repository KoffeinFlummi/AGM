/*
Name: AGM_Artillery_fnc_mapCompEventEnterCords

Author: Pabst Mirror

Description:
  Loads the entered cords, gets their position, and computes a firing solution.

Parameters:
  NONE

Returns:
  NONE

Example:
  called from button's "action" in gui_mapComputer.hpp
*/

private ["_mortarVeh", "_cordsText", "_position", "_chargeSelected"];

#define MAP_CORD_EDIT ((uiNamespace getVariable ["AGM_Artillery_MapComputer_Dialog", displayNull]) displayCtrl 233237)
#define MAP_CHARGE_LISTBOX (((uiNamespace getVariable ["AGM_Artillery_MapComputer_Dialog", displayNull])) displayCtrl 233232)

_mortarVeh = vehicle AGM_player;

_cordsText = ctrlText MAP_CORD_EDIT;
_position = [_cordsText] call AGM_Artillery_fnc_getPosFromMapCords;

_chargeSelected = lbCurSel MAP_CHARGE_LISTBOX;
if (_chargeSelected < 0) exitWith {systemChat "Error: No Charge Selected";};

[_mortarVeh, true, (currentMagazine _mortarVeh), _chargeSelected, _position] spawn AGM_Artillery_fnc_createFiringSolution;
