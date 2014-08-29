/*
 * Author: KoffeinFlummi
 *
 * Applies given code to every element in an array, LIKE SOMETHING SQF SHOULD HAVE BY DEFAULT.
 *
 * Arguments:
 * 0: Array to be thingied.
 * 1: Code to be applied to every element.
 *
 * Return Value:
 * Final array
 *
 * Usage:
 * [["2", "gobblecock", "25"], {parseNumber _this}] call AGM_Core_fnc_map ==> [2, 0, 25]
 */

private ["_array", "_code"];

_array = _this select 0;
_code = _this select 1;

for "_i" from 0 to (count _array - 1) do {
  _array set [_i, (_array select _i) call _code];
};

_array
