// by commy2

_keyCode = _this call AGM_Core_fnc_convertKeyCode;
_isInput = false;

if (_keyCode == profileNamespace getVariable "AGM_Key_increaseBrightness") then {
	_isInput = call AGM_NightVision_fnc_increaseBrightness;
};

if (_keyCode == profileNamespace getVariable "AGM_Key_decreaseBrightness") then {
	_isInput = call AGM_NightVision_fnc_decreaseBrightness;
};
_isInput
