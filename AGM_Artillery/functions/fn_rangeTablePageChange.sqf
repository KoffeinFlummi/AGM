/*
Name: AGM_Artillery_fnc_rangeTablePageChange

Author: Pabst Mirror

Description:
  Updates the rangeTable when the 'charge' number is changed

Parameters:
  NONE

Returns:
  NONE

Example:
  Called from "onLBSelChanged" in gui_rangeTable.hpp
*/

#define RANGE_TABLE       ((uiNamespace getVariable "AGM_Artillery_RangeTable_Dialog_display") displayCtrl 20001)
#define LIST_CHARGE       ((uiNamespace getVariable "AGM_Artillery_RangeTable_Dialog_display") displayCtrl 1501)

_listBoxData = LIST_CHARGE lbData (lbCurSel LIST_CHARGE);
if (isNil "_listBoxData" || {_listBoxData == ""}) exitWith {systemChat "Error: lbCurSel out of bounds or no data";};
_muzzleVelocity = parseNumber _listBoxData;

_precalcArray = [_muzzleVelocity, AGM_Artillery_rangeTable_airFriction] call AGM_Artillery_fnc_rangeTablePreCalculatedValues;

lnbClear RANGE_TABLE;
{
  RANGE_TABLE lnbAddRow _x;
} forEach _precalcArray;

//put dummy line at end because scrolling is fucked and can't see last line
RANGE_TABLE lnbAddRow ["", "", "", "", "", "", "", "", "", "", ""];
