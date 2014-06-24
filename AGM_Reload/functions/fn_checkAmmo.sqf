// by commy2

_this spawn {
	_weapon = _this select 0;
	_skipDelay = _this select 1;

	_magazine = switch (_weapon) do {
		case (primaryWeapon player) : {primaryWeaponMagazine player select 0};
		case (secondaryWeapon player) : {secondaryWeaponMagazine player select 0};
		case (handgunWeapon player) : {handgunMagazine player select 0};
	};

	_ammo = if (isNil "_magazine") then {0} else {
		(player ammo _weapon) / getNumber (configFile >> "CfgMagazines" >> _magazine >> "count");
	};

	if !(_skipDelay) then {
		player playActionNow "Gear";
		sleep 1
	};

	_color = [
		2 * (1 - _ammo) min 1,
		2 * _ammo min 1,
		00
	];

	_count = round (10 * _ammo);
	_string = "";
	for "_a" from 1 to _count do {
		_string = _string + "|";
	};
	_text = [_string, _color] call AGM_Core_fnc_stringToColoredText;

	_string = "";
	for "_a" from (_count + 1) to 10 do {
		_string = _string + "|";
	};

	_text = composeText [
		_text,
		[_string, [0.5, 0.5, 0.5]] call AGM_Core_fnc_stringToColoredText
	];

	_picture = getText (configFile >> "CfgMagazines" >> _magazine >> "picture");

	[_text, _picture] call AGM_Core_fnc_displayTextPicture;
};
