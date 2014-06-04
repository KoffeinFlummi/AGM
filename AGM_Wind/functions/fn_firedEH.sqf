private ["_unit", "_weaponType", "_ammoType", "_round", "_coefficient", "_velocity", "_velocityX", "_velocityY", "_velocityZ", "_velocityNewX", "_velocityNewY", "_velocityNewZ", "_deltaTime", "_time"];

_unit = _this select 0;
_weaponType = _this select 1;
_ammoType = _this select 4;
_round = _this select 5;

if (!local _unit) exitwith {};
if (!isPlayer _unit) exitwith {};
if !(_unit == player) exitwith {};
if (_round isKindOf "GrenadeHand") exitWith {};

_coefficient = 0.7;
if (_round isKindOf "GrenadeCore") then {
  _coefficient = 0.2;
};
if (_round isKindOf "RocketCore") then {
  _coefficient = 0.35;
};

// HUMIDITY
_velocity = velocity _round;
_velocityX = _velocity select 0;
_velocityY = _velocity select 1;
_velocityZ = _velocity select 2;
_velocityNewX = _velocityX - _velocityX * humidity * 0.2;
_velocityNewY = _velocityY - _velocityY * humidity * 0.2;
_velocityNewZ = _velocityZ - _velocityZ * humidity * 0.2;
_round setVelocity [_velocityNewX, _velocityNewY, _velocityNewZ];

// WIND
_time = time;
while {!isNull _round and alive _round} do {
  _velocity = velocity _round;
  _velocityX = _velocity select 0;
  _velocityY = _velocity select 1;
  _velocityZ = _velocity select 2;
  
  // Use actual time delay between iterations instead of a set interval to account for ultra-low framerates.
  _deltaTime = time - _time;

  _velocityNewX = _velocityX + _coefficient * (wind select 0) * _deltaTime;
  _velocityNewY = _velocityY + _coefficient * (wind select 1) * _deltaTime;

  _round setVelocity [_velocityNewX, _velocityNewY, _velocityZ];

  _time = time;
  sleep 0.05;
};