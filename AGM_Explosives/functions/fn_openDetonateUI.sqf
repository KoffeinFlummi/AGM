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
_actions = [];
{
	if (!isNull(_x select 0)) then {
		_item = ConfigFile >> "CfgMagazines" >> (_x select 3);
		/*
			0 = Text
			1 = statement to execute
			2 = condition before execute
			3 = showDisabled
			4 = priority
			5 = icon
			6+ = extra variables.
		*/
		_action = [_x select 2, {[player,(_this select 6), player getVariable ["AGM_Clacker", []] select (_this select 5), false, false] call AGM_Explosives_fnc_DetonateExplosive;call AGM_Interaction_fnc_hideMenu;}, {true}, _foreachIndex, getText(_item >> "picture"), _foreachIndex, _range];
		_actions set [count _actions, _action];
	};
} foreach _result;

[_actions, {"AGM_Explosives" call AGM_Interaction_fnc_openMenuSelf;}] call AGM_Interaction_fnc_openSelectMenu;