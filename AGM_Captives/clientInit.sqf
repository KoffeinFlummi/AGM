// by commy2

[missionNamespace, "playerChanged", {
	_unit = _this select 0;

	if (_unit getVariable ["AGM_isCaptive", false]) then {
		/*disable user input*/
	};
}] call AGM_Core_fnc_addCustomEventhandler;
