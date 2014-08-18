// by commy2

/*
	Door_4_rot
	Door_Handle_4_rot_1
	Door_Handle_4_rot_2
	Door_Locked_1_rot
*/

#define MAX_DISTANCE 2
#define DOOR_TYPES ["door", "hatch"]

private ["_position0", "_position1", "_intersections", "_count", "_house", "_door", "_index", "_id"];

_position0 = positionCameraToWorld [0, 0, 0];
_position1 = positionCameraToWorld [0, 0, MAX_DISTANCE];

_intersections = lineIntersectsWith [ATLToASL _position0, ATLToASL _position1, player, objNull, true];

_count = count _intersections;

if (_count == 0) exitWith {};

_house = _intersections select (_count - 1);

// shithouse is bugged
if (typeOf _house == "") exitWith {};

_intersections = [_house, "GEOM"] intersect [_position0, _position1];

_door = _intersections select 0 select 0;
if (isNil "_door") exitWith {};

_door = toArray _door;	//@todo v1.26

_index = _door find 95;
if (_index == -1) exitWith {};

_id = toString [_door select _index + 1];

_door resize _index;
_door = toString _door;

if (_house animationPhase format ["%1_%2_rot", _door, _id] <= 0 && {_house getVariable [format ["BIS_Disabled_Door_%1", _id], 0] == 1}) exitWith {
	[_house, format ["Door_Handle_%1_rot_1", _id], format ["Door_Locked_%1_rot", _id]] spawn compile preprocessFileLineNumbers "\A3\Structures_F\scripts\LockedDoor_open.sqf";
};

AGM_Interaction_isOpeningDoor = true;
playSound "AGM_Sound_Click";

[_house, _door, _id] spawn {
	_house = _this select 0;

	_animation0 = format ["%1_%2_rot",        _this select 1, _this select 2];
	_animation1 = format ["%1_Handle_%2_rot_1", _this select 1, _this select 2];
	_animation2 = format ["%1_Handle_%2_rot_2", _this select 1, _this select 2];

	_phase = _house animationPhase _animation0;
	_position = getPosASL player;

	_usedMouseWheel = false;
	waitUntil {
		if (inputAction "PrevAction" > 0 || {inputAction "NextAction" > 0}) then {
			_usedMouseWheel = true;
		};

		_phase = _phase + (inputAction "PrevAction" / 12) min 1;
		_phase = _phase - (inputAction "NextAction" / 12) max 0;

		_house animate [_animation0, _phase];
		_house animate [_animation1, _phase];
		_house animate [_animation2, _phase];

		!AGM_Interaction_isOpeningDoor || {getPosASL player distance _position > 1}
	};

	if !(_usedMouseWheel) then {
		_phase = [0, 1] select (_house animationPhase _animation0 < 0.5);

		_house animate [_animation0, _phase];
		_house animate [_animation1, _phase];
		_house animate [_animation2, _phase];
	};

	AGM_Interaction_isOpeningDoor = false;
};
