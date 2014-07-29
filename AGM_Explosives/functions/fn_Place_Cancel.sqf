/*
	Name: AGM_Explosives_fnc_Place_Cancel
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Cancels placement of the explosive
	
	Parameters:
		Nothing
	
	Returns:
		Nothing
	
	Example:
		call AGM_Explosives_fnc_Place_Cancel;
*/
if (AGM_Explosives_pfeh_running) then {
	["AGM_Explosives_Placement","OnEachFrame"] call BIS_fnc_removeStackedEventHandler;
	AGM_Explosives_pfeh_running = false;
};
if (!isNull (AGM_Explosives_Setup)) then {
	deleteVehicle AGM_Explosives_Setup;
};
AGM_Explosives_Setup = objNull;