/*
	Author: aeroson
	
	Description:
		Crew Info module handler
	
	Parameters: 
		Whatever module provides
	
	Returns:
		Nothing
*/

if !(isServer) exitWith {};

_logic = _this select 0;
_activated = _this select 2;

if !(_activated) exitWith {};

[_logic, "AGM_CrewInfo_Visibility",         "Visibility"           ] call AGM_Core_fnc_readNumericParameterFromModule;

diag_log text "[AGM]: CrewInfo Module Initialized.";