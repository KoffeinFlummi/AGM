_this spawn {
  _unit = _this select 0;
  _weaponType = _this select 1;
  _ammoType = _this select 4;
  _round = _this select 5;

  if !(local _unit) exitwith {};
  if !(isPlayer _unit) exitwith {};
  if !(_unit == player) exitwith {};
  if (_round isKindOf "GrenadeHand") exitWith {};

  _coefficient = 0.7;
  if (_round isKindOf "GrenadeCore") then {
    _coefficient = 0.2;
  };
  if (_round isKindOf "RocketCore") then {
    _coefficient = 0.35;
  };

  // HUMIDITY
  _round setVelocity ([velocity _round, {_this - _this * humidity * 0.2}] call AGM_Core_fnc_map);

  // WIND
  _time = time;
  while {!isNull _round and alive _round} do {
    // Use actual time delay between iterations instead of a set interval to account for ultra-low framerates.
    _deltaTime = time - _time;

    _velocityNew = [
      ((velocity _round) select 0) + _coefficient * (wind select 0) * _deltaTime,
      ((velocity _round) select 1) + _coefficient * (wind select 1) * _deltaTime,
      ((velocity _round) select 2)
    ];

    _round setVelocity _velocityNew;

    _time = time;
    sleep 0.05;
  };
};
