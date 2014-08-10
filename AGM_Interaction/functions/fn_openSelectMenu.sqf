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
64 cutRsc ["InteractionMenu", "PLAIN",0.5, false];
AGM_Interaction_Current = 0;
showHUD false;
if (player getVariable ["AGM_AcceptAction", -1] == -1) then {
	player setVariable ["AGM_AcceptAction", player addAction ["", {_action = AGM_Interaction_Buttons select AGM_Interaction_Current; if (call (_action select 2)) then {_action call (_action select 1);};},
		nil, 0, false, true, "DefaultAction",
		"_this == _target && {!isNil 'AGM_Interaction_MainButton'}"
	]];
	player addAction ["", {call AGM_Interaction_MainButton;},
		nil, 0, false, true, "menuBack",
		"_this == _target && {!isNil 'AGM_Interaction_MainButton'}"
	];
	(findDisplay 46) displayAddEventHandler ["MouseZChanged", "if(isNil 'AGM_Interaction_MainButton')exitWith{false};((_this select 1) < 0) call AGM_Interaction_fnc_MoveDown;true"];
};
AGM_Interaction_MainButton = _this select 1;
false call AGM_Interaction_fnc_moveDown;