// by commy2

player playActionNow "PutDown";

_this spawn {
	_vehicle = _this select 0;
	_isClockwise = _this select 1;

	sleep 1;

	_vehicle setDir getDir _vehicle + ([-22.5, 22.5] select _isClockwise);
};
