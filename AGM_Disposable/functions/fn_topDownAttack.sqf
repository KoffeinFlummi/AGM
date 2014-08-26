// by commy2

if (isNil "AGM_Debug" || {AGM_Debug != "TOPDOWN"}) exitWith {};

_this spawn {
	_projectile = _this select 5;

	_target = cursorTarget;

	// save values of the auto-guided  missile
	_type = typeOf _projectile;
	_position = getPosATL _projectile;
	_vector = [vectorDir _projectile, vectorUp _projectile];
	_velocity = velocity _projectile;

	deleteVehicle _projectile;

	// create new non-guided missile
	_projectile = createVehicle [_type, _position, [], 0, "FLY"];
	_projectile setVectorDirAndUp _vector;
	_projectile setVelocity _velocity;

	// common functions
	_fnc_getHeight = compile format ["(getPosASL _this select 2) - %1", getPosASL _projectile select 2];
	_fnc_getPitch = {asin (vectorDir _this select 2)};
	_fnc_getVectorUp = {
		private ["_l", "_r"];

		_l = sqrt ((_this select 0) ^ 2 + (_this select 1) ^ 2);
		_r = -(_this select 2) / _l;

		[
			(_this select 0) * _r,
			(_this select 1) * _r,
			_l
		]
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

	_projectile setVectorDirAndUp [
		_vector,
		_vector call _fnc_getVectorUp
	];
	_projectile setVelocity _vector vectorMultiply vectorMagnitude velocity _projectile;

	// missile reached travel hight, change direction again
	waitUntil {!alive _projectile || {_projectile call _fnc_getHeight > 150}};

	_vector = vectorDir _projectile;
	_vector set [2, 0];
	_vector = vectorNormalized _vector;

	_projectile setVectorDirAndUp [
		_vector,
		_vector call _fnc_getVectorUp
	];
	_projectile setVelocity _vector vectorMultiply vectorMagnitude velocity _projectile;

	// loop to stay in travel hight and correct altitude, @todo add correction for moving targets later
	_time = time;
	while {
		alive _projectile
		&& {_projectile distance _target > 500}
	} do {
		_height = _projectile call _fnc_getHeight;
		_pitch = _projectile call _fnc_getPitch;

		_dir = 0;
		_up = if (abs (150 - _height) < 1) then {-_pitch min 10 max -10} else {
			([-20, 20] select (_height < 150)) * (time - _time);
		};

		[_projectile, _dir, _up] call AGM_Core_fnc_changeProjectileDirection;

		systemChat str (_projectile distance _target);

		_time = time;
		sleep 0.05;
	};

	// missile missed target or hit a bird or something
	if (!alive _projectile) exitWith {};

	// target vehicle, @todo add correction for moving targets later
	_vector = getPosASL _projectile vectorFromTo getPosASL _target;

	_projectile setVectorDirAndUp [
		_vector,
		_vector call _fnc_getVectorUp
	];
	_projectile setVelocity _vector vectorMultiply vectorMagnitude velocity _projectile;

};
