/*
Name: AGM_MagazineRepack_fnc_selectFromInventory

Author: PabstMirror

Description:
  Starts repacking from a magazine selected in inventory.

Parameters:
  0: STRING - classname of magazine
  
Returns:
  NONE
*/

private ["_classname", "_magRepackArray", "_index"];

_classname = _this select 0;
_magRepackArray = [false] call AGM_MagazineRepack_fnc_magazineRepack;
_index = (_magRepackArray select 0) find _classname;
if (_index < 0) exitWith {
  ["AGM_MagazineRepack_fnc_selectFromInventory: bad classname - %1", _classname] call BIS_fnc_error;
};
[((_magRepackArray select 0) select _index), ((_magRepackArray select 1) select _index)] call AGM_MagazineRepack_fnc_startPackingProgressBar;
