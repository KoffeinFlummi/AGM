// BWA3 Realism - Wind Simulation
// (C) 2013 KoffeinFlummi. See LICENSE.


// Fired EH
BWA3_Wind_fnc_firedEH = {
  private ["_unit", "_weaponType", "_ammoType", "_round", "_coefficient"];

  _unit = _this select 0;
  _weaponType = _this select 1;
  _ammoType = _this select 5;
  _round = _this select 6;

  if (!local _unit) exitwith {};
  if (!isPlayer _unit) exitwith {};
  if !(_unit == player) exitwith {};

  _coefficient = 1;
  _interval = 0.1;

  0 spawn {
    while (!isNull _projectile and alive _round) do {
      _windX = wind select 0;
      _windY = wind select 1;

      hint format["X: %1 \nY: %2",_windX,_windY];

      _velocity = velocity _round;
      _velocityX = _velocity select 0;
      _velocityY = _velocity select 1;
      _velocityZ = _velocity select 2;

      _velocityNewX = _interval * _coefficient * (_velocityX + (1/_velocityY) * _windX);
      _velocityNewY = _interval * _coefficient * (_velocityY + (1/_velocityX) * _windY);

      _round setVelocity [_velocityNewX, _velocityNewY, _velocityZ];

      sleep _interval;
    };
  };

};