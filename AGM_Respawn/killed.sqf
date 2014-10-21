/*
Author: jodav

Description:
Saves the gear when the player is killed
*/

AGM_Respawn_unitGear = [];

_unit = _this select 0;

if (AGM_Respawn_SavePreDeathGear > 0) then {
  AGM_Respawn_unitGear = [_unit] call AGM_Respawn_fnc_getAllGear;
};
