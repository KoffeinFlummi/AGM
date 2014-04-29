// by commy2

_vehicle = _this select 0;

_maxSpeed = speed _vehicle;
if (_maxSpeed < 10) then {_maxSpeed = 10};

waitUntil {
	_speed = speed _vehicle;
	if (_speed > _maxSpeed) then {
		_velocity = velocity _vehicle;
		_vehicle setVelocity [
			(_velocity select 0) * _maxSpeed / _speed,
			(_velocity select 1) * _maxSpeed / _speed,
			(_velocity select 2) * _maxSpeed / _speed
		];
	};
	!AGM_isSpeedLimiter || {player != driver _vehicle}
};
AGM_isSpeedLimiter = false;
