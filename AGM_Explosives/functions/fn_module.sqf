/*
	Name: AGM_Explosives_fnc_module
	
	Author: Garth de Wet (LH)
	
	Description:
		Initialises the explosives module
	
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
["AGM_Explosives_RequireSpecialist", (_logic getVariable "RequireExplosive")] call AGM_Core_fnc_setParameter;
["AGM_Explosives_PunishNonSpecialists", (_logic getVariable "PunishNonExplosive")] call AGM_Core_fnc_setParameter;

diag_log text "[AGM]: Explosive Module Initialized.";