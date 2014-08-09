/*
	Name: AGM_Explosives_fnc_PlaceExplosive
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Places an explosive at the requested position
	
	Parameters:
		0: OBJECT - unit
		1: POSITION - Position to place explosive
		2: NUMBER - Rotation
		3: STRING - Magazine class
		4: Config - Config of trigger
		5: ARRAY - variables required for the trigger type
	
	Returns:
		OBJECT: Placed explosive
	
	Example:
		_explosive = [player, player modelToWorld [0,0.5, 0.1], 134, "SatchelCharge_Remote_Mag", "Command", []] call AGM_Explosives_fnc_PlaceExplosive;
*/
private ["_pos", "_dir", "_mag", "_ammo", "_vars", "_unit", "_config", "_explosive"];
_unit = _this select 0;
_pos = _this select 1;
_dir = _this select 2;
_mag = _this select 3;
_config = _this select 4;
_vars = _this select 5;
_setDir = true;
if (count _this > 6) then {
	_setDir = _this select 6;
};

if (isNil "_config") exitWith {
	diag_log format ["AGM_Explosives: Error config not passed to PlaceExplosive: %1", _this];
	objNull
};

_trigger = ConfigFile >> "CfgMagazines" >> _mag >> "AGM_Triggers" >> _config;
_config = ConfigFile >> "CfgAGM_Triggers" >> _config;

if (isNil "_config") exitWith {
	diag_log format ["AGM_Explosives: Error config not found in PlaceExplosive: %1", _this];
	objNull
};

_ammo = getText(ConfigFile >> "CfgMagazines" >> _mag >> "ammo");
if (isText(_trigger >> "ammo")) then {
	_ammo = getText (_trigger >> "ammo");
};
_explosive = createVehicle [_ammo, _pos, [], 0, "NONE"];
if (isText(_config >> "onPlace") && {[_unit,_explosive,_mag,_vars] call compile (getText (_config >> "onPlace"))}) exitWith {_explosive};
if (_setDir) then {
	[[_explosive, _dir, getNumber (_trigger >> "pitch")], "AGM_Explosives_fnc_setPos"] call AGM_Core_fnc_execRemoteFnc;
};
_explosive