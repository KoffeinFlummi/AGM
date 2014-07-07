/*
	Name: AGM_Goggles_fnc_ExternalCamera
	
	Author: Garth de Wet (LH)
	
	Description:
	Returns if the camera is external or not.
	
	Parameters: 
	Nothing
	
	Returns:
	Boolean - whether the camera is in external view or not.
	
	Example:
	call AGM_Goggles_fnc_ExternalCamera;
*/
if (["AGM_Goggles", "showInThirdPerson"] call AGM_Core_fnc_getOption) exitWith { false };
(cameraView == "External")