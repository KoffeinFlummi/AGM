// by commy2

private ["_position", "_direction", "_vectorX", "_vectorY", "_vectorZ", "_length"];

_position = _this select 0;
_direction = _this select 1;

if (typeName _position != "ARRAY") then {_position = getPosATL _position};
if (typeName _direction != "ARRAY") then {_direction = getPosATL _direction};

_position resize 3;
_direction resize 3;

_vectorX = (_direction select 0) - (_position select 0);
_vectorY = (_direction select 1) - (_position select 1);
_vectorZ = (_direction select 2) - (_position select 2);

_length = sqrt (_vectorX ^ 2 + _vectorY ^ 2 + _vectorZ ^ 2);

[
	((_vectorX / _length) min 1) max -1,
	((_vectorY / _length) min 1) max -1,
	((_vectorZ / _length) min 1) max -1
]
