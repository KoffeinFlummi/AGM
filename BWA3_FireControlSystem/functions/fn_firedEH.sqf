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

if (player != gunner _unit) exitWith {};
if !(_magazineType in (_unit getVariable "BWA3_FCSMagazines")) exitWith {};

// get offset
/*
_FCSMagazines = _unit getVariable "BWA3_FCSMagazines";
for "_i" from 0 to (count _FCSMagazines - 1) do {
  if (_FCSMagazines select _i == _magazineType) exitWith {_offset = (_unit getVariable "BWA3_FCSElevation") select _i;};
};
*/
_offset = (_unit getVariable "BWA3_FCSElevation") select 0;

_direction = vectorDir _round;
_azimuth = (_direction select 0) atan2 (_direction select 1) + (_unit getVariable "BWA3_FCSAzimuth");
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