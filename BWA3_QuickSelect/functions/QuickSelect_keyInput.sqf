// by commy2

_key = _this select 0;
_shft = _this select 1;
_ctrl = _this select 2;
_alt = _this select 3;
_isInput = false;

if (_key == 2) then {		//KEY 1
	if (!BWA3_QuickSelect_keyDown) then {
		_weapon = handgunWeapon player;
		if (currentWeapon player == _weapon) then {
			[_weapon] call BWA3_QuickSelect_selectWeaponMode;
		} else {
			player selectWeapon _weapon;
		};
	};

	BWA3_QuickSelect_keyDown = true;
	_isInput = true;
};

if (_key == 3) then {		//KEY 2
	if (!BWA3_QuickSelect_keyDown) then {
		/*_weapon = primaryWeapon player;
		if (currentWeapon player == _weapon) then {
			[_weapon] call BWA3_QuickSelect_selectWeaponMode;
		} else {
			player selectWeapon _weapon;
		};*/
	};

	BWA3_QuickSelect_keyDown = true;
	_isInput = true;
};

if (_key == 4) then {		//KEY 3
	if (!BWA3_QuickSelect_keyDown) then {
		_weapon = primaryWeapon player;
		if (currentWeapon player == _weapon) then {
			[_weapon] call BWA3_QuickSelect_selectWeaponMode;
		} else {
			player selectWeapon _weapon;
		};
	};

	BWA3_QuickSelect_keyDown = true;
	_isInput = true;
};

if (_key == 5) then {		//KEY 4
	if (!BWA3_QuickSelect_keyDown) then {
		_weapon = primaryWeapon player;
		player selectWeapon _weapon;
		[_weapon] call BWA3_QuickSelect_selectWeaponMuzzle;
	};

	BWA3_QuickSelect_keyDown = true;
	_isInput = true;
};

if (_key == 6) then {		//KEY 5
	if (!BWA3_QuickSelect_keyDown) then {
		_weapon = secondaryWeapon player;
		if (currentWeapon player == _weapon) then {
			[_weapon] call BWA3_QuickSelect_selectWeaponMode;
		} else {
			player selectWeapon _weapon;
		};
	};

	BWA3_QuickSelect_keyDown = true;
	_isInput = true;
};

if (_key == 11) then {	//KEY 0
	if (!BWA3_QuickSelect_keyDown) then {
		player action ["SwitchWeapon", vehicle player, vehicle player, 99];
	};

	BWA3_QuickSelect_keyDown = true;
	_isInput = true;
};
_isInput
