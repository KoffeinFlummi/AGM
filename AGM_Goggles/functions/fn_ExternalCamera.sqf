/*
	Name: AGM_Goggles_fnc_ExternalCamera
	
	Author: Garth de Wet (LH), Sniperwolf572
	
	Description:
	Returns if the camera is external or not.
	
	Parameters: 
	Nothing
	
	Returns:
	Boolean - whether the camera is in external view or not.
	
	Example:
	call AGM_Goggles_fnc_ExternalCamera;
*/
if (profileNamespace getVariable ["AGM_showInThirdPerson", false]) exitWith { false };
(cameraView == "EXTERNAL" || cameraView == "GROUP")