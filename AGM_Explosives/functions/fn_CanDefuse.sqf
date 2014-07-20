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
if (vehicle player != player || {!("AGM_DefusalKit" in (items player))}) exitWith {false};

AGM_Interaction_Target = nearestObject [_unit, "TimeBombCore"];
if (isNull(AGM_Interaction_Target)) exitWith {false};

(player distance AGM_Interaction_Target < 4) && {call AGM_Interaction_fnc_canInteract}