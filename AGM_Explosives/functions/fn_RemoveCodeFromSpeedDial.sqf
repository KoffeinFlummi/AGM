/*
	Name: AGM_Explosives_fnc_RemoveCodeFromSpeedDial
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Removes an explosive code from the speed dial of the player.
	
	Parameters:
		STRING - Name of speed dial
	
	Returns:
		Nothing
	
	Example:
		"explosive 1" call AGM_Explosives_fnc_RemoveCodeFromSpeedDial;
*/
if (isNil "AGM_Explosives_Phone_SpeedDial") exitWith{};
{
	if ((_x select 0) == _this) exitWith {
		AGM_Explosives_Phone_SpeedDial set [_foreachIndex, "x"];
		AGM_Explosives_Phone_SpeedDial = AGM_Explosives_Phone_SpeedDial - ["x"];
	};
} foreach AGM_Explosives_Phone_SpeedDial;