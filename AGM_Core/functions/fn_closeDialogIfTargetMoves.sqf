// by commy2

_this spawn {
	_target = _this select 0;

	_position = getPosATL _target;
	if (surfaceIsWater _position) then {
		_position = getPosASL _target;
	};

	waitUntil {
		if (_target distanceSqr _position > 1) then {
			closeDialog 0;
		};
		!dialog
	};
};
