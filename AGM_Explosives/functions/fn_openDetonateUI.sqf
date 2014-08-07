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
private ["_unit","_result", "_item", "_index", "_listIDC", "_item"];
_unit = _this select 0;
_range = 0;
{
	if (getNumber (ConfigFile >> "CfgWeapons" >> _x >> "AGM_Detonator") == 1) then {
		_cr = getNumber (ConfigFile >> "CfgWeapons" >> _x >> "AGM_Range");
		if (_range < _cr) then {
			_range = _cr;
		};
	};
} count (items _unit);

_listIDC = [localize "STR_AGM_Explosives_DetonateMenu", localize "STR_AGM_Explosives_Detonate", format ["[player,%1, player getVariable ['AGM_Clacker', []] select (parseNumber lbData [8866, lbCurSel 8866]), false, false] call AGM_Explosives_fnc_DetonateExplosive;closeDialog 0;", _range], "closeDialog 0;'AGM_Explosives' call AGM_Interaction_fnc_openMenuSelf;"] call AGM_Interaction_fnc_openSelectMenu;

_result = _unit getVariable ["AGM_Clacker", []];

private ["_item", "_index"];
{
	if (!isNull(_x select 0)) then {
		_item = ConfigFile >> "CfgMagazines" >> (_x select 3);
		_index = lbAdd [_listIDC, _x select 2];
		lbSetData [_listIDC, _index, str(_foreachIndex)];
		lbSetPicture [_listIDC, _index, getText(_item >> "picture")];
	};
} foreach _result;

lbSetCurSel [_listIDC, 0];