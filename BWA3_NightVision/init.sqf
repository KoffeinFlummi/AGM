// by commy2

BWA3_NightVision_keyInput = compile preprocessFileLineNumbers "\bwa3_nightvision\scripts\keyInput.sqf";

sleep 0.1;
0 spawn compile preprocessFileLineNumbers "\bwa3_nightvision\scripts\adjustBrightness.sqf";

(findDisplay 46) displayAddEventHandler ["KeyDown", "_this call BWA3_NightVision_keyInput"];
