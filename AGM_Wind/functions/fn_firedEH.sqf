_this spawn {
  _unit = _this select 0;
  _weaponType = _this select 1;
  _ammoType = _this select 4;
  _round = _this select 5;

  if !(local _unit) exitwith {};
  if !(isPlayer _unit) exitwith {};
  if !(_unit == player) exitwith {};
  if (_round isKindOf "GrenadeHand") exitWith {};

  _airFriction = - getNumber (configFile >> "CfgAmmo" >> _ammoType >> "airFriction");
  _simulation = getText (configFile >> "CfgAmmo" >> _ammoType >> "simulation");
  if (_airFriction < 0 || { simulation == "shotMissile"} || {_simulation == "shotRocket"}) then {
    _airFriction = 0.0007;
  };

  // WIND
  _time = time;
  while {!isNull _round and alive _round} do {
    // Use actual time delay between iterations instead of a set interval to account for ultra-low framerates.
    _deltaTime = time - _time;

    // See https://github.com/KoffeinFlummi/AGM/issues/996
    _velocityNew = (velocity _round) vectorAdd (wind vectorMultiply (vectorMagnitude ((velocity _round) vectorAdd wind) * _airFriction * _deltaTime));

    _round setVelocity _velocityNew;

    _time = time;
    sleep 0.05;
  };
};
