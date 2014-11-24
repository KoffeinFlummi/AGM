/*
 * Authors: KoffeinFlummi, esteldunedain
 *
 * Changes the bullet trajectory depending on wind, density and temperature.
 *
 * Arguments:
 * Fired EH
 *
 * Return Value:
 * none
 */

private ["_unit", "_ammoType", "_round", "_dispersion", "_additionalVel"];

_unit = _this select 0;
_ammoType = _this select 4;
_round = _this select 5;

if !(local _unit) exitWith {};
if !([_unit] call AGM_Core_fnc_isPlayer) exitWith {};
if (_round isKindOf "GrenadeHand") exitWith {};

// Additional dispersion
_dispersion = getNumber (configFile >> "CfgAmmo" >> _ammoType >> "AGM_Bullet_Dispersion");

// Powder temp effect
_additionalVel = (vectorMagnitude (velocity _round)) * ((((AGM_Wind_currentTemperature + 273.13) / 288.13 - 1) / 2.5 + 1 ) - 1);

[_round, ((random 2) - 1) * _dispersion, ((random 2) - 1) * _dispersion, _additionalVel] call AGM_Core_fnc_changeProjectileDirection;

_this spawn {
  _unit = _this select 0;
  _weaponType = _this select 1;
  _ammoType = _this select 4;
  _round = _this select 5;

  _airFriction = getNumber (configFile >> "CfgAmmo" >> _ammoType >> "airFriction");
  _airFrictionWind = - _airFriction;

  _simulation = getText (configFile >> "CfgAmmo" >> _ammoType >> "simulation");
  if (_airFriction > 0 || {_simulation == "shotMissile"} || {_simulation == "shotRocket"}) then {
    // Do not correct for airDensity y airFriction is not logical on the first place
    _airFriction = 0;
    _airFrictionWind = 0.0007;
  };

  // WIND
  _time = time;
  while {!isNull _round and alive _round} do {
    // Use actual time delay between iterations instead of a set interval to account for ultra-low framerates.
    _deltaTime = time - _time;

    // See https://github.com/KoffeinFlummi/AGM/issues/996
    _velocity = velocity _round;
    _velocityNew = _velocity vectorAdd (_velocity vectorMultiply (vectorMagnitude _velocity * (AGM_Wind_currentRelativeDensity - 1) * _airFriction * _deltaTime))
                             vectorAdd (wind vectorMultiply (vectorMagnitude (_velocity vectorAdd wind) * AGM_Wind_currentRelativeDensity * _airFrictionWind * _deltaTime));

    _round setVelocity _velocityNew;

    _time = time;
    sleep 0.05;
  };
};
