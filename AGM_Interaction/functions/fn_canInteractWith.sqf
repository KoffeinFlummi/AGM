// by commy2

private "_unit";

_unit = _this select 0;

_unit isKindOf "Civilian" &&
{alive _unit} &&
{count (weapons _unit) == 0} &&
{call AGM_Interaction_fnc_canInteract}
