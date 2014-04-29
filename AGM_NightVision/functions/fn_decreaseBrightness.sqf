// by commy2

_vehicle = vehicle player;
_NVGBrightness = _vehicle getVariable "AGM_NVGBrightness";
_return = false;

if (_NVGBrightness > 0 && {currentVisionMode player == 1}) then {
	_NVGBrightness = _NVGBrightness - 5;
	_vehicle setVariable ["AGM_NVGBrightness", _NVGBrightness, false];
	_text = format [localize "STR_AGM_NVGBrightness", str _NVGBrightness];
	[_text, true] spawn AGM_Hint_displayText;
	_return = true;
};
_return
