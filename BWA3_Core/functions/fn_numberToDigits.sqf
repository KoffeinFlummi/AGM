// by commy2

private ["_number", "_minLength", "_length", "_digits", "_index", "_count"];

_number = _this select 0;
_minLength = _this select 1;

_number = _number min 999999;
_length = floor (log _number + 1);

if !(isNil "_minLength") then {_length = (_length max _minLength) min 6};

_digits = [];

if (_number < 1) exitWith {
	for "_index" from 0 to (_length - 1) do {
		_digits set [_index, 0];
	};
	_digits
};

while {
	_count = count _digits;
	_count < _length
} do {
	_digit = floor (_number / (10 ^ (_length - _count - 1)));
	{
		_digit = _digit - _x * (10 ^ (_count - _forEachIndex));
	} forEach _digits;
	_digits set [_count, _digit];
};
_digits
