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

/*
_isSpecialist = (_unit call AGM_Explosives_fnc_isSpecialist);
_mag = getText ConfigFile >> "CfgAmmo" >> typeof AGM_Interaction_Target >> "Magazine";
_mag = configFile >> "CfgMagazines" >> _mag;
if (getNumber (_mag >> "AGM_explodeOnDefuse") == 1 && {AGM_Explosives_PunishNonSpecialists > 0 && !_isSpecialist}) exitWith {
	[_unit, [_explosive, 1, 75], true, true] call AGM_Explosives_fnc_DetonateExplosive;
};
*/
_unit action ["Deactivate", _unit, _explosive];