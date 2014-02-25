// by commy2

_key = _this select 0;
_shft = _this select 1;
_ctrl = _this select 2;
_alt = _this select 3;
_isInput = false;

if (_key == 2 && {!_ctrl}) then {		//KEY 1
	if (!BWA3_WeaponSelect_keyDown) then {
		handgunWeapon player call BWA3_WeaponSelect_selectWeaponMode;
	};
	BWA3_WeaponSelect_keyDown = true;
	_isInput = true;
};

if (_key == 3 && {!_ctrl}) then {		//KEY 2
	if (!BWA3_WeaponSelect_keyDown) then {
		primaryWeapon player call BWA3_WeaponSelect_selectWeaponMode;
	};
	BWA3_WeaponSelect_keyDown = true;
	_isInput = true;
};

if (_key == 4 && {!_ctrl}) then {		//KEY 3
	if (!BWA3_WeaponSelect_keyDown) then {
		primaryWeapon player call BWA3_WeaponSelect_selectWeaponMuzzle;
	};
	BWA3_WeaponSelect_keyDown = true;
	_isInput = true;
};

if (_key == 5 && {!_ctrl}) then {		//KEY 4
	if (!BWA3_WeaponSelect_keyDown) then {
		secondaryWeapon player call BWA3_WeaponSelect_selectWeaponMode;
	};
	BWA3_WeaponSelect_keyDown = true;
	_isInput = true;
};

if (_key == 6 && {!_ctrl}) then {		//KEY 5
	if (!BWA3_WeaponSelect_keyDown) then {
		_weapons = weapons player - [handgunWeapon player] - [primaryWeapon player] - [secondaryWeapon player];
		_binocular = (
			if (count _weapons == 1) then {_weapons select 0} else {""}
		);
		_binocular call BWA3_WeaponSelect_selectWeaponMode;
	};
	BWA3_WeaponSelect_keyDown = true;
	_isInput = true;
};

if (_key == 7 && {!_ctrl}) then {		//KEY 6
	if (!BWA3_WeaponSelect_keyDown) then {
		handgunWeapon player call BWA3_WeaponSelect_selectWeaponMuzzle;
	};
	BWA3_WeaponSelect_keyDown = true;
	_isInput = true;
};

if (_key == 8 && {!_ctrl}) then {		//KEY 7
	if (!BWA3_WeaponSelect_keyDown) then {
		secondaryWeapon player call BWA3_WeaponSelect_selectWeaponMuzzle;
	};
	BWA3_WeaponSelect_keyDown = true;
	_isInput = true;
};

if (_key == 9 && {!_ctrl}) then {		//KEY 8
	_isInput = true;
};

if (_key == 10 && {!_ctrl}) then {		//KEY 9
	_isInput = true;
};

if (_key == 11 && {!_ctrl}) then {		//KEY 0
	if (!BWA3_WeaponSelect_keyDown) then {
		player action ["SwitchWeapon", vehicle player, vehicle player, 99];
	};
	BWA3_WeaponSelect_keyDown = true;
	_isInput = true;
};
_isInput
