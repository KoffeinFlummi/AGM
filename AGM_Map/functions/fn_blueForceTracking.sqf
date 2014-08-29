/*
 * Author: KoffeinFlummi
 *
 * Initializes the blue force tracking module.
 *
 * Arguments:
 * Whatever the module provides. (I dunno.)
 *
 * Return Value:
 * None
 */

_logic = _this select 0;
_units = _this select 1;
_activated = _this select 2;

if !(_activated) exitWith {};

_logic spawn {
  _interval = parseNumber (_this getVariable "Interval");

  diag_log text "[AGM]: BlueForceTracking Module Initialized.";

  _side = side player;
  _markers = [];
  while {True} do {
    {
      deleteMarkerLocal _x;
    } count _markers;
    _markers = [];

    _groups = [allGroups, {side leader _this == _side}] call AGM_Core_fnc_filter;

    for "_i" from 0 to (count _groups - 1) do {
      _group = _groups select _i;
      _markerType = [_group] call AGM_Core_fnc_getMarkerType;
      _color = ["ColorGUER", "ColorWEST", "ColorEAST"] select ((["GUER", "WEST", "EAST"] find (str side leader _group)) max 0);

      _marker = createMarker ["AGM_BFT_"+(str _i), [(getPos leader _group) select 0, (getPos leader _group) select 1]];
      _marker setMarkerTypeLocal _markerType;
      _marker setMarkerColorLocal _color;
      _marker setMarkerTextLocal (groupID _group);

      _markers = _markers + [_marker];
    };

    sleep _interval;
  };
};

