// by commy2

private ["_keyCode", "_key", "_alt", "_ctrl", "_shft"];

_keyCode = _this select 0;

_key = toString ((toArray keyName floor _keyCode) - [34]);

_keyCode = round ((_keyCode % 1) * 10);

_alt = _keyCode >= 4;
_ctrl = _keyCode >= [2, 6] select _alt;
_shift = _keyCode % 2 == 1;

format ["%1%2%3%4",
	["", format ["%1 + ", localize "STR_BWA3_Core_Alt"]] select _alt,
	["", format ["%1 + ", localize "STR_BWA3_Core_Ctrl"]] select _ctrl,
	["", format ["%1 + ", localize "STR_BWA3_Core_Shift"]] select _shift,
	_key
]
