_this spawn {
  _unit = _this select 0;
  _weaponType = _this select 1;
  _ammoType = _this select 4;
  _round = _this select 5;

  if !(local _unit) exitwith {};
  if !(isPlayer _unit) exitwith {};
  if !(_unit == player) exitwith {};
  if (_round isKindOf "GrenadeHand") exitWith {};

  // For deduction see https://github.com/KoffeinFlummi/AGM/issues/996
  // _K_lat = (4/pi) * (L/D) * (-airFriction)
  _K_lat = -5.09;               //L/D = 4
  if (_round isKindOf "GrenadeCore") then {
    _K_lat = -1.27;             //L/D = 1
  };
  if (_round isKindOf "RocketCore") then {
    _coefficient = -12.7;       //L/D = 10
  };
  _K_lat = _K_lat * getNumber (configFile >> "CfgAmmo" >> _ammoType >> "airFriction");

  // HUMIDITY
  _round setVelocity ([velocity _round, {_this - _this * humidity * 0.1}] call AGM_Core_fnc_map);

  // WIND
  _time = time;
  while {!isNull _round and alive _round} do {
    // Use actual time delay between iterations instead of a set interval to account for ultra-low framerates.
    _deltaTime = time - _time;
    _wind = wind;
    _wind pushBack 0;

    _velocityNew = (velocity _round) vectorAdd (_wind vectorMultiply ((vectorMagnitude _wind) * _K_lat * _deltaTime));

    _round setVelocity _velocityNew;

    _time = time;
    sleep 0.05;
  };
};
