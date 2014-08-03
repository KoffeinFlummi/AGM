/*
	Name: AGM_Explosives_fnc_Place_AttachTo
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Attaches the explosive to the passed vehicle
	
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
	_dir = (getDir AGM_Explosives_Setup);
	if (_dir > 180) then {
		_dir = _dir - 180;
	} else {
		_dir = 180 + _dir;
	};
	_explosive = [player, getPosATL AGM_Explosives_Setup, _class, AGM_Explosives_Setup getVariable "AGM_DetonateCode", _dir,AGM_Explosives_Setup getVariable "AGM_Timer"] call AGM_Explosives_fnc_PlaceExplosive;
	AGM_Explosives_Null = [_explosive,_this, _class, _dir] spawn {
		sleep 0.1 + getNumber(ConfigFile >> "CfgMagazines" >> (_this select 2) >> "AGM_DelayTime");
		(_this select 0) attachTo [(_this select 1)];
		_dir = (_this select 3) - (getDir (_this select 1));
		(_this select 0) setDir _dir;
	};
	deleteVehicle AGM_Explosives_Setup;
	player RemoveMagazineGlobal _class;
};
AGM_Explosives_Setup = objNull;