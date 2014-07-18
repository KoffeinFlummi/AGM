/*
 * Author: CAA-Picard
 *
 * Return true if the position is inside the map marker (to allow dragging).
 * 
 * Argument:
 * 0: x Position (in meters)
 * 1: y Position (in meters)
 * 
 * Return value:
 * Boolean
 */

#define TEXTURE_WIDTH_IN_M           6205
#define DIST_BOTTOM_TO_CENTER_PERC  -0.32
#define DIST_TOP_TO_CENTER_PERC      0.66
#define DIST_LEFT_TO_CENTER_PERC     0.32

_pos = [_this select 0, _this select 1, 0];
_relPos = _pos vectorDiff [AGM_MapTools_pos select 0, AGM_MapTools_pos select 1, 0];
_dirVector = [sin(AGM_MapTools_angle), cos(AGM_MapTools_angle), 0];

// Projection of the relative position over the longitudinal axis of the map tool
_lambdaLong = _dirVector vectorDotProduct _relPos;
if (_lambdaLong < DIST_BOTTOM_TO_CENTER_PERC * TEXTURE_WIDTH_IN_M) exitWith {false};

// Projection of the relative position over the trasversal axis of the map tool
_lambdaTrasAbs = vectorMagnitude (_relPos vectorDiff (_dirVector vectorMultiply _lambdaLong));
if (_lambdaLong > DIST_TOP_TO_CENTER_PERC * TEXTURE_WIDTH_IN_M) exitWith {false};
if (_lambdaTrasAbs > DIST_LEFT_TO_CENTER_PERC * TEXTURE_WIDTH_IN_M) exitWith {false};

true
