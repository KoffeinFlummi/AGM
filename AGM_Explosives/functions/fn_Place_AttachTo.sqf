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
	AGM_Explosives_pfeh_running = false;
};
private ["_class", "_explosive"];
_class = AGM_Explosives_Setup getVariable ["AGM_ExplosiveClass", ""];
if(_class != "") then {
	private "_explosive";
	_explosive = [getPosATL AGM_Explosives_Setup, _class, AGM_Explosives_Setup getVariable "AGM_DetonateCode", 180 + (getDir AGM_Explosives_Setup)] call AGM_Explosives_fnc_PlaceExplosive;
	AGM_Explosives_Null = [_explosive,_this, _class] spawn {
		sleep 0.1 + getNumber(ConfigFile >> "CfgMagazines" >> (_this select 2) >> "AGM_DelayTime");
		(_this select 0) attachTo [(_this select 1)];
	};
	deleteVehicle AGM_Explosives_Setup;
	player RemoveMagazineGlobal _class;
};
AGM_Explosives_Setup = objNull;