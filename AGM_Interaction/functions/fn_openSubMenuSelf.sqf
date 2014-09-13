// by commy2

private ["_count", "_index", "_action", "_subMenu"];

AGM_Interaction_MenuType = 3;	// 0 Interaction, 1 Self Interaction, +2 for sub menu
uiNamespace setVariable ["AGM_Interaction_CursorPosition", [controlNull, 0.5, 0.5, -1]];

_actions = [];
_patches = [];
_class = _this select 0;

_object = vehicle player;




// fix inheritance
_configClass = configFile >> "CfgVehicles" >> typeOf _object >> "AGM_SelfActions" >> _class;

_fnc_GetActions = {
	_parents = _this select 0;
	_actions = _this select 1;
	_patches = _this select 2;
	_class = _this select 3;
	_baseConfig = _this select 4;

	_count = count _parents;
	for "_i" from 0 to (_count - 1) do {
		_config = _baseConfig >> _parents select _i >> "AGM_SelfActions" >> _class;

		_count = count _config;
		if (_count > 0) then {
			for "_index" from 0 to (_count - 1) do {
				_action = if (_this select 5) then {_config select _index} else {_this select 6 >> configName (_config select _index)};
				_cache = missionNamespace getVariable ["AGM_Interaction_MenuCache", [[], [], []]];

				if (count _action > 0) then {
					_configName = configName _action;

					_cacheConfigs = _cache select 0;
					_cacheActions = _cache select 1;
					_cacheIndices = _cache select 2;

					_indexCache = _cacheConfigs find _action;
					if (_indexCache == -1) then {
						_displayName = getText (_action >> "displayName");
						_distance = 0;
						_priority = getNumber (_action >> "priority");
						_subMenu = getArray (_action >> "subMenu");
						_tooltip = getText (_action >> "tooltip");

						// Condition
						_condition = getText (_action >> "condition");
						if (_condition == "") then {_condition = "true"};

						_condition = _condition + format [" && {%1 call AGM_Core_canInteract}", getArray (_action >> "exceptions")];
						_condition = compile _condition;

						// Condition to show the action
						_conditionShow = getText (_action >> "conditionShow");
						_conditionShow = if (_conditionShow == "") then {{true}} else {compile _conditionShow};

						_showDisabled = getNumber (_action >> "showDisabled") == 1;
						if (isText (_action >> "conditionShow")) then {
							_showDisabled = call _conditionShow;
						};

						// Exceptions to the general conditions that have to be true
						_exceptions = getArray (_action >> "exceptions");

						// statement
						_statement = getText (_action >> "statement");
						_statement = compile _statement;

						if (profileNamespace getVariable ["AGM_Interaction_FlowMenu", false]) then {
							_statement = if (getText (_action >> "statement") == "" && {count _subMenu > 1}) then {
								compile format ["call AGM_Interaction_fnc_hideMenu;if(%2 == 1)then{['%1'] call AGM_Interaction_fnc_openSubMenuSelf;}else{['%1'] call AGM_Interaction_fnc_openSubMenu;};", _subMenu select 0, _subMenu select 1];
							} else {
								compile ("call AGM_Interaction_fnc_hideMenu;" + getText (_action >> "statement"));
							};
						};

						// icon
						_icon = getText (_action >> "Icon");
						if (_icon == "") then {
							_icon = "\AGM_Interaction\UI\dot_ca.paa";
						};

						_actionToCache = [_displayName, _statement, _condition, _priority, _subMenu, _icon, _tooltip, _conditionShow, _exceptions, _distance];

						if (!(_configName in _patches) && {_showDisabled || {call _condition}} && {_distance == 0 || {[_object, _distance] call AGM_Interaction_fnc_isInRange}}) then {
							_actions pushBack _actionToCache;
							_patches pushBack _configName;
						};

						_indexCache = _cacheActions find _actionToCache;
						if (_indexCache == -1) then {
							_indexCache = count _cacheActions;
							_cacheActions pushBack _actionToCache;
						};

						_cacheConfigs pushBack _action;
						_cacheIndices pushBack _indexCache;

						_cache = [_cacheConfigs, _cacheActions, _cacheIndices];
						if (!isNil "AGM_Debug" && {AGM_Debug == "InteractionMenu"}) then {diag_log text format ["%1 loaded into cache", _action]};
					} else {
						if (!isNil "AGM_Debug" && {AGM_Debug == "InteractionMenu"}) then {diag_log text format ["%1 loaded from cache", _action]};

						_cachedAction = _cacheActions select (_cacheIndices select _indexCache);

						_showDisabled = getNumber (_action >> "showDisabled") == 1;
						if (isText (_action >> "conditionShow")) then {
							_showDisabled = call (_cachedAction select 7);
						};

						if (!(_configName in _patches) && {_showDisabled || {call (_cachedAction select 2)}} && {[_object, (_cachedAction select 9)] call AGM_Interaction_fnc_isInRange || {(_cachedAction select 9) == 0}}) then {
							_actions pushBack _cachedAction;
							_patches pushBack _configName;
						};
					};
				};

				AGM_Interaction_MenuCache = _cache;
			};
		};
	};

	[_actions, _patches]
};

_parents = [configfile >> "CfgVehicles" >> typeOf _object, true] call BIS_fnc_returnParents;
_result = [_parents, [], [], _class, missionConfigFile >> "CfgVehicles", true] call _fnc_GetActions;
_result = [_parents, _result select 0, _result select 1, _class, configfile >> "CfgVehicles", false, _configClass] call _fnc_GetActions;
_actions = _result select 0;

// search vehicle namespace
/*_customActions = (_object getVariable ["AGM_InteractionsSelf", [-1, [], []]]) select 2;
for "_index" from 0 to (count _customActions - 1) do {
	_customAction = _customActions select _index;
	_displayName = _customAction select 0;
	_distance = 0;
	_condition = _customAction select 1;
	_statement = _customAction select 2;
	_showDisabled = _customAction select 3;
	_priority = _customAction select 4;
	_subMenu = [];
	_icon = "\AGM_Interaction\UI\dot_ca.paa";
	_tooltip = "";
	_conditionShow = {true};
	_exceptions = [];

	if (_showDisabled || {call _condition}) then {
		_actions pushBack [_displayName, _statement, _condition, _priority, _subMenu, _icon, _tooltip, _conditionShow, _exceptions, _distance];
	};
};*/

_count = count _actions;
if (_count == 0) exitWith {};

_actions call AGM_Interaction_fnc_sortOptionsByPriority;

AGM_Interaction_Buttons = _actions;

[{
	if !(profileNamespace getVariable ["AGM_Interaction_AutoCloseMenu", false]) then {
		call AGM_Interaction_fnc_hideMenu;
		"Default" spawn AGM_Interaction_fnc_openMenuSelf;
	};
}, true, (profileNamespace getVariable ["AGM_Interaction_FlowMenu", false]), true, _object] call AGM_Interaction_fnc_initialiseInteraction;
