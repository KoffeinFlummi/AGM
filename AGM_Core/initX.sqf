// BWA3 Realism - Core
// (C) 2013 KoffeinFlummi. See LICENSE.

"AGM_Core_remoteFnc" addPublicVariableEventHandler {
	(_this select 1) call AGM_Core_fnc_execRemoteFnc;
};

if (isDedicated) exitWith {};

AGM_Core_keyInput  = compile preprocessFileLineNumbers "\AGM_core\scripts\KeyX\keyInput.sqf";
AGM_Core_editKey   = compile preprocessFileLineNumbers "\AGM_core\scripts\KeyX\editKey.sqf";
AGM_Core_openMenu  = compile preprocessFileLineNumbers "\AGM_core\scripts\KeyX\openMenu.sqf";
AGM_Core_closeMenu = compile preprocessFileLineNumbers "\AGM_core\scripts\KeyX\closeMenu.sqf";
AGM_Core_nextKeys = compile preprocessFileLineNumbers "\AGM_core\scripts\KeyX\nextKeys.sqf";
AGM_Core_toggleState = compile preprocessFileLineNumbers "\AGM_core\scripts\KeyX\toggleState.sqf";

AGM_KeyX_fnc_getMods = compile preprocessFileLineNumbers "\AGM_Core\scripts\KeyX\getMods.sqf";

AGM_KeyX_inputStates = [];
AGM_KeyX_inputTimes = [];
AGM_KeyX_inputTimesNoHold = [];
AGM_KeyX_inputMods = [];

for "_index" from 0 to 300 do {
	AGM_KeyX_inputStates set [_index, 0];
	AGM_KeyX_inputTimes set [_index, 0];
	AGM_KeyX_inputTimesNoHold set [_index, 0];
	AGM_KeyX_inputMods set [_index, 0];
};

[false] call AGM_Core_fnc_setKeyDefault;

call compile preprocessFileLineNumbers "\AGM_core\scripts\KeyX\KeyInput\initKeys.sqf";

0 spawn {
	while {true} do {
		waitUntil {!isNull (findDisplay 46)}; sleep 1;
		(findDisplay 46) displayAddEventHandler ["KeyDown", "_this call AGM_Core_onKeyDown"];
		(findDisplay 46) displayAddEventHandler ["KeyUp", "_this call AGM_Core_onKeyUp"];
		waitUntil {isNull (findDisplay 46)};
	};
};

0 spawn {
	sleep 1;
	player setVariable ["AGM_Name", name player, true];
};
