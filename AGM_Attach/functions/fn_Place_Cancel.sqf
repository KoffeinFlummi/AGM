/*
  Name: AGM_Attach_fnc_Place_Cancel
  
  Author(s):
    Pabst Mirror (based on Explosive attach by Garth de Wet (LH))
  
  Description:
    Cancels placement of the lightObject
  
  Parameters:
    Nothing
  
  Returns:
    Nothing
  
  Example:
    call AGM_Attach_fnc_Place_Cancel;
*/
if (AGM_Attach_pfeh_running) then {
  ["AGM_Attach_Placement","OnEachFrame"] call BIS_fnc_removeStackedEventHandler;
  AGM_Attach_pfeh_running = false;
};
if (!isNull (AGM_Attach_SetupObject)) then {
  deleteVehicle AGM_Attach_SetupObject;
};
AGM_Attach_SetupPlacmentItem = "";
AGM_Attach_SetupPlacmentText = "";
AGM_Attach_SetupObject = objNull;
AGM_Attach_SetupAttachVehicle = objNull;
if (isNil {AGM_Attach_placer}) then {
  AGM_Attach_placer = objNull;
};
AGM_Attach_placer forceWalk false;
AGM_Attach_placer = objNull;
call AGM_Interaction_fnc_hideMouseHint;
[AGM_player, "DefaultAction", AGM_player getVariable ["AGM_Attach_Place",  -1]] call AGM_Core_fnc_removeActionEventHandler;
[AGM_player, "MenuBack",      AGM_player getVariable ["AGM_Attach_Cancel", -1]] call AGM_Core_fnc_removeActionEventHandler;
