/*
	Name: AGM_Interaction_fnc_openSelectMenu
	
	Author: Garth de Wet (LH)
	
	Description:
		Opens the select menu UI and sets up the UI
	
	Parameters: 
		0: ARRAY - items
			ARRAY
				0 = Text
				1 = statement to execute
				2 = condition before execute
				3 = showDisabled
				4 = priority
				5 = icon
				6+ extra variables. The entire array is passed as a parameter to the statement.
		1: Code - Cancel Action
	Returns:
		Nothing
	
	Example:
*/
_customActions = _this select 0;
_count = count _customActions;
if (_count == 0) exitWith {};
_customActions call AGM_Interaction_fnc_sortOptionsByPriority;
AGM_Interaction_Buttons = _customActions;
closeDialog 0;
[(_this select 1), true] call AGM_Interaction_fnc_initialiseInteraction;
/* if (AGM_Interaction_Updater) exitWith {};
[] spawn {
	AGM_Interaction_Updater = true;
	while {!isNil "AGM_Interaction_MainButton"} do {
		0 call AGM_Interaction_fnc_moveDown;
		sleep 1;
	};
	AGM_Interaction_Updater = false;
}; */