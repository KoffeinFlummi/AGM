// BWA3 Realism - Wind Simulation
// (C) 2013 KoffeinFlummi. See LICENSE.


// Fired EH
BWA3_Wind_fnc_firedEH = {
  _unit = _this select 0;
  _weaponType = _this select 1;
  _ammoType = _this select 5;
  _round = _this select 6;

  if (!local _unit) exitwith {};
  if (!isPlayer _unit) exitwith {};
  if !(_unit == player) exitwith {};

  _coefficient = 1;
  _interval = 0.01;
  _oldtime = time;

  while {!isNull _round and alive _round} do {
    _windX = wind select 0;
    _windY = wind select 1;

    _velocity = velocity _round;
    _velocityX = _velocity select 0;
    _velocityY = _velocity select 1;
    _velocityZ = _velocity select 2;
    
    // Use actual time delay between iterations instead of sleep to account for ultra-low framerates.
    _newtime = time;
    _deltaTime = _newtime - _oldtime;

    _velocityNewX = _velocityX + _windX * _coefficient * _deltaTime;
    _velocityNewY = _velocityY + _windY * _coefficient * _deltaTime;

    _round setVelocity [_velocityNewX, _velocityNewY, _velocityZ];

    _oldtime = time;
    sleep _interval;
  };
  
};