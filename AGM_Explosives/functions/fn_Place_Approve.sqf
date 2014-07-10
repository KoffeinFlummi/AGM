/*
	Name: AGM_Explosives_fnc_Place_Approve
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
	
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
	AGM_Explosives_Setup enableSimulation true;
	while {_pos != _oldPos AND _limiter < 10} do {
		sleep 0.1;
		_oldPos = _pos;
		_pos = (GetPosATL AGM_Explosives_Setup) select 2;
		_limiter = _limiter + 0.1;
	};
	sleep getNumber(ConfigFile >> "CfgMagazines" >> _explosive >> "AGM_DelayTime");
	// Position, Mag Class, code
	[GetPosATL AGM_Explosives_Setup, _explosive, AGM_Explosives_Setup getVariable "AGM_DetonateCode", 180 + (getDir AGM_Explosives_Setup)] call AGM_Explosives_fnc_PlaceExplosive;
	player RemoveMagazineGlobal _explosive;
};
deleteVehicle AGM_Explosives_Setup;
AGM_Explosives_Setup = objNull;