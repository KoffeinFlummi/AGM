// by commy2

_weapon = _this select 1;
_projectile = _this select 5;

if (_weapon != "Throw") exitWith {};

if (AGM_Grenades_Mode != 0) then {
  _velocity = velocity _projectile;
  _velocityX = _velocity select 0;
  _velocityY = _velocity select 1;
  _velocityZ = _velocity select 2;

  switch (AGM_Grenades_Mode) do {
    //high throw
    case 1 : {
      _velocity = [
        0.5 * _velocityX,
        0.5 * _velocityY,
        [0, 0, 0] distance [0.5 * _velocityX, 0.5 * _velocityY, 0.5 * _velocityZ]
      ];
    };
    //precise throw
    case 2 : {
      _direction = player weaponDirection _weapon;

      _speed = speed _projectile / 3.6;

      _velocity = [
        _speed * (_direction select 0),
        _speed * (_direction select 1),
        _speed * (_direction select 2)
      ];
    };
    //roll grande
    case 3 : {
      _direction = [_weapon] call AGM_Core_fnc_getWeaponAzimuthAndInclination select 0;

      _speed = speed _projectile / 3.6;

      _velocity = [
        _speed * sin _direction,
        _speed * cos _direction,
        - _speed
      ];
    };
    //drop grenade
    case 4 : {
      _velocity = [0, 0, 0];
    };
  };

  _projectile setVelocity _velocity;
};

if (typeOf _projectile == "AGM_G_M84") then {
  nul = _this spawn {
    _projectile = _this select 5;

    sleep getNumber (configFile >> "CfgAmmo" >> typeOf _projectile >> "fuseDistance");

    if (alive _projectile) then {
      playSound3D ["A3\Sounds_F\weapons\Explosion\explosion_mine_1.wss", _projectile, false, getPos _projectile, 5, 1.2, 400];

      _affected = _projectile nearEntities ["CAManBase", 50];
      {
        [[_x, _projectile], "AGM_Grenades_fnc_flashbangEffect", _x] call AGM_Core_fnc_execRemoteFnc;
      } count _affected;
    };
  };
};

