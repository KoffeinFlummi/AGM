/*
	Name: AGM_Explosives_fnc_selectTrigger
	
	Author: Garth de Wet (LH)
	
	Description:
		Opens the UI for explosive placement selection
	
	Parameters: 
		0: String - Magazine
		1: Number - trigger
	
	Returns:
		Nothing
	
	Example:
		["SatchelCharge_Remote_Mag",0] call AGM_Explosives_fnc_selectTrigger;
*/
private ["_magazine","_trigger"];
closeDialog 0;
_magazine = _this select 0;
_trigger = parseNumber (_this select 1);
if (_trigger == 1) exitWith {
	[_magazine] call AGM_Explosives_fnc_openTimerSetUI;
};
if (_trigger == 0 or _trigger == 2) exitWith {
	[player, _magazine] call AGM_Explosives_fnc_SetupExplosive;
};