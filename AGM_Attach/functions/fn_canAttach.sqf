// by commy2

private "_item";

_item = _this select 0;

canStand player &&
{alive player} &&
{player getVariable ["AGM_AttachedItemName", ""] == ""} &&
{_item in (magazines player + items player + [""])}
