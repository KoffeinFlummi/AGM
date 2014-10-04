/*
	Name: AGM_Interaction_fnc_showMenu
	
	Author:
		commy2
		Garth de Wet (LH)
	
	Description:
	
	Parameters: 
		0: NUMBER - Menu type (0 - interaction, 1 - self-interaction, 2 - sub-interaction, 3 - sub-self-interaction)
		1: OBJECT - Target object
		2: STRING - Sub-Menu ClassName
	
	Returns:
		Nothing
	
	Example:
		[0, AGM_Interaction_Target] call AGM_Interaction_fnc_showMenu;
		[1, player] call AGM_Interaction_fnc_showMenu;
		[2, AGM_Interaction_Target, "AGM_Explosives"] call AGM_Interaction_fnc_showMenu;
		[3, player, "AGM_Explosives"] call AGM_Interaction_fnc_showMenu;
*/
private ["_player", "_vehicle", "_mainButtonAction", "_object", "_index", "_actions", "_result", "_menuType"];
#define DEFAULT_ICON "\AGM_Interaction\UI\dot_ca.paa"
_player = call AGM_Core_fnc_player;
_vehicle = vehicle _player;

AGM_Interaction_MenuType = _this select 0;	// 0 Interaction, 1 Self Interaction

_mainButtonAction = [
	{call AGM_Interaction_fnc_hideMenu},
	{call AGM_Interaction_fnc_hideMenu},
	{"Default" call AGM_Interaction_fnc_openMenu},
	{"Default" call AGM_Interaction_fnc_openMenuSelf}
] select AGM_Interaction_MenuType;

_menuType = AGM_Interaction_MenuType % 2;
uiNamespace setVariable ["AGM_Interaction_CursorPosition", [controlNull, 0.5, 0.5, -1]];

AGM_Interaction_Target = _this select 1;
_object = AGM_Interaction_Target;

if (_menuType == 0 && {(isNull (_object) || {!([_object, 4] call AGM_Interaction_fnc_isInRange)})}) exitWith {};//call ([AGM_Interaction_fnc_onButtonDown, AGM_Interaction_fnc_onButtonDownSelf] select _menuType)};
if !([_player, _object] call AGM_Core_fnc_canInteractWith) exitWith {};

_parents = [configFile >> "CfgVehicles" >> typeOf _object, true] call BIS_fnc_returnParents;
_result = [_object, _parents, [], [], missionConfigFile >> "CfgVehicles", true, ["AGM_Actions", "AGM_SelfActions"] select _menuType, _this select 2] call AGM_Interaction_fnc_GetActions;
_actions = ([_object, _parents, _result select 0, _result select 1,configFile >> "CfgVehicles", false, ["AGM_Actions", "AGM_SelfActions"] select _menuType, _this select 2] call AGM_Interaction_fnc_GetActions) select 0;

if (AGM_Interaction_MenuType < 2) then {
	_customActions = (_object getVariable [["AGM_Interactions", "AGM_SelfInteractions"] select _menuType, [-1, [], []]]) select 2;
	for "_index" from 0 to (count _customActions - 1) do {
		private ["_customAction", "_displayName", "_distance","_condition","_statement","_showDisabled", "_priority"];
		_customAction = _customActions select _index;
		_displayName = _customAction select 0;
		_distance = _customAction select 1;
		_condition = _customAction select 2;
		_statement = _customAction select 3;
		_showDisabled = _customAction select 4;
		_priority = _customAction select 5;

		if ((_showDisabled || {[_object, _player] call _condition}) && {[_object, _distance] call AGM_Interaction_fnc_isInRange || {_distance == 0}}) then {
			_actions pushBack [_displayName, _statement, _condition, _priority, [], DEFAULT_ICON, "", {true}, [], _distance, ""];
		};
	};
};

if (count _actions == 0) exitWith {};//call ([AGM_Interaction_fnc_onButtonDown, AGM_Interaction_fnc_onButtonDownSelf] select _menuType)};

_actions call AGM_Interaction_fnc_sortOptionsByPriority;
AGM_Interaction_Buttons = _actions;
[_mainButtonAction, (_this select 2) != "", (profileNamespace getVariable ["AGM_Interaction_FlowMenu", false]), _menuType == 1, _object] call AGM_Interaction_fnc_initialiseInteraction;
