// by commy2

_weapon = currentWeapon player;

if (!("AGM_muzzle_snds_SAFE" in getArray (configFile >> "CfgWeapons" >> _weapon >> "WeaponSlotsInfo" >> "MuzzleSlot" >> "compatibleItems")) || {!(AGM_allowSafeMode select 0)}) exitWith {};

AGM_isSafeMode = true;

_fnc_normalize = {
	player action ["SwitchWeapon", player, player, 99];
	player selectWeapon primaryWeapon player;
};

_fnc_addSilencer = {
	player setWeaponReloadingTime [player, primaryWeapon player, 0.01];
	player addPrimaryWeaponItem "AGM_muzzle_snds_SAFE";
	player setWeaponReloadingTime [player, primaryWeapon player, 0.01];
};

call _fnc_normalize;
call _fnc_addSilencer;

_picture = format ["<img size='2' color='#ffffff' image='%1'/>", getText (configFile >> "CfgWeapons" >> _weapon >>  "picture")];
[formatText ["%1%2%3", parseText _picture, lineBreak, localize "STR_AGM_SafeMode"], true] call AGM_Core_fnc_displayText;

waitUntil {
	if (dialog) then {
		player removePrimaryWeaponItem "AGM_muzzle_snds_SAFE";
		waitUntil {
			player setWeaponReloadingTime [player, primaryWeapon player, 0.01];
			!dialog
		};
		call _fnc_addSilencer;
	};
	!("AGM_muzzle_snds_SAFE" in primaryWeaponItems player) || {currentWeapon player != _weapon} || {player != vehicle player} || {inputAction "NextWeapon" > 0}
};

player removePrimaryWeaponItem "AGM_muzzle_snds_SAFE";

if (inputAction "NextWeapon" > 0) then {sleep 0.01};
if (currentWeapon player == _weapon) then {call _fnc_normalize};

AGM_isSafeMode = false;
