// by commy2

0 spawn compile preProcessFileLineNumbers '\AGM_Interaction\scripts\Interaction_showPlayerNames.sqf';

AGM_Interaction_keyInput = compile preProcessFileLineNumbers "\AGM_Interaction\scripts\Interaction_keyInput.sqf";
//AGM_Interaction_keyRelease = compile preProcessFileLineNumbers "\AGM_Interaction\scripts\Interaction_keyRelease.sqf";

0 spawn {
	waitUntil {!isNull (findDisplay 46)};
	(findDisplay 46) displayAddEventHandler ["KeyDown", "[_this select 1, _this select 2, _this select 3, _this select 4] call AGM_Interaction_keyInput"];
	//(findDisplay 46) displayAddEventHandler ["KeyUp", "_this select 1 call AGM_Interaction_keyRelease"];
};
