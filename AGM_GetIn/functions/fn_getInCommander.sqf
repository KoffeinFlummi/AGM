// by commy2

private ["_player", "_vehicle"];

_player = _this select 0;
_vehicle = _this select 1;

_player action [
  ["GetInCommander", "MoveToCommander"] select (vehicle _player == _vehicle),
  _vehicle
];
