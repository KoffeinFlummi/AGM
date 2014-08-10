/*
	Name: AGM_Interaction_fnc_initialiseInteraction
	
	Author: Garth de Wet (LH)
	
	Description:
		Initialises the interaction click handlers.
	
	Parameters: 
		CODE - code to call when right clicking.
	
	Returns:
		Nothing
	
	Example:
		{"Default" call AGM_Interaction_fnc_openMenu;} call AGM_Interaction_fnc_initialiseInteraction;
*/
64 cutRsc ["InteractionMenu", "PLAIN",0.5, false];
AGM_Interaction_Current = 0;
showHUD false;
if (player getVariable ["AGM_AcceptAction", -1] == -1) then {
	player setVariable ["AGM_AcceptAction", player addAction ["", {_action = AGM_Interaction_Buttons select AGM_Interaction_Current; if (call (_action select 2)) then {_action call (_action select 1);};},
		nil, 0, false, true, "DefaultAction",
		"!isNil 'AGM_Interaction_MainButton'"
	]];
	player addAction ["", {call AGM_Interaction_MainButton;},
		nil, 0, false, true, "menuBack",
		"!isNil 'AGM_Interaction_MainButton'"
	];
	(findDisplay 46) displayAddEventHandler ["MouseZChanged", "if(isNil 'AGM_Interaction_MainButton')exitWith{false};(if((_this select 1) < 0)then{1}else{-1}) call AGM_Interaction_fnc_MoveDown;true"];
};
AGM_Interaction_MainButton = _this select 0;
0 call AGM_Interaction_fnc_moveDown;
((uiNamespace getVariable "Interaction_Display") displayCtrl (1210)) ctrlShow (_this select 1);