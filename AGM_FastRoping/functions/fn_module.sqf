/*
	Name: AGM_FastRoping_fnc_module

	Author: Matthew Graham (JonBons)

	Description:
		Initialises the restrictions for the fast roping module

	Parameters:
		Things

	Returns:
		Nothing

	Example:

*/
if !(isServer) exitWith {};
_logic = _this select 0;
_activated = _this select 2;

if !(_activated) exitWith {};

[_logic, "AGM_FastRoping_RequireCrew",         "RequireCrew"           ] call AGM_Core_fnc_readBooleanParameterFromModule;


diag_log text "[AGM]: Fast Roping Module Initialized.";
