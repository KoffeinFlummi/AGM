/*
 * Author: KoffeinFlummi
 *
 * Calculates the angle offset necessary to hit the current target.
 *
 * Arguments:
 * 0: distance to target in meters
 * 1: current angle of the turret
 * 2: maximum elevation of the turret
 * 3: initSpeed of the projectile
 * 4: airFriction of the projectile
 * 5: maximum timeToLive of the projectile
 * 6: simulationStep of the projectile
 * 
 * Return Value:
 * offset from the current angle necessary to hit the target
 */

private ["_distance","_angleTarget","_maxElev","_initSpeed","_airFriction","_timeToLive","_timeToLive","_simulationStep","_angle","_posTargetX","_posTargetY","_posX","_posY","_velocityX","_velocityY","_velocityMagnitude"];

_distance       = _this select 0;
_angleTarget    = _this select 1;
_maxElev        = _this select 2;
_initSpeed      = _this select 3;
_airFriction    = _this select 4;
_timeToLive     = _this select 5;
_simulationStep = _this select 6;

if (_simulationStep == 0) exitWith {_angleTarget};
_angle = _angleTarget;

// get relative position of target in 2D plane
_posTargetX = (cos _angleTarget) * _distance;
_posTargetY = (sin _angleTarget) * _distance;

/*
while {_angle <= _maxElev} do {
  _posX = 0;
  _posY = 0;
  _velocityX = (cos _angle) * _initSpeed;
  _velocityY = (sin _angle) * _initSpeed;

  // trace the path of the bullet
  for "_i" from 1 to ((floor (_timeToLive / _simulationStep)) + 1) do {
    _posX = _posX + _velocityX * _simulationStep;
    _posY = _posY + _velocityY * _simulationStep;
    if (_posX >= _posTargetX) exitWith {}; // bullet passed the target
    _velocityMagnitude = sqrt (_velocityX^2 + _velocityY^2);
    _velocityX = _velocityX + _velocityX * _velocityMagnitude * _airFriction * _simulationStep;
    _velocityY = _velocityY + _velocityY * _velocityMagnitude * _airFriction * _simulationStep - 9.81 * _simulationStep;
  };

  if (_posX >= _posTargetX and _posY >= _posTargetY) exitWith {};
  _angle = _angle + 0.05;
};
*/
_min = _angle;
_max = _maxElev;
while {true} do {
  
  _posX = 0;
  _posY = 0;
  _velocityX = (cos _angle) * _initSpeed;
  _velocityY = (sin _angle) * _initSpeed;

  // trace the path of the bullet
  for "_i" from 1 to ((floor (_timeToLive / _simulationStep)) + 1) do {
    _posX = _posX + _velocityX * _simulationStep;
    _posY = _posY + _velocityY * _simulationStep;
    if (_posX >= _posTargetX) exitWith {}; // bullet passed the target
    _velocityMagnitude = sqrt (_velocityX^2 + _velocityY^2);
    _velocityX = _velocityX + _velocityX * _velocityMagnitude * _airFriction * _simulationStep;
    _velocityY = _velocityY + _velocityY * _velocityMagnitude * _airFriction * _simulationStep - 9.81 * _simulationStep;
  };

  if (_posX >= _posTargetX and _posY >= _posTargetY) exitWith {};
  _angle = _angle + 0.005;
};

_angle - _angleTarget