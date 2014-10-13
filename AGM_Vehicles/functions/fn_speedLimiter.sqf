// by commy2

_this spawn {
  _vehicle = _this select 0;
  _player = call AGM_Core_fnc_player;
  
  if (missionNamespace getVariable ["AGM_isSpeedLimiter", false]) exitWith {
    [localize "STR_AGM_SpeedLimiter_Off"] call AGM_Core_fnc_displayTextStructured;
    playSound "AGM_Sound_Click";
    AGM_isSpeedLimiter = false;
  };

  [localize "STR_AGM_SpeedLimiter_On"] call AGM_Core_fnc_displayTextStructured;
  playSound "AGM_Sound_Click";
  AGM_isSpeedLimiter = true;

  _maxSpeed = speed _vehicle;
  if (_maxSpeed < 10) then {_maxSpeed = 10};

  waitUntil {
    _speed = speed _vehicle;
    if (_speed > _maxSpeed) then {
      _velocity = velocity _vehicle;
      _vehicle setVelocity [
        (_velocity select 0) * _maxSpeed / _speed,
        (_velocity select 1) * _maxSpeed / _speed,
        (_velocity select 2) * _maxSpeed / _speed
      ];
    };
    !AGM_isSpeedLimiter || {_player != driver _vehicle}
  };
  AGM_isSpeedLimiter = false;
};
