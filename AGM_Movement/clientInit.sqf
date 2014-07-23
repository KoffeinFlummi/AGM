// by commy2

0 spawn compile preprocessFileLineNumbers "\AGM_Movement\fatigue.sqf";
0 spawn compile preprocessFileLineNumbers "\AGM_Movement\showWeight.sqf";

if (!isNil "AGM_Debug" && {AGM_Debug == "Fatigue"}) then {
	waitUntil {
		hintSilent str getFatigue player;
		false
	};
};
