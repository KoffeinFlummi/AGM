// by commy2

private "_ctrlJavelinMode";

disableSerialization;
_ctrlJavelinMode = (uiNamespace getVariable ["AGM_dlgJavelinOptics", displayNull]) displayCtrl 1006;

getNumber (configFile >> "CfgWeapons" >> currentWeapon player >> "AGM_enableTopDownAttack") == 1
&& {ctrlShown _ctrlJavelinMode}
