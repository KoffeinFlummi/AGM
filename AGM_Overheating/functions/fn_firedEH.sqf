// by commy2

#define THRESHOLD_1 0.5
#define THRESHOLD_2 0.8
#define THRESHOLD_3 1.0
#define MAX_TEMPERATURE 3

_weapon = _this select 1;
_projectile = _this select 5;

_increment = getNumber (configFile >> "CfgWeapons" >> _weapon >> "AGM_Overheating_Increment");
_cooldown = getNumber (configFile >> "CfgWeapons" >> _weapon >> "AGM_Overheating_Cooldown");

if (_increment == 0) exitWith {};

_string = format ["AGM_Overheating_%1", _weapon];

_overheat = player getVariable [_string, [0, 0]];
_temperature = _overheat select 0;
_time = _overheat select 1;

_temperature = (_temperature + _increment - _cooldown * (time - _time) max _increment) min MAX_TEMPERATURE;

if (!isNil "AGM_Debug" && {AGM_Debug == "Overheating"}) then {
    hintSilent format ["Temperature: %1%\nTime: %2s\nIncrement: %3\nCooldown: %4", _temperature * 100, time - _time, _increment, _cooldown];
};

_time = time;

player setVariable [_string, [_temperature, _time], false];

if (_temperature > THRESHOLD_1) then {
	_intensity = 0.1 * (_temperature - THRESHOLD_1);
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

	if (_temperature > THRESHOLD_2) then {
		_dispersion = getNumber (configFile >> "CfgWeapons" >> _weapon >> "AGM_Overheating_Dispersion");
		_random = _dispersion * (_temperature - THRESHOLD_2);

		_velocity = velocity _projectile;
		_velocity = [
			(_velocity select 0) * (1 - _random + 2 * random _random),
			(_velocity select 1) * (1 - _random + 2 * random _random),
			(_velocity select 2) * (1 - _random + 2 * random _random)
		];

		if (_temperature > THRESHOLD_3) then {
			_factor = 1 - 0.05 * (_temperature - THRESHOLD_3);

			_velocity = [
				_factor * (_velocity select 0),
				_factor * (_velocity select 1),
				_factor * (_velocity select 2)
			];
		};
		_projectile setVelocity _velocity;
	};
};
