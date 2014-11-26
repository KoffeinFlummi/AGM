// by commy2

private ["_info", "_house", "_door", "_id"];

_info = [2] call AGM_Interaction_fnc_getDoor;

_house = _info select 0;
_door = _info select 1;
_id = _info select 2;

if (isNull _house) exitWith {};

if (_house animationPhase format ["%1_%2_rot", _door, _id] <= 0 && {_house getVariable [format ["BIS_Disabled_Door_%1", _id], 0] == 1}) exitWith {
	[_house, format ["Door_Handle_%1_rot_1", _id], format ["Door_Locked_%1_rot", _id]] spawn compile preprocessFileLineNumbers "\A3\Structures_F\scripts\LockedDoor_open.sqf";
};

AGM_Interaction_isOpeningDoor = true;
playSound "AGM_Sound_Click";

_info spawn {
	_house = _this select 0;

	_animation0 = format ["%1_%2_rot",          _this select 1, _this select 2];
	_animation1 = format ["%1_Handle_%2_rot_1", _this select 1, _this select 2];
	_animation2 = format ["%1_Handle_%2_rot_2", _this select 1, _this select 2];
	_animation3 = format ["Door_0%2",            _this select 1, _this select 2];
	_animation4 = format ["dvere%2",            _this select 1, _this select 2];

	_phase = _house animationPhase _animation0;
	_position = getPosASL player;

	_time = time + 0.2;
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
		_house animate [_animation3, _phase];
		_house animate [_animation4, _phase];

		!AGM_Interaction_isOpeningDoor || {getPosASL player distance _position > 1}
	};

	if (!_usedMouseWheel && {time < _time}) then {
		_phase = [0, 1] select (_house animationPhase _animation0 < 0.5);

		_house animate [_animation0, _phase];
		_house animate [_animation1, _phase];
		_house animate [_animation2, _phase];
		_house animate [_animation3, _phase];
		_house animate [_animation4, _phase];
	};

	AGM_Interaction_isOpeningDoor = false;
};
