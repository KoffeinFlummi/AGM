// by commy2

private "_vehicle";

_vehicle = _this select 0;

player == _vehicle &&
{profileNamespace getVariable ['AGM_enableQuickSelect', true]} &&
{player getVariable ['AGM_CanTreat', true]} &&
{isNull (player getVariable ['AGM_carriedItem', objNull])}
