// by commy2

private ["_key", "_shft", "_ctrl", "_alt"];

_key = _this select 0;
_shft = _this select 1;
_ctrl = _this select 2;
_alt =_this select 3;

_key = _key + (
	(
		if (_shft) then {2^0} else {0}
	) + (
		if (_ctrl) then {2^1} else {0}
	) + (
		if (_alt) then {2^2} else {0}
	)
) / 10;
_key
