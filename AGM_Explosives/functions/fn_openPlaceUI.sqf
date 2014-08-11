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
private ["_unit","_mags", "_item", "_index", "_listIDC"];
_unit = _this select 0;
call AGM_Explosives_fnc_Place_Cancel;

_listIDC = [localize "STR_AGM_Explosives_PlaceMenu", localize "STR_AGM_Explosives_Place", "closeDialog 0;private ['_mag'];_mag=lbData [8866, lbCurSel 8866];[_mag] call AGM_Explosives_fnc_openTriggerSelectionUI;", "closeDialog 0;'AGM_Explosives' call AGM_Interaction_fnc_openMenuSelf;"] call AGM_Interaction_fnc_openSelectMenu;

_mags = magazines _unit;
_list = [];
_itemCount = [];
{
	_item = ConfigFile >> "CfgMagazines" >> _x;
	if (getNumber(_item >> "AGM_Placeable") == 1) then {
		_index = _list find _item;
		if (_index != -1) then {
			_itemCount set [_index, (_itemCount select _index) + 1];
		} else {
			_list set [count _list, _item];
			_itemCount set [count _itemCount, 1];
		};
	};
} count _mags;
{
	_index = lbAdd [_listIDC, format [getText(_x >> "displayName") + " (%1)", _itemCount select _foreachIndex]];
	lbSetData [_listIDC, _index, configName _x];
	lbSetPicture [_listIDC, _index, getText(_x >> "picture")];
} foreach _list;

lbSort ((findDisplay 8854) displayCtrl _listIDC);
lbSetCurSel [_listIDC, 0];