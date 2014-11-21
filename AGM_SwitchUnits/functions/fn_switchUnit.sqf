/*
  Name: AGM_SwitchUnits_fnc_switchUnit
  
  Author(s):
    jodav
  
  Description:
    Selects the new given player unit
  
  Parameters:
    0: OBJECT - the unit to switch to
  
  Returns:
    VOID
*/

private ["_newUnit"];

_newUnit = _this select 1;


// don't switch to original player units
if (!(_newUnit getVariable ["AGM_SwitchUnits_IsPlayerUnit", false]) && player != _newUnit && !(_newUnit getVariable ["AGM_SwitchUnits_IsPlayerControlled", false])) then {
    
  _newUnit spawn {
    private ["_unit", "_originalOwner", "_oldUnit", "_respawnEhId"];
    _unit = _this;
    
    _originalOwner = owner _unit;
    
    // should switch locality
    // This doesn't work anymore, because one's now able to switch to units from a different side
    //[_unit] joinSilent group player;
    [[_unit, player], "{(_this select 0) setOwner owner (_this select 1)}", 1] call AGM_Core_fnc_execRemoteFnc;
    
    _oldUnit = player;
    waitUntil {sleep 0.2; local _unit};
    
    _oldUnit setVariable ["AGM_SwitchUnits_IsPlayerControlled", false, true];
    _oldUnit setVariable ["AGM_SwitchUnits_PlayerControlledName", "", true];
    
    _respawnEhId = _unit getVariable ["AGM_SwitchUnits_RespawnEhId", -1];
    if (_respawnEhId != -1) then {
      _oldUnit removeEventHandler ["Respawn", _respawnEhId];
    };
    
    selectPlayer _unit;
    
    _unit setVariable ["AGM_SwitchUnits_OriginalOwner", _originalOwner, true];
    _unit setVariable ["AGM_SwitchUnits_IsPlayerControlled", true, true];
    _unit setVariable ["AGM_SwitchUnits_PlayerControlledName", AGM_SwitchUnits_OriginalName, true];
    
    _respawnEhId = _unit addEventHandler ["Respawn", {
      [AGM_SwitchUnits_OriginalUnit, _this select 0] spawn AGM_SwitchUnits_fnc_switchBack;
    }];
    _unit setVariable ["AGM_SwitchUnits_RespawnEhId", _respawnEhId, true];
    
    // set owner back to original owner
    _oldOwner = _oldUnit getVariable["AGM_SwitchUnits_OriginalOwner", -1];
    [[_oldUnit, _oldOwner], "{(_this select 0) setOwner (_this select 1)}", 1] call AGM_Core_fnc_execRemoteFnc;
    
    ["Localize: Switched unit."] call AGM_Core_fnc_displayTextStructured;
  };
};
