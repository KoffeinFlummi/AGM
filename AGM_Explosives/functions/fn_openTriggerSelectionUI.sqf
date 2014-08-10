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
// Simple method while there isn't any other detonators.
_hasClacker = false;
{
	if (getNumber (ConfigFile >> "CfgWeapons" >> _x >> "AGM_Detonator") == 1) exitWith {
		_hasClacker = true;
	};
} count (items player);

_triggerTypes = [_magazine] call AGM_Explosives_fnc_TriggerType;
_mag = ConfigFile >> "CfgMagazines" >> _magazine >> "AGM_Triggers";
_actions = [];
{
	if (configName _x == "Command" && !_hasClacker) then {
	} else {
		_action = [if(isText(_mag >> configName _x >> "displayName"))then{getText(_mag >> configName _x >> "displayName")}else{getText(_x >> "displayName")}, {[_this select 6, _this select 5] call AGM_Explosives_fnc_selectTrigger;}, {true}, 0, if(isText(_mag >> configName _x >> "picture"))then{getText(_mag >> configName _x >> "picture")}else{getText(_x >> "picture")}, configName _x, _magazine];
		_actions set [count _actions, _action];
	};
} count _triggerTypes;

if (count _actions == 0) then {
	[player] call AGM_Explosives_fnc_openPlaceUI;
	[format[localize "STR_AGM_Explosives_NoTriggersAvailable", getText(configFile >> "CfgMagazines" >> _magazine >> "DisplayName")]] call AGM_Core_fnc_displayTextStructured;
}else{
	[_actions, {[player] call AGM_Explosives_fnc_openPlaceUI;}] call AGM_Interaction_fnc_openSelectMenu;
};