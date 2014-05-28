// by commy2

AGM_isSafeMode = false;
AGM_allowSafeMode = [true, 0];

AGM_fnc_safeMode = compile preprocessFileLineNumbers "\agm_safemode\scripts\safeMode.sqf";
AGM_SafeMode_toggleSafeMode = compile preprocessFileLineNumbers "\agm_safemode\scripts\toggleSafeMode.sqf";
AGM_SafeMode_takeEH = compile preprocessFileLineNumbers "\agm_safemode\scripts\takeEH.sqf";
AGM_SafeMode_firedEH = compile preprocessFileLineNumbers "\agm_safemode\scripts\firedEH.sqf";




/*

overheat var

AGM_fnc_safeMode = {
	_weapon = currentWeapon player;

	player setWeaponReloadingTime [player, _weapon, 0.01];
	player addPrimaryWeaponItem "AGM_muzzle_snds_SAFE";
	player setWeaponReloadingTime [player, _weapon, 0.01];

	waitUntil {
		if (dialog) then {
			player removePrimaryWeaponItem "AGM_muzzle_snds_SAFE";
			waitUntil {!dialog};
			player setWeaponReloadingTime [player, _weapon, 0.01];
			player addPrimaryWeaponItem "AGM_muzzle_snds_SAFE";
			player setWeaponReloadingTime [player, _weapon, 0.01];
		};
		!("AGM_muzzle_snds_SAFE" in primaryWeaponItems player) || {currentWeapon player != _weapon}
	};

	player removePrimaryWeaponItem "AGM_muzzle_snds_SAFE";
};

AGM_SafeMode_toggleSafeMode = {
	_muzzle = (primaryWeaponItems player) select 0;
	if (_muzzle == "") exitWith {
		0 spawn AGM_fnc_safeMode;
	};
	if (_muzzle == "AGM_muzzle_snds_SAFE") exitWith {
		player removePrimaryWeaponItem "AGM_muzzle_snds_SAFE";
	};
};

*/
