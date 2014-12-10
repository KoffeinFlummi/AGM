// by commy2

[missionNamespace, "playerChanged", {
	showHUD !((_this select 0) getVariable ["AGM_isCaptive", false]);
}] call AGM_Core_fnc_addCustomEventhandler;
