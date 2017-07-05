/*
Name: AGM_Artillery_fnc_mapCompEventClickOnMap

Author: Pabst Mirror

Description:
  Converts numbers into nicely formated strings.

Parameters:
  0: CONTROL - Map Control
  1: NUMBER  - Mouse Button
  2: NUMBER  - Mouse X pos
  2: NUMBER  - Mouse Y pos

Returns:
  NONE

Example:
  called from "onMouseButtonClick" in gui_mapComputer.hpp
*/

#define MAP_CHARGE_LISTBOX (((uiNamespace getVariable ["AGM_Artillery_MapComputer_Dialog", displayNull])) displayCtrl 233232)

_mapControl = _this select 0;
_button = _this select 1;
_screenX = _this select 2;
_screenY = _this select 3;

_mortarVeh = (vehicle AGM_player);

if (_button != 0) exitWith {};

_position = _mapControl ctrlMapScreenToWorld  [_screenX, _screenY]; 
_position set [2, 0];

_chargeSelected = lbCurSel MAP_CHARGE_LISTBOX;
if (_chargeSelected < 0) exitWith {systemChat "Error: No Charge Selected";};

[_mortarVeh, true, (currentMagazine _mortarVeh), _chargeSelected, _position] spawn AGM_Artillery_fnc_createFiringSolution;
