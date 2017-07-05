/*
Name: AGM_Artillery_fnc_firedEH

Author: Pabst Mirror (based on AGM_Wind_fnc_firedEH by KoffeinFlummi, esteldunedain)

Description:
  Wind/Submunitions Handling

Parameters: (normal BIS "Fired" EH stuff)
  0: OBJECT - Mortar Vehicle
  4: STRING - Ammo classname
  6: OBJECT - The shell object

Returns:
  None

Example:
  called from Extended_FiredBIS_EventHandlers
*/

private ["_ammoType", "_round", "_dispersion", "_additionalVel"];

// _unit = _this select 0;
_ammoType = _this select 4;
_round = _this select 6;

// Additional dispersion
_dispersion = 0;   //getNumber (configFile >> "CfgAmmo" >> _ammoType >> "AGM_Bullet_Dispersion");

// Powder temp effect
_additionalVel = (vectorMagnitude (velocity _round)) * ((((AGM_Wind_currentTemperature + 273.13) / 288.13 - 1) / 2.5 + 1 ) - 1);

// systemChat format ["debug: %1 vel[%2] disp[%3] add[%4]", _ammoType, (vectorMagnitude (velocity _round)), _dispersion, _additionalVel];

[_round, ((random 2) - 1) * _dispersion, ((random 2) - 1) * _dispersion, _additionalVel] call AGM_Core_fnc_changeProjectileDirection;

_this spawn {
  private ["_ammoType", "_round", "_airFriction", "_carryAmmo", "_carryEjectHeight", "_markerStringName", "_time", "_deltaTime", "_velocity", "_aparentWind", "_changeInVelocity", "_velocityNew", "_predictedPos", "_linConversion", "_actualEjectPos", "_boom"];

  _ammoType = _this select 4;
  _round = _this select 6;

  _airFriction = getNumber (configFile >> "CfgAmmo" >> _ammoType >> "AGM_Artillery_realAirFriction");
  _carryAmmo = getText (configFile >> "CfgAmmo" >> _ammoType >> "AGM_Artillery_carryAmmo");
  _carryEjectHeight = getNumber (configFile >> "CfgAmmo" >> _ammoType >> "AGM_Artillery_carryEjectHeight");

  //debug marker
  _markerStringName = format ["test%1", _round];
  createMarker [_markerStringName, [0,0,0]];
  _markerStringName setMarkerType "mil_dot";
  _markerStringName setMarkerText str time;

  _time = time;
  sleep 0.05;
  while {(!isNull _round) && (alive _round)} do {
    _markerStringName setMarkerPos position _round;//debug marker

    _deltaTime = time - _time;  // Use actual time delay between iterations instead of a set interval to account for ultra-low framerates.
    _velocity = velocity _round;
    _aparentWind = wind vectorDiff _velocity;

    _changeInVelocity = _aparentWind vectorMultiply ((vectorMagnitude _aparentWind) * AGM_Wind_currentRelativeDensity * -1 * _airFriction * _deltaTime);

    // hintSilent format ["Change\n%1", _changeInVelocity vectorMultiply (1/(_deltaTime max 0.000001))];

    _velocityNew = _velocity vectorAdd _changeInVelocity;
    _round setVelocity _velocityNew;

    if ((_carryAmmo != "") && ((_velocityNew select 2) < 1)) then {  //hasSubmunition and after reaching max height (starting downward velocity)
      _predictedPos = (getPos _round) vectorAdd (_velocityNew vectorMultiply _deltaTime);  //see where it will be next frame
      if ((_predictedPos select 2) < _carryEjectHeight) then {
        //Calc the actual postion at the given height (Linear interpolation)
        _linConversion = linearConversion [((getPos _round) select 2), (_predictedPos select 2), _carryEjectHeight, 0, _deltaTime, true];
        _actualEjectPos = (getPos _round) vectorAdd (_velocityNew vectorMultiply _linConversion);
        _boom = _carryAmmo createVehicle _actualEjectPos;
        _boom setPos _actualEjectPos;
        _carryAmmo = "";
      };
    };
    _time = time;
    sleep 0.05;
  };
};
