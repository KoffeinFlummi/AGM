// BWA3 Realism - Core
// (C) 2013 KoffeinFlummi. See LICENSE.

#define PREPROCESS(FILE) AGM_##FILE = compile preprocessFile format["\AGM_core\scripts\%1.sqf", #FILE];

AGM_Hint_lastHint = [time, 0];

PREPROCESS(Hint_displayText)

/*
// Menu
0 spawn {
  waituntil {!isnull (finddisplay 46)};
  (findDisplay 46) displayAddEventHandler ["KeyDown", "_this call AGM_Core_fnc_keyInput;"];  
};
*/

AGM_Core_Menu_Button = [];

AGM_Core_keyInput = compile preprocessFile "\AGM_core\scripts\keyInput.sqf";
AGM_Core_editKey = compile preprocessFile "\AGM_core\scripts\editKey.sqf";
AGM_Core_openMenu = compile preprocessFile "\AGM_core\scripts\openMenu.sqf";
AGM_Core_closeMenu = compile preprocessFile "\AGM_core\scripts\closeMenu.sqf";

call AGM_Core_fnc_setKeyDefault;
