// by commy2

#define ARRAY_SIZE 300

AGM_KeyX_inputStates = [];
AGM_KeyX_inputTimes = [];
AGM_KeyX_inputTimesNoHold = [];
AGM_KeyX_inputMods = [];

for "_index" from 0 to (ARRAY_SIZE - 1) do {
	AGM_KeyX_inputStates set [_index, 0];
	AGM_KeyX_inputTimes set [_index, 0];
	AGM_KeyX_inputTimesNoHold set [_index, 0];
	AGM_KeyX_inputMods set [_index, 0];
};

AGM_KeyX_fnc_getMods = compile preprocessFileLineNumbers "\AGM_Core\scripts\KeyX\getMods.sqf";
AGM_KeyX_fnc_keyDownEH = compile preprocessFileLineNumbers "\AGM_Core\scripts\KeyX\keyDown.sqf";
AGM_KeyX_fnc_keyUpEH = compile preprocessFileLineNumbers "\AGM_Core\scripts\KeyX\keyUp.sqf";

if (isNil "AGM_KeyX_keyInputHandle") then {
	AGM_KeyX_keyInputHandle = 0 spawn {
		while {true} do {
			waitUntil {!isNull (findDisplay 46)};
			findDisplay 46 displayAddEventHandler ["keyDown", {_this call AGM_KeyX_fnc_keyDownEH}];
			findDisplay 46 displayAddEventHandler ["keyUp", {_this call AGM_KeyX_fnc_keyUpEH}];
			waitUntil {isNull (findDisplay 46)};
		};
	};
};
