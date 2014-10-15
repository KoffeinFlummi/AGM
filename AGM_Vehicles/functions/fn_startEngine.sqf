// by commy2

#define STARTUP_DELAY 1.3

_vehicle = _this select 0;
_isEngineOn = _this select 1;

if (_isEngineOn && {call AGM_Core_fnc_player == driver _vehicle} && {speed _vehicle == 0}) then {
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
