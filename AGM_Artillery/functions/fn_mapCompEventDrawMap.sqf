/*
Name: AGM_Artillery_fnc_mapCompEventDrawMap

Author: Pabst Mirror

Description:
  Draws range circles (from pre-computed range table)

Parameters:
  0: CONTROL - Map computer Map Control

Returns:
  NONE

Example:
  called from "onDraw" in gui_mapComputer.hpp
*/

#define MAP_CHARGE_LISTBOX (((uiNamespace getVariable ["AGM_Artillery_MapComputer_Dialog", displayNull])) displayCtrl 233232)

_theMap = _this select 0;
_mortarVeh = (vehicle AGM_player);

//Draw Self?


//Calculate Target Pos and Draw
_dist = _mortarVeh getVariable ["AGM_Artillery_targetHorziontalDistance", 0];
_az = _mortarVeh getVariable ["AGM_Artillery_targetAzimuth", 0];

_targetPos = [(getPos _mortarVeh), _dist, _az] call BIS_fnc_relPos;

_theMap drawEllipse [_targetPos, 30, 30, 0, [1,0,1,1], ""];
_theMap drawEllipse [_targetPos, 60, 60, 0, [1,0,1,1], ""];


//Draw Min Max Range
_chargeSelected = lbCurSel MAP_CHARGE_LISTBOX;
if (_chargeSelected < 0) exitWith {};
_listBoxData = MAP_CHARGE_LISTBOX lbData (lbCurSel MAP_CHARGE_LISTBOX);
if (isNil "_listBoxData") exitWith {};

_muzzleVelocity = parseNumber _listBoxData;
_airFriction = -0.0001; //todo

_lookUpTableArray = [_muzzleVelocity, _airFriction] call AGM_Artillery_fnc_rangeTablePreCalculatedValues;

if (count _lookUpTableArray < 1) exitWith {};

_minRange = parseNumber ((_lookUpTableArray select 0) select 0);
_maxRange = parseNumber ((_lookUpTableArray select ((count _lookUpTableArray) - 1)) select 0);

_theMap drawEllipse [(getpos _mortarVeh), _minRange, _minRange, 0, [1,0,0,1], ""];
_theMap drawEllipse [(getpos _mortarVeh), _maxRange, _maxRange, 0, [1,0,0,1], ""];
