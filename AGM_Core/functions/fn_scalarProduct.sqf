/*
Author: commy2

Description:
multiplies a vector with a scale to change the lenght of a vector

Arguments:
  1 : A Vector, Array
  2 : Another Vector, Array

Return Value:
Scalar product, Number
*/

private ["_vector1", "_vector2", "_count", "_scalar", "_index"];

_vector1 = _this select 0;
_vector2 = _this select 1;

_count = (count _vector1) min (count _vector2);

_scalar = 0;
for "_index" from 0 to (_count - 1) do {
	_scalar = _scalar + (_vector1 select _index) * (_vector2 select _index);
};
_scalar
