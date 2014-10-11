/*
  Name: AGM_SwitchUnits_fnc_handleMapClick
  
  Author(s):
    jodav
  
  Description:
    Finds the clicked unit
  
  Parameters:
    0: OBJECT - MapClickEventHandlerArgs
  
  Returns:
    VOID
*/

private ["_args", "_pos", "_sideNearest"];

_args = _this select 0;
_pos = _this select 1;

_sideNearest = [];

{
  if (side _x == side (_args select 0) && alive _x && !isPlayer _x) then {
    _sideNearest pushBack _x;
  };
} forEach (nearestObjects [_pos, ["Man"], 20]);


if (count _sideNearest > 0) then {
  private ["_switchUnit"];
  
  _switchUnit = _sideNearest select 0;
  [(_args select 0), _switchUnit] call AGM_SwitchUnits_fnc_switchUnit;
  
  openMap false;
};