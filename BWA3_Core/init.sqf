// BWA3 Realism - Core
// (C) 2013 KoffeinFlummi. See LICENSE.

#define PREPROCESS(FILE) BWA3_##FILE = compile preprocessFile format["\bwa3_core\scripts\%1.sqf", #FILE];

BWA3_Hint_lastHint = [time, 0];

PREPROCESS(Hint_displayText)

/*
// Menu
0 spawn {
  waituntil {!isnull (finddisplay 46)};
  (findDisplay 46) displayAddEventHandler ["KeyDown", "_this call BWA3_Core_fnc_keyInput;"];  
};
*/