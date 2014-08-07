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
// Simple method while there isn't any other detonators.
_hasClacker = false;
{
	if (getNumber (ConfigFile >> "CfgWeapons" >> _x >> "AGM_Detonator") == 1) exitWith {
		_hasClacker = true;
	};
} count (items player);

_listIDC = [localize "STR_AGM_Explosives_TriggerMenu", localize "STR_AGM_Explosives_SelectTrigger", format["['%1',lbData [8866, lbCurSel 8866]] call AGM_Explosives_fnc_selectTrigger;", _magazine], "closeDialog 0;[player] call AGM_Explosives_fnc_openPlaceUI;"] call AGM_Interaction_fnc_openSelectMenu;

_triggerTypes = [_magazine] call AGM_Explosives_fnc_TriggerType;
_mag = ConfigFile >> "CfgMagazines" >> _magazine >> "AGM_Triggers";
{
	if (configName _x == "Command" && !_hasClacker) then {
	} else {
		_index = lbAdd [_listIDC, if(isText(_mag >> configName _x >> "displayName"))then{getText(_mag >> configName _x >> "displayName")}else{getText(_x >> "displayName")}];
		lbSetData [_listIDC, _index, configName _x];
		lbSetPicture [_listIDC, _index, if(isText(_mag >> configName _x >> "picture"))then{getText(_mag >> configName _x >> "picture")}else{getText(_x >> "picture")}];
	};
} count _triggerTypes;

lbSetCurSel [_listIDC, 0];

if (lbSize _listIDC == 0) then {
	closeDialog 0;
	[player] call AGM_Explosives_fnc_openPlaceUI;
	[format[localize "STR_AGM_Explosives_NoTriggersAvailable", getText(configFile >> "CfgMagazines" >> _magazine >> "DisplayName")]] call AGM_Core_fnc_displayTextStructured;
};