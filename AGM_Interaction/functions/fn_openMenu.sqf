// by commy2

AGM_Interaction_Buttons = [];
_actions = [];
_patches = [];
_class = _this;
if (_class == "") then {AGM_Interaction_Target = cursorTarget};
_object = AGM_Interaction_Target; if !([player, _object] call AGM_Core_fnc_canInteractWith) exitWith {};

// fix inheritance
_configClass = configFile >> "CfgVehicles" >> typeOf _object >> "AGM_Actions";
if !(_class in ["", "Default"]) then {_configClass = _configClass >> _class};

// search mission config file
_parents = [configfile >> "CfgVehicles" >> typeOf _object, true] call BIS_fnc_returnParents;
{
	_config = missionConfigFile >> "CfgVehicles" >> _x >> "AGM_Actions";
	if !(_class in ["", "Default"]) then {_config = _config >> _class};

	_count = count _config;
	if (_count > 0) then {
		for "_index" from 0 to (_count - 1) do {
			_action = _config select _index;

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
					_icon = "AGM_Interaction\UI\IconInteraction_ca.paa";
				};

				if (!(_configName in _patches) && {_showDisabled || {call _condition}} && {[_object, _distance] call AGM_Interaction_fnc_isInRange || {_distance == 0}}) then {
					_actions set [count _actions, [_displayName, _statement, _condition, _priority, _icon]];
					_patches set [count _patches, _configName];
				};
			};
		};
	};
} forEach _parents;

// search add-on config file
{
	_config = configfile >> "CfgVehicles" >> _x >> "AGM_Actions";
	if !(_class in ["", "Default"]) then {_config = _config >> _class};

	_count = count _config;
	if (_count > 0) then {
		for "_index" from 0 to (_count - 1) do {
			_action = _configClass >> configName (_config select _index);

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
					_icon = "AGM_Interaction\UI\IconInteraction_ca.paa";
				};

				if (!(_configName in _patches) && {_showDisabled || {call _condition}} && {[_object, _distance] call AGM_Interaction_fnc_isInRange || {_distance == 0}}) then {
					_actions set [count _actions, [_displayName, _statement, _condition, _priority, _icon]];
					_patches set [count _patches, _configName];
				};
			};
		};
	};
} forEach _parents;

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
	_icon = "AGM_Interaction\UI\IconInteraction_ca.paa";
	
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
closeDialog 0;
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
	(findDisplay 46) displayAddEventHandler ["MouseZChanged", "if(isNil 'AGM_Interaction_MainButton')exitWith{false};((_this select 1) < 0) call AGM_Interaction_fnc_MoveDown;true"];
};
AGM_Interaction_MainButton = {call AGM_Interaction_fnc_hideMenu;};
if !(_class in ["", "Default"]) then {
	AGM_Interaction_MainButton = {"Default" call AGM_Interaction_fnc_openMenu;};
};
false call AGM_Interaction_fnc_moveDown;
[] spawn {
	while {!isNil "AGM_Interaction_MainButton"} do {
		sleep 0.1;
		if (!([player, AGM_Interaction_Target] call AGM_Core_fnc_canInteractWith)) exitWith {};
		if (!([AGM_Interaction_Target, 10] call AGM_Interaction_fnc_isInRange)) exitWith {};
	};
	call AGM_Interaction_fnc_hideMenu;
};