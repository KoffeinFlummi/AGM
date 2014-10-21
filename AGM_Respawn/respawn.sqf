/*
Author: jodav

Description:
Restores the gear when the player respawns
*/

_respawnedUnit = _this select 0;

if (AGM_Respawn_SavePreDeathGear > 0) then {
  [_respawnedUnit, AGM_Respawn_unitGear] call AGM_Respawn_fnc_restoreGear;
};
