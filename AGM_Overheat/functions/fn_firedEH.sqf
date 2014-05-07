// by commy2

#define THRESHOLD_1 0.5
#define THRESHOLD_2 0.8
#define THRESHOLD_3 1.0

_unit = _this select 0;
_weapon = _this select 1;
_projectile = _this select 5;

_increment = getNumber (configFile >> "CfgWeapons" >> _weapon >> "AGM_Overheat_Increment");
_cooldown = getNumber (configFile >> "CfgWeapons" >> _weapon >> "AGM_Overheat_Cooldown");

if (_increment == 0) exitWith {};

_string = format ["AGM_Overheat_%1", _weapon];

_overheat = player getVariable [_string, [0, 0]];
_temperature = _overheat select 0;
_time = _overheat select 1;

_temperature = _temperature + _increment - _cooldown * (time - _time) max _increment;

if (AGM_Debug) then {
	hintSilent format ["Temperature: %1%\nTime: %2s\nIncrement: %3\nCooldown: %4", _temperature * 100, time - _time, _increment, _cooldown];
};

_time = time;

player setVariable [_string, [_temperature, _time], false];

if (_temperature > THRESHOLD_1) then {
	_velocity = velocity _projectile;
	_velocityX = _velocity select 0;
	_velocityY = _velocity select 1;
	_velocityZ = _velocity select 2;

	_dispersion = getNumber (configFile >> "CfgWeapons" >> _weapon >> "AGM_Overheat_Dispersion");
	_random = _dispersion * (_temperature - THRESHOLD_1);

	_projectile setVelocity [
		_velocityX * (1 - _random + 2 * random _random),
		_velocityY * (1 - _random + 2 * random _random),
		_velocityZ * (1 - _random + 2 * random _random)
	];

	if (_temperature > THRESHOLD_2) then {
		_intensity = (_temperature - THRESHOLD_2) * 0.05 max 0.15;
		_position = getPosATL _projectile;
		drop [
			["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 1, 16],
			"",
			"Billboard",
			1,
			1.2,
			_position,
			[0, 0, 0.25],
			0,
			1.275,
			1,
			0.025,
			[0.28, 0.33, 0.37],
			[[0.6, 0.6, 0.6, _intensity]],
			[0.2],
			1,
			0.04,
			"",
			"",
			""
		];

		if (_temperature > THRESHOLD_3 + random 10) then {
			[_weapon] spawn AGM_Overheat_weaponJamming;
		};
	};
};
