/*
 * Author: KoffeinFlummi, commy2
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

private ["_array", "_code", "_newArray"];

_array = _this select 0;
_code = _this select 1;

if (!assert (!isNil "_array")) exitWith {
  diag_log text format ["[AGM] ERROR: No array for function filter in %1", _fnc_scriptNameParent];
  []
};

_newArray = [];
{
  if (_x call _code) then {
    _newArray pushBack _x;
  };
} forEach _array;
_newArray
