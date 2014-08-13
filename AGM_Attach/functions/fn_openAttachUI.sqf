/*
	Name: AGM_Attach_fnc_openAttachUI
	
	Author: Garth de Wet (LH)
	
	Description:
		Opens the UI for attaching objects.
	
	Parameters: 
		0: OBJECT - unit
	
	Returns:
		Nothing
	
	Example:
		[player] call AGM_Attach_fnc_openAttachUI;
*/
private ["_unit","_mags", "_actions", "_attachables", "_item"];
_unit = _this select 0;
_mags = magazines _unit;
_attachables = ["AGM_IR_Strobe_Item", "B_IR_Grenade", "O_IR_Grenade", "I_IR_Grenade", "Chemlight_blue", "Chemlight_green", "Chemlight_red", "Chemlight_yellow"];

_actions = [localize "STR_AGM_Attach_AttachDetach", localize "STR_AGM_Attach_Attach"] call AGM_Interaction_fnc_prepareSelectMenu;
{
	if (_x in _mags) then {
		_item = ConfigFile >> "CfgMagazines" >> _x;
		_actions = [
			_actions,
			getText(_item >> "displayName"),
			getText(_item >> "picture"),
			_x
		] call AGM_Interaction_fnc_AddSelectableItem;
	};
} foreach _attachables;

[_actions,{[player, _this] call AGM_Attach_fnc_attach;call AGM_Interaction_fnc_hideMenu;},{"" call AGM_Interaction_fnc_openMenuSelf;}] call AGM_Interaction_fnc_openSelectMenu;