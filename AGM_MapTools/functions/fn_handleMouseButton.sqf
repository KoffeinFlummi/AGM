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
if (_dir == 1 && !_handled) then {
  AGM_MapTools_dragging = false;
  AGM_MapTools_rotating = false;
  
  // Check if clicking the maptool
  if (_pos call AGM_MapTools_fnc_isInsideMapTool) exitWith {
    // Store data for dragging
    AGM_MapTools_startPos = + AGM_MapTools_pos;
    AGM_MapTools_startDragPos = + _pos;
    if (_shiftKey) then {
      // Store data for rotating
      AGM_MapTools_startAngle = + AGM_MapTools_angle;
      AGM_MapTools_startDragAngle = (180 + ((AGM_MapTools_startDragPos select 0) - (AGM_MapTools_startPos select 0)) atan2 ((AGM_MapTools_startDragPos select 1) - (AGM_MapTools_startPos select 1)) mod 360);
      // Start rotating
      AGM_MapTools_rotating = true;
    } else {
      // Start dragging
      AGM_MapTools_dragging = true;
    };
    _handled = true;
  };
};

// If releasing
if (_dir != 1 && (AGM_MapTools_dragging or AGM_MapTools_rotating)) exitWith {
  AGM_MapTools_dragging = false;
  AGM_MapTools_rotating = false;
  _handled = true;
};
_handled
