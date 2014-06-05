// by commy2

#define MAX_TEMPERATURE 3

_this spawn {
	_weapon = _this select 0;

	_animation = getText (configFile >> "CfgWeapons" >> _weapon >> "reloadAction");

	player playActionNow _animation;

	sleep 2.5;

	_string = format ["AGM_Overheating_%1", _weapon];
	_temperature = (player getVariable [_string, [0, 0]]) select 0;

	_red = [255 * (2 * _temperature / MAX_TEMPERATURE min 1), 2] call AGM_Core_fnc_toHex;
	_green = [255 * (2 * (MAX_TEMPERATURE - _temperature) / MAX_TEMPERATURE min 1), 2] call AGM_Core_fnc_toHex;

	_picture = format ["<img size='2' color='#%1%200' image='%3'/>", _red, _green, getText (configFile >> "CfgWeapons" >> _weapon >> "picture")];
	_line = "<t color='#" + _red + _green + "00'>" + localize "STR_AGM_Overheating_Temperature" + "</t>";

	[formatText ["%1%2%3", parseText _picture, lineBreak, parseText _line]] call AGM_Core_fnc_displayText;
};
