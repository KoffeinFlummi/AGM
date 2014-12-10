// by commy2

[_this select 0, "AGM_kockedOut", {
	if (local (_this select 0)) then {_this call AGM_Captives_fnc_handleKockedOut};
}] call AGM_Core_fnc_addCustomEventhandler;

[_this select 0, "AGM_wokeUp", {
	if (local (_this select 0)) then {_this call AGM_Captives_fnc_handleWokeUp};
}] call AGM_Core_fnc_addCustomEventhandler;

// prevent players from throwing grenades
[_this select 0, "Throw", {(_this select 1) getVariable ["AGM_isCaptive", false]}, {}] call AGM_Core_fnc_addActionEventhandler;
