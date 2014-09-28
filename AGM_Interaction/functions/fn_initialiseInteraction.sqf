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

_player = call AGM_Core_fnc_player;
_vehicle = vehicle _player;
//_object = [AGM_Interaction_Target, _player] select (AGM_Interaction_MenuType % 2 == 1);

AGM_Interaction_Shortcuts = [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1];

// Flow menu
if (_this select 2) then {
	64 cutRsc ["AGM_FlowMenu", "PLAIN",0.5, false];
	AGM_Interaction_SelectedButton = 0;
	showHUD false;
	(findDisplay 1713999) closeDisplay 1;
	if (player getVariable ["AGM_AcceptAction", -1] == -1) then {
		[{if(isNil {AGM_Interaction_MainButton} || {!(profileNamespace getVariable ['AGM_Interaction_FlowMenu', false])})exitWith{false};(if((_this select 0) < 0)then{1}else{-1}) call AGM_Interaction_fnc_MoveDown;true}] call AGM_Core_fnc_addScrollWheelEventHandler;

		player setVariable ["AGM_AcceptAction", [player, "DefaultAction", {(!isNil {AGM_Interaction_MainButton}) && {(profileNamespace getVariable ['AGM_Interaction_FlowMenu', false])}}, {_action = AGM_Interaction_Buttons select AGM_Interaction_SelectedButton;if ([_player, _target] call (_action select 2)) then {call AGM_Interaction_fnc_hideMenu;if (count _action > 6) then {(_action select 6) call (_action select 1);}else{call (_action select 1);};};}] call AGM_core_fnc_addActionEventHandler];
		player setVariable ["AGM_AcceptAction", [player, "menuBack", {(!isNil {AGM_Interaction_MainButton}) && {(profileNamespace getVariable ['AGM_Interaction_FlowMenu', false])}}, {call AGM_Interaction_MainButton;}] call AGM_core_fnc_addActionEventHandler];
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

		(findDisplay 1713999) displayAddEventHandler ["KeyDown", "_this call AGM_Interaction_fnc_menuKeyInput"];
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
		_ctrlInteractionDialogShortcut = _dlgInteractionDialog displayCtrl (30 + _i);
		//_ctrlInteractionDialogBackground = _dlgInteractionDialog displayCtrl (40 + _i);

		if (_i < _count) then {
			_action = AGM_Interaction_Buttons select _i;
			_ctrlInteractionDialog ctrlSetText (_action select 0);
			_ctrlInteractionDialog ctrlEnable ([_player, _target] call (_action select 2));

			_ctrlInteractionDialogIcon ctrlSetText (_action select 5);
			_ctrlInteractionDialogShortcut ctrlSetText (_action select 10);
			//_ctrlInteractionDialogBackground ctrlShow true;

			AGM_Interaction_Shortcuts set [_i, [_action select 10] call AGM_Core_fnc_letterToCode];
		} else {
			_ctrlInteractionDialog ctrlSetText "";
			_ctrlInteractionDialog ctrlEnable false;

			_ctrlInteractionDialogIcon ctrlSetText "";
			_ctrlInteractionDialogShortcut ctrlSetText "";
			//_ctrlInteractionDialogBackground ctrlShow false;
		};
	};

	// Update Buttons
	if (_subMenu) exitWith {};

	_updateLoop = 0 spawn {
		disableSerialization;
		_dlgMenu = uiNamespace getVariable ["AGM_Interaction_Dialog", displayNull];
		_ctrlTooltip = _dlgMenu displayCtrl 40;

		_player = call AGM_Core_fnc_player;
		_vehicle = vehicle _player;
		_target = [AGM_Interaction_Target, _player] select (AGM_Interaction_MenuType % 2 == 1);

		waitUntil {
			AGM_Interaction_Tooltips = [[], [], [], [], [], [], [], [], [], []];
			{
				_ctrlText = _dlgMenu displayCtrl (10 + _forEachIndex);
				_ctrlIcon = _dlgMenu displayCtrl (20 + _forEachIndex);

				_condition = _x select 2;
				_conditionShow = _x select 7;
				_distance = _x select 9;

				AGM_Interaction_CurrentTooltip = [];

				_enable = (_distance == 0 || {[_target, _distance] call AGM_Interaction_fnc_isInRange}) && {[_player, _target] call _condition} && {[_player, _target] call _conditionShow};
				if (isNil "_enable") then {_enable = false};

				AGM_Interaction_Tooltips set [_forEachIndex, AGM_Interaction_CurrentTooltip];

				// apply conditional tooltips
				if (_forEachIndex == call AGM_Interaction_fnc_getSelectedButton) then {
					_tooltip = _x select 6;

					_showTooltip = _tooltip != "";

					_tooltip = text _tooltip;

					{
						_showTooltip = true;
						_tooltip = composeText [_tooltip, lineBreak, _x];
					} forEach (AGM_Interaction_Tooltips select _forEachIndex);

					_ctrlTooltip ctrlSetStructuredText _tooltip;
					_ctrlTooltip ctrlShow _showTooltip;
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
		_ctrlTooltip = _dlgMenu displayCtrl 40;

		_selectedButton = -1;
		waitUntil {
			if (_selectedButton != call AGM_Interaction_fnc_getSelectedButton) then {
				_selectedButton = call AGM_Interaction_fnc_getSelectedButton;

				_showTooltip = false;
				_tooltip = if (_selectedButton < 0 || {_selectedButton >= count AGM_Interaction_Buttons}) then {text ""} else {
					_text = AGM_Interaction_Buttons select _selectedButton select 6;

					_showTooltip = _text != "";

					_text = text _text;

					{
						_showTooltip = true;
						_text = composeText [_text, lineBreak, _x];
					} forEach (AGM_Interaction_Tooltips select _selectedButton);

					_text
				};

				_ctrlTooltip ctrlSetStructuredText _tooltip;
				_ctrlTooltip ctrlShow _showTooltip;
			};
			sleep 0.01;
			isNull (findDisplay 1713999)
		};

		terminate _this;
	};
};
