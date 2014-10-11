/*
  Author(s):
    jodav
*/

0 spawn {
  sleep 5;
  if (AGM_SwitchUnits_EnableSwitchUnits == 0) exitWith{};

  private ["_side"];
  _side = [west, east, independent, civilian] select AGM_SwitchUnits_SwitchUnitsAllowedForSide;

  if (side player == _side) then {
    [player, _side] call AGM_SwitchUnits_fnc_initPlayer;
  };
};