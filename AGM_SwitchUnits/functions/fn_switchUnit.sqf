private ["_newUnit"];

_newUnit = _this select 1;


// don't switch to original player units
if (!(_newUnit getVariable ["AGM_SwitchUnit_IsPlayerUnit", false]) && player != _newUnit && !(_newUnit getVariable ["AGM_SwitchUnit_IsPlayerControlled", false])) then {
    
  _newUnit spawn {
    private ["_unit", "_oldUnit"];
    _unit = _this;
    //[_unit] joinSilent SwitchUnits_OriginalGroup;
    _oldUnit = player;
    waitUntil {local _unit};
    
    _oldUnit setVariable ["AGM_SwitchUnit_IsPlayerControlled", false, true];
    _oldUnit setVariable ["AGM_SwitchUnit_PlayerControlledName", "", true];
    
    _unit setVariable ["AGM_SwitchUnit_IsPlayerControlled", true, true];
    _unit setVariable ["AGM_SwitchUnit_PlayerControlledName", AGM_SwitchUnit_OriginalName, true];
    
    selectPlayer _unit;
    
    ["Localize: Switched unit."] call AGM_Core_fnc_displayTextStructured;
  };
};