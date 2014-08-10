/*
	Name: AGM_Logistics_fnc_openMagazineMenu
	
	Author: Garth de Wet (LH)
	
	Description:
		Opens the UI for selecting magazines to load into vehicle.
	
	Parameters:
		0: OBJECT - vehicle
	
	Returns:
		Nothing
	
	Example:
		[AGM_Interaction_Target] call AGM_Logistics_fnc_openMagazineMenu;
*/
private ["_vehicle","_magazines"];
AGM_Logistics_targetVehicle = _this select 0;
_magazines = [player, AGM_Logistics_targetVehicle] call AGM_Logistics_fnc_getLoadableMagazines;

_listed = [];
_actions = [];
{
	if (!(_x in _listed) && {[AGM_Logistics_targetVehicle, _x] call AGM_Logistics_fnc_canLoadMagazine}) then {
		_class = ConfigFile >> "CfgMagazines" >> _x;
		_action = [getText (_class >> "DisplayName"),
			{call AGM_Interaction_fnc_hideMenu;[player, AGM_Logistics_targetVehicle, _this select 5] call AGM_Logistics_fnc_loadMagazine;},
			{true}, 0,
			getText (_class >> "picture"),
			_x
		];
		_listed set [count _listed, _x];
		_actions set [count _actions, _action];
	};
} count _magazines;

[_actions, {"Default" call AGM_Interaction_fnc_openMenu;}] call AGM_Interaction_fnc_openSelectMenu;