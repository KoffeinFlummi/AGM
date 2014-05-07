// by commy2

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

hintSilent format ["Temperature: %1%\nTime: %2s\nIncrement: %3\nCooldown: %4", _temperature * 100, time - _time, _increment, _cooldown];

_time = time;

player setVariable [_string, [_temperature, _time], false];

if (_temperature > 1) then {
	_intensity = _temperature * 0.05 max 0.15;
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
		[[0.8, 0.8, 0.8, _intensity]],
		[0.2],
		1,
		0.04,
		"",
		"",
		""
	];
	if (_temperature > 1 + random 10) then {
		0 spawn AGM_Overheat_weaponJamming;
	};
};
