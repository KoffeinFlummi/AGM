// by commy2

BWA3_WeaponSelect_keyInput = compile preprocessFileLineNumbers "\bwa3_weaponselect\scripts\keyInput.sqf";

waitUntil {!isNull (findDisplay 46)};
(findDisplay 46) displayAddEventHandler ["KeyDown", "_this call BWA3_WeaponSelect_keyInput"];
