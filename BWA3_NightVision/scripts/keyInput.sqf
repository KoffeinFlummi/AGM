/*
BWA3 script, by commy2
this code is property of the ArmA 3 Bundeswehr modification
ask us nicely at http://www.bwmod.de/ if you want to re-use any of this script
we don't support changed code based on this work
*/

_keyCode = _this call BWA3_fnc_convertKeyCode;
_isInput = false;

if (_keyCode == profileNamespace getVariable "BWA3_Key_increaseBrightness") then {
	_isInput = call BWA3_NightVision_fnc_increaseBrightness;
};

if (_keyCode == profileNamespace getVariable "BWA3_Key_decreaseBrightness") then {
	_isInput = call BWA3_NightVision_fnc_decreaseBrightness;
};
_isInput
