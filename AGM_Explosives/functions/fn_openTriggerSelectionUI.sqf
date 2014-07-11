/*
	Name: AGM_Explosives_fnc_openTriggerSelectionUI
	
	Author: Garth de Wet (LH)
	
	Description:
		Opens the UI for explosive placement selection
	
	Parameters: 
		0: String - explosive magazine
	
	Returns:
		Nothing
	
	Example:
		[lbData [8866, lbCurSel 8866]] call AGM_Explosives_fnc_openTriggerSelectionUI;
*/
private ["_magazine", "_index","_triggerTypes", "_item"];
_magazine = _this select 0;
closeDialog 0;
createDialog "RscAGM_SelectAnItem";

buttonSetAction [8860, format["['%1',lbData [8866, lbCurSel 8866]] call AGM_Explosives_fnc_selectTrigger;", _magazine]];
_triggerTypes = [_magazine] call AGM_Explosives_fnc_TriggerType;

ctrlSetText [8860, localize "STR_AGM_Explosives_SelectTrigger"];
ctrlSetText [8870, localize "STR_AGM_Explosives_TriggerMenu"];

lbClear 8866;
// clacker enabled
if (_triggerTypes select 0) then {
	_item = ConfigFile >> "CfgWeapons" >> "AGM_Clacker";
	_index = lbAdd [8866, getText(_item >> "DisplayName")];
	lbSetData [8866, _index, "0"];
	lbSetPicture [8866, _index, getText(_item >> "picture")];
};
// timer
if (_triggerTypes select 1) then {
	_index = lbAdd [8866, localize "STR_AGM_Explosives_timerName"];
	lbSetData [8866, _index, "1"];
	lbSetPicture [8866, _index, "AGM_Explosives\data\UI\Timer.paa"];
};
// Cellphone enabled
if (_triggerTypes select 2) then {
	_item = ConfigFile >> "CfgWeapons" >> "AGM_Cellphone";
	_index = lbAdd [8866, getText(_item >> "DisplayName")];
	lbSetData [8866, _index, "2"];
	lbSetPicture [8866, _index, getText(_item >> "picture")];
};

lbSetCurSel [8866, 0];