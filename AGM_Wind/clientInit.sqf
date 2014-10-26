// by CAA-Picard

if !(hasInterface) exitWith {};

// Kestrel Stuff
AGM_isKestrel = false;
AGM_isKestrelWheel = false;

0 spawn {
  waitUntil {preloadTitleRsc ["AGM_Kestrel", "PLAIN"]};
  waitUntil {preloadTitleRsc ["AGM_KestrelWheel", "PLAIN"]};
  waitUntil {preloadTitleRsc ["AGM_KestrelWheel_Preload", "PLAIN"]};
};

// Air temperature and air density
if (isNumber (configFile >> "CfgWorlds" >> worldName >> "AGM_TempMeanJan")) then {
  AGM_TempMeanJan = getNumber (configFile >> "CfgWorlds" >> worldName >> "AGM_TempMeanJan");
  AGM_TempMeanJul = getNumber (configFile >> "CfgWorlds" >> worldName >> "AGM_TempMeanJul");
  AGM_TempAmplitudeJan = getNumber (configFile >> "CfgWorlds" >> worldName >> "AGM_TempAmplitudeJan");
  AGM_TempAmplitudeJul = getNumber (configFile >> "CfgWorlds" >> worldName >> "AGM_TempAmplitudeJul");
} else {
  _lat = - getNumber (configFile >> "CfgWorlds" >> worldName >> "latitude");
  if (_lat == 0) then {_lat = 0.1;};
  _yearlyTempMean = 28 min (28 - (abs(_lat) - 23.5) * (3.14159/180) * 6371 / 145);
  AGM_TempMeanJan = _yearlyTempMean - _lat / abs(_lat) * ((abs(_lat) max 25) - 25) * 30 / 65;
  AGM_TempMeanJul = _yearlyTempMean + _lat / abs(_lat) * ((abs(_lat) max 25) - 25) * 30 / 65;
  AGM_TempAmplitudeJan = 10;
  AGM_TempAmplitudeJul = 10;
};

0 spawn {
  while {true} do {
    _annualCoef = 0.5 - 0.5 * cos(360 * dateToNumber date);
    _dailyTempMean =      AGM_TempMeanJan      * (1 - _annualCoef) + AGM_TempMeanJul      * _annualCoef;
    _dailyTempAmplitude = AGM_TempAmplitudeJan * (1 - _annualCoef) + AGM_TempAmplitudeJul * _annualCoef;

    _hourlyCoef = -0.5 * sin(360 * ((3 + (date select 3))/24 + (date select 4)/1440));
    AGM_Wind_currentTemperature = _dailyTempMean + _hourlyCoef * _dailyTempAmplitude - 2 * humidity - 4 * overcast;
    AGM_Wind_currentRelativeDensity = (273.15 + 20) / (273.15 + AGM_Wind_currentTemperature);
    sleep 60;
  };
};

// Wind Reading
0 spawn {
  while {true} do {
    waitUntil {(inputAction "Compass" > 0 or inputAction "CompassToggle" > 0) and (vehicle player == player)};

    _windStrength = sqrt((wind select 0) ^ 2 + (wind select 1) ^ 2);

    _arrowRscString = "";
    _strengthString = "";
    _colorString = "";
    switch true do {
      case (_windStrength <= 0.5) : {_strengthString = localize "STR_AGM_Wind_NoMeasurable"; _colorString = "FFFFFF"; };
      case (_windStrength <= 3) :   {_strengthString = localize "STR_AGM_Wind_VeryLight"; _arrowRscString = "VeryLight"; _colorString = "CCFFFF";};
      case (_windStrength <= 5) :   {_strengthString = localize "STR_AGM_Wind_Light"; _arrowRscString = "Light"; _colorString = "99FF99";};
      case (_windStrength <= 7) :   {_strengthString = localize "STR_AGM_Wind_Moderate"; _arrowRscString = "Moderate"; _colorString = "99FF00";};
      default                       {_strengthString = localize "STR_AGM_Wind_Strong"; _arrowRscString = "Strong"; _colorString = "FF6600";};
    };

    if (_windStrength <= 0.5) then {
      hintSilent localize "STR_AGM_Wind_NoMeasurableWind";
    } else {
      // Only show cardinal direction of wind if player has a compass
      _items = assignedItems player;
      if ({_x == "ItemCompass"} count _items > 0) then {
        _originString = [] call AGM_Core_fnc_getWindDirection;
        hintSilent parseText format["<t color='#%1'>%2</t> %3 %4", _colorString, _strengthString, localize "STR_AGM_Wind_WindFromThe", _originString];
      };
    };

    // Draw arrow indicator
    186186 cutRsc ["AGM_Wind_Arrow", "PLAIN"];

    // Calculate relative direction between player
    #define numSectors 16
    _relAngle = windDir - (getdir (player));
    _sector = round(_relAngle / (360/numSectors)) + 1;
    if (_sector < 1) then {
      _sector = _sector + numSectors;
    };
    if (_sector > numSectors) then {
      _sector = _sector - numSectors;
    };

    // Update arrow indicator texture
    _textureName = if (_arrowRscString == "") then {
      "\AGM_Wind\ui\AGM_noWind.paa"
    } else {
      format["\AGM_Wind\ui\AGM_Wind%1-%2.paa", _arrowRscString, if (_sector < 10) then {"0"+str(_sector)} else {str(_sector)}]
    };
    ((uiNamespace getVariable "AGM_Wind_Arrow") displayCtrl 185185) ctrlSetText _textureName;

    sleep 0.1;
    //186186 cutText ["", "PLAIN"];
    hint "";
  };
};
