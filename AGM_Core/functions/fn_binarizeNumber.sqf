/*
 * Author: commy2
 *
 * Get binary equivalent of a decimal number.
 * 
 * Argument:
 * 0: Decimal Number (Number)
 * 
 * Return value:
 * Booleans (Array)
 */

private ["_number", "_array", "_index", "_rest"];

_number = round _this;

_array = [false, false, false, false, false, false, false, false];
_index = 0;

while {_number > 0} do {
	_rest = _number mod 2;
	_number = floor (_number / 2);

	_array set [_index, _rest == 1];
	_index = _index + 1;
};
_array
