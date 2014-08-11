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
call AGM_Interaction_fnc_hideMenu;
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

_result = _unit getVariable ["AGM_Clacker", []];
_actions = [localize "STR_AGM_Explosives_DetonateMenu", localize "STR_AGM_Explosives_Detonate"] call AGM_Interaction_fnc_prepareSelectMenu;
{
	if (!isNull(_x select 0)) then {
		_item = ConfigFile >> "CfgMagazines" >> (_x select 3);
		_actions = [
			_actions,
			_x select 2,
			getText(_item >> "picture"),
			[_foreachIndex, _range]
		] call AGM_Interaction_fnc_AddSelectableItem;
	};
} foreach _result;

[_actions, {[player,parseNumber (_this select 1), player getVariable ["AGM_Clacker", []] select parseNumber (_this select 0), false, false] call AGM_Explosives_fnc_DetonateExplosive;call AGM_Interaction_fnc_hideMenu;}, {"AGM_Explosives" call AGM_Interaction_fnc_openMenuSelf;}] call AGM_Interaction_fnc_openSelectMenu;