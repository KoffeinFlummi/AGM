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
_unit action ["Deactivate", _unit, _explosive];