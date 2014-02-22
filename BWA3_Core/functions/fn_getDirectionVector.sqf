/*
Author: commy2

Description:
Creates a unit vector from position or object A to position or object B

Arguments:
0 : An object or position, object or array
1 : Another object or position, object or array

Return Value:
A unit vector, 3-element-Array
*/

private ["_position0", "_position1", "_vectorX", "_vectorY", "_vectorZ", "_lenght"];

_position0 = _this select 0;
_position1 = _this select 1;

if (typeName _position0 != "ARRAY") then {_position0 = getPosATL _position0};
if (typeName _position1 != "ARRAY") then {_position1 = getPosATL _position1};

_position0 resize 3;
_position1 resize 3;

_vectorX = (_position1 select 0) - (_position0 select 0);
_vectorY = (_position1 select 1) - (_position0 select 1);
_vectorZ = (_position1 select 2) - (_position0 select 2);

_lenght = sqrt (_vectorX ^ 2 + _vectorY ^ 2 + _vectorZ ^ 2);

[
	((_vectorX / _lenght) min 1) max -1,
	((_vectorY / _lenght) min 1) max -1,
	((_vectorZ / _lenght) min 1) max -1
]
