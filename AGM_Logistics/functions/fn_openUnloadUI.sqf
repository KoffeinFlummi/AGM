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
_listIDC = [localize "STR_AGM_Logistics_UnloadMenu", localize "STR_AGM_Logistics_UnloadItem", "[AGM_Logistics_targetVehicle, call compile (lbData [8866, lbCurSel 8866])] spawn AGM_Logistics_fnc_unloadItem;closeDialog 0;"] call AGM_Interaction_fnc_openSelectMenu;

if (isClass (configFile >> "CfgVehicles" >> typeOf(_vehicle) >> "AGM_Load")) exitWith {
	_attachPoints = _vehicle call AGM_Logistics_fnc_getLoadPoints;
	{
		_class = _x select 4;
		{
			_index = lbAdd [_listIDC, getText (ConfigFile >> "CfgVehicles" >> typeOf(_x) >> "displayName")];
			lbSetData [_listIDC, _index, format ["['AGM_Load_%1', %2]", _class, _foreachIndex]];
		} foreach (_x select 3);
	} count _attachPoints;

	lbSetCurSel [_listIDC, 0];
};

_attachPoints = _vehicle getVariable ["AGM_Logistics_loadedItems", []];
{
	_index = lbAdd [_listIDC, getText (ConfigFile >> "CfgVehicles" >> typeOf(_x) >> "displayName")];
	lbSetData [_listIDC, _index, format ["['AGM_Logistics_loadedItems', %1]", _foreachIndex]];
} foreach _attachPoints;