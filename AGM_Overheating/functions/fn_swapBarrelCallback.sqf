// by commy2

private "_weapon";

_weapon = _this select 0;

// don't consume the barrel, but rotate through them.
//player removeItem "AGM_SpareBarrel";

[localize "STR_AGM_Overheating_SwappedBarrel", "\AGM_Overheating\UI\spare_barrel_ca.paa"] call AGM_Core_fnc_displayTextPicture;

player setVariable [format ["AGM_Overheating_%1", _weapon], [0, 0], false];
