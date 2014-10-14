// by commy2

private ["_player", "_vehicle", "_turret"];

_player = _this select 0;
_vehicle = _this select 1;
_turret = _this select 2;

_player action [
  ["GetInTurret", "MoveToTurret"] select (vehicle _player == _vehicle),
  _vehicle,
  _turret
];
