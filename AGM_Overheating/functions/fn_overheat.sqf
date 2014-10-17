// by commy2

private ["_unit", "_weapon", "_projectile", "_increment", "_cooldown", "_variableName", "_overheat", "_temperature", "_time"];

_unit = _this select 0;
_weapon = _this select 1;
_projectile = _this select 5;

// @todo config values in CfgMagazines + Non linear cooldown
_increment = 1/250;		// 250 shots for max temp.
_cooldown = 1/25/60;	// 25 minutes for complete cooldown from max temp.


// each weapon has it's own variable. Can't store the temperature in the weapon since they are not objects unfortunately.
_variableName = format ["AGM_Overheating_%1", _weapon];


// get old values
_overheat = _unit getVariable [_variableName, [0, 0]];
_temperature = _overheat select 0;
_time = _overheat select 1;


// calculate the new values
// the *first shot after a break in the firing should set the temperature variable to the *first increment, not zero
_temperature = (_temperature + _increment - _cooldown * (time - _time) max _increment) min 1;

if (!isNil "AGM_Debug" && {AGM_Debug == "Overheating"}) then {
	hintSilent format ["Temperature: %1%\nTime: %2s\nIncrement: %3\nCooldown: %4", _temperature * 100, time - _time, _increment, _cooldown];
};


// set updated values
_time = time;

_unit setVariable [_variableName, [_temperature, _time], false];


// Smoke SFX, beginning at TEMP 0.15
private "_intensity";

_intensity = 0.3 * (_temperature - 0.15) max 0;

if (_intensity > 0) then {
	private "_position";
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
};


// dispersion and bullet slow down
private ["_dispersion", "_velocity", "_slowdownFactor", "_count"];

_velocity = velocity _projectile;

_dispersion = getArray (configFile >> "CfgWeapons" >> _weapon >> "AGM_Overheating_Dispersion");

_count = count _dispersion;
if (_count > 0) then {
	_dispersion = ([_dispersion, (_count - 1) * _temperature] call AGM_Core_fnc_interpolateFromArray) max 0;

	// @todo FUNCTION for projectile dispersion and slowdown, Placeholder
	_velocity = [
		(_velocity select 0) * (1 - _dispersion + 2 * random _dispersion),
		(_velocity select 1) * (1 - _dispersion + 2 * random _dispersion),
		(_velocity select 2) * (1 - _dispersion + 2 * random _dispersion)
	];
};

_slowdownFactor = getArray (configFile >> "CfgWeapons" >> _weapon >> "AGM_Overheating_slowdownFactor");

_count = count _slowdownFactor;
if (_count > 0) then {
	_slowdownFactor = ([_slowdownFactor, (_count - 1) * _temperature] call AGM_Core_fnc_interpolateFromArray) max 0;

	// @todo FUNCTION for projectile dispersion and slowdown, Placeholder
	// Value EX: _slowdownFactor = 1 - 0.05 * (_temperature - 1);
	_velocity = [
		_slowdownFactor * (_velocity select 0),
		_slowdownFactor * (_velocity select 1),
		_slowdownFactor * (_velocity select 2)
	];
};

_projectile setVelocity _velocity;


// jamming
private "_jamChance";

_jamChance = getArray (configFile >> "CfgWeapons" >> _weapon >> "AGM_Overheating_jamChance");

_count = count _jamChance;
if (_count == 0) then {
	_jamChance = [0];
	_count = 1;
};

_jamChance = [_jamChance, (_count - 1) * _temperature] call AGM_Core_fnc_interpolateFromArray;

if (!isNil "AGM_Debug") then {
	if (AGM_Debug == "Jamming") then {
		systemChat format ["Jam chance: %1%", _jamChance];
	};
	if (AGM_Debug == "Jamming50") then {
		_jamChance = 0.5;
	};
};

if (random 1 < _jamChance) then {
	[_unit, _weapon] call AGM_Overheating_fnc_jamWeapon;
};
