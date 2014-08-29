// by commy2

#define DOOR_TYPES ["door", "hatch"]
#define DOOR_NULL [objNull, "", ""]

private ["_distance", "_position0", "_position1", "_intersections", "_count", "_house", "_door", "_index", "_id"];

_distance = _this select 0;

_position0 = positionCameraToWorld [0, 0, 0];
_position1 = positionCameraToWorld [0, 0, _distance];

_intersections = lineIntersectsWith [ATLToASL _position0, ATLToASL _position1, player, objNull, true];

_count = count _intersections;
if (_count == 0) exitWith {DOOR_NULL};

_house = _intersections select (_count - 1);

// shithouse is bugged
if (typeOf _house == "") exitWith {DOOR_NULL};

_intersections = [_house, "GEOM"] intersect [_position0, _position1];

_door = _intersections select 0 select 0;
if (isNil "_door") exitWith {DOOR_NULL};

_door = toArray _door;	//@todo v1.26

_index = _door find 95;
if (_index == -1) exitWith {DOOR_NULL};

_id = toString [_door select _index + 1];

_door resize _index;
_door = toString _door;

[_house, _door, _id]

