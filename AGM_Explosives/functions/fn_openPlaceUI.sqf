/*
	Name: AGM_Explosives_fnc_openPlaceUI
	
	Author: Garth de Wet (LH)
	
	Description:
		Opens the UI for explosive placement selection
	
	Parameters: 
		0: OBJECT - unit
	
	Returns:
		Nothing
	
	Example:
		[player] call AGM_Explosives_fnc_openPlaceUI;
*/
private ["_unit","_mags", "_item", "_index"];
_unit = _this select 0;

createDialog "RscAGM_SelectAnItem";

buttonSetAction [8860, "[player, lbData [8866, lbCurSel 8866]] call AGM_Explosives_fnc_SetupExplosive;closeDialog 0;"];
lbClear 8866;
_mags = magazines _unit;
{
	_item = ConfigFile >> "CfgMagazines" >> _x;
	if (getNumber(_item >> "AGM_Placeable") == 1) then {
		_index = lbAdd [8866, getText(_item >> "displayName")];
		lbSetData [8866, _index, _x];
		lbSetPicture [8866, _index, getText(_item >> "picture")];
	};
} count _mags;