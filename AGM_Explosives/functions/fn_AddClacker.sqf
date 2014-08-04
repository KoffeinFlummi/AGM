/*
	Name: AGM_Explosives_fnc_AddClacker
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Adds an explosive as a clacker item to the passed unit if the unit has a AGM_Clacker item.
	
	Parameters:
		0: OBJECT - unit
		1: OBJECT - Explosive
		2: STRING - Magazine
	
	Returns:
		Nothing
	
	Example:
		[_unit, _explosive, "SatchelCharge_Remote_Mag"] AGM_Explosives_fnc_AddClacker;
*/
private ["_unit", "_explosive", "_clacker", "_config", "_mag"];
_unit = _this select 0;
_explosive = _this select 1;
_mag = _this select 2;

if !("AGM_Clacker" in (items _unit)) exitWith {};
_config = ConfigFile >> "CfgMagazines" >> _mag >> "AGM_Triggers" >> "Command";

_clacker = _unit getVariable ["AGM_Clacker", []];
AGM_Explosives_PlacedCount = AGM_Explosives_PlacedCount + 1;
_clacker set [count _clacker, [_explosive, getNumber(_config >> "FuseTime"), "E: " + str(AGM_Explosives_PlacedCount),_mag]];
_unit setVariable ["AGM_Clacker", _clacker, true];
_unit sideChat format [localize "STR_AGM_Explosives_DetonateCode", AGM_Explosives_PlacedCount];