/*
	Name: AGM_Explosives_fnc_openPlaceUI
	
	Author: Garth de Wet (LH)
	
	Description:
		Opens the UI for explosive placement selection
	
	Parameters: 
		0: OBJECT - unit
	
	Returns:
		Nothing
	
	Example:
		[player] call AGM_Explosives_fnc_openPlaceUI;
*/
private ["_unit","_mags", "_item", "_index", "_listIDC"];
_unit = _this select 0;
call AGM_Explosives_fnc_Place_Cancel;

_listIDC = [localize "STR_AGM_Explosives_PlaceMenu", localize "STR_AGM_Explosives_Place", "private ['_triggerTypes', '_mag'];_mag=lbData [8866, lbCurSel 8866];_triggerTypes = [_mag] call AGM_Explosives_fnc_TriggerType;if ({_x} count _triggerTypes > 1) then {[_mag] call AGM_Explosives_fnc_openTriggerSelectionUI;}else{if(_triggerTypes select 1)then{[_mag] call AGM_Explosives_fnc_openTimerSetUI;}else{[player, _mag] call AGM_Explosives_fnc_SetupExplosive;closeDialog 0;};};"] call AGM_Interaction_fnc_openSelectMenu;

_mags = magazines _unit;
{
	_item = ConfigFile >> "CfgMagazines" >> _x;
	if (getNumber(_item >> "AGM_Placeable") == 1) then {
		_index = lbAdd [_listIDC, getText(_item >> "displayName")];
		lbSetData [_listIDC, _index, _x];
		lbSetPicture [_listIDC, _index, getText(_item >> "picture")];
	};
} count _mags;

lbSetCurSel [_listIDC, 0];