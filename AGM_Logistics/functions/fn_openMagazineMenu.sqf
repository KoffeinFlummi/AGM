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
private ["_vehicle","_magazines", "_listIDC"];
AGM_Logistics_targetVehicle = _this select 0;
_magazines = [player, AGM_Logistics_targetVehicle] call AGM_Logistics_fnc_getLoadableMagazines;

_listIDC = [localize "STR_AGM_Logistics_MagazineMenu", localize "STR_AGM_Logistics_LoadItem", "_mag = lbData [8866, lbCurSel 8866];closeDialog 0;[player, AGM_Logistics_targetVehicle, _mag] call AGM_Logistics_fnc_loadMagazine;"] call AGM_Interaction_fnc_openSelectMenu;

_listed = [];
{
	if (!(_x in _listed) && {[AGM_Logistics_targetVehicle, _x] call AGM_Logistics_fnc_canLoadMagazine}) then {
		_class = ConfigFile >> "CfgMagazines" >> _x;
		_index = lbAdd [_listIDC, getText (_class >> "DisplayName")];
		lbSetData [_listIDC, _index, _x];
		lbSetPicture [_listIDC, _index, getText (_class >> "picture")];
		_listed set [count _listed, _x];
	};
} count _magazines;

lbSetCurSel [_listIDC, 0];