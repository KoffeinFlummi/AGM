// BWA3 Realism - Core
// (C) 2013 KoffeinFlummi. See LICENSE.

#define PREPROCESS(FILE) BWA3_##FILE = compile preprocessFile format["\bwa3_core\scripts\%1.sqf", #FILE];

BWA3_Hint_lastHint = [time, 0];

PREPROCESS(Hint_displayText)

// MP Synchronization
0 spawn {
  if (!isMultiplayer) exitWith {};
  while {true} do {
    if (isServer) then {
      BWA3_Weather = [date, wind, fogParams, overcast, rain];
      publicVariable "BWA3_Weather";
    } else {
      sleep 3;
      setDate (BWA3_Weather select 0);
      setWind [((BWA3_Weather select 1) select 0), ((BWA3_Weather select 1) select 1), true];
      0 setFog (BWA3_Weather select 2);
      0 setOvercast (BWA3_Weather select 3);
      0 setRain (BWA3_Weather select 4);
    };
    sleep 300;
  };
};

/*
// Menu
0 spawn {
  waituntil {!isnull (finddisplay 46)};
  (findDisplay 46) displayAddEventHandler ["KeyDown", "_this call BWA3_Core_fnc_keyInput;"];  
};
*/