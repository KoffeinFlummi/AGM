_unit = _this select 0;

// Substitute wind calculations for AI by lowering accuracy
if !(isPlayer _unit) then {
  _windStrength = sqrt((wind select 0) ^ 2 + (wind select 1) ^ 2);
  _unit setSkill ["aimingAccuracy", (_unit skill "aimingAccuracy") * (1 - _windStrength / 14)];
};

// Wind Reading
0 spawn {
  while {true} do {
    waitUntil {inputAction "Compass" > 0 or inputAction "CompassToggle" > 0};
    _windStrength = sqrt((wind select 0) ^ 2 + (wind select 1) ^ 2);

    _strengthString = "";
    _colorString = "";
    switch true do {
      case (_windStrength <= 0.5) : {_strengthString = localize "STR_AGM_Wind_NoMeasurable"; _colorString = "FFFFFF";};
      case (_windStrength <= 3) :   {_strengthString = localize "STR_AGM_Wind_VeryLight"; _colorString = "CCFFFF";};
      case (_windStrength <= 5) :   {_strengthString = localize "STR_AGM_Wind_Light"; _colorString = "99FF99";};
      case (_windStrength <= 7) :   {_strengthString = localize "STR_AGM_Wind_Moderate"; _colorString = "99FF00";};
      default                       {_strengthString = localize "STR_AGM_Wind_Strong"; _colorString = "FF6600";};
    };

    _originString = [] call AGM_Core_fnc_getWindDirection;

    if (_windStrength <= 0.5) then {
      hintSilent localize "STR_AGM_Wind_NoMeasurableWind";
    } else {
      hintSilent parseText format["<t color='#%1'>%2</t> %3 %4", _colorString, _strengthString, localize "STR_AGM_Wind_WindFromThe", _originString];
    };

    sleep 0.1;
    hint "";
  };
};