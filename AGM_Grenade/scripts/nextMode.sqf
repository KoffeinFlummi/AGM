// by commy2

_mode = AGM_Grenade_Mode;

if (_mode == 4) then {
	_mode = 0;
} else {
	_mode = _mode + 1;
};

_hint = [
	"Normal throw",
	"High throw",
	"Precise throw",
	"Roll grenade",
	"Drop grenade"
] select _mode;

[_hint] call AGM_Core_fnc_displayText;

AGM_Grenade_Mode = _mode;
