// by commy2

private ["_player", "_item"];

_player = _this select 0;
_item = _this select 1;

canStand _player &&
{alive _player} &&
{_player getVariable ["AGM_AttachedItemName", ""] == ""} &&
{_item in (magazines _player + items _player + [""])}
