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
private ["_mag", "_setup"];
_setup = AGM_Explosives_Setup;
AGM_Explosives_Setup = objNull;
player forceWalk false;
player setVariable ["AGM_PlantingExplosive", true];
_mag = _setup getVariable ["AGM_Class", ""];
if (_mag != "") then {
	private ["_pos", "_oldPos", "_limiter", "_fnc_SimilarPos"];
	_pos = -5;
	_oldPos = -1;
	_limiter = 0;
	_dir = (getDir _setup);
	if (_dir > 180) then {
		_dir = _dir - 180;
	} else {
		_dir = 180 + _dir;
	};
	_fnc_SimilarPos = {
		_pos1 = _this select 0;
		_pos2 = _this select 1;
		((_pos1 - _pos2) < 0.05)
	};
	_setup enableSimulationGlobal true;
	player playActionNow "MedicOther";
	sleep 0.2;
	while {!([_pos,_oldPos] call _fnc_SimilarPos) AND _limiter < 10} do {
		sleep 0.1;
		_oldPos = _pos;
		_pos = (GetPosATL _setup) select 2;
		_limiter = _limiter + 0.1;
	};
	player setVariable ["AGM_PlantingExplosive", false];
	sleep getNumber(ConfigFile >> "CfgMagazines" >> _mag >> "AGM_DelayTime");
	if (!isNull([player, GetPosATL _setup, _dir, _mag, _setup getVariable "AGM_Trigger", [_setup getVariable "AGM_Timer"]] call AGM_Explosives_fnc_PlaceExplosive)) then {
		player RemoveMagazine _mag;
	};
};
deleteVehicle _setup;