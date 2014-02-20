// BWA3 Realism - Wind Simulation
// (C) 2013 KoffeinFlummi. See LICENSE.

#define BWA3_INTERVAL 0.05;

// Fired EH
BWA3_Wind_fnc_firedEH = {
  private ["_unit", "_weaponType", "_ammoType", "_round", "_coefficient", "_humidity", "_velocity", "_velocityX", "_velocityY", "_velocityZ", "_velocityNewX", "_velocityNewY", "_velocityNewZ", "_deltaTime", "_time"];

  _unit = _this select 0;
  _weaponType = _this select 1;
  _ammoType = _this select 4;
  _round = _this select 6;

  if (!local _unit) exitwith {};
  if (!isPlayer _unit) exitwith {};
  if !(_unit == player) exitwith {};
  if (_round isKindOf "GrenadeHand") exitWith {};

  _coefficient = 0.7;
  if (_round isKindOf "GrenadeCore") then {
    _coefficient = 0.2;
  };

  // HUMIDITY
  _humidity = ((fogParams select 0) + rain) / 2;
  _velocity = velocity _round;
  _velocityX = _velocity select 0;
  _velocityY = _velocity select 1;
  _velocityZ = _velocity select 2;
  _velocityNewX = _velocityX - _velocityX * _humidity * 0.2;
  _velocityNewY = _velocityY - _velocityY * _humidity * 0.2;
  _velocityNewZ = _velocityZ - _velocityZ * _humidity * 0.2;
  _round setVelocity [_velocityNewX, _velocityNewY, _velocityNewZ];

  _time = time;
  // WIND
  while {!isNull _round and alive _round} do {
    _velocity = velocity _round;
    _velocityX = _velocity select 0;
    _velocityY = _velocity select 1;
    _velocityZ = _velocity select 2;
    
    // Use actual time delay between iterations instead of set interval to account for ultra-low framerates.
    _deltaTime = time - _time;

    _velocityNewX = _velocityX + _coefficient * (wind select 0) * _deltaTime;
    _velocityNewY = _velocityY + _coefficient * (wind select 1) * _deltaTime;

    _round setVelocity [_velocityNewX, _velocityNewY, _velocityZ];

    _time = time;
    sleep BWA3_INTERVAL;
  };
  
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

    sleep 0.05;
    hint "";
  };
};