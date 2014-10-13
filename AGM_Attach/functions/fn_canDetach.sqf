// by commy2

private ["_player"];

_player = _this select 0;

canStand _player &&
{alive _player} &&
{_player getVariable ["AGM_AttachedItemName", ""] != ""}
