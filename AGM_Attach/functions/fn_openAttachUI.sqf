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
    [player, player, "self"] call AGM_Attach_fnc_openAttachUI;
*/
private ["_unit", "_attachToVehicle", "_attachToPointName", "_listed", "_attachables", "_actions", "_item"];

_unit = _this select 0;
_attachToVehicle = _this select 1;
_attachToPointName = _this select 2;

_listed = [];
_attachables = magazines _unit;
_actions = [localize "STR_AGM_Attach_AttachDetach", localize "STR_AGM_Attach_Attach"] call AGM_Interaction_fnc_prepareSelectMenu;
{
  if !(_x in _listed) then {
    _item = ConfigFile >> "CfgMagazines" >> _x;
    if (getNumber (_item >> "AGM_Attachable") == 1) then {
      _actions = [
      _actions,
      getText(_item >> "displayName"),
      getText(_item >> "picture"),
      _x
      ] call AGM_Interaction_fnc_AddSelectableItem;
    };
    _listed pushBack _x;
  };
} forEach _attachables;
_attachables = items _unit;
{
  if !(_x in _listed) then {
    _item = ConfigFile >> "CfgWeapons" >> _x;
    if (getNumber (_item >> "AGM_Attachable") == 1) then {
      _actions = [
      _actions,
      getText(_item >> "displayName"),
      getText(_item >> "picture"),
      _x
      ] call AGM_Interaction_fnc_AddSelectableItem;
    };
    _listed pushBack _x;
  };
} forEach _attachables;

[
_actions,
compile format ["
  [AGM_player, AGM_Interaction_Target, '%1', _this] call AGM_Attach_fnc_attach;
  call AGM_Interaction_fnc_hideMenu;
  ", _attachToPointName], //ugh, compile
{
  call AGM_Interaction_fnc_hideMenu;
  if !(profileNamespace getVariable ["AGM_Interaction_AutoCloseMenu", false]) then {"Default" call AGM_Interaction_fnc_openMenuSelf};
}
] call AGM_Interaction_fnc_openSelectMenu;
