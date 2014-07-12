// by CAA-Picard

if !(hasInterface) exitWith {};

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