// by commy2

private ["_vehicle", "_magazine", "_weapon"];

_vehicle = _this select 0;
_magazine = _this select 1;
_weapon = (_this call AGM_Logistics_fnc_getWeaponsOfMagazine) select 0;

if (isNil "_magazine" || {!(_magazine in (magazines player + magazineCargo _vehicle))}) exitWith {false};

if (getNumber (configFile >> "CfgMagazines" >> _magazine >> "AGM_MagazineReloadType") == 1) then {
	_magazine = getArray (configFile >> "CfgMagazines" >> _magazine >> "AGM_Magazines") select 0;	//@todo 1agm_mag different a3_mags		maybe use _weapon to get it?
	_vehicle ammo _weapon < getNumber (configFile >> "CfgMagazines" >> _magazine >> "count");
} else {true}
