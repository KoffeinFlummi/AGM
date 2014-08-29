// by commy2

_mode = AGM_Grenades_Mode;

if (_mode == 4) then {
  _mode = 0;
} else {
  _mode = _mode + 1;
};

// ROLL GRENADE DOESN'T WORK RIGHT NOW
if (_mode == 3) then {
  _mode = 4;
};

_hint = [
  localize "STR_AGM_Grenades_NormalThrow",
  localize "STR_AGM_Grenades_HighThrow",
  localize "STR_AGM_Grenades_PreciseThrow",
  localize "STR_AGM_Grenades_RollGrenade",
  localize "STR_AGM_Grenades_DropGrenade"
] select _mode;

[_hint] call AGM_Core_fnc_displayTextStructured;

AGM_Grenades_Mode = _mode;
