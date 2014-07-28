/*
Author: jodav

Description:
Saves the gear when the player is killed and restores it on respawn
*/

unitGear = [];

player addEventHandler ["Killed", {

  if (!(isNil "AGM_Respawn_SavePreDeathGear") and {AGM_Respawn_SavePreDeathGear}) then {
      _killedUnit = _this select 0;
      unitGear = [_killedUnit] call AGM_Respawn_fnc_getAllGear;
  };
}];

player addEventHandler ["Respawn", {

  if (!(isNil "AGM_Respawn_SavePreDeathGear") and {AGM_Respawn_SavePreDeathGear}) then {

    _body = _this select 1;
    [_body, false] call AGM_Respawn_fnc_removeBody;
       
    // just to be safe
    _body removeAllEventHandlers "Killed";
    _body removeAllEventHandlers "Respawn";
    
    
    _respawnedUnit = _this select 0;
    [_respawnedUnit, unitGear] call AGM_Respawn_fnc_restoreGear;
  };

}];
