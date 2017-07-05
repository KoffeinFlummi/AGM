/*
  Name: AGM_Logistics_fnc_openParadropUI

  Author: Garth de Wet (LH), Ir0n1E

  Description:
    Opens the UI for unload position selection

  Parameters:
    0: OBJECT - vehicle to open unload UI on

  Returns:
    Nothing

  Example:
    [AGM_Logistics_targetVehicle] call AGM_Logistics_fnc_openParadropUI;
*/
private ["_vehicle", "_index", "_listIDC"];
_vehicle = _this select 0;

AGM_Logistics_targetVehicle = _vehicle;
_actions = [localize "STR_AGM_Logistics_UnloadMenu", localize "STR_AGM_Paradrop_Unload"] call AGM_Interaction_fnc_prepareSelectMenu;
if (isClass (configFile >> "CfgVehicles" >> typeOf(_vehicle) >> "AGM_Load")) then {
  _attachPoints = _vehicle call AGM_Logistics_fnc_getLoadPoints;
  {
    _class = _x select 4;
    {
      _actions = [
        _actions,
        getText (ConfigFile >> "CfgVehicles" >> typeOf(_x) >> "displayName"),
        getText (ConfigFile >> "CfgVehicles" >> typeOf(_x) >> "picture"),
        ["AGM_Load_" + _class, _foreachIndex]
      ] call AGM_Interaction_fnc_AddSelectableItem;
    } foreach (_x select 3);
  } count _attachPoints;
};

_attachPoints = _vehicle getVariable ["AGM_Logistics_loadedItems", []];
{
  _actions = [
    _actions,
    getText (ConfigFile >> "CfgVehicles" >> typeOf(_x) >> "displayName"),
    getText (ConfigFile >> "CfgVehicles" >> typeOf(_x) >> "picture"),
    ["AGM_Logistics_loadedItems", _foreachIndex]
  ] call AGM_Interaction_fnc_AddSelectableItem;
} foreach _attachPoints;

[
  _actions,
  {
    call AGM_Interaction_fnc_hideMenu;
    [AGM_Logistics_targetVehicle, _this] call AGM_Paradrop_fnc_paraDrop;
  },
  {
    call AGM_Interaction_fnc_hideMenu;
    if !(profileNamespace getVariable ["AGM_Interaction_AutoCloseMenu", false]) then {"Default" call AGM_Interaction_fnc_openMenu};
  }
] call AGM_Interaction_fnc_openSelectMenu;