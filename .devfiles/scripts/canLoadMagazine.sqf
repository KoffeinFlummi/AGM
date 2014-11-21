// by commy2

private ["_vehicle", "_magazine", "_weapon"];

_vehicle = _this select 0;
_magazine = _this select 1;
_weapon = (_this call AGM_Logistics_getWeaponsOfMagazine) select 0;

if (
	isNil "_magazine" ||
	//{!(_magazine in (magazines player + magazineCargo _vehicle))}
	{!(_magazine in magazines player)}
) exitWith {false};

if (getNumber (configFile >> "CfgMagazines" >> _magazine >> "AGM_MagazineReloadType") == 1) then {
	_magazine = [_vehicle, _magazine] call AGM_Logistics_getMagazineOfVehicle;

	if (_magazine == "") exitWith {
		systemChat "ERROR: Mag not found";
		false
	};

	_vehicle ammo _weapon < getNumber (configFile >> "CfgMagazines" >> _magazine >> "count");
} else {true}
