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

_unit addAction [localize "STR_AGM_Explosives_AttachTo", "cursorTarget call AGM_Explosives_fnc_Place_AttachTo;", nil, 22, false, true, "","AGM_Explosives_pfeh_running AND {!isNull(AGM_Explosives_Setup) AND (cursorTarget isKindOf 'Car') AND (cursorTarget distance AGM_Explosives_Setup) < 2.5}"];
_unit addAction [localize "STR_AGM_Explosives_PlaceAction", "[] spawn AGM_Explosives_fnc_Place_Approve;", nil, 21, false, true, "","AGM_Explosives_pfeh_running AND {!isNull(AGM_Explosives_Setup)}"];
_unit addAction [localize "STR_AGM_Explosives_CancelAction", "call AGM_Explosives_fnc_Place_Cancel;", nil, 20, false, true, "","AGM_Explosives_pfeh_running AND {!isNull(AGM_Explosives_Setup)}"];

_unit SetVariable ["AGM_Clacker", [], true];