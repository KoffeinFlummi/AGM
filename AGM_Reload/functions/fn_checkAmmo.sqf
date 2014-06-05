// by commy2

_this spawn {
	_weapon = _this select 0;

	_magazine = switch (_weapon) do {
		case (primaryWeapon player) : {primaryWeaponMagazine player select 0};
		case (secondaryWeapon player) : {secondaryWeaponMagazine player select 0};
		case (handgunWeapon player) : {handgunMagazine player select 0};
	};

	_ammo = if (isNil "_magazine") then {0} else {
		(player ammo _weapon) / getNumber (configFile >> "CfgMagazines" >> _magazine >> "count");
	};

	_animation = getText (configFile >> "CfgWeapons" >> _weapon >> "reloadAction");

	player playActionNow _animation;

	sleep 2.5;

	_red = [255 * (2 * (1 - _ammo) min 1), 2] call AGM_Core_fnc_toHex;
	_green = [255 * (2 * _ammo min 1), 2] call AGM_Core_fnc_toHex;

	_picture = if (isNil "_magazine") then {""} else {
		format ["<img size='2' color='#%1%200' image='%3'/>", _red, _green, getText (configFile >> "CfgMagazines" >> _magazine >> "picture")];
	};

	_line = "<t color='#" + _red + _green + "00'>" + localize "STR_AGM_Reload_Ammo" + "</t>";

	[formatText ["%1%2%3", parseText _picture, lineBreak, parseText _line]] call AGM_Core_fnc_displayText;
};
