/*
	Name: AGM_Explosives_fnc_openDetonateUI
	
	Author: Garth de Wet (LH)
	
	Description:
		Opens the UI for explosive detonation selection
	
	Parameters: 
		0: OBJECT - unit
	
	Returns:
		Nothing
	
	Example:
		[player] call AGM_Explosives_fnc_openDetonateUI;
*/
private ["_unit","_result", "_item", "_index", "_listIDC"];
_unit = _this select 0;

_listIDC = [localize "STR_AGM_Explosives_DetonateMenu", localize "STR_AGM_Explosives_Detonate", "[player, player getVariable ['AGM_Clacker', []] select (parseNumber lbData [8866, lbCurSel 8866]), false, false] call AGM_Explosives_fnc_DetonateExplosive;closeDialog 0;"] call AGM_Interaction_fnc_openSelectMenu;

_result = _unit getVariable ["AGM_Clacker", []];

private ["_item", "_index"];
{
	if (!isNull(_x select 0)) then {
		_item = ConfigFile >> "CfgMagazines" >> (_x select 4);
		_index = lbAdd [_listIDC, _x select 3];
		lbSetData [_listIDC, _index, str(_foreachIndex)];
		lbSetPicture [_listIDC, _index, getText(_item >> "picture")];
	};
} foreach _result;

lbSetCurSel [_listIDC, 0];