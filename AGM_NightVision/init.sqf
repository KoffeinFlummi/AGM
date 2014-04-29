// by commy2

AGM_NightVision_keyInput = compile preprocessFileLineNumbers "\AGM_nightvision\scripts\keyInput.sqf";

sleep 0.1;
0 spawn compile preprocessFileLineNumbers "\AGM_nightvision\scripts\adjustBrightness.sqf";

(findDisplay 46) displayAddEventHandler ["KeyDown", "_this call AGM_NightVision_keyInput"];
