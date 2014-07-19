// by commy2

0 spawn compile preprocessFileLineNumbers "\AGM_Movement\fatigue.sqf";

if (!isNil "AGM_Debug") then {
	waitUntil {
		hintSilent str getFatigue player;
		false
	};
};
