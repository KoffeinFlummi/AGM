/*
 * Author: CAA-Picard
 *
 * Handle mouse buttons.
 *
 * Argument:
 * 0: 1 if mouse down down, 0 if mouse button up (Number)
 * 1: Parameters of the mouse button event
 *
 * Return value:
 * Boolean, true if event was handled
 */

private ["_dir", "_params", "_control", "_button", "_screenPos", "_shiftKey", "_ctrlKey", "_handled", "_pos"];

// If no map tool marker then exit
if (isNil "AGM_Map_mapToolFixed") exitWith {};

_dir       = _this select 0;
_params    = _this select 1;
_control   = _params select 0;
_button    = _params select 1;
_screenPos = [_params select 2, _params select 3];
_shiftKey  = _params select 4;
_ctrlKey   = _params select 5;
_handled   = false;

// If it's not a left button event, exit
if (_button != 0) exitWith {};

// Transform mouse screen position to coordinates
_pos  = _control ctrlMapScreenToWorld _screenPos;

// If clicking
if (_dir == 1 && !_handled) exitWith {
  AGM_Map_dragging = false;
  AGM_Map_rotating = false;

  // Check if clicking the maptool
  if (_pos call AGM_Map_fnc_isInsideMapTool) exitWith {
    // Store data for dragging
    AGM_Map_startPos = + AGM_Map_pos;
    AGM_Map_startDragPos = + _pos;
    if (_ctrlKey) then {
      // Store data for rotating
      AGM_Map_startAngle = + AGM_Map_angle;
      AGM_Map_startDragAngle = (180 + ((AGM_Map_startDragPos select 0) - (AGM_Map_startPos select 0)) atan2 ((AGM_Map_startDragPos select 1) - (AGM_Map_startPos select 1)) mod 360);
      // Start rotating
      AGM_Map_rotating = true;
    } else {
      // Start dragging
      AGM_Map_dragging = true;
    };
    _handled = true;
  };
  _handled
};

// If releasing
if (_dir != 1 && (AGM_Map_dragging or AGM_Map_rotating)) exitWith {
  AGM_Map_dragging = false;
  AGM_Map_rotating = false;
  _handled = true;
  _handled
};

_handled
