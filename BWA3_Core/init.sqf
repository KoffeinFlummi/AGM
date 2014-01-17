// BWA3 Realism - Core
// (C) 2013 KoffeinFlummi. See LICENSE.


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
      setWind ((BWA3_Weather select 1) + [false]);
      0 setFog (BWA3_Weather select 2);
      0 setOvercast (BWA3_Weather select 3);
      0 setRain (BWA3_Weather select 4);
    };
    sleep 300;
  }
}