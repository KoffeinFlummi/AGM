// by commy2

_vehicle = vehicle player;
_NVGBrightness = _vehicle getVariable "BWA3_NVGBrightness";
_return = false;

if (_NVGBrightness < 100 && {currentVisionMode player == 1}) then {
	_NVGBrightness = _NVGBrightness + 5;
	_vehicle setVariable ["BWA3_NVGBrightness", _NVGBrightness, false];
	_text = format [localize "STR_BWA3_NVGBrightness", str _NVGBrightness];
	[_text, true] spawn BWA3_Hint_displayText;
	_return = true;
};
_return
