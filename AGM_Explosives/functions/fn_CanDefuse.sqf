/*
	Name: AGM_Explosives_fnc_CanDefuse
	
	Author: Garth de Wet (LH)
	
	Description:
		Checks if a unit can defuse an explosive
	
	Parameters: 
		0: OBJECT - unit
	
	Returns:
		Nothing
	
	Example:
		[player] call AGM_Explosives_fnc_CanDefuse;
*/
private "_unit";
_unit = _this select 0;
if (vehicle _unit != _unit || {!("AGM_DefusalKit" in (items _unit))}) exitWith {false};
_isSpecialist = (_unit call AGM_Explosives_fnc_isSpecialist);

if ((AGM_Explosives_RequireSpecialist > 0) && {!_isSpecialist}) exitWith {false};

AGM_Interaction_Target = nearestObject [_unit, "TimeBombCore"];
if (isNull(AGM_Interaction_Target)) exitWith {false};
/*
// Assume the specialist will have knowledge that a particular explosive will detonate on defuse,
// Thus stop the specialist from attempting to defuse it.
_mag = getText ConfigFile >> "CfgAmmo" >> typeof AGM_Interaction_Target >> "Magazine";
_mag = configFile >> "CfgMagazines" >> _mag;
if (getNumber (_mag >> "AGM_explodeOnDefuse") == 1 && {AGM_Explosives_PunishNonSpecialists > 0 && _isSpecialist}) exitWith {
	false
};
*/

_unit distance AGM_Interaction_Target < 4