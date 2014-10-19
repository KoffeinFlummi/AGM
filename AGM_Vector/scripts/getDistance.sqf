// by commy2

#define MIN_DISTANCE 10
#define MAX_DISTANCE ([6000, 9000] select (AGM_vectorSettings select 3))
#define INTERVAL 2

/*_position = ATLToASL positionCameraToWorld [0, 0, 0];
_direction = ATLToASL positionCameraToWorld [0, 0, 1];
_direction set [0, (_direction select 0) - (_position select 0)];
_direction set [1, (_direction select 1) - (_position select 1)];
_direction set [2, (_direction select 2) - (_position select 2)];

_distance = MAX_DISTANCE;
_iteration = _distance;
_laser = [];
_line = [_position, _laser];

while {
	_iteration > 0.1
} do {
	_iteration = _iteration / 2;

	_laser set [0, (_position select 0) + _distance * (_direction select 0)];
	_laser set [1, (_position select 1) + _distance * (_direction select 1)];
	_laser set [2, (_position select 2) + _distance * (_direction select 2)];

	_distance = _distance + ([1, -1] select (lineIntersects _line || {terrainIntersectASL _line}) * _iteration);
};*/

/*
_distance = [INTERVAL, MAX_DISTANCE, MIN_DISTANCE] call AGM_Core_fnc_getTargetDistance;

if (AGM_vectorSettings select 3) then {
	_distance = 3.28084 * _distance;
	if (_distance == MIN_DISTANCE) then {_distance = -9999};
	if (_distance == MAX_DISTANCE * 1.5) then {_distance = -9999};
} else {
	_distance = INTERVAL * round (_distance / INTERVAL);
	if (_distance == MIN_DISTANCE) then {_distance = -9999};
	if (_distance == MAX_DISTANCE) then {_distance = -9999};
};

_distance
*/

private ["_dlgVectorOptics", "_distance"];

disableSerialization;
_dlgVectorOptics = uiNamespace getVariable ['AGM_dlgVectorOptics', displayNull];

_distance = ctrlText (_dlgVectorOptics displayCtrl 151);

if (_distance == "----") exitWith {-9999};

_distance = round parseNumber _distance;

if (AGM_vectorSettings select 3) then {
	_distance = 3.28084 * _distance;
};

if (_distance > MAX_DISTANCE) exitWith {-9999};
if (_distance < MIN_DISTANCE) exitWith {-9999};

_distance
