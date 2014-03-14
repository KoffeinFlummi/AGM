/*
BWA3 script, by commy2
this code is property of the ArmA 3 Bundeswehr modification
ask us nicely at http://www.bwmod.de/ if you want to re-use any of this script
we don't support changed code based on this work
*/

#define SETKEYDEFAULT(VAR, KEY) \
_key = profileNamespace getVariable format ["BWA3_Key_%1", #VAR]; \
if (isNil "_key") then { \
	profileNamespace setVariable [format ["BWA3_Key_%1", #VAR], KEY]; \
};
#define PREPROCESS(FILE) BWA3_NightVision_##FILE = compile preprocessFile format["\bwa3_nightvision\scripts\%1.sqf", #FILE];

SETKEYDEFAULT(increaseBrightness, 201.1)
SETKEYDEFAULT(decreaseBrightness, 209.1)

PREPROCESS(adjustBrightness)
PREPROCESS(keyInput)

sleep 0.1;
0 spawn BWA3_NightVision_adjustBrightness;
(findDisplay 46) displayAddEventHandler ["KeyDown", "[_this select 1, _this select 2, _this select 3, _this select 4] call BWA3_NightVision_keyInput"];
