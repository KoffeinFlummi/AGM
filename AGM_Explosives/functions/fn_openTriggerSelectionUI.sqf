/*
	Name: AGM_Explosives_fnc_openTriggerSelectionUI
	
	Author: Garth de Wet (LH)
	
	Description:
		Opens the UI for explosive trigger selection
	
	Parameters: 
		0: String - explosive magazine
	
	Returns:
		Nothing
	
	Example:
		[lbData [8866, lbCurSel 8866]] call AGM_Explosives_fnc_openTriggerSelectionUI;
*/
private ["_magazine", "_index","_triggerTypes", "_item", "_listIDC"];
_magazine = _this select 0;
closeDialog 0;

_listIDC = [localize "STR_AGM_Explosives_TriggerMenu", localize "STR_AGM_Explosives_SelectTrigger", format["['%1',lbData [8866, lbCurSel 8866]] call AGM_Explosives_fnc_selectTrigger;", _magazine]] call AGM_Interaction_fnc_openSelectMenu;

_triggerTypes = [_magazine] call AGM_Explosives_fnc_TriggerType;

// clacker enabled
if (_triggerTypes select 0 && {"AGM_Clacker" in (items player)}) then {
	_item = ConfigFile >> "CfgWeapons" >> "AGM_Clacker";
	_index = lbAdd [_listIDC, getText(_item >> "DisplayName")];
	lbSetData [_listIDC, _index, "0"];
	lbSetPicture [_listIDC, _index, getText(_item >> "picture")];
};
// timer
if (_triggerTypes select 1) then {
	_index = lbAdd [_listIDC, localize "STR_AGM_Explosives_timerName"];
	lbSetData [_listIDC, _index, "1"];
	lbSetPicture [_listIDC, _index, "AGM_Explosives\data\UI\Timer.paa"];
};
// Cellphone enabled
if (_triggerTypes select 2) then {
	_item = ConfigFile >> "CfgWeapons" >> "AGM_Cellphone";
	_index = lbAdd [_listIDC, getText(_item >> "DisplayName")];
	lbSetData [_listIDC, _index, "2"];
	lbSetPicture [_listIDC, _index, getText(_item >> "picture")];
};

lbSetCurSel [_listIDC, 0];