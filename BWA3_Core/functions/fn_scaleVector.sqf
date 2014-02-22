/*
Author: commy2

Description:
multiplies a vector with a scale to change the lenght of a vector

Arguments:
  1 : A Scale, Number
  2 : A Vector, Array

Return Value:
A Vector, Array
*/

private ["_scale", "_vector"];

_scale = _this select 0;
_vector = + _this select 1;

{
	_vector set [_forEachIndex, _scale * (_vector select _forEachIndex)];
} forEach _vector;
_vector
