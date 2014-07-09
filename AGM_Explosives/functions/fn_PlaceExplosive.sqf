/*
	Name: AGM_Explosives_fnc_PlaceExplosive
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		
	
	Parameters:
		0: POSITION - Position to place IED
		1: STRING - Ammo class
		2: STRING - Code for remote Explosives
		3: NUMBER - Rotation
	
	Returns:
		OBJECT: Placed IED
	
	Example:
		// cellphone IED
		_explosive = [player modelToWorld [0,0.5, 0.1], "AGM_Explosives_explosive_Cellphone_Short_Mortar_12VBattery", "13112", 134] call AGM_Explosives_fnc_PlaceExplosive;
		// Clacker IED
		_explosive = [player modelToWorld [0,0.5, 0.1], "AGM_Explosives_explosive_Clacker_Short_Mortar_12VBattery", "", 45] call AGM_Explosives_fnc_PlaceExplosive;
*/
private ["_pos", "_ammo", "_explosive", "_code"];
_pos = _this select 0;
_ammo = getText(configFile >> "CfgMagazines" >> (_this select 1) >> "ammo");
_code = _this select 2;

_explosive = createVehicle [_ammo, _pos, [], 0, "NONE"];
_explosive setDir (_this select 3);
_explosive setPosATL _pos;

if (getText(configFile >> "CfgMagazines" >> (_this select 1) >> "AGM_OnCreate") != "") then {
	_explosive spawn compile (getText(configFile >> "CfgMagazines" >> (_this select 1) >> "AGM_OnCreate"));
};

switch (getNumber(configFile >> "CfgMagazines" >> (_this select 1) >> "AGM_Explosives_Type")) do {
	case TYPE_Cellphone:
	{
		AGM_Explosives_List set [count AGM_Explosives_List, [_explosive,_code,getNumber(configFile >> "CfgMagazines" >> (_this select 1) >> "AGM_FuseTime"),getNumber (configFile >> "CfgMagazines" >> (_this select 1) >> "AGM_MaxDistance")]];
		publicVariable "AGM_Explosives_List";
		AGM_Explosives_PlacedCount = AGM_Explosives_PlacedCount + 1;
		[format ["E: %1", AGM_Explosives_PlacedCount],_code] call AGM_Explosives_fnc_AddCodeToSpeedDial;
		player sideChat format [localize "STR_AGM_Explosives_INSURGENCY_explosive_DetonateCode", _code];
	};
	case TYPE_Clacker:
	{
		private "_clacker";
		_clacker = player getVariable ["AGM_Clacker", []];
		_clacker set [count _clacker, [_explosive, getNumber(configFile >> "CfgMagazines" >> (_this select 1) >> "AGM_FuseTime"),getNumber (configFile >> "CfgMagazines" >> (_this select 1) >> "AGM_MaxDistance")]];
		player setVariable ["AGM_Clacker", _clacker, true];
	};
	default
	{
	};
};

_explosive