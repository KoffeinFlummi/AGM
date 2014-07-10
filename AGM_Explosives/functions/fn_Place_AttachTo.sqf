/*
	Name: AGM_Explosives_fnc_Place_AttachTo
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
	
	Parameters:
		OBJECT: Object to attach to.
	
	Returns:
		Nothing
	
	Example:
		cursorTarget call AGM_Explosives_fnc_Place_AttachTo;
*/
if (AGM_Explosives_pfeh_running) then {
	["AGM_Explosives_Placement","OnEachFrame"] call BIS_fnc_removeStackedEventHandler;
};
if(AGM_Explosives_Setup getVariable ["AGM_ExplosiveClass", ""] != "") then {
	private "_explosive";
	_explosive = [getPosATL AGM_Explosives_Setup, AGM_Explosives_Setup getVariable "AGM_ExplosiveClass", AGM_Explosives_Setup getVariable "AGM_DetonateCode", 180 + (getDir AGM_Explosives_Setup)] call AGM_Explosives_fnc_PlaceExplosive;
	deleteVehicle AGM_Explosives_Setup;
	AGM_Explosives_Null = [_explosive,_this] spawn {
		sleep 0.1;
		(_this select 0) attachTo [(_this select 1)];
	};
};
AGM_Explosives_Setup = objNull;