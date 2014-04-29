// by commy2

0 spawn compile preprocessFileLineNumbers '\AGM_Interaction\scripts\showPlayerNames.sqf';

AGM_Interaction_keyInput = compile preprocessFileLineNumbers "\AGM_Interaction\scripts\keyInput.sqf";
//AGM_Interaction_keyRelease = compile preprocessFileLineNumbers "\AGM_Interaction\scripts\keyRelease.sqf";

0 spawn {
	waitUntil {!isNull (findDisplay 46)};
	(findDisplay 46) displayAddEventHandler ["KeyDown", "_this call AGM_Interaction_keyInput"];
	//(findDisplay 46) displayAddEventHandler ["KeyUp", "_this call AGM_Interaction_keyRelease"];
};
