/*
	Name: AGM_Explosives_fnc_DefuseExplosive
	
	Author: Garth de Wet (LH)
	
	Description:
		Defuses an Explosive
	
	Parameters: 
		0: OBJECT - unit
		1: OBJECT - Explosive
	
	Returns:
		Nothing
	
	Example:
		[player, AGM_Interaction_Target] call AGM_Explosives_fnc_DefuseExplosive;
*/
private ["_unit", "_explosive"];
_unit = _this select 0;
_explosive = _this select 1;

_mag = getText (ConfigFile >> "CfgAmmo" >> typeof _explosive >> "defaultMagazine");
_mag = configFile >> "CfgMagazines" >> _mag;
if (getNumber (_mag >> "AGM_explodeOnDefuse") == 1) exitWith {
	[_unit, 0, [_explosive, 1], true, true] call AGM_Explosives_fnc_DetonateExplosive;
};

_unit action ["Deactivate", _unit, _explosive];