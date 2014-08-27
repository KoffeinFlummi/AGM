// by commy2

if (isNil "AGM_Debug" || {AGM_Debug != "TOPDOWN"}) exitWith {};

_this spawn {
	_projectile = _this select 5;

	_target = cursorTarget;

	// save values of the auto-guided  missile
	_type = typeOf _projectile;
	_position = position _projectile;
	_vector = [vectorDir _projectile, vectorUp _projectile];
	_velocity = velocity _projectile;

	deleteVehicle _projectile;

	// create new non-guided missile
	_projectile = createVehicle [_type, _position, [], 0, "FLY"];
	_projectile setVectorDirAndUp _vector;
	_projectile setVelocity _velocity;

	// common functions
	_heightStart = getPosASL _projectile select 2;
	_fnc_getHeight = {(getPosASL _this select 2) - _heightStart};

	_fnc_getPitch = {asin (vectorDir _this select 2)};

	_fnc_getHorizontalDistance = {
		private "_v";

		_v = getPosASL (_this select 0) vectorDiff getPosASL (_this select 1);

		sqrt ((_v select 0) ^ 2 + (_v select 1) ^ 2)
	};

	_fnc_getDirTo = {
		private "_v";

		_v = getPosASL (_this select 0) vectorFromTo getPosASL (_this select 1);

		(_v select 0) atan2 (_v select 1)
	};

	_getPitchTo = {
		private "_v";

		_v = getPosASL (_this select 0) vectorFromTo getPosASL (_this select 1);

		asin (_v select 2)
	};

	_fnc_changeMissileDirection = {
		private ["_projectile", "_v", "_l", "_r"];

		_projectile = _this select 0;
		_v = _this select 1;

		_l = sqrt ((_v select 0) ^ 2 + (_v select 1) ^ 2);
		_r = -(_v select 2) / _l;

		_projectile setVectorDirAndUp [
			_v,
			[
				(_v select 0) * _r,
				(_v select 1) * _r,
				_l
			]
		];
		_projectile setVelocity _v vectorMultiply vectorMagnitude velocity _projectile;
	};

	// init phase
	sleep 0.5;

	// targeting sets cursorTarget to objNull after firing for a short amount of time, @todo better fix later
	if (isNull _target) then {
		_target = cursorTarget;
	};

	// premature explosion
	if (!alive _projectile) exitWith {};

	// get in travel hight phase, abrupt direction change
	_vector = vectorDir _projectile;
	_vector set [2, 2];
	_vector = vectorNormalized _vector;

	[_projectile, _vector] call _fnc_changeMissileDirection;

	// missile reached travel height, change direction again
	waitUntil {!alive _projectile || {_projectile call _fnc_getHeight > 150}};

	// premature explosion2
	if (!alive _projectile) exitWith {};

	_vector = vectorDir _projectile;
	_vector set [2, 0];
	_vector = vectorNormalized _vector;

	[_projectile, _vector] call _fnc_changeMissileDirection;

	// loop to stay in travel height and correct altitude
	_time = time;
	while {
		alive _projectile
		&& {[_projectile, _target] call _fnc_getHorizontalDistance > 100}
	} do {
		_height = _projectile call _fnc_getHeight;
		_pitch = _projectile call _fnc_getPitch;

		_dir = ([_projectile, _target] call _fnc_getDirTo) - direction _projectile;
		_up = if (abs (150 - _height) < 1) then {-_pitch min 10 max -10} else {
			([-20, 20] select (_height < 150)) * (time - _time);
		};

		[_projectile, _dir, _up] call AGM_Core_fnc_changeProjectileDirection;

		_time = time;
		sleep 0.05;
	};

	// missile missed target or hit a bird or something
	if (!alive _projectile) exitWith {};

	// allah ackbar, motherufcker
	while {
		alive _projectile
	} do {
		_height = _projectile call _fnc_getHeight;
		_pitch = _projectile call _fnc_getPitch;

		_dir = ([_projectile, _target] call _fnc_getDirTo) - direction _projectile;
		_up = ([_projectile, _target] call _getPitchTo) - (_projectile call _fnc_getPitch);

		[_projectile, _dir, _up] call AGM_Core_fnc_changeProjectileDirection;

		_time = time;
		sleep 0.05;
	};
};
