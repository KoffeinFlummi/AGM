// by commy2

private "_vehicle";

_vehicle = _this select 0;

isNull (gunner _vehicle) &&
{alive _vehicle} &&
{!(_vehicle getVariable ["AGM_inUse", false])}
