// by commy2

player addEventHandler ["Take", {
	if (_this select 0 == _this select 1 && {isClass (configFile >> "CfgMagazines" >> _this select 2)}) then {
		[currentWeapon vehicle player, vehicle player, true] call AGM_Reload_fnc_checkAmmo;
	};
}];
