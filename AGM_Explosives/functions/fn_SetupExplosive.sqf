/*
	Name: AGM_Explosives_fnc_SetupExplosive
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Starts the setup process for the passed IED.
	
	Parameters:
		0: OBJECT - Unit placing IED.
		1: STRING - Classname of IED to place. (CfgMagazine class)
	
	Returns:
		Nothing
	
	Example:
		[player, "SatchelCharge_Remote_Mag"] call AGM_Explosives_fnc_SetupExplosive;
*/
_this spawn {
	private ["_explosiveClass", "_code", "_unit", "_count"];
	_explosiveClass = _this select 1;
	_unit = _this select 0;
	sleep 0.03;
	_code = str(round (random 9999));
	_count = 4 - count (toArray _code);
	while {_count > 0} do {
		_code = "0" + _code;
		_count = _count - 1;
	};
	
	AGM_Explosives_Setup = getText(ConfigFile >> "CfgMagazines" >> _explosiveClass >> "AGM_SetupObject") createVehicleLocal [0,0,-10000];
	
	AGM_Explosives_Setup enableSimulation false;
	AGM_Explosives_Setup setVariable ["AGM_ExplosiveClass", _explosiveClass];
	AGM_Explosives_Setup setVariable ["AGM_DetonateCode", _code];

	["AGM_Explosives_Placement","OnEachFrame", {
		AGM_Explosives_pfeh_running = true;
		AGM_Explosives_Setup setPos (positionCameraToWorld [0,0,1]);
	}] call BIS_fnc_addStackedEventHandler;
};
true