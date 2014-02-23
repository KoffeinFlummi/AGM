// by commy2

BWA3_QuickSelect_getWeaponModes = compile preProcessFileLineNumbers "\BWA3_QuickSelect\functions\QuickSelect_getWeaponModes.sqf";
BWA3_QuickSelect_getWeaponMuzzles = compile preProcessFileLineNumbers "\BWA3_QuickSelect\functions\QuickSelect_getWeaponMuzzles.sqf";
BWA3_QuickSelect_keyInput = compile preProcessFileLineNumbers "\BWA3_QuickSelect\functions\QuickSelect_keyInput.sqf";
BWA3_QuickSelect_keyRelease = compile preProcessFileLineNumbers "\BWA3_QuickSelect\functions\QuickSelect_keyRelease.sqf";
BWA3_QuickSelect_selectWeaponMode = compile preProcessFileLineNumbers "\BWA3_QuickSelect\functions\QuickSelect_selectWeaponMode.sqf";
BWA3_QuickSelect_selectWeaponMuzzle = compile preProcessFileLineNumbers "\BWA3_QuickSelect\functions\QuickSelect_selectWeaponMuzzle.sqf";

BWA3_QuickSelect_keyDown = false;

0 spawn {
	sleep 0.1;
	waitUntil {!isNull (findDisplay 46)};
	(findDisplay 46) displayAddEventHandler ["KeyDown", "[_this select 1, _this select 2, _this select 3, _this select 4] call BWA3_QuickSelect_keyInput"];
	(findDisplay 46) displayAddEventHandler ["KeyUp", "[_this select 1] call BWA3_QuickSelect_keyRelease"];
};
