/*
 * Author: commy2
 *
 * Convert an array of booleans into a number.
 *
 * Argument:
 * 0: Booleans (Array of Booleans)
 *
 * Return value:
 * Bitmask (Number)
 */

private ["_array", "_result"];

_array = _this;

_result = 0;
{
  if (_x) then {_result = _result + 2 ^ _forEachIndex};
} forEach _array;

_result
