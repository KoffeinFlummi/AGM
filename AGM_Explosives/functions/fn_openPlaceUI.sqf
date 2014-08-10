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
_actions = [];
{
	_action = [format [getText(_x >> "displayName") + " (%1)", _itemCount select _foreachIndex], {[_this select 5] call AGM_Explosives_fnc_openTriggerSelectionUI;}, {true}, _foreachIndex, getText(_x >> "picture"), configName _x];
	_actions set [count _actions, _action];
} foreach _list;

[_actions, {"AGM_Explosives" call AGM_Interaction_fnc_openMenuSelf;}] call AGM_Interaction_fnc_openSelectMenu;