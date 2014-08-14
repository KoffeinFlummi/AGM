/*
	Name: AGM_Interaction_fnc_initialiseInteraction
	
	Author:
		commy2
		Garth de Wet (LH)
	
	Description:
		Initialises the interaction click handlers.
	
	Parameters: 
		0 : CODE - code to call when right clicking/center button
		1 : BOOLEAN - Submenu
		2 : BOOLEAN - Flow Menu
		3 : BOOLEAN - Self interaction
		4 : OBJECT - Target
	
	Returns:
		Nothing
	
	Example:
		[{"Default" call AGM_Interaction_fnc_openMenu;}, true, (profileNamespace getVariable ["AGM_Interaction_FlowMenu", false]), AGM_Interaction_Target] call AGM_Interaction_fnc_initialiseInteraction;
*/
private ["_subMenu", "_selfMenu", "_target"];
AGM_Interaction_MainButton = _this select 0;
_subMenu = _this select 1;
_selfMenu = _this select 3;
_target = _this select 4;

// Flow menu
if (_this select 2) then {
	64 cutRsc ["AGM_FlowMenu", "PLAIN",0.5, false];
	AGM_Interaction_SelectedButton = 0;
	showHUD false;
	(findDisplay 1713999) closeDisplay 1;
	if (player getVariable ["AGM_AcceptAction", -1] == -1) then {
		(findDisplay 46) displayAddEventHandler ["MouseZChanged", "if(isNil {AGM_Interaction_MainButton} || {!(profileNamespace getVariable ['AGM_Interaction_FlowMenu', false])})exitWith{false};(if((_this select 1) < 0)then{1}else{-1}) call AGM_Interaction_fnc_MoveDown;true"];
		player setVariable ["AGM_AcceptAction", player addAction ["", {_action = AGM_Interaction_Buttons select AGM_Interaction_SelectedButton;if (call (_action select 2)) then {call AGM_Interaction_fnc_hideMenu;if (count _action > 6) then {(_action select 6) call (_action select 1);}else{call (_action select 1);};};},
			nil, 0, false, true, "DefaultAction",
			"(!isNil {AGM_Interaction_MainButton}) && {(profileNamespace getVariable ['AGM_Interaction_FlowMenu', false])}"
		]];
		player addAction ["", {call AGM_Interaction_MainButton;},
			nil, 0, false, true, "menuBack",
			"(!isNil {AGM_Interaction_MainButton}) && {(profileNamespace getVariable ['AGM_Interaction_FlowMenu', false])}"
		];
	};
	0 call AGM_Interaction_fnc_moveDown;
	((uiNamespace getVariable "AGM_Flow_Display") displayCtrl (1210)) ctrlShow _subMenu;
	((uiNamespace getVariable "AGM_Flow_Display") displayCtrl (1023)) ctrlShow _subMenu;
	((uiNamespace getVariable "AGM_Flow_Display") displayCtrl (1213)) ctrlShow _subMenu;
}else{ // Rose
	if !(_subMenu) then {
		(findDisplay 1713999) closeDisplay 1;
	
		(findDisplay 46) createDisplay "AGM_Interaction_Dialog";
		// Add eventhandlers
		(findDisplay 1713999) displayAddEventHandler ["KeyDown", "_this call AGM_Core_onKeyDown"];
		(findDisplay 1713999) displayAddEventHandler ["KeyUp", "_this call AGM_Core_onKeyUp"];
	};
	disableSerialization;
	_dlgInteractionDialog = uiNamespace getVariable "AGM_Interaction_Dialog";
	_ctrlInteractionDialog = _dlgInteractionDialog displayCtrl 3;
	setMousePosition [0.5, 0.5];
	if !(_subMenu) then {
		if (_target isKindOf "Man") then {
			_ctrlInteractionDialog ctrlSetText (if (alive _target) then {name _target} else {_target getVariable ["AGM_Name", "Unknown"]});
		}else{
			_ctrlInteractionDialog ctrlSetText (getText (configFile >> "CfgVehicles" >> (typeOf _target) >> "displayName"));
		};
	} else {
		_ctrlInteractionDialog ctrlSetText "<< " + localize "STR_AGM_Interaction_Back";
	};

	for "_i" from 0 to 9 do {
		_ctrlInteractionDialog = _dlgInteractionDialog displayCtrl (10 + _i);
		_ctrlInteractionDialog ctrlShow true;

		_ctrlInteractionDialogIcon = _dlgInteractionDialog displayCtrl (20 + _i);

		if (_i < _count) then {
			_action = AGM_Interaction_Buttons select _i;
			_ctrlInteractionDialog ctrlSetText (_action select 0);
			_ctrlInteractionDialog ctrlEnable (call (_action select 2));

			_ctrlInteractionDialogIcon ctrlSetText (_action select 5);
		} else {
			_ctrlInteractionDialog ctrlSetText "";
			_ctrlInteractionDialog ctrlEnable false;

			_ctrlInteractionDialogIcon ctrlSetText "";
		};
	};
};