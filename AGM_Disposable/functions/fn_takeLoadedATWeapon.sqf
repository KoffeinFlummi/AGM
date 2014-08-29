// by commy2

_weapon = getText (configFile >> 'CfgWeapons' >> _this select 2 >> 'AGM_LauncherClass');
_magazine = getText (configFile >> 'CfgWeapons' >> _this select 2 >> 'AGM_LauncherMagazine');

if (backpack player == "") then {
	player addBackpack "Bag_Base";

	player addMagazine _magazine;
	player addWeapon _weapon;

	removeBackpack player;
} else {
	player addMagazine _magazine;
	player addWeapon _weapon;
};

