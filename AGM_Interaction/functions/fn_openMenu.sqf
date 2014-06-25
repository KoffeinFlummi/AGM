// by commy2

AGM_Interaction_Buttons = [];

_actions = [];
_patches = [];
_class = _this;
if (_class == "") then {AGM_Interaction_Target = cursorTarget};
_object = AGM_Interaction_Target;

// search mission config file
_parents = [configfile >> "CfgVehicles" >> typeOf _object, true] call BIS_fnc_returnParents;
{
	_config = missionConfigFile >> "CfgVehicles" >> _x >> "AGM_Actions";
	if (_class != "") then {_config = _config >> _this};

	_count = count _config;
	if (_count > 0) then {
		for "_a" from 0 to (_count - 1) do {
			_action = _config select _a;

			if (count _action > 0) then {
				_configName = configName _action;
				_displayName = getText (_action >> "displayName");
				_distance = getNumber (_action >> "distance");
				_condition = compile getText (_action >> "condition");
				_statement = compile getText (_action >> "statement");
				_showDisabled = getNumber (_action >> "showDisabled") == 1;
				_priority = getNumber (_action >> "priority");

				if (!(_configName in _patches) && {_showDisabled || {call _condition}} && {[_object, _distance] call AGM_Interaction_fnc_isInRange || {_distance == 0}}) then {
					_actions set [count _actions, [_displayName, _statement, _condition, _priority]];
					_patches set [count _patches, _configName];
				};
			};
		};
	};
} forEach _parents;

// search add-on config file
_config = configfile >> "CfgVehicles" >> typeOf _object >> "AGM_Actions";
if (_class != "") then {_config = _config >> _this};

_count = count _config;
if (_count > 0) then {
	for "_a" from 0 to (_count - 1) do {
		_action = _config select _a;

		if (count _action > 0) then {
			_configName = configName _action;
			_displayName = getText (_action >> "displayName");
			_distance = getNumber (_action >> "distance");
			_condition = compile getText (_action >> "condition");
			_statement = compile getText (_action >> "statement");
			_showDisabled = getNumber (_action >> "showDisabled") == 1;
			_priority = getNumber (_action >> "priority");

			if (!(_configName in _patches) && {_showDisabled || {call _condition}} && {[_object, _distance] call AGM_Interaction_fnc_isInRange || {_distance == 0}}) then {
				_actions set [count _actions, [_displayName, _statement, _condition, _priority]];
				_patches set [count _patches, _configName];
			};
		};
	};
};

_count = count _actions;
if (_count == 0) exitWith {};

_actions call AGM_Interaction_fnc_sortOptionsByPriority;

AGM_Interaction_Buttons = _actions;

closeDialog 0;
createDialog "AGM_Interaction_Dialog";

if (_class == "") then {setMousePosition [0.5, 0.5]};

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

_ctrlInteractionDialog = _dlgInteractionDialog displayCtrl 2;
if (_class == "") then {
	AGM_Interaction_MainButton = "closeDialog 0;";
	if (AGM_Interaction_Target isKindOf "Man") then {
		_ctrlInteractionDialog ctrlSetText (AGM_Interaction_Target getVariable ["AGM_Name", (name AGM_Interaction_Target)]);
	} else {
		_ctrlInteractionDialog ctrlSetText (getText (configFile >> "CfgVehicles" >> (typeOf AGM_Interaction_Target) >> "displayName"));
	};
} else {
	AGM_Interaction_MainButton = "'' call AGM_Interaction_fnc_openMenu;";
	_ctrlInteractionDialog ctrlSetText "<< " + localize "STR_AGM_Interaction_Back";
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
