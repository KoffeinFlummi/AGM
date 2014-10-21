/*
Author: jodav

Description:
Restores the gear when the player respawns
*/

_xehPars = _this select 0;
_respawnedUnit = _xehPars select 0;

if (_respawnedUnit != player) exitWith {};

if (AGM_Respawn_SavePreDeathGear > 0) then {
  [_respawnedUnit, AGM_Respawn_unitGear] call AGM_Respawn_fnc_restoreGear;
};