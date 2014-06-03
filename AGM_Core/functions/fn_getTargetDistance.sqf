/*
 * Author: commy2
 *
 * Get the distance to the next object the player is looking at. Used for laser distance measurements.
 * 
 * Argument:
 * 0: How accurate will the measurement be? In meters. (Number)
 * 1: Maximal distance to measure. (Number)
 * 2: Minimal distance to measure. (optional, Number)
 * 
 * Return value:
 * Measured distance in meters. Can return maximal or minimal distance (Number)
 */

private ["_interval", "_maxDistance", "_minDistance", "_position", "_line", "_distance", "_iteration"];

_interval = _this select 0;
_maxDistance = _this select 1;
_minDistance = _this select 2;

_position = ATLtoASL positionCameraToWorld [0, 0, 0];
_line = [_position, _position];

_distance = _maxDistance;
_iteration = _distance;

while {
	_iteration > _interval / 2
} do {
	_iteration = _iteration / 2;

	_line set [1, ATLtoASL positionCameraToWorld [0, 0, _distance]];

	_distance = _distance + (([1, -1] select (lineIntersects (_line + [vehicle player]) || {terrainIntersectASL _line})) * _iteration);
};

_distance = _interval * round (_distance / _interval);

_distance = _distance min _maxDistance;

if !(isNil "_minDistance") then {_distance = _distance max _minDistance};

_distance
