/*
 * Author: KoffeinFlummi
 *
 * Filters array and removes every element not fitting the condition
 *
 * Arguments:
 * 0: Array to be filtered.
 * 1: Code to be evaluated.
 *
 * Return Value:
 * Final array
 *
 * Usage:
 * [[0,1,2,3,4], {_this > 2}] call AGM_Core_fnc_filter ==> [3,4]
 */

private ["_array", "_code", "_arrayNew"];

_array = _this select 0;
_code = _this select 1;

_arrayNew = [];

for "_i" from 0 to (count _array - 1) do {
  if ((_array select _i) call _code) then {
    _arrayNew set [count _arrayNew, _array select _i];
  };
};

_arrayNew
