/*
 	Name: AGM_Drag_fnc_Initialise
 	
 	Author(s):
		L-H

 	Description:
		Adds an EventHandler to check if a weapon has been assembled.
	
	Parameters:
		Nothing
 	
 	Returns:
		Nothing
 	
 	Example:
		// Called by ArmA via Function Library
		call AGM_Drag_fnc_Initialise;
*/
player addEventHandler ["WeaponAssembled", {[(_this select 1),true,false] call AGM_Drag_fnc_InitialiseDragable;}];
player addEventHandler ["WeaponDisassembled", {(_this select 0) call AGM_Drag_fnc_releaseObject;}];
player addEventHandler ["Killed", {(_this select 0) call AGM_Drag_fnc_releaseObject;}];
AGM_Drag_ShiftDown = false;
AGM_Drag_CurrentHeightChange = 0;

[] spawn {
	waitUntil {sleep 0.13;!isNull(findDisplay 46)};
	(findDisplay 46) displayAddEventHandler ["MouseZChanged", "(_this select 1) call AGM_Drag_fnc_HandleScrollWheel"];
	(findDisplay 46) displayAddEventHandler ["KeyDown", "if ((_this select 1) == 42) then {AGM_Drag_ShiftDown = true;};"];
	(findDisplay 46) displayAddEventHandler ["KeyUp", "AGM_Drag_ShiftDown = false;"];
};

if (isNil "AGM_Drag_MaxWeight") then {
	AGM_Drag_MaxWeight = 800;
};