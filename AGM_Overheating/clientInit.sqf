// by commy2

//give spare barrel
_this spawn {
	waitUntil {!isNull (findDisplay 46)};
	if (getNumber (configFile >> "CfgWeapons" >> currentWeapon player >> "AGM_Overheating_allowSwapBarrel") == 1) then {
		player addItem "AGM_SpareBarrel"; 
	};
};
