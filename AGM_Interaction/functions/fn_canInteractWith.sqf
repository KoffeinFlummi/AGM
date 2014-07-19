// by commy2

private "_unit";

_unit = _this select 0;

_unit isKindOf "Civilian" &&
{alive _unit} &&
{alive player} &&
{player getVariable ["AGM_AttachedItemName", ""] == ""} &&
{count (weapons _unit) == 0}
