/*
	Name: AGM_Logistics_fnc_openLoadUI
	
	Author: Garth de Wet (LH)
	
	Description:
		Opens the UI for load position selection
	
	Parameters:
		
	
	Returns:
		Nothing
	
	Example:
		[AGM_Interaction_Target, AGM_Logistics_targetVehicle] call AGM_Logistics_fnc_openLoadUI;
*/
private ["_vehicle","_result", "_item", "_index", "_listIDC"];
_item = _this select 0;
_vehicle = _this select 1;

_listIDC = [localize "STR_AGM_Logistics_LoadMenu", localize "STR_AGM_Logistics_LoadItem", "[AGM_Interaction_Target, AGM_Logistics_targetVehicle, lbData [8866, lbCurSel 8866]] spawn AGM_Logistics_fnc_loadItem;closeDialog 0;"] call AGM_Interaction_fnc_openSelectMenu;

_size = getNumber(ConfigFile >> "CfgVehicles" >> Typeof(_item) >> "AGM_Size");
_attachPoints = _vehicle call AGM_Logistics_fnc_getLoadPoints;
{
	if ([_x select 1, _x select 3] call AGM_Logistics_fnc_remainingSpace >= _size) then {
		_index = lbAdd [_listIDC, getText (ConfigFile >> "CfgVehicles" >> typeOf(_vehicle) >> "AGM_Load" >> _x select 4 >> "DisplayName")];
		lbSetData [_listIDC, _index, _x select 4];
	};
} count _attachPoints;

lbSetCurSel [_listIDC, 0];

AGM_Interaction_Target = _item;
AGM_Logistics_targetVehicle = _vehicle;