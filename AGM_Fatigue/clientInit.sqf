// by commy2

0 spawn compile preprocessFileLineNumbers "\AGM_Fatigue\fatigue.sqf";

if (!isNil "AGM_Debug") then {
	waitUntil {
		hintSilent str getFatigue player;
		false
	};
};
