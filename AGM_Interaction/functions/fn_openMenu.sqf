/*
	Name: AGM_Interaction_fnc_openMenu
	
	Author:
		commy2
		Garth de Wet (LH)
	
	Description:
		Opens the interaction menu of AGM_Interaction_Target.
	
	Parameters: 
		STRING - class name of the interaction options
	Returns:
		Nothing
	
	Example:
		// Opens default initial menu
		"" call AGM_interaction_fnc_openMenu;
		// Opens the Explosive submenu.
		"AGM_Explosives" call AGM_Interaction_fnc_openMenu;
*/
AGM_Interaction_Buttons = [];
_actions = [];
_patches = [];
_class = _this;

if (_class != "" && {!(missionNamespace getVariable ["AGM_Interaction_isMousePressed", true]) && !(profileNamespace getVariable ["AGM_Interaction_FlowMenu", false])}) exitWith {};

if (_class == "") then {AGM_Interaction_Target = cursorTarget};
_object = AGM_Interaction_Target; if !([player, _object] call AGM_Core_fnc_canInteractWith) exitWith {};

// fix inheritance
_configClass = configFile >> "CfgVehicles" >> typeOf _object >> "AGM_Actions";
if !(_class in ["", "Default"]) then {_configClass = _configClass >> _class};

// search mission config file
_parents = [configfile >> "CfgVehicles" >> typeOf _object, true] call BIS_fnc_returnParents;
_fnc_GetActions = {
	_actions = _this select 1;
	_patches = _this select 2;
	_class = _this select 3;
	{
		_config = (_this select 4) >> _x >> "AGM_Actions";
		if !(_class in ["", "Default"]) then {_config = _config >> _class};

		_count = count _config;
		if (_count > 0) then {
			for "_index" from 0 to (_count - 1) do {
				_action = [];
				if (_this select 5) then {
					_action = _config select _index;
				}else{
					_action = (_this select 6) >> configName (_config select _index);
				};

				if (count _action > 0) then {
					_configName = configName _action;
					_displayName = getText (_action >> "displayName");
					_distance = getNumber (_action >> "distance");
					_condition = getText (_action >> "condition");
					if (_condition == "") then {_condition = "true"};

					_condition = _condition + format [" && {%1 call AGM_Core_canInteract} && {[player, AGM_Interaction_Target] call AGM_Core_fnc_canInteractWith}", getArray (_action >> "exceptions")];
					_condition = compile _condition;
					_statement = compile ("call AGM_Interaction_fnc_hideMenu;" + getText (_action >> "statement"));
					_showDisabled = getNumber (_action >> "showDisabled") == 1;
					if (isText (_action >> "conditionShow")) then {
						_showDisabled = call compile getText (_action >> "conditionShow");
					};
					_priority = getNumber (_action >> "priority");
					_icon = getText (_action >> "icon");
					if (_icon == "") then {
						_icon = "AGM_Interaction\UI\dot_ca.paa";
					};

					if (!(_configName in _patches) && {_showDisabled || {call _condition}} && {[_object, _distance] call AGM_Interaction_fnc_isInRange || {_distance == 0}}) then {
						_actions set [count _actions, [_displayName, _statement, _condition, _priority, _icon]];
						_patches set [count _patches, _configName];
					};
				};
			};
		};
	} forEach (_this select 0);
	
	[_actions, _patches]
};
_result = [_parents, [], [], _class, missionConfigFile >> "CfgVehicles", true] call _fnc_GetActions;
_result = [_parents, _result select 0, _result select 1, _class, configfile >> "CfgVehicles", false, _configClass] call _fnc_GetActions;
_actions = _result select 0;

// search vehicle namespace
_customActions = _object getVariable ["AGM_Interactions", []];
for "_index" from 0 to (count _customActions - 1) do {
	_customAction = _customActions select _index;
	_displayName = _customAction select 0;
	_distance = _customAction select 1;
	_condition = _customAction select 2;
	_statement = _customAction select 3;
	_showDisabled = _customAction select 4;
	_priority = _customAction select 5;
	_icon = "AGM_Interaction\UI\dot_ca.paa";
	
	if (count _customAction > 6) then{
		_icon = _customAction select 5;
	};

	if ((_showDisabled || {call _condition}) && {[_object, _distance] call AGM_Interaction_fnc_isInRange || {_distance == 0}}) then {
		_actions set [count _actions, [_displayName, _statement, _condition, _priority, _icon]];
	};
};

_count = count _actions;
if (_count == 0) exitWith {};

_actions call AGM_Interaction_fnc_sortOptionsByPriority;
AGM_Interaction_Buttons = _actions;
if !(_class in ["", "Default"])then{
	[{"Default" call AGM_Interaction_fnc_openMenu;}, true, (profileNamespace getVariable ["AGM_Interaction_FlowMenu", false]), false, _object, _class == ""] call AGM_Interaction_fnc_initialiseInteraction;
}else{
	[{call AGM_Interaction_fnc_hideMenu;}, false, (profileNamespace getVariable ["AGM_Interaction_FlowMenu", false]), false, _object, _class == ""] call AGM_Interaction_fnc_initialiseInteraction;
};
/* if (AGM_Interaction_Updater) exitWith {};
[] spawn {
	AGM_Interaction_Updater = true;
	while {!isNil "AGM_Interaction_MainButton"} do {
		if (!([player, AGM_Interaction_Target] call AGM_Core_fnc_canInteractWith)) exitWith {};
		if (!([AGM_Interaction_Target, 6] call AGM_Interaction_fnc_isInRange)) exitWith {};
		// 0 call AGM_Interaction_fnc_moveDown;
		sleep 0.75;
	};
	call AGM_Interaction_fnc_hideMenu;
	AGM_Interaction_Updater = false;
}; */