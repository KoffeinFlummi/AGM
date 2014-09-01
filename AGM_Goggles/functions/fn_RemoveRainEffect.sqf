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
for "_i" from 0 to (count AGM_Goggles_RainDrops) do {
	((AGM_Goggles_RainDrops select _i) select 0) ctrlShow false;
};