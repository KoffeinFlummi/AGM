// by commy2

_reloadAction = getText (configFile >> "CfgWeapons" >> currentWeapon player >> "reloadAction");

player playActionNow _reloadAction;

["Weapon unjammed"] call AGM_Core_fnc_displayText;

AGM_isWeaponJammed = false;
