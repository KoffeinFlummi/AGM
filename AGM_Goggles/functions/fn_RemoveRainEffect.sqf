/*
	Name: AGM_Goggles_fnc_RemoveRainEffect
	
	Author: Garth de Wet (LH)
	
	Description:
	Removes rain effects from the screen. Resets the rain array.
	
	Parameters: 
	Nothing
	
	Returns:
	Nothing
	
	Example:
	call AGM_Goggles_fnc_RemoveRainEffect;
*/
if (isNil {AGM_Goggles_RainDrops}) exitWith {};
{
	(_x select 0) ctrlShow false;
	_x set [1, false];
} count AGM_Goggles_RainDrops;