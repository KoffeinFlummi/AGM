/*
BWA3 function, by commy2
this code is property of the ArmA 3 Bundeswehr modification
ask us nicely at http://www.bwmod.de/ if you want to re-use any of this script
we don't support changed code based on this work
*/

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
