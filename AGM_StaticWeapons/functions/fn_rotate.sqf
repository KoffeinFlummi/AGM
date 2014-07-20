// by commy2

player playActionNow "PutDown";

_this spawn {
	_vehicle = _this select 0;
	_isClockwise = _this select 1;

	sleep 1;

	_angle = getDir _vehicle + ([-22.5, 22.5] select _isClockwise);

	[[_vehicle, _angle], "{_vehicle = _this select 0; _angle = _this select 1; _vehicle setDir _angle; _vehicle setVectorUp (surfaceNormal getPosASL _vehicle)}", _vehicle] call AGM_Core_fnc_execRemoteFnc;
};
