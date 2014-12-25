/*
Name: AGM_MagazineRepack_fnc_startPackingProgressBar

Author: commy2 (orginaly from openSelectMagazineUI)

Description:
  Starts the progressBar for repacking magazines.

Parameters:
  0: STRING - classname of magazine
  1: NUMBER - time to repack, for progressbar
  
Returns:
  NONE
*/

private ["_data"];

_data = _this;
call AGM_Interaction_fnc_hideMenu;
if (isNil "_data") exitWith {};
_data set [1, [_data select 1] call AGM_Core_fnc_toNumber];
[_data select 1, _data, "AGM_MagazineRepack_fnc_magazineRepackCallback", localize "STR_AGM_MagazineRepack_RepackingMagazine"] call AGM_Core_fnc_progressBar;
[player] call AGM_core_fnc_goKneeling;
