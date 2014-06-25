// by commy2

_weapon = _this select 1;
_projectile = _this select 5;

if (_weapon != "Throw") exitWith {};
if (AGM_Grenades_Mode == 0) exitWith {};

_velocity = velocity _projectile;
_velocityX = _velocity select 0;
_velocityY = _velocity select 1;
_velocityZ = _velocity select 2;

switch (AGM_Grenades_Mode) do {
	//high throw
	case 1 : {
		_velocity = [
			0.5 * _velocityX,
			0.5 * _velocityY,
			[0, 0, 0] distance [0.5 * _velocityX, 0.5 * _velocityY, 0.5 * _velocityZ]
		];
	};
	//precise throw
	case 2 : {
		_position = positionCameraToWorld [0,0,0];
		_direction = _position vectorAdd (player weaponDirection _weapon);

		_speed = speed _projectile / 3.6;

		_velocity = [
			_speed * ((_direction select 0) - (_position select 0)),
			_speed * ((_direction select 1) - (_position select 1)),
			_speed * ((_direction select 2) - (_position select 2))
		];
	};
	//roll grande
	case 3 : {
		_direction = [_weapon] call AGM_Core_fnc_getTargetAzimuthAndInclinationWeapon select 0;

		_speed = speed _projectile / 3.6;

		_velocity = [
			_speed * sin _direction,
			_speed * cos _direction,
			- _speed
		];
	};
	//drop grenade
	case 4 : {
		_velocity = [0, 0, 0];
	};
};

_projectile setVelocity _velocity;
