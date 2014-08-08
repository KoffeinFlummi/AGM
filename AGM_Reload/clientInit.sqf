// by commy2

player addEventHandler ["Take", {
	if (_this select 0 == _this select 1 && {_this select 2 == currentMagazine player}) then {
		_vehicle = vehicle player;
		[_vehicle, currentWeapon _vehicle, currentMuzzle _vehicle, currentMagazine _vehicle, true] call AGM_Reload_fnc_checkAmmo;
	};
}];
