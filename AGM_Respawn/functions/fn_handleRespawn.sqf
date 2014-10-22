/*
  Name: AGM_Respawn_fnc_handleRespawn
  
  Author(s):
    jodav
  
  Description:
    Handles the XEH Respawn event
  
  Parameters:
    0: OBJECT - Respawned Unit
    1: ?
  
  Returns:
    VOID
*/

private ["_respawnedUnit"];

_respawnedUnit = _this select 0;

// Restores the gear when the player respawns
if (AGM_Respawn_SavePreDeathGear > 0) then {
  [_respawnedUnit, AGM_Respawn_unitGear] call AGM_Respawn_fnc_restoreGear;
};
