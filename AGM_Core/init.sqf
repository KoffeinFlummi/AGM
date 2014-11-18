// BWA3 Realism - Core
// (C) 2013 KoffeinFlummi. See LICENSE.

"AGM_Core_remoteFnc" addPublicVariableEventHandler {
  (_this select 1) call AGM_Core_fnc_execRemoteFnc;
};

0 spawn {
  if (hasInterface) then {waitUntil {!isNull player}} else {sleep 1};
  {
    if (typeName _x == "ARRAY") then {
      (_x select 0) call (_x select 1);
    };
  } forEach (missionNamespace getVariable ["AGM_Core_persistentFnc", []]);
};

call compile preprocessFileLineNumbers "\AGM_core\scripts\Version\checkVersionNumber.sqf";

if (!hasInterface) exitWith {};

call compile preprocessFileLineNumbers "\AGM_core\scripts\assignedItemFix.sqf";

AGM_Core_keyInput  = compile preprocessFileLineNumbers "\AGM_core\scripts\keyInput.sqf";
AGM_Core_keyRelease  = compile preprocessFileLineNumbers "\AGM_core\scripts\keyRelease.sqf";
AGM_Core_editKey   = compile preprocessFileLineNumbers "\AGM_core\scripts\editKey.sqf";
AGM_Core_openMenu  = compile preprocessFileLineNumbers "\AGM_core\scripts\openMenu.sqf";
AGM_Core_closeMenu = compile preprocessFileLineNumbers "\AGM_core\scripts\closeMenu.sqf";
AGM_Core_nextKeys = compile preprocessFileLineNumbers "\AGM_core\scripts\nextKeys.sqf";
AGM_Core_toggleState = compile preprocessFileLineNumbers "\AGM_core\scripts\toggleState.sqf";

[false] call AGM_Core_fnc_setKeyDefault;

AGM_Core_keyStates = [];
AGM_Core_keyTimes = [];
for "_index" from 0 to 300 do {
  AGM_Core_keyStates set [_index, 0];
  AGM_Core_keyTimes set [_index, -1];
};

call compile preprocessFileLineNumbers "\AGM_core\scripts\KeyInput\initCanInteractFunction.sqf";
call compile preprocessFileLineNumbers "\AGM_core\scripts\KeyInput\initKeys.sqf";
call compile preprocessFileLineNumbers "\AGM_core\scripts\KeyInput\initScrollWheel.sqf";

0 spawn {
  while {true} do {
    waitUntil {!isNull (findDisplay 46)}; sleep 0.1;
    findDisplay 46 displayAddEventHandler ["KeyDown", "_this call AGM_Core_onKeyDown"];
    findDisplay 46 displayAddEventHandler ["KeyUp", "_this call AGM_Core_onKeyUp"];
    findDisplay 46 displayAddEventHandler ["MouseZChanged", "_this call AGM_Core_onScrollWheel"];
    [false] call AGM_Core_fnc_disableUserInput;
    waitUntil {isNull (findDisplay 46)};
  };
};

enableCamShake true;

[player] call AGM_Core_fnc_setName;
