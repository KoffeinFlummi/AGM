// by commy2

private "_unit";

_unit = _this select 0;

_unit getVariable ["AGM_hasEarPlugsin", false]
|| {_unit getVariable ["X39_MedSys_var_hasEarplugs", false]}
