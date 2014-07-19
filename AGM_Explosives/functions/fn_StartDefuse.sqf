/*
	Name: AGM_Explosives_fnc_StartDefuse
	
	Author: Garth de Wet (LH)
	
	Description:
		Starts defusing an explosive
	
	Parameters: 
		0: OBJECT - Target explosive
	
	Returns:
		Nothing
	
	Example:
		[AGM_Interaction_Target] call AGM_Explosives_fnc_StartDefuse;
*/
private ["_target", "_defuseTime"];
_target = (_this select 0);
_defuseTime = 5;
if (isNumber(ConfigFile >> "CfgAmmo" >> typeOf (_target) >> "AGM_DefuseTime")) then {
	_defuseTime = getNumber(ConfigFile >> "CfgAmmo" >> typeOf (_target) >> "AGM_DefuseTime");
};
[_defuseTime, [player,_target], "AGM_Explosives_fnc_DefuseExplosive", localize "STR_AGM_Explosives_DefusingExplosive"] call AGM_Core_fnc_progressBar;