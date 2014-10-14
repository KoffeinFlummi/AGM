// by commy2

#define STARTUP_DELAY 1.3

_player = _this select 0;
_vehicle = _this select 1;
_isEngineOn = _this select 2;

if (_isEngineOn && {_player == driver _vehicle} && {speed _vehicle == 0}) then {
	[_vehicle] spawn {
		_vehicle = _this select 0;

		_direction = [vectorDir _vehicle, vectorUp _vehicle];

		_time = time + STARTUP_DELAY;
		waitUntil {
			_vehicle setVelocity [0, 0, 0];
			_vehicle setVectorDirAndUp _direction;
			time > _time
		};
	};
};
