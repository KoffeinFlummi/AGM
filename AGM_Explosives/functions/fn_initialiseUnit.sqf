/*
	Name: AGM_Explosives_fnc_initialiseUnit
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Initialises a unit for explosive usage.
	
	Parameters:
		0: Object - Unit
	
	Returns:
		None
	
	Example:
		[player] call AGM_Explosives_fnc_initialiseUnit;
*/
private "_unit";
_unit = _this select 0;
//_unit SetVariable ["AGM_Clacker", [], true];