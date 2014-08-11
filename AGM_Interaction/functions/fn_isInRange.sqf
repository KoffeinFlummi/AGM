/*
 * Author: commy2
 *
 * Check if the vehicle is in range of the player.
 * 
 * Argument:
 * 0: Vehicke (Object)
 * 1: Distance in meters (Number)
 * 
 * Return value:
 * (Bool)
 */

private ["_vehicle", "_distance", "_position0", "_position1"];//, "_direction"];

_vehicle = _this select 0;
_distance = _this select 1;

if (_vehicle isKindOf "Man") exitWith {player distance _vehicle < _distance};

_position0 = getPosASL player;
_position1 = getPosASL _vehicle;

/*
_direction = _position1 vectorDiff _position0;
_direction = _direction vectorMultiply (_distance / (vectorMagnitude _direction));

_position0 = eyePos player;
_position1 = _position0 vectorAdd _direction;

_vehicle in lineIntersectsWith [_position0, _position1] || {player distance _vehicle < _distance}
*/

_position0 = ATLToASL positionCameraToWorld [0, 0, 0];
_position0 set [2, (_position0 select 2) - (getTerrainHeightASL _position0 min 0)];

_position1 = ATLToASL positionCameraToWorld [0, 0, _distance];
_position1 set [2, (_position1 select 2) - (getTerrainHeightASL _position1 min 0)];

_vehicle in lineIntersectsWith [_position0, _position1] || {player distance _vehicle < _distance}
