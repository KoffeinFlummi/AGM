// by commy2

private ["_count", "_index", "_action", "_subMenu"];

AGM_Interaction_Buttons = [];
uiNamespace setVariable ["AGM_Interaction_CursorPosition", [controlNull, 0.5, 0.5, -1]];

_actions = [];
_patches = [];


_object = vehicle player;



// fix inheritance
_configClass = configFile >> "CfgVehicles" >> typeOf _object >> "AGM_SelfActions";

// search mission config file
_parents = [configfile >> "CfgVehicles" >> typeOf _object, true] call BIS_fnc_returnParents;
{
	_config = missionConfigFile >> "CfgVehicles" >> _x >> "AGM_SelfActions";

	_count = count _config;
	if (_count > 0) then {
		for "_index" from 0 to (_count - 1) do {
			_action = _config select _index;

			if (count _action > 0) then {
				_configName = configName _action;
				_displayName = getText (_action >> "displayName");

				_condition = getText (_action >> "condition");
				if (_condition == "") then {_condition = "true"};

				_condition = _condition + format [" && {%1 call AGM_Core_canInteract}", getArray (_action >> "exceptions")];
				_condition = compile _condition;
				_statement = compile getText (_action >> "statement");
				_showDisabled = getNumber (_action >> "showDisabled") == 1;
				if (isText (_action >> "conditionShow")) then {
					_showDisabled = call compile getText (_action >> "conditionShow");
				};
				_priority = getNumber (_action >> "priority");

				_subMenu = getArray (_action >> "subMenu");

				if (!(_configName in _patches) && {_showDisabled || {call _condition}}) then {
					_actions set [count _actions, [_displayName, _statement, _condition, _priority, _subMenu]];
					_patches set [count _patches, _configName];
				};
			};
		};
	};
} forEach _parents;

// search add-on config file
{
	_config = configfile >> "CfgVehicles" >> _x >> "AGM_SelfActions";

	_count = count _config;
	if (_count > 0) then {
		for "_index" from 0 to (_count - 1) do {
			_action = _configClass >> configName (_config select _index);

			if (count _action > 0) then {
				_configName = configName _action;
				_displayName = getText (_action >> "displayName");

				_condition = getText (_action >> "condition");
				if (_condition == "") then {_condition = "true"};

				_condition = _condition + format [" && {%1 call AGM_Core_canInteract}", getArray (_action >> "exceptions")];
				_condition = compile _condition;
				_statement = compile getText (_action >> "statement");
				_showDisabled = getNumber (_action >> "showDisabled") == 1;
				if (isText (_action >> "conditionShow")) then {
					_showDisabled = call compile getText (_action >> "conditionShow");
				};
				_priority = getNumber (_action >> "priority");

				_subMenu = getArray (_action >> "subMenu");

				if (!(_configName in _patches) && {_showDisabled || {call _condition}}) then {
					_actions set [count _actions, [_displayName, _statement, _condition, _priority, _subMenu]];
					_patches set [count _patches, _configName];
				};
			};
		};
	};
} forEach _parents;

// search vehicle namespace
_customActions = player getVariable ["AGM_InteractionsSelf", []];
for "_index" from 0 to (count _customActions - 1) do {
	_customAction = _customActions select _index;
	_displayName = _customAction select 0;

	_condition = _customAction select 1;
	_statement = _customAction select 2;
	_showDisabled = _customAction select 3;
	_priority = _customAction select 4;
	_subMenu = [];

	if (_showDisabled || {call _condition}) then {
		_actions set [count _actions, [_displayName, _statement, _condition, _priority, _subMenu]];
	};
};

_count = count _actions;
if (_count == 0) exitWith {};

_actions call AGM_Interaction_fnc_sortOptionsByPriority;

AGM_Interaction_Buttons = _actions;

(findDisplay 1713999) closeDisplay 1;
(findDisplay 46) createDisplay "AGM_Interaction_Dialog";

// add keys to display
(findDisplay 1713999) displayAddEventHandler ["KeyDown", "_this call AGM_Core_onKeyDown"];
(findDisplay 1713999) displayAddEventHandler ["KeyUp", "_this call AGM_Core_onKeyUp"];

setMousePosition [0.5, 0.5];

disableSerialization;
_dlgInteractionDialog = uiNamespace getVariable "AGM_Interaction_Dialog";

/*
for "_a" from 0 to (_count - 1) do {
	_action = AGM_Interaction_Buttons select _a;

	_ctrlInteractionDialog = _dlgInteractionDialog displayCtrl (10 + _a);
	_ctrlInteractionDialog ctrlShow true;
	_ctrlInteractionDialog ctrlSetText (_action select 0);
	_ctrlInteractionDialog ctrlEnable (call (_action select 2));
};
*/

_ctrlInteractionDialog = _dlgInteractionDialog displayCtrl 3;

AGM_Interaction_MainButton = "(findDisplay 1713999) closeDisplay 1;";

if (_object isKindOf "Man") then {
	_ctrlInteractionDialog ctrlSetText (if (alive _object) then {name _object} else {_object getVariable ["AGM_Name", "Unknown"]});
} else {
	_ctrlInteractionDialog ctrlSetText (getText (configFile >> "CfgVehicles" >> typeOf _object >> "displayName"));
};

for "_i" from 0 to 9 do {
	_ctrlInteractionDialog = _dlgInteractionDialog displayCtrl (10 + _i);
	_ctrlInteractionDialog ctrlShow true;

	if (_i < _count) then {
		_action = AGM_Interaction_Buttons select _i;
		_ctrlInteractionDialog ctrlSetText (_action select 0);
		_ctrlInteractionDialog ctrlEnable (call (_action select 2));
	} else {
		_ctrlInteractionDialog ctrlSetText "";
		_ctrlInteractionDialog ctrlEnable false;
	}
};
