// by commy2

private ["_count", "_index", "_action", "_subMenu"];

_prevMenuType = missionNamespace getVariable ["AGM_Interaction_MenuType", -1];
_prevTargetType = missionNamespace getVariable ["AGM_Interaction_TargetType", ""];

//AGM_Interaction_Buttons = [];
uiNamespace setVariable ["AGM_Interaction_CursorPosition", [controlNull, 0.5, 0.5, -1]];

_actions = [];
_patches = [];

AGM_Interaction_Target = cursorTarget;
_object = AGM_Interaction_Target;

AGM_Interaction_TargetType = typeOf _object;

if (isNull (_object) || {!([_object, 4] call AGM_Interaction_fnc_isInRange)}) exitWith {call AGM_Interaction_fnc_onButtonDownSelf}; 
AGM_Interaction_MenuType = 0;	// 0 Interaction, 1 Self Interaction

if !([player, _object] call AGM_Core_fnc_canInteractWith) exitWith {};

if (_prevMenuType != AGM_Interaction_MenuType || {_prevTargetType != AGM_Interaction_TargetType}) then {
	// fix inheritance

	if (!isNil "AGM_Debug" && {AGM_Debug == "InteractionMenu"}) then {
		systemChat "recompile";
	};

	_configClass = configFile >> "CfgVehicles" >> typeOf _object >> "AGM_Actions";

	_fnc_GetActions = {
		_actions = _this select 1;
		_patches = _this select 2;
		{
			_config = (_this select 3) >> _x >> "AGM_Actions";

			_count = count _config;
			if (_count > 0) then {
				for "_index" from 0 to (_count - 1) do {
					_action = [];
					if (_this select 4) then {
						_action = _config select _index;
					}else{
						_action = (_this select 5) >> configName (_config select _index);
					};

					if (count _action > 0) then {
						_configName = configName _action;
						_displayName = getText (_action >> "displayName");
						_distance = getNumber (_action >> "distance");
						_condition = getText (_action >> "condition");
						if (_condition == "") then {_condition = "true"};

						_condition = _condition + format [" && {%1 call AGM_Core_canInteract} && {[player, AGM_Interaction_Target] call AGM_Core_fnc_canInteractWith}", getArray (_action >> "exceptions")];
						_condition = compile _condition;
						_priority = getNumber (_action >> "priority");
						_subMenu = getArray (_action >> "subMenu");
						_tooltip = getText (_action >> "tooltip");
						_statement = {};
						
						// Condition to show the action
						_conditionShow = getText (_action >> "conditionShow");
						if (_conditionShow == "") then {_conditionShow = "true"};

						_conditionShow = compile _conditionShow;
						
						_showDisabled = getNumber (_action >> "showDisabled") == 1;
						if (isText (_action >> "conditionShow")) then {
							_showDisabled = call _conditionShow;
						};

						// Conditions that have to be true or else they show the following tooltip upon clicking
						_conditionsTooltip = getArray (_action >> "conditionsTooltip");

						{
							if (_forEachIndex mod 2 == 0) then {
								_conditionsTooltip set [_forEachIndex, compile _x];
							};
						} forEach _conditionsTooltip;
						
						if (profileNamespace getVariable ["AGM_Interaction_FlowMenu", false]) then {
							if (getText (_action >> "statement") == "" && {count _subMenu > 1}) then {
								_statement = compile format ["call AGM_Interaction_fnc_hideMenu;if(%2 == 1)then{['%1'] call AGM_Interaction_fnc_openSubMenuSelf;}else{'%1' call AGM_Interaction_fnc_openSubMenu;};", _subMenu select 0, _subMenu select 1];
							}else{
								_statement = compile ("call AGM_Interaction_fnc_hideMenu;" + getText (_action >> "statement"));
							};
						}else{
							_statement = compile (getText (_action >> "statement"));
						};
						
						_icon = getText (_action >> "icon");
						if (_icon == "") then {
							_icon = "AGM_Interaction\UI\dot_ca.paa";
						};

						if (!(_configName in _patches) && {_showDisabled || {call _condition}} && {[_object, _distance] call AGM_Interaction_fnc_isInRange || {_distance == 0}}) then {
							_actions set [count _actions, [_displayName, _statement, _condition, _priority, _subMenu, _icon, _tooltip, _conditionShow, _conditionsTooltip]];
							_patches set [count _patches, _configName];
						};
					};
				};
			};
		} forEach (_this select 0);
		
		[_actions, _patches]
	};
	_parents = [configfile >> "CfgVehicles" >> typeOf _object, true] call BIS_fnc_returnParents;
	_result = [_parents, [], [], missionConfigFile >> "CfgVehicles", true] call _fnc_GetActions;
	_result = [_parents, _result select 0, _result select 1, configfile >> "CfgVehicles", false, _configClass] call _fnc_GetActions;
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
		_subMenu = [];
		_icon = "AGM_Interaction\UI\dot_ca.paa";

		if ((_showDisabled || {call _condition}) && {[_object, _distance] call AGM_Interaction_fnc_isInRange || {_distance == 0}}) then {
			_actions set [count _actions, [_displayName, _statement, _condition, _priority, _subMenu, _icon]];
		};
	};

	_actions call AGM_Interaction_fnc_sortOptionsByPriority;

	AGM_Interaction_Buttons = _actions;
};

_count = count AGM_Interaction_Buttons;
if (_count == 0) exitWith {call AGM_Interaction_fnc_onButtonDownSelf};

[{call AGM_Interaction_fnc_hideMenu;}, false, (profileNamespace getVariable ["AGM_Interaction_FlowMenu", false]), true, _object] call AGM_Interaction_fnc_initialiseInteraction;
