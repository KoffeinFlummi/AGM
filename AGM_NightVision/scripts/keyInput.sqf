// by commy2

_keyCode = [_this select 1, _this select 2, _this select 3, _this select 4] call AGM_Core_fnc_convertKeyCode;
_vehicle = vehicle player;
_isInput = false;

if (_keyCode == profileNamespace getVariable "AGM_Key_increaseNVGBrightness") then {
	_isInput = [_vehicle] call AGM_NightVision_fnc_increaseNVGBrightness;
};

if (_keyCode == profileNamespace getVariable "AGM_Key_decreaseNVGBrightness") then {
	_isInput = [_vehicle] call AGM_NightVision_fnc_decreaseNVGBrightness;
};
_isInput
