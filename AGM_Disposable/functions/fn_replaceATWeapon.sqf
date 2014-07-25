// by commy2

_unit = _this select 0;
_weapon = getText (configFile >> 'CfgWeapons' >> _this select 1 >> 'AGM_UsedTube');
_items = secondaryWeaponItems _unit;

_unit addWeapon _weapon;
_unit selectWeapon _weapon;
{
	if (_x != "") then {_unit addSecondaryWeaponItem _x};
} forEach _items;
