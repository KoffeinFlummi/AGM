// by commy2

BWA3_WeaponSelect_getWeaponModes = compile preProcessFileLineNumbers "\BWA3_WeaponSelect\functions\WeaponSelect_getWeaponModes.sqf";
BWA3_WeaponSelect_getWeaponMuzzles = compile preProcessFileLineNumbers "\BWA3_WeaponSelect\functions\WeaponSelect_getWeaponMuzzles.sqf";
BWA3_WeaponSelect_keyInput = compile preProcessFileLineNumbers "\BWA3_WeaponSelect\functions\WeaponSelect_keyInput.sqf";
BWA3_WeaponSelect_keyRelease = compile preProcessFileLineNumbers "\BWA3_WeaponSelect\functions\WeaponSelect_keyRelease.sqf";
BWA3_WeaponSelect_selectWeaponMode = compile preProcessFileLineNumbers "\BWA3_WeaponSelect\functions\WeaponSelect_selectWeaponMode.sqf";
BWA3_WeaponSelect_selectWeaponMuzzle = compile preProcessFileLineNumbers "\BWA3_WeaponSelect\functions\WeaponSelect_selectWeaponMuzzle.sqf";

BWA3_WeaponSelect_keyDown = false;

0 spawn {
	sleep 0.1;
	waitUntil {!isNull (findDisplay 46)};
	(findDisplay 46) displayAddEventHandler ["KeyDown", "[_this select 1, _this select 2, _this select 3, _this select 4] call BWA3_WeaponSelect_keyInput"];
	(findDisplay 46) displayAddEventHandler ["KeyUp", "_this select 1 call BWA3_WeaponSelect_keyRelease"];
};
