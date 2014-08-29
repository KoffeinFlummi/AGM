// by commy2

_vehicle = _this select 0;
_magazine = _this select 1;
_weapon = _this select 2;

if !(_this call AGM_Logistics_canLoadMagazine) exitWith {};

if (_magazine in magazines player) then {
	player removeMagazine _magazine;
} else {
	systemChat "-.-";
};

if (getNumber (configFile >> "CfgMagazines" >> _magazine >> "AGM_MagazineReloadType") == 1) then {
	_vehicle setAmmo [_weapon, (_vehicle ammo _weapon) + 1];
} else {
	_vehicle addMagazineGlobal _magazine;
};
