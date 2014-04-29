// by commy2

_vehicle = _this select 0;
_brightness = _vehicle getVariable ["BWA3_NVGBrightness", 50];
_return = false;

if (_brightness < 100 && {currentVisionMode player == 1}) then {
	_brightness = _brightness + 5;
	_vehicle setVariable ["BWA3_NVGBrightness", _brightness, false];
	_text = format [localize "STR_BWA3_NVGBrightness", _brightness];
	[_text, true] call BWA3_Core_fnc_displayText;
	_return = true;
};
_return
