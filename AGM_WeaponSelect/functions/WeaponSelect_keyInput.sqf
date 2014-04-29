// by commy2

_key = _this select 0;
_shft = _this select 1;
_ctrl = _this select 2;
_alt = _this select 3;
_isInput = false;

if (_key == 2 && {!_ctrl}) then {		//KEY 1
	if (!AGM_WeaponSelect_keyDown) then {
		handgunWeapon player call AGM_WeaponSelect_selectWeaponMode;
	};
	AGM_WeaponSelect_keyDown = true;
	_isInput = true;
};

if (_key == 3 && {!_ctrl}) then {		//KEY 2
	if (!AGM_WeaponSelect_keyDown) then {
		primaryWeapon player call AGM_WeaponSelect_selectWeaponMode;
	};
	AGM_WeaponSelect_keyDown = true;
	_isInput = true;
};

if (_key == 4 && {!_ctrl}) then {		//KEY 3
	if (!AGM_WeaponSelect_keyDown) then {
		primaryWeapon player call AGM_WeaponSelect_selectWeaponMuzzle;
	};
	AGM_WeaponSelect_keyDown = true;
	_isInput = true;
};

if (_key == 5 && {!_ctrl}) then {		//KEY 4
	if (!AGM_WeaponSelect_keyDown) then {
		secondaryWeapon player call AGM_WeaponSelect_selectWeaponMode;
	};
	AGM_WeaponSelect_keyDown = true;
	_isInput = true;
};

if (_key == 6 && {!_ctrl}) then {		//KEY 5
	if (!AGM_WeaponSelect_keyDown) then {
		_weapons = weapons player - [handgunWeapon player] - [primaryWeapon player] - [secondaryWeapon player];
		_binocular = (
			if (count _weapons == 1) then {_weapons select 0} else {""}
		);
		_binocular call AGM_WeaponSelect_selectWeaponMode;
	};
	AGM_WeaponSelect_keyDown = true;
	_isInput = true;
};

if (_key == 7 && {!_ctrl}) then {		//KEY 6
	if (!AGM_WeaponSelect_keyDown) then {
		handgunWeapon player call AGM_WeaponSelect_selectWeaponMuzzle;
	};
	AGM_WeaponSelect_keyDown = true;
	_isInput = true;
};

if (_key == 8 && {!_ctrl}) then {		//KEY 7
	if (!AGM_WeaponSelect_keyDown) then {
		secondaryWeapon player call AGM_WeaponSelect_selectWeaponMuzzle;
	};
	AGM_WeaponSelect_keyDown = true;
	_isInput = true;
};

if (_key == 9 && {!_ctrl}) then {		//KEY 8
	_isInput = true;
};

if (_key == 10 && {!_ctrl}) then {		//KEY 9
	_isInput = true;
};

if (_key == 11 && {!_ctrl}) then {		//KEY 0
	if (!AGM_WeaponSelect_keyDown) then {
		player action ["SwitchWeapon", vehicle player, vehicle player, 99];
	};
	AGM_WeaponSelect_keyDown = true;
	_isInput = true;
};
_isInput
