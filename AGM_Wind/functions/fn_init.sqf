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
    _windOrigin = (windDir + 180) % 360;

    _strengthString = "";
    _colorString = "";
    switch true do {
      case (_windStrength <= 0.5) : {_strengthString = "No measurable"; _colorString = "FFFFFF";};
      case (_windStrength <= 3) :   {_strengthString = "Very light"; _colorString = "CCFFFF";};
      case (_windStrength <= 5) :   {_strengthString = "Light"; _colorString = "99FF99";};
      case (_windStrength <= 7) :   {_strengthString = "Moderate"; _colorString = "99FF00";};
      default                       {_strengthString = "Strong"; _colorString = "FF6600";};
    };

    _originString = ["N", "NE", "E", "SE", "S", "SW", "W", "NW"] select (round (_windOrigin / 45) % 8);

    if (_windStrength <= 0.5) then {
      hintSilent "No measurable wind";
    } else {
      hintSilent parseText format["<t color='#%1'>%2</t> wind from the %3", _colorString, _strengthString, _originString];
    };

    sleep 0.1;
    hint "";
  };
};