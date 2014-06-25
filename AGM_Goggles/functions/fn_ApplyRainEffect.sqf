/*
	Name: AGM_Goggles_fnc_ApplyRainEffect
	
	Author: Garth de Wet (LH)
	
	Description:
	Sets screen tint for glasses.
	Sets screen overlay for glasses. (broken/fixed)
	Sets dirt/rain overlay for glasses.
	
	Parameters: 
	0: ARRAY
		0: BOOL - Whether to set the rain effect or not
		1: NUMBER - The rain drop texture to use.
	
	Returns:
	Nothing
	
	Example:
	[true, 2] call AGM_Goggles_fnc_ApplyRainEffect;
*/
#define IMAGEPATH "AGM_Goggles\textures\fx\rain\%1.paa"

if !(_this select 0) exitWith{false};
if (cameraOn == player) then {
	if (isNull(uiNamespace getVariable ["AGM_Goggles_DisplayEffects", displayNull])) then {
		100 cutRsc["RscAGM_GogglesEffects", "PLAIN",0, false];
	};
	(uiNamespace getVariable ["AGM_Goggles_DisplayEffects", displayNull] displayCtrl 10661) ctrlSetText format[IMAGEPATH, _this select 1];
};