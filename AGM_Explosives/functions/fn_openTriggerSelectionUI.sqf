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
private ["_magazine", "_index","_triggerTypes", "_listIDC"];
_magazine = _this select 0;
closeDialog 0;

_listIDC = [localize "STR_AGM_Explosives_TriggerMenu", localize "STR_AGM_Explosives_SelectTrigger", format["['%1',lbData [8866, lbCurSel 8866]] call AGM_Explosives_fnc_selectTrigger;", _magazine]] call AGM_Interaction_fnc_openSelectMenu;

_triggerTypes = [_magazine] call AGM_Explosives_fnc_TriggerType;
{
	_index = lbAdd [_listIDC, getText(_x >> "displayName")];
	lbSetData [_listIDC, _index, configName _x];
	lbSetPicture [_listIDC, _index, getText(_x >> "picture")];
} count _triggerTypes;

lbSetCurSel [_listIDC, 0];