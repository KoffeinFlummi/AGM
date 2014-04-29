// by commy2

AGM_WeaponSelect_keyInput = compile preprocessFileLineNumbers "\agm_weaponselect\scripts\keyInput.sqf";

waitUntil {!isNull (findDisplay 46)};
(findDisplay 46) displayAddEventHandler ["KeyDown", "_this call AGM_WeaponSelect_keyInput"];
