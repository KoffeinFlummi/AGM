/*
Author: jodav

Description:
Saves the gear when the player is killed
*/

AGM_Respawn_unitGear = [];


_xehPars = _this select 0;
_unit = _xehPars select 0;
//_attacker = _xehPars select 1;

if (_unit != player) exitWith {};

if (AGM_Respawn_SavePreDeathGear > 0) then {
  AGM_Respawn_unitGear = [_unit] call AGM_Respawn_fnc_getAllGear;
};