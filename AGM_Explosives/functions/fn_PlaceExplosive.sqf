/*
	Name: AGM_Explosives_fnc_PlaceExplosive
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Places an explosive at the requested position
	
	Parameters:
		0: OBJECT - unit
		1: POSITION - Position to place explosive
		2: STRING - Magazine class
		3: STRING - Code for remote Explosives (only used for cellphone based explosives)
		4: NUMBER - Rotation
		5: NUMBER - (OPTIONAL) timer
	
	Returns:
		OBJECT: Placed explosive
	
	Example:
		_explosive = [player modelToWorld [0,0.5, 0.1], "SatchelCharge_Remote_Mag", "", 134] call AGM_Explosives_fnc_PlaceExplosive;
*/
private ["_pos", "_ammo", "_explosive", "_code"];
_pos = _this select 1;
_code = _this select 3;
_mag = _this select 2;
_ammo = getText(configFile >> "CfgMagazines" >> _mag >> "ammo");
_unit = _this select 0;

_explosive = createVehicle [_ammo, _pos, [], 0, "NONE"];
_explosive setDir (_this select 4);
_explosive setPosATL _pos;

if (getText(configFile >> "CfgMagazines" >> _mag >> "AGM_OnCreate") != "") then {
	_explosive spawn compile (getText(configFile >> "CfgMagazines" >> _mag >> "AGM_OnCreate"));
};
private ["_triggerSupport"];
_triggerSupport = _this select 5; // check for a timer
if (!isNil "_triggerSupport") exitWith {
	[_explosive, _triggerSupport] call AGM_Explosives_fnc_startTimer;
	_explosive
};
// Set up trigger types for explosive.
_triggerSupport = [_mag] call AGM_Explosives_fnc_TriggerType;
// clacker enabled
if (_triggerSupport select 0 && {"AGM_Clacker" in (items _unit)}) then {
	private "_clacker";
	_clacker = _unit getVariable ["AGM_Clacker", []];
	AGM_Explosives_PlacedCount = AGM_Explosives_PlacedCount + 1;
	_clacker set [count _clacker, [_explosive, getNumber(configFile >> "CfgMagazines" >> _mag >> "AGM_FuseTime"),getNumber (configFile >> "CfgMagazines" >> _mag >> "AGM_MaxDistance"), "E: " + str(AGM_Explosives_PlacedCount),_mag]];
	_unit setVariable ["AGM_Clacker", _clacker, true];
	_unit sideChat format [localize "STR_AGM_Explosives_DetonateCode", AGM_Explosives_PlacedCount];
};
// Cellphone enabled
if (_triggerSupport select 2) then {
	AGM_Explosives_List set [count AGM_Explosives_List, [_explosive,_code,getNumber(configFile >> "CfgMagazines" >> _mag >> "AGM_FuseTime"),getNumber (configFile >> "CfgMagazines" >> _mag >> "AGM_MaxDistance")]];
	publicVariable "AGM_Explosives_List";
	AGM_Explosives_PlacedCount = AGM_Explosives_PlacedCount + 1;
	[format ["E: %1", AGM_Explosives_PlacedCount],_code] call AGM_Explosives_fnc_AddCodeToSpeedDial;
	_unit sideChat format [localize "STR_AGM_Explosives_DetonateCode", _code];
};

_explosive