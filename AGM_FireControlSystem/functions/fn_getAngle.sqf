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

#define PRECISION 0.1

private ["_distance","_angleTarget","_maxElev","_initSpeed","_airFriction","_timeToLive","_timeToLive","_simulationStep","_angle","_posTargetX","_posTargetY","_posX","_posY","_velocityX","_velocityY","_velocityMagnitude"];

_distance       = _this select 0;
_angleTarget    = _this select 1;
_maxElev        = _this select 2;
_initSpeed      = _this select 3;
_airFriction    = _this select 4;
_timeToLive     = _this select 5;
_simulationStep = _this select 6;

if (_simulationStep == 0) exitWith {_angleTarget};

AGM_FCS_traceBullet = {
  private ["_distance", "_angleTarget", "_maxElev", "_initSpeed", "_airFriction", "_timeToLive", "_simulationStep", "_angle", "_posTargetX", "_posTargetY", "_posX", "_posY", "_velocityX", "_velocityY", "_velocityMagnitude"];

  _distance       = _this select 0;
  _angleTarget    = _this select 1;
  _maxElev        = _this select 2;
  _initSpeed      = _this select 3;
  _airFriction    = _this select 4;
  _timeToLive     = _this select 5;
  _simulationStep = _this select 6;
  _angle          = _this select 7;

  _angle = _angle - _angleTarget;
  _angleTarget = 0;

  _posTargetX = (cos _angleTarget) * _distance;
  _posTargetY = (sin _angleTarget) * _distance;

  _posX = 0;
  _posY = 0;

  _velocityX = (cos _angle) * _initSpeed;
  _velocityY = (sin _angle) * _initSpeed;

  // trace the path of the bullet
  for "_i" from 1 to ((floor (_timeToLive / _simulationStep)) + 1) do {
    _velocityMagnitude = sqrt (_velocityX^2 + _velocityY^2);
    _velocityX = _velocityX + _simulationStep * (_velocityX * _velocityMagnitude * _airFriction);
    _velocityY = _velocityY + _simulationStep * (_velocityY * _velocityMagnitude * _airFriction - 9.81);
    _posX = _posX + _velocityX * _simulationStep;
    _posY = _posY + _velocityY * _simulationStep;
    if (_posX >= _posTargetX) exitWith {}; // bullet passed the target
  };


  _posY - _posTargetY
};

if ((_this + [_maxElev]) call AGM_FCS_traceBullet < 0) exitWith {_maxElev - _angleTarget};
  
// Newton Method / Secand Method
_angle1 = _angleTarget;
_angle2 = _maxElev;
_it2 = 0;
_f1 = (_this + [_angle1]) call AGM_FCS_traceBullet;

while {(abs _f1) > PRECISION} do {
  _f2 = (_this + [_angle2]) call AGM_FCS_traceBullet;
  _temp = _angle2-_f2*(_angle2-_angle1)/(_f2-_f1);
  _angle1 = _angle2;
  _angle2 = _temp;
  _f1 = _f2;
  _it2 = _it2+1;
};
//player globalChat format ["it1: %1 | _angle1: %2 | it2: %3 | _angle2: %4",_it1, _angle-_angleTarget, _it2, _angle2-_angleTarget];

_angle=_angle2;
_angle - _angleTarget
