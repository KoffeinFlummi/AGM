// by commy2

_reloadAction = getText (configFile >> "CfgWeapons" >> currentWeapon player >> "reloadAction");

player playActionNow _reloadAction;

[localize "STR_AGM_WeaponUnjammed"] call AGM_Core_fnc_displayText;

AGM_isWeaponJammed = false;
