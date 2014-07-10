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
private ["_unit", "_result"];
_unit = _this select 0;
createDialog "RscAGM_SelectAnItem";

buttonSetAction [8860, "[player, player getVariable ['AGM_Clacker', []] select (parseNumber lbData [8866, lbCurSel 8866]), false, false] call AGM_Explosives_fnc_DetonateExplosive;closeDialog 0;"];
ctrlSetText [8860, localize "STR_AGM_Explosives_Detonate"];
ctrlSetText [8870, localize "STR_AGM_Explosives_DetonateMenu"];

_result = _unit getVariable ["AGM_Clacker", []];

private ["_item", "_index"];
lbClear 8866;
{
	if (!isNull(_x select 0)) then {
		_item = ConfigFile >> "CfgMagazines" >> (_x select 4);
		_index = lbAdd [8866, "E: " + str(_x select 3)];// + getText(_item >> "displayName")];
		lbSetData [8866, _index, str(_foreachIndex)];
		lbSetPicture [8866, _index, getText(_item >> "picture")];
	};
} foreach _result;