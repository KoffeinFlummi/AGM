// by commy2

_vehicle = _this select 0;
_brightness = player getVariable ["AGM_NVGBrightness", 50];
_return = false;

if (_brightness < 100 && {currentVisionMode player == 1}) then {
	_brightness = _brightness + 5;
	player setVariable ["AGM_NVGBrightness", _brightness, false];
	_text = format [localize "STR_AGM_NightVision_NVGBrightness", _brightness];
	[_text, true] call AGM_Core_fnc_displayText;
	_return = true;
};
_return
