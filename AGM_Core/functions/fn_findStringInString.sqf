/*
 * Author: commy2
 *
 * Find a string within a string. This gives an index
 * 
 * Argument:
 * 0: A short string (String)
 * 1: A long string which might contain the first string. (String)
 * 
 * Return value:
 * Index of the first letter of the short string in the long string. -1 if the short string is not in the long string. (Number)
 */

private ["_string0", "_string1", "_array0", "_array1", "_index", "_testArray1", "_a"];

_string0 = _this select 0;
_string1 = _this select 1;

_array0 = toArray _string0;
_array1 = toArray _string1;

_index = 0;
while {true} do {
	_index = _array1 find (_array0 select 0);
	if (_index == -1) exitWith {_index = -1};

	_testArray1 = + _array1;
	for "_a" from 0 to (_index - 1) do {
		_testArray1 set [_a, -1];
	};
	_testArray1 = _testArray1 - [-1];
	_testArray1 resize count _array0;

	if (_string0 == toString _testArray1) exitWith {};

	_array1 set [_index, -1];
};
_index
