// by commy2

private ["_player", "_vehicle", "_index"];

_player = _this select 0;
_vehicle = _this select 1;
_index = AGM_Interaction_MenuData select 0;

_player action [
  ["GetInCargo", "MoveToCargo"] select (vehicle _player == _vehicle),
  _vehicle,
  _index
];
