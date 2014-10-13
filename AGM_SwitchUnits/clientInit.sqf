/*
  Author(s):
    jodav
*/

0 spawn {
  private ["_side"];
  
  waitUntil {!isNil "AGM_SwitchUnits_EnableSwitchUnits"};
  if (AGM_SwitchUnits_EnableSwitchUnits == 0) exitWith{};

  _side = [west, east, independent, civilian] select AGM_SwitchUnits_SwitchUnitsAllowedForSide;

  if (side player == _side) then {
    [player, _side] call AGM_SwitchUnits_fnc_initPlayer;
  };
};