// by commy2

_jammedWeapon = _this select 0;

AGM_isWeaponJammed = true;

[localize "STR_AGM_WeaponJammed"] call AGM_Core_fnc_displayText;

waitUntil {
	_weapon = currentWeapon player;
	player setWeaponReloadingTime [player, _weapon, 0.55];
	!AGM_isWeaponJammed || {_weapon != _jammedWeapon} || {player != vehicle player} || {inputAction "reloadMagazine" > 0}
};

AGM_isWeaponJammed = false;
