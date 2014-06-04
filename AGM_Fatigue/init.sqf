// by commy2

AGM_Fatigue_heartbeat = compile preprocessFileLineNumbers "\AGM_Fatigue\scripts\heartbeat.sqf";
AGM_Fatigue_recoil = compile preprocessFileLineNumbers "\AGM_Fatigue\scripts\recoil.sqf";
AGM_Fatigue_blinking = compile preprocessFileLineNumbers "\AGM_Fatigue\scripts\blinking.sqf";
AGM_Fatigue_vision = compile preprocessFileLineNumbers "\AGM_Fatigue\scripts\vision.sqf";
AGM_Fatigue_stumble = compile preprocessFileLineNumbers "\AGM_Fatigue\scripts\stumble.sqf";
AGM_Fatigue_vision = compile preprocessFileLineNumbers "\AGM_Fatigue\scripts\vision.sqf";

0 spawn compile preprocessFileLineNumbers "\AGM_Fatigue\scripts\fatigue.sqf";

if (!isNil "AGM_Debug") then {
	waitUntil {
		hintSilent str getFatigue player;
		false
	};
};
