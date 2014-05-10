// by commy2

_muzzle = (primaryWeaponItems player) select 0;
if (_muzzle == "") exitWith {
	0 spawn AGM_fnc_safeMode;
};
if (_muzzle == "AGM_muzzle_snds_SAFE") exitWith {
	if (AGM_isSafeMode) then {
		player removePrimaryWeaponItem "AGM_muzzle_snds_SAFE";

		_picture = format ["<img size='2' color='#ffffff' image='%1'/>", getText (configFile >> "CfgWeapons" >> primaryWeapon player >>  "picture")];
		[formatText ["%1%2%3", parseText _picture, lineBreak, localize "STR_AGM_SafeModeLifted"], true] call AGM_Core_fnc_displayText;
	};
};
