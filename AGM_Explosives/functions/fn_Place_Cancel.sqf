/*
	Name: AGM_Explosives_fnc_Place_Cancel
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
	
	Parameters:
		Nothing
	
	Returns:
		Nothing
	
	Example:
		call AGM_Explosives_fnc_Place_Cancel;
*/
["AGM_Explosives_Placement","OnEachFrame"] call BIS_fnc_removeStackedEventHandler;
deleteVehicle AGM_Explosives_Setup;
AGM_Explosives_Setup = objNull;