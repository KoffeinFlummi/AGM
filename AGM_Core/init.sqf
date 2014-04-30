// BWA3 Realism - Core
// (C) 2013 KoffeinFlummi. See LICENSE.

AGM_Core_Menu_Button = [];

AGM_Core_keyInput = compile preprocessFileLineNumbers "\AGM_core\scripts\keyInput.sqf";
AGM_Core_editKey = compile preprocessFileLineNumbers "\AGM_core\scripts\editKey.sqf";
AGM_Core_openMenu = compile preprocessFileLineNumbers "\AGM_core\scripts\openMenu.sqf";
AGM_Core_closeMenu = compile preprocessFileLineNumbers "\AGM_core\scripts\closeMenu.sqf";

call AGM_Core_fnc_setKeyDefault;

call compile preprocessFileLineNumbers "\AGM_core\scripts\KeyInput\initKeys.sqf";
