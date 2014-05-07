// by commy2

_weapon = _this select 0;

player removeItem "AGM_SpareBarrel";

[localize "STR_AGM_SwappedBarrel"] call AGM_Core_fnc_displayText;

player setVariable [format ["AGM_Overheat_%1", _weapon], [0, 0], false];
AGM_isWeaponJammed = false;
