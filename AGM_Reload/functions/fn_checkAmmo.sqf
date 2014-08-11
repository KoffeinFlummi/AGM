// by commy2

#define COUNT_BARS 12

_this spawn {
	_vehicle = _this select 0;
	_weapon = _this select 1;
	_muzzle = _this select 2;
	_magazine = _this select 3;
	_skipDelay = _this select 4;

	_showNumber = false;
	_ammo = 0;
	_maxRounds = 1;
	_count = 0;

	// not grenade launcher
	if (_muzzle == _weapon) then {
		_maxRounds = getNumber (configFile >> "CfgMagazines" >> _magazine >> "count") max 1;

		_ammo = _vehicle ammo _weapon;
		if (_maxRounds >= COUNT_BARS) then {
			_count = round (COUNT_BARS * _ammo / _maxRounds);

			if (_ammo > 0) then {_count = _count max 1};
			if (_ammo < _maxRounds) then {_count = _count min (COUNT_BARS - 1)};
		} else {
			_count = _ammo;
		};

	// grenade launcher
	} else {
		_showNumber = true;

		if (_magazine != "") then {
			_count = {_x == _magazine} count (magazines _vehicle + [_magazine]);
		} else {
			_count = {_x in getArray (configFile >> "CfgWeapons" >> _weapon >> _muzzle >> "Magazines")} count magazines _vehicle;
		}
	};

	if !(_skipDelay) then {
		player playActionNow "Gear";
		sleep 1
	};

	_text = if (_showNumber) then {
		parseText format ["<t align='center' >%1x</t>", _count]
	} else {
		_color = [
			2 * (1 - _ammo / _maxRounds) min 1,
			2 * _ammo / _maxRounds min 1,
			00
		];

		_string = "";
		for "_a" from 1 to _count do {
			_string = _string + "|";
		};
		_text = [_string, _color] call AGM_Core_fnc_stringToColoredText;

		_string = "";
		for "_a" from (_count + 1) to (_maxRounds min COUNT_BARS) do {
			_string = _string + "|";
		};

		composeText [
			_text,
			[_string, [0.5, 0.5, 0.5]] call AGM_Core_fnc_stringToColoredText
		]
	};

	_picture = getText (configFile >> "CfgMagazines" >> _magazine >> "picture");

	[_text, _picture] call AGM_Core_fnc_displayTextPicture;
};
