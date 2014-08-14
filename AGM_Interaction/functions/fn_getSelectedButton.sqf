// by commy2

#define MIN_DISTANCE 0.025

private ["_position", "_distance", "_angle"];

_position = uiNamespace getVariable ['AGM_Interaction_CursorPosition', [0.5, 0.5, 0]];

_position = [((_position select 1) - 0.5) / safezoneH, ((_position select 2) - 0.5) / safezoneW, 0];

_distance = [0, 0, 0] vectorDistanceSqr _position;

// is in center
if (_distance < MIN_DISTANCE) exitWith {-1};

_angle = (_position select 0) atan2 (_position select 1);

// rotate circle
_angle = 180 - _angle + 360 / 10 / 2;
if (_angle < 0) then {_angle = _angle + 360};

_angle = floor (_angle / 360 * 10);
if (_angle == 10) then {0} else {_angle}
