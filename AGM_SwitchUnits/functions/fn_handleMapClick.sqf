/*
  Name: AGM_SwitchUnits_fnc_handleMapClick
  
  Author(s):
    bux578
  
  Description:
    Finds the clicked unit
  
  Parameters:
    0: OBJECT - MapClickEventHandlerArgs
      0: OBJECT - unit // useless
      1: ARRAY<OBJECT> - sides
  
  Returns:
    VOID
*/

private ["_sides", "_pos", "_sideNearest"];

// that's wrong
//_currentPlayerUnit = (_this select 0) select 0;

_sides = (_this select 0) select 1;
_pos = _this select 1;

_sideNearest = [];

{
  if ([_x] call AGM_SwitchUnits_fnc_isValidAi && (side group _x in _sides)) then {
    _sideNearest pushBack _x;
  };
} forEach (nearestObjects [_pos, ["Man"], 20]);


if (count _sideNearest > 0) then {
  private ["_switchUnit"];
  
  _switchUnit = _sideNearest select 0;
  [AGM_player, _switchUnit] call AGM_SwitchUnits_fnc_switchUnit;
  
  openMap false;
};
