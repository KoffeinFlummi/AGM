// by commy2 and CAA-Picard

private ["_unit", "_weapon", "_ammo", "_projectile", "_variableName", "_overheat", "_temperature", "_time", "_energyIncrement", "_barrelMass", "_scaledTemperature"];

_unit = _this select 0;
_weapon = _this select 1;
_ammo = _this select 4;
_projectile = _this select 6;
_velocity = velocity _projectile;

// each weapon has it's own variable. Can't store the temperature in the weapon since they are not objects unfortunately.
_variableName = format ["AGM_Overheating_%1", _weapon];

// get old values
_overheat = _unit getVariable [_variableName, [0, 0]];
_temperature = _overheat select 0;
_time = _overheat select 1;

// Get physical parameters
_energyIncrement = 0.75 * 0.0005 * getNumber (configFile >> "CfgAmmo" >> _ammo >> "AGM_BulletMass") * (vectorMagnitudeSqr _velocity);
_barrelMass = 0.50 * (getNumber (configFile >> "CfgWeapons" >> _weapon >> "WeaponSlotsInfo" >> "mass") / 22.0) max 1.0;

// Calculate cooling
_temperature = [_temperature, _barrelMass, time - _time] call AGM_Overheating_fnc_cooldown;
// Calculate heating
_temperature = _temperature + _energyIncrement / (_barrelMass * 466); // Steel Heat Capacity = 466 J/(Kg.K)

// set updated values
_time = time;
_unit setVariable [_variableName, [_temperature, _time], false];
_scaledTemperature = (_temperature / 1000) min 1;

// Smoke SFX, beginning at TEMP 0.15
private "_intensity";

_intensity = (_scaledTemperature - 0.2) * 1.25;
if (_intensity > 0) then {
  private ["_position", "_direction"];

  _position = position _projectile;
  _direction = (_unit weaponDirection _weapon) vectorMultiply 0.25;

  drop [
    "\A3\data_f\ParticleEffects\Universal\Refract",
    "",
    "Billboard",
    1.1,
    2,
    _position,
    _direction,
    1,
    1.2,
    1.0,
    0.1,
    [0.1,0.15],
    [[0.06,0.06,0.06,0.32*_scaledTemperature], [0.3,0.3,0.3,0.28*_scaledTemperature], [0.3,0.3,0.3,0.25*_scaledTemperature], [0.3,0.3,0.3,0.22*_scaledTemperature], [0.3,0.3,0.3,0.1*_scaledTemperature]],
    [1,0],
    0.1,
    0.05,
    "",
    "",
    ""
  ];

  _intensity = (_scaledTemperature - 0.5) * 2;
  if (_intensity > 0) then {
    drop [
      ["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 1, 16],
      "",
      "Billboard",
      1,
      1.2,
      _position,
      [0,0,0.25],
      0,
      1.275,
      1,
      0.025,
      [0.28,0.33,0.37],
      [[0.6,0.6,0.6,0.3*_intensity]],
      [0.2],
      1,
      0.04,
      "",
      "",
      ""
    ];
  };
};


// dispersion and bullet slow down
private ["_dispersion", "_velocity", "_slowdownFactor", "_count"];

_dispersion = getArray (configFile >> "CfgWeapons" >> _weapon >> "AGM_Overheating_Dispersion");

_count = count _dispersion;
if (_count > 0) then {
  _dispersion = ([_dispersion, (_count - 1) * _scaledTemperature] call AGM_Core_fnc_interpolateFromArray) max 0;

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
  _slowdownFactor = ([_slowdownFactor, (_count - 1) * _scaledTemperature] call AGM_Core_fnc_interpolateFromArray) max 0;

  // @todo FUNCTION for projectile dispersion and slowdown, Placeholder
  // Value EX: _slowdownFactor = 1 - 0.05 * (_scaledTemperature - 1);
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

_jamChance = [_jamChance, (_count - 1) * _scaledTemperature] call AGM_Core_fnc_interpolateFromArray;

if (!isNil "AGM_Debug") then {
  if ("Jam" in AGM_Debug) then {
    _jamChance = 0.5;
  };
  if ("Overheating" in AGM_Debug) then {
    hintSilent format ["Temperature/JamChance: %1, %2", _temperature, 1.0 / _jamChance];
  };
};

if (random 1 < _jamChance) then {
  [_unit, _weapon] call AGM_Overheating_fnc_jamWeapon;
};
