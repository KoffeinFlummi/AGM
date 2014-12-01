// by commy2

0 spawn {
	waitUntil {!isNull player};

	[player] call AGM_NoRadio_fnc_muteUnit;
};

[missionNamespace, "playerChanged", {
	[_this select 0] call AGM_NoRadio_fnc_muteUnit;
	[_this select 1] call AGM_NoRadio_fnc_unmuteUnit;
}] call AGM_Core_fnc_addCustomEventHandler;
