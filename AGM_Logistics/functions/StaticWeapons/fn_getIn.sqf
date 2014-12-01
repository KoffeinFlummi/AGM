// by commy2

_vehicle = _this select 0;

AGM_player action [
  ["GetInGunner", "MoveToGunner"] select (vehicle AGM_player == _vehicle),
  _vehicle
];
