// by commy2

_keyCode = _this call BWA3_NightVision_fnc_convertKeyCode;
_isInput = false;

if (_keyCode == profileNamespace getVariable "BWA3_Key_increaseBrightness") then {
	_isInput = call BWA3_NightVision_fnc_increaseBrightness;
};

if (_keyCode == profileNamespace getVariable "BWA3_Key_decreaseBrightness") then {
	_isInput = call BWA3_NightVision_fnc_decreaseBrightness;
};
_isInput
