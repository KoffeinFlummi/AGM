// by commy2

private ["_position0", "_position1", "_positionX", "_line", "_intersections"];

_position0 = + _this select 0;
_position1 = + _this select 1;

_positionX = + _position1;
_line = [_position0, _positionX];

while {
	_position0 distance _position1 > 0.01
} do {
	_intersections = {
		_x isKindOf "Static" || {_x isKindOf "AllVehicles"}
	} count (lineIntersectsWith _line);

	if (
		_intersections > 0 || {terrainIntersectASL _line}
	) then {
		_position1 set [0, _positionX select 0];
		_position1 set [1, _positionX select 1];
		_position1 set [2, _positionX select 2];
	} else {
		_position0 set [0, _positionX select 0];
		_position0 set [1, _positionX select 1];
		_position0 set [2, _positionX select 2];
	};

	_positionX set [0, (_position0 select 0) + 0.5 * ((_position1 select 0) - (_position0 select 0))];
	_positionX set [1, (_position0 select 1) + 0.5 * ((_position1 select 1) - (_position0 select 1))];
	_positionX set [2, (_position0 select 2) + 0.5 * ((_position1 select 2) - (_position0 select 2))];
};
_positionX
