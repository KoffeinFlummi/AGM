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
["AGM_Explosives_Placement","OnEachFrame"] call BIS_fnc_removeStackedEventHandler;
if (AGM_Explosives_Setup getVariable ["AGM_ExplosiveClass", ""] != "") then {
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
	// Position, AMMO Class, code
	[GetPosATL AGM_Explosives_Setup, AGM_Explosives_Setup getVariable "AGM_ExplosiveClass", AGM_Explosives_Setup getVariable "AGM_DetonateCode", 180 + (getDir AGM_Explosives_Setup)] call AGM_Explosives_fnc_PlaceExplosive;
	deleteVehicle AGM_Explosives_Setup;
};
AGM_Explosives_Setup = objNull;