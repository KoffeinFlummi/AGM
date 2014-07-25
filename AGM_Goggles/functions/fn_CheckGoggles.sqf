/*
	Author: Garth de Wet (LH)
	
	Description:
	Performs rain checks and checks to see whether glasses effects have been applied or not.
	Checks for external camera and removes effects.
	
	Parameters: 
	Nothing
	
	Returns:
	Nothing
	
	Example:
	[] execVM "AGM_Goggles\functions\fn_CheckGoggles.sqf";
*/
#include "\AGM_Goggles\script.sqf"
#define RAINCHECK 5

private ["_lastRainCheck"];
waitUntil {sleep 0.46;alive player};
call AGM_Goggles_fnc_CheckGlasses;
["AGM_Goggles_RotorWash", "OnEachFrame", "call AGM_Goggles_fnc_OnEachFrame;"] call BIS_fnc_addStackedEventHandler;
while {alive player} do {
	sleep 1;
	if (true) then {
		call AGM_Goggles_fnc_CheckGlasses;
		if !(player call AGM_Goggles_fnc_isGogglesVisible) exitWith {
			if (AGM_Goggles_EffectsActive) then {
				call AGM_Goggles_fnc_RemoveGlassesEffect;
			};
		};
		if (call AGM_Goggles_fnc_ExternalCamera) exitWith {
			if (AGM_Goggles_EffectsActive) then {
				call AGM_Goggles_fnc_RemoveGlassesEffect;
			};
		};
		// Detect if curator interface is open and disable effects
		if (!isNull(findDisplay 312)) exitWith {
			if (AGM_Goggles_EffectsActive) then {
				call AGM_Goggles_fnc_RemoveGlassesEffect;
			};
		};
		// Check rain
		if (GETRAINT(RTIME) <= time - (RAINCHECK + GETRAINT(RAMOUNT)*RAINCHECK)) then {
			SETLRAIN(RTIME, time);
			(rain > 0.1) call AGM_Goggles_fnc_RainCheck;
		};

		if !(AGM_Goggles_EffectsActive) then {
			(goggles player) call AGM_Goggles_fnc_ApplyGlassesEffect;
		} else {
			if ((goggles player) call AGM_Goggles_fnc_isDivingGoggles && {underwater player}) then {
				call AGM_Goggles_fnc_RemoveRainEffect;
				call AGM_Goggles_fnc_RemoveDirtEffect;
				call AGM_Goggles_fnc_RemoveDustEffect;
			};
		};
	};
};