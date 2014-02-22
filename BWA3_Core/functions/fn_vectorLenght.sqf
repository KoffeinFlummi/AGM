/*
Author: commy2

Description:
multiplies a vector with a scale to change the lenght of a vector

Arguments:
A Vector, Array

Return Value:
Absolute value, Number
*/

private ["_vector", "_absolute"];

_vector = _this select 0;

_absolute = 0;
{
	_absolute = _absolute + (_vector select _forEachIndex) ^ 2;
} forEach _vector;

sqrt _absolute
