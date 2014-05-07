/*
Author: commy2

Description:
multiplies a vector with a scale to change the lenght of a vector

Arguments:
  1 : A Vector, Array
  2 : Another Vector, Array

Return Value:
Vector product, Array
*/

private ["_vector1", "_vector2"];

_vector1 = _this select 0;
_vector2 = _this select 1;

[
	(_vector1 select 1) * (_vector2 select 2) - (_vector1 select 2) * (_vector2 select 1),
	(_vector1 select 2) * (_vector2 select 0) - (_vector1 select 0) * (_vector2 select 2),
	(_vector1 select 0) * (_vector2 select 1) - (_vector1 select 1) * (_vector2 select 0)
]
