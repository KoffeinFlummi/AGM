/*
 * Author: KoffeinFlummi
 *
 * Adjusts the direction of a shell.
 *
 * Arguments:
 * -> arguments of the FiredBIS EH
 *
 * Return Value:
 * None
 */
_unit = _this select 0;
_weaponType = _this select 1;
_ammoType = _this select 4;
_magazineType = _this select 5;
_round = _this select 6;

_FCSMagazines = _unit getVariable "AGM_FCSMagazines";
_FCSElevation = _unit getVariable "AGM_FCSElevation";

if (player != gunner _unit) exitWith {};
if !(_magazineType in _FCSMagazines) exitWith {};

// GET ELEVATION OFFSET OF CURRENT MAGAZINE
_offset = 0;
{
  if (_x == _magazineType) exitWith {
    _offset = _FCSElevation select _forEachIndex;
  };
} forEach _FCSMagazines;

_direction = vectorDir _round;
_azimuth = (_direction select 0) atan2 (_direction select 1) + (_unit getVariable "AGM_FCSAzimuth");
_altitude = sqrt ((_direction select 1) ^ 2 + (_direction select 0) ^ 2) atan2 - (_direction select 2) + _offset;

_direction = [
  sin _azimuth * sin _altitude,
  cos _azimuth * sin _altitude,
  - cos _altitude
];

_velocity = velocity _round;
_velocity = sqrt ((_velocity select 0) ^ 2 + (_velocity select 1) ^ 2 + (_velocity select 2) ^ 2);
_velocity = [(_direction select 0) * _velocity, (_direction select 1) * _velocity, (_direction select 2) * _velocity];

_round setVectorDirAndUp [
  _direction,
  [
    (_direction select 0) * (_direction select 2) / sqrt ((_direction select 0) ^ 2 + (_direction select 1) ^ 2),
    (_direction select 1) * (_direction select 2) / sqrt ((_direction select 0) ^ 2 + (_direction select 1) ^ 2),
    sqrt ((_direction select 0) ^ 2 + (_direction select 1) ^ 2)
  ]
];
_round setPosASL (getPosASL _round);
_round setVelocity _velocity;