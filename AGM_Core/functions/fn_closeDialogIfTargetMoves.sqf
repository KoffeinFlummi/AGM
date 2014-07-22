// by commy2

_this spawn {
	_target = _this select 0;

	_position = getPosASL _target;

	waitUntil {
		if (getPosASL _target distanceSqr _position > 1) then {
			closeDialog 0;
		};
		!dialog
	};
};
