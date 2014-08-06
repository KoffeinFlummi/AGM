/*
	Name: AGM_Explosives_fnc_selectTrigger
	
	Author: Garth de Wet (LH)
	
	Description:
		Selects a trigger for an explosive.
	
	Parameters: 
		0: String - Magazine
		1: Number - trigger index in AGM_triggers of magazine class
	
	Returns:
		Nothing
	
	Example:
		["SatchelCharge_Remote_Mag",0] call AGM_Explosives_fnc_selectTrigger;
*/
private ["_magazine","_trigger"];
closeDialog 0;
_magazine = _this select 0;
_trigger = _this select 1;
_config = ConfigFile >> "CfgAGM_Triggers" >> _trigger;

// If the onSetup function returns true, it is handled elsewhere
if (isText(_config >> "onSetup") && {[_magazine] call compile getText (_config >> "onSetup")}) exitWith {};

[player, _magazine, _config] call AGM_Explosives_fnc_SetupExplosive;