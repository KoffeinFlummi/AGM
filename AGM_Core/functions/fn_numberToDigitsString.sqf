// by commy2

private ["_digits", "_count", "_string", "_index"];

_digits = _this call AGM_Core_fnc_numberToDigits;

_count = count _digits;

_string = "";
for "_index" from 0 to (_count - 1) do {
	_string = _string + str (_digits select _index);
};
_string
