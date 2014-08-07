/*
	Name: AGM_Explosives_fnc_SetupExplosive
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Starts the setup process for the passed explosive.
	
	Parameters:
		0: OBJECT - Unit placing explosive.
		1: STRING - Classname of explosive to place. (CfgMagazine class)
		2: Config - Trigger Config
		3: NUMBER - (optional) timer
	
	Returns:
		Nothing
	
	Example:
		[player, "SatchelCharge_Remote_Mag", "Command"] call AGM_Explosives_fnc_SetupExplosive;
*/
_this spawn {
	private ["_unit", "_class", "_config", "_timer"];
	_unit = _this select 0;
	_class = _this select 1;
	_config = _this select 2;
	_timer = _this select 3;
	// Commented out due to the fact there is a distinction between who can deactivate mines and who can plant them in standard configs.
	// Would require custom config entries (AGM_ExplosiveSpecialist/AGM_Specialist) which excludes custom mods.
	//if ((AGM_Explosives_RequireSpecialist > 0) && {!(_unit call AGM_Explosives_fnc_isSpecialist)}) exitWith {};
	if (isNil "_config") then {
		_config = getArray(ConfigFile >> "CfgMagazines" >> _class >> "AGM_Triggers" >> "AGM_Triggers") select 0;
	};
	
	AGM_Explosives_Setup = getText(ConfigFile >> "CfgMagazines" >> _class >> "AGM_SetupObject") createVehicleLocal [0,0,-10000];
	
	AGM_Explosives_Setup enableSimulation false;
	AGM_Explosives_Setup setVariable ["AGM_Class", _class];
	AGM_Explosives_Setup setVariable ["AGM_Trigger", _config];
	if (!isNil "_timer") then {
		AGM_Explosives_Setup setVariable ["AGM_Timer", _timer];
	};
	
	_unit forceWalk true;
	AGM_Explosives_TweakedAngle = 180;
	["AGM_Explosives_Placement","OnEachFrame", {
		AGM_Explosives_pfeh_running = true;
		_pos = (eyePos player) vectorAdd (positionCameraToWorld [0,0,1] vectorDiff positionCameraToWorld [0,0,0]);
		AGM_Explosives_Setup setPosASL _pos;
		if (!AGM_Explosives_Shiftdown) then {
			AGM_Explosives_Setup setDir (AGM_Explosives_TweakedAngle + getDir player);
		};
	}] call BIS_fnc_addStackedEventHandler;
};