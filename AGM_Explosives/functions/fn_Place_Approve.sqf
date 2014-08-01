/*
	Name: AGM_Explosives_fnc_Place_Approve
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Approves placement of the explosive, releases the placement object for it to settle in a location suitable for the explosive to be created.
	
	Parameters:
		Nothing
	
	Returns:
		Nothing
	
	Example:
		spawn AGM_Explosives_fnc_Place_Approve;
*/
if (AGM_Explosives_pfeh_running) then {
	["AGM_Explosives_Placement","OnEachFrame"] call BIS_fnc_removeStackedEventHandler;
	AGM_Explosives_pfeh_running = false;
};
private "_explosive";
_explosive = AGM_Explosives_Setup getVariable ["AGM_ExplosiveClass", ""];
if (_explosive != "") then {
	private ["_pos", "_oldPos", "_limiter"];
	_pos = -5;
	_oldPos = -1;
	_limiter = 0;
	_dir = (getDir AGM_Explosives_Setup);
	if (_dir > 180) then {
		_dir = _dir - 180;
	} else {
		_dir = 180 + _dir;
	};
	AGM_Explosives_Setup enableSimulation true;
	while {_pos != _oldPos AND _limiter < 10} do {
		sleep 0.1;
		_oldPos = _pos;
		_pos = (GetPosATL AGM_Explosives_Setup) select 2;
		_limiter = _limiter + 0.1;
	};
	sleep getNumber(ConfigFile >> "CfgMagazines" >> _explosive >> "AGM_DelayTime");
	// Position, Mag Class, code
	[player, GetPosATL AGM_Explosives_Setup, _explosive, AGM_Explosives_Setup getVariable "AGM_DetonateCode", _dir,AGM_Explosives_Setup getVariable "AGM_Timer"] call AGM_Explosives_fnc_PlaceExplosive;
	player RemoveMagazineGlobal _explosive;
};
deleteVehicle AGM_Explosives_Setup;
AGM_Explosives_Setup = objNull;