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

  // just to be safe
  _body removeAllEventHandlers "Killed";
  _body removeAllEventHandlers "Respawn";
    
  if (AGM_Respawn_RemoveDeadBodies > 0) then {
    [_body, false] call AGM_Respawn_fnc_removeBody;
  };
    
  if (AGM_Respawn_SavePreDeathGear > 0) then {
    _respawnedUnit = _this select 0;
    [_respawnedUnit, AGM_Respawn_unitGear] call AGM_Respawn_fnc_restoreGear;
  };

}];

// team leaders can move the rallypoint

{
  if (isNil _x) then {
    missionNamespace setVariable [_x, objNull];
  };
} forEach ["AGM_Rallypoint_West", "AGM_Rallypoint_East", "AGM_Rallypoint_Independent", "AGM_RallypointExit_West", "AGM_RallypointExit_East", "AGM_RallypointExit_Independent"];

if (player == leader group player) then {
  player setVariable ['AGM_canMoveRallypoint', true, true];
};
