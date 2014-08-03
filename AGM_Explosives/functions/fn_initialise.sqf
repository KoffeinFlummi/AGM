/*
	Name: AGM_Explosives_fnc_Initialise
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Initialises explosive behaviour.
	
	Parameters:
		None
	
	Returns:
		None
	
	Example:
		None
*/
if (isServer) then {
	if (isNil "AGM_Explosives_List") then {
		AGM_Explosives_List = [];
		publicVariable "AGM_Explosives_List";
	};
	/*
		All Jammer code is disabled for now.
	if (isNil "AGM_Explosives_Jammers") then {
		AGM_Explosives_Jammers = [];
		publicVariable "AGM_Explosives_Jammers";
	};
	*/
};
if !(hasInterface) exitWith {};
AGM_Explosives_PlacedCount = 0;
AGM_Explosives_Setup = objNull;
//AGM_Explosives_CurrentSpeedDial=-1;
//AGM_Explosives_Phone_SpeedDial = [];
AGM_Explosives_ShiftDown = false;
AGM_Explosives_pfeh_running = false;
AGM_Explosives_null= [] spawn {
	waitUntil {sleep 0.356;!isNull(findDisplay 46)};
	(findDisplay 46) displayAddEventHandler ["MouseZChanged", "(_this select 1) call AGM_Explosives_fnc_HandleScrollWheel"];
	(findDisplay 46) displayAddEventHandler ["KeyDown", "if ((_this select 1) == 42) then {AGM_Explosives_ShiftDown = true;};"];
	(findDisplay 46) displayAddEventHandler ["KeyUp", "AGM_Explosives_ShiftDown = false;"];
	[player] call AGM_Explosives_fnc_initialiseUnit;
};