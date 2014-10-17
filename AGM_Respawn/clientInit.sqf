/*
Author: jodav

Description:
Saves the gear when the player is killed and restores it on respawn
*/

AGM_Respawn_unitGear = [];

player addEventHandler ["Killed", {

  if (AGM_Respawn_SavePreDeathGear > 0) then {
    _killedUnit = _this select 0;
    AGM_Respawn_unitGear = [_killedUnit] call AGM_Respawn_fnc_getAllGear;
  };
  
}];

player addEventHandler ["Respawn", {
    
  _body = _this select 1;
    
  /*if (AGM_Respawn_RemoveDeadBodies > 0) then {
    [_body, false] call AGM_Respawn_fnc_removeBody;
  };*/
    
  if (AGM_Respawn_SavePreDeathGear > 0) then {
    _respawnedUnit = _this select 0;
    [_respawnedUnit, AGM_Respawn_unitGear] call AGM_Respawn_fnc_restoreGear;
  };

}];
