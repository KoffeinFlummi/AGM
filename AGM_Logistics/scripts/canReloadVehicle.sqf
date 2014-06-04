// by commy2

/*WIP*/

_vehicle = _this select 0;

_magazinesCargo = magazines player + magazineCargo _vehicle;

_vehicleWeapons = weapons _vehicle;
_vehicleMagazines = [];

{_vehicleMagazines + getArray (configFile >> "CfgWeapons" >> _x >> "magazines")} forEach _vehicleWeapons;

_vehicleMagazinesCurrent = magazines _vehicle;

{




	_reloadMagazines = getArray (configFile >> "CfgMagazines" >> _x >> "AGM_Magazines");

	if (
		_vehicleMagazines - _reloadMagazines
	) then {;


	_array - [_x]
} forEach _magazinesCargo;




_vehicle setAmmo [_weapon, (_vehicle ammo _weapon) + 1];



AGM_Logistics_ReloadActions {
	class "Titan_AA" {
		type = 1;
		magazine = "missiles_titan";
		weapon = "";
	};
};



