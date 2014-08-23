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
  _airFriction = - getNumber (configFile >> "CfgAmmo" >> _ammoType >> "airFriction");
  diag_log _airFriction;

  // HUMIDITY
  _round setVelocity ([velocity _round, {_this - _this * humidity * 0.1}] call AGM_Core_fnc_map);

  // WIND
  _time = time;
  while {!isNull _round and alive _round} do {
    // Use actual time delay between iterations instead of a set interval to account for ultra-low framerates.
    _deltaTime = time - _time;

    _velocityNew = (velocity _round) vectorAdd (wind vectorMultiply ((vectorMagnitude ((velocity _round) vectorAdd wind) * _airFriction * _deltaTime));
    diag_log _deltaTime;
    diag_log velocity _round;
    diag_log (wind vectorMultiply ((vectorMagnitude velocity _round) * _airFriction * _deltaTime));

    _round setVelocity _velocityNew;

    _time = time;
    sleep 0.05;
  };
};
