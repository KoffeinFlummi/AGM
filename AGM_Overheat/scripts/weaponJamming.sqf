// by commy2

AGM_isWeaponJammed = true;

waitUntil {
	player setWeaponReloadingTime [player, currentWeapon player, 0.55];
	!AGM_isWeaponJammed || {inputAction "reloadMagazine" > 0}
};

AGM_isWeaponJammed = false;
