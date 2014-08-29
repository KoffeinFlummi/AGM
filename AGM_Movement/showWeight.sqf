//by commy2

disableSerialization;
while {true} do {
	waitUntil {!isNull (findDisplay 602)};
	waitUntil {
		findDisplay 602 displayCtrl 111 ctrlSetText format ["%1 - %2 %3", name player, localize "STR_AGM_Movement_Weight", [player] call AGM_Movement_fnc_getWeight];
		isNull (findDisplay 602)
	};
};
