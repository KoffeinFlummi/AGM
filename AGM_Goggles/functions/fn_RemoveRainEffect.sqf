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
#include "\AGM_Goggles\script.sqf"

AGM_Goggles_Effects set [LRAIN, [false, 0, time]];
if (!isNull(uiNamespace getVariable ["AGM_Goggles_DisplayEffects", displayNull])) then {
	(uiNamespace getVariable ["AGM_Goggles_DisplayEffects", displayNull] displayCtrl 10661) ctrlSetText "";
};
