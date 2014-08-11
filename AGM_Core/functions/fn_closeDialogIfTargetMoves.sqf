// by commy2

_this spawn {
	_target = _this select 0;
	_ignoreDead = _this select 1;

	if (isNil "_ignoreDead") then {_ignoreDead = false};

	_position = getPosASL _target;

	waitUntil {
		if (getPosASL _target distanceSqr _position > 1 || {!alive _target && {!_ignoreDead}}) then {
			closeDialog 0;
		};
		!dialog
	};
};
