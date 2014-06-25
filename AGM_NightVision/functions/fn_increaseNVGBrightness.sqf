// by commy2

_vehicle = _this select 0;
_brightness = player getVariable ["AGM_NVGBrightness", 0];
_return = false;

if (_brightness < 1 && {currentVisionMode player == 1}) then {
	_brightness = round (10 * _brightness + 1) / 10;

	player setVariable ["AGM_NVGBrightness", _brightness, false];

	AGM_NightVision_ppEffectNVGBrightness ppEffectAdjust [1, 1, _brightness / 4, [0, 0, 0, 0], [0, 0, 0, 1], [0, 0, 0, 1]];
	AGM_NightVision_ppEffectNVGBrightness ppEffectCommit 0;

	[format [localize "STR_AGM_NightVision_NVGBrightness", format ["%1%", _brightness * 100]]] call AGM_Core_fnc_displayTextStructured;
	playSound "AGM_Sound_Click";
	_return = true;
};
_return
