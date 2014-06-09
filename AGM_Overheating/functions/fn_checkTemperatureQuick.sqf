// by commy2 and CAA-Picard

#define MAX_TEMPERATURE 3

_this spawn {
	_weapon = _this select 0;

	// Calculate cool down of weapon since last shot
	_cooldown = getNumber (configFile >> "CfgWeapons" >> _weapon >> "AGM_Overheating_Cooldown");

	_string = format ["AGM_Overheating_%1", _weapon];

	_overheat = player getVariable [_string, [0, 0]];
	_temperature = _overheat select 0;
	_time = _overheat select 1;

	_temperature = (_temperature - _cooldown * (time - _time)) max 0;

	if (!isNil "AGM_Debug" && {AGM_Debug == "Overheating"}) then {
		hintSilent format ["Temperature: %1%\nTime: %2s\nIncrement: %3\nCooldown: %4", _temperature * 100, time - _time, 0, _cooldown];
	};

	// Store new temperature
	_time = time;
	player setVariable [_string, [_temperature, _time], false];

	// Play animation and report temperature
	/*_animation = getText (configFile >> "CfgWeapons" >> _weapon >> "reloadAction");

	player playActionNow _animation;*/
	player playActionNow "Gear";

	sleep 2;

	_red = [255 * (2 * _temperature / MAX_TEMPERATURE min 1), 2] call AGM_Core_fnc_toHex;
	_green = [255 * (2 * (MAX_TEMPERATURE - _temperature) / MAX_TEMPERATURE min 1), 2] call AGM_Core_fnc_toHex;

	_picture = format ["<img size='2' color='#%1%200' image='%3'/>", _red, _green, getText (configFile >> "CfgWeapons" >> _weapon >> "picture")];
	//_line = "<t color='#" + _red + _green + "00'>" + localize "STR_AGM_Overheating_Temperature" + "</t>";

	_count = 2 + round (10 * _temperature / MAX_TEMPERATURE);
	_line = "<t color='#" + _red + _green + "00'>";
	for "_a" from 1 to _count do {
		_line = _line + "|";
	};
	_line = _line + "</t><t color='#555555'>";
	for "_a" from (_count + 1) to 12 do {
		_line = _line + "|";
	};
	_line = _line + "</t>";

	[formatText ["%1%2%3", parseText _picture, lineBreak, parseText _line]] call AGM_Core_fnc_displayText;
};
