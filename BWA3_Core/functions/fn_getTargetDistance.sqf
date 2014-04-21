/*
 * Author: commy2
 *
 * Gets the distance to the current target
 *
 * Arguments:
 * 0: interval
 * 1: maxDistance
 * 2: minDistance
 *
 * Return Value:
 * distance
 */

private ["_interval", "_maxDistance", "_minDistance", "_position", "_direction", "_distance", "_iteration", "_laser", "_line"];

_interval = (_this select 0) max 1;
_maxDistance = _this select 1;
_minDistance = _this select 2;

_position = ATLToASL positionCameraToWorld [0, 0, 0];
_direction = ATLToASL positionCameraToWorld [0, 0, 1];

_direction set [0, (_direction select 0) - (_position select 0)];
_direction set [1, (_direction select 1) - (_position select 1)];
_direction set [2, (_direction select 2) - (_position select 2)];

_distance = _maxDistance;
_iteration = _distance;
_laser = [];
_line = [_position, _laser];

while {
  _iteration > _interval / 2
} do {
  _iteration = _iteration / 2;

  _laser set [0, (_position select 0) + _distance * (_direction select 0)];
  _laser set [1, (_position select 1) + _distance * (_direction select 1)];
  _laser set [2, (_position select 2) + _distance * (_direction select 2)];

  _distance = _distance + (([1, -1] select (lineIntersects (_line + [vehicle player]) || {terrainIntersectASL _line})) * _iteration);
};

_distance = _interval * round (_distance / _interval);

_distance = _distance min _maxDistance;

if !(isNil "_minDistance") then {_distance = _distance max _minDistance};

_distance
