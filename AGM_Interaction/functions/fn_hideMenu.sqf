/*
	Name: AGM_Interaction_fnc_hideMenu
	
	Author: Garth de Wet (LH)
	
	Description:
		Closes the Interaction menu
	
	Parameters: 
		Nothing
	
	Returns:
		Nothing
	
	Example:
		call AGM_Interaction_fnc_hideMenu;
*/
closeDialog 0;
(findDisplay 1713999) closeDisplay 1;
(uiNameSpace getVariable "Interaction_Display") closeDisplay 0;
AGM_Interaction_MainButton = nil;
showHUD true;
AGM_Interaction_Buttons = nil;