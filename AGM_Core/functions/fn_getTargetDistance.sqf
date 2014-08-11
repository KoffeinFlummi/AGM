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

private ["_interval", "_maxDistance", "_minDistance", "_position", "_laser", "_line", "_distance", "_iteration"];

_interval = _this select 0;
_maxDistance = _this select 1;
_minDistance = _this select 2;

_position = ATLToASL positionCameraToWorld [0, 0, 0];
_position set [2, (_position select 2) - (getTerrainHeightASL _position min 0)];

_laser = + _position;
_line = [_position, _laser];

_distance = _maxDistance;
_iteration = _distance;

while {
	_iteration > _interval / 2
} do {
	_iteration = _iteration / 2;

	_laser = ATLToASL positionCameraToWorld [0, 0, _distance];
	_laser set [2, (_laser select 2) - (getTerrainHeightASL _laser min 0)];
	_line set [1, _laser];

	_distance = _distance + (([1, -1] select (lineIntersects (_line + [vehicle player]) || {terrainIntersectASL _line})) * _iteration);
};

_distance = _interval * round (_distance / _interval);

_distance = _distance min _maxDistance;

if !(isNil "_minDistance") then {_distance = _distance max _minDistance};

_distance
