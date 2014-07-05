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
	player playActionNow "Gear";

	sleep 1;

	_color = [
		2 * _temperature / MAX_TEMPERATURE min 1,
		2 * (MAX_TEMPERATURE - _temperature) / MAX_TEMPERATURE min 1,
		00
	];

	_count = 2 + round (10 * _temperature / MAX_TEMPERATURE);
	_string = "";
	for "_a" from 1 to _count do {
		_string = _string + "|";
	};
	_text = [_string, _color] call AGM_Core_fnc_stringToColoredText;

	_string = "";
	for "_a" from (_count + 1) to 12 do {
		_string = _string + "|";
	};

	_text = composeText [
		_text,
		[_string, [0.5, 0.5, 0.5]] call AGM_Core_fnc_stringToColoredText
	];

	_picture = getText (configFile >> "CfgWeapons" >> _weapon >> "picture");

	[_text, _picture] call AGM_Core_fnc_displayTextPicture;
};
