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
	[localize "STR_AGM_Interaction_MakeSelection", if (_subMenu)then{localize "STR_AGM_Interaction_Back"}else{""}, localize "STR_AGM_Interaction_ScrollHint"] call AGM_Interaction_fnc_showMouseHint;
	((uiNamespace getVariable "AGM_Flow_Display") displayCtrl (1210)) ctrlShow _subMenu;
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

	// Update Buttons
	if (_subMenu) exitWith {};

	_updateLoop = 0 spawn {
		disableSerialization;
		_dlgMenu = uiNamespace getVariable ["AGM_Interaction_Dialog", displayNull];
		_ctrlTooltip = _dlgMenu displayCtrl 4;

		waitUntil {
			{
				_ctrlText = _dlgMenu displayCtrl (10 + _forEachIndex);
				_ctrlIcon = _dlgMenu displayCtrl (20 + _forEachIndex);

				_condition = _x select 2;
				_conditionShow = _x select 7;
				_distance = _x select 9;

				_enable = (_distance == 0 || {[AGM_Interaction_Target, _distance] call AGM_Interaction_fnc_isInRange}) && _condition && _conditionShow;
				if (isNil "_enable") then {_enable = false};

				// apply conditional tooltips
				if (_forEachIndex == call AGM_Interaction_fnc_getSelectedButton) then {
					_tooltip = _x select 6;

					_ctrlTooltip ctrlSetText _tooltip;
					_ctrlTooltip ctrlShow (_tooltip != "");
				};

				_ctrlText ctrlEnable _enable;
				_ctrlIcon ctrlEnable _enable;
			} forEach AGM_Interaction_Buttons;

			sleep 0.5;
			isNull (findDisplay 1713999)
		};
	};

	_updateLoop spawn {
		disableSerialization;
		_dlgMenu = uiNamespace getVariable ["AGM_Interaction_Dialog", displayNull];
		_ctrlTooltip = _dlgMenu displayCtrl 4;

		_selectedButton = -1;
		waitUntil {
			if (_selectedButton != call AGM_Interaction_fnc_getSelectedButton) then {
				_selectedButton = call AGM_Interaction_fnc_getSelectedButton;
				_tooltip = if (_selectedButton < 0 || {_selectedButton >= count AGM_Interaction_Buttons}) then {""} else {
					AGM_Interaction_Buttons select _selectedButton select 6;
				};

				_ctrlTooltip ctrlSetText _tooltip;
				_ctrlTooltip ctrlShow (_tooltip != "");
			};
			sleep 0.01;
			isNull (findDisplay 1713999)
		};

		terminate _this;
	};
};

