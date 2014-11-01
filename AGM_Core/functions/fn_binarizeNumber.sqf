/*
 * Author: commy2
 *
 * Get a binary equivalent of a decimal number.
 *
 * Argument:
 * 0: Decimal Number (Number)
 * 1: Minimum length of the returned Array, note: returned array can be larger (Number, optional default 8)
 *
 * Return value:
 * Booleans (Array)
 */

private ["_number", "_minLength", "_array", "_index", "_rest"];

_number = round (_this select 0);
_minLength = _this select 1;

if (isNil "_minLength") then {_minLength = 8};

_array = [];
_array resize _minLength;

for "_index" from 0 to (_minLength - 1) do {
  _array set [_index, false];
};

_index = 0;

while {_number > 0} do {
  _rest = _number mod 2;
  _number = floor (_number / 2);

  _array set [_index, _rest == 1];
  _index = _index + 1;
};
_array
