// BWA3 Realism - Core
// (C) 2013 KoffeinFlummi. See LICENSE.

#define PREPROCESS(FILE) BWA3_##FILE = compile preprocessFile format["\bwa3_core\scripts\%1.sqf", #FILE];

BWA3_Hint_lastHint = [time, 0];

PREPROCESS(Hint_displayText)

if (isMultiplayer) then {
  BWA3_Weather = [];

  // SERVER
  if (isServer) then {
    0 spawn {
      while {true} do {
        BWA3_Weather = [date, wind, fogParams, overcast, rain, time mod 60];
        publicVariable "BWA3_Weather";
        sleep 60;
      };
    };
  };

  // CLIENT
  "BWA3_Weather" addPublicVariableEventHandler {
    _publicArray = _this select 1;
    setDate (_publicArray select 0);
    skipTime ((_publicArray select 5) / 3600);
    setWind [((_publicArray select 1) select 0), ((_publicArray select 1) select 1), true];
    0 setFog (_publicArray select 2);
    0 setOvercast (_publicArray select 3); // seems to be bugged ATM
    0 setRain (_publicArray select 4);
  };
};


/*
// Menu
0 spawn {
  waituntil {!isnull (finddisplay 46)};
  (findDisplay 46) displayAddEventHandler ["KeyDown", "_this call BWA3_Core_fnc_keyInput;"];  
};
*/