/*
Author: commy2

Description:
Converts number to binary number

Arguments:
A number

Return Value:
A binary number, String
*/

private ["_number", "_sign", "_bin", "_rest"];

_number = _this;
_sign = if (_number < 0) then {"-"} else {""};

_number = round abs _number;
_bin = if (_number == 0) then {"0"} else {""};

while {_number > 0} do {
	_rest = str (_number mod 2);
	_number = floor (_number / 2);

	_bin = _rest + _bin;
};
_sign + _bin
