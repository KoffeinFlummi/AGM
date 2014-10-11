/*
  Name: AGM_SwitchUnits_fnc_switchBack
  
  Author(s):
    jodav
  
  Description:
    Switches back to the original player unit
    This method needs to be "spawn"ed
  
  Parameters:
    0: OBJECT - original player unit
    1: OBJECT - respawned unit
  
  Returns:
    VOID
*/

private ["_originalPlayerUnit", "_currentUnit"];
_originalPlayerUnit = _this select 0;
_currentUnit = _this select 1;

waitUntil {local _originalPlayerUnit};

selectPlayer _originalPlayerUnit;

deleteVehicle _currentUnit;
