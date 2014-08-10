/*
	Name: AGM_Logistics_fnc_openUnloadUI
	
	Author: Garth de Wet (LH)
	
	Description:
		Opens the UI for unload position selection
	
	Parameters:
		0: OBJECT - vehicle to open unload UI on
	
	Returns:
		Nothing
	
	Example:
		[AGM_Logistics_targetVehicle] call AGM_Logistics_fnc_openUnloadUI;
*/
private ["_vehicle", "_index", "_listIDC"];
_vehicle = _this select 0;

AGM_Logistics_targetVehicle = _vehicle;
_actions = [];
if (isClass (configFile >> "CfgVehicles" >> typeOf(_vehicle) >> "AGM_Load")) then {
	_attachPoints = _vehicle call AGM_Logistics_fnc_getLoadPoints;
	{
		_class = _x select 4;
		{
			_action = [getText (ConfigFile >> "CfgVehicles" >> typeOf(_x) >> "displayName"),
				{call AGM_Interaction_fnc_hideMenu;[AGM_Logistics_targetVehicle, _this select 5] spawn AGM_Logistics_fnc_unloadItem;},
				{true}, _foreachIndex,
				getText (ConfigFile >> "CfgVehicles" >> typeOf(_x) >> "picture"),
				["AGM_Load_" + _class, _foreachIndex]
			];
			_actions set [count _actions, _action];
		} foreach (_x select 3);
	} count _attachPoints;
};

_attachPoints = _vehicle getVariable ["AGM_Logistics_loadedItems", []];
{
	_action = [getText (ConfigFile >> "CfgVehicles" >> typeOf(_x) >> "displayName"),
		{call AGM_Interaction_fnc_hideMenu;[AGM_Logistics_targetVehicle, _this select 5] spawn AGM_Logistics_fnc_unloadItem;},
		{true}, _foreachIndex,
		getText (ConfigFile >> "CfgVehicles" >> typeOf(_x) >> "picture"),
		["AGM_Logistics_loadedItems", _foreachIndex]
	];
	_actions set [count _actions, _action];
} foreach _attachPoints;

[_actions, {"Default" call AGM_Interaction_fnc_openMenu;}] call AGM_Interaction_fnc_openSelectMenu;