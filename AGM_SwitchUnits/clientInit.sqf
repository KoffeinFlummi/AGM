/*
  Author(s):
    bux578
*/

0 spawn {
  private ["_side"];
  
  waitUntil {sleep 0.5; !isNil "AGM_SwitchUnits_EnableSwitchUnits"};
  if (AGM_SwitchUnits_EnableSwitchUnits == 0) exitWith {};
  
  //_side = [west, east, independent, civilian] select AGM_SwitchUnits_SwitchUnitsAllowedForSide;
  
  _sides = [];
  
  if(AGM_SwitchUnits_SwitchToWest == 1) then {_sides pushBack west};
  if(AGM_SwitchUnits_SwitchToEast == 1) then {_sides pushBack east};
  if(AGM_SwitchUnits_SwitchToIndependent == 1) then {_sides pushBack independent};
  if(AGM_SwitchUnits_SwitchToCivilian == 1) then {_sides pushBack civilian};
  
  if (player getVariable ["AGM_CanSwitchUnits", false]) then {
    [player, _sides] call AGM_SwitchUnits_fnc_initPlayer;
  };
};
