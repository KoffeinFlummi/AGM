/*
Name: AGM_InventoryInteraction_fnc_handleClickEquiped

Author: Pabst Mirror

Description:
   Handles clicking (or double clicking) on the 5 assigned item slots

Parameters:
  0: ARRAY - ctrl event
  1: BOOL - was double click

Returns:
  BOOL - handeled, always false

Example:
  internal use
*/
#include "\AGM_InventoryInteraction\scriptDefines.sqf"

private ["_idc", "_mouseButton", "_mousePos", "_wasDoubleClick", "_settingDoubleClick", "_searchArray", "_classNamesArray", "_configPath", "_baseClassname", "_clickedClassName"];

_idc = ctrlIDC ((_this select 0) select 0);
_mouseButton = ((_this select 0) select 1);
_mousePos = (_this select 0) select [2, 2];
_wasDoubleClick = _this select 1;

//Right clicks will close menu
if (_mouseButton == 1) exitWith {
  [] call AGM_InventoryInteraction_fnc_closeItemInfoBox;
  false
};

//Ignore if clicktype is different than user setting (where's the xor command?)
_settingDoubleClick = (profileNamespace getVariable ["AGM_InvInteractDoubleClick", false]);
if ((_wasDoubleClick || _settingDoubleClick) && !(_wasDoubleClick && _settingDoubleClick)) exitWith {false};

//[[array of possible classnames], config path, base classname]
_searchArray = switch (_idc) do {
case (IDC_SLOT_MAP): {[(assignedItems (call AGM_Core_fnc_player)), (configFile >> "CfgWeapons"), "ItemMap"]};
case (IDC_SLOT_GPS): {[(assignedItems (call AGM_Core_fnc_player)), (configFile >> "CfgWeapons"), "ItemGPS"]};
case (IDC_SLOT_RADIO): {[(assignedItems (call AGM_Core_fnc_player)), (configFile >> "CfgWeapons"), "ItemRadio"]};
case (IDC_SLOT_COMPASS): {[(assignedItems (call AGM_Core_fnc_player)), (configFile >> "CfgWeapons"), "ItemCompass"]};
case (IDC_SLOT_WATCH): {[(assignedItems (call AGM_Core_fnc_player)), (configFile >> "CfgWeapons"), "ItemWatch"]};
case (IDC_SLOT_BACKPACK): {[[backpack (call AGM_Core_fnc_player)], (configFile >> "CfgVehicles"), "Bag_Base"]};
  default {[]};
};

if ((count _searchArray) != 3) exitWith {false};
_classNamesArray = _searchArray select 0;
_configPath = _searchArray select 1;
_baseClassname = _searchArray select 2;

_clickedClassName = "";
{
  //finds the assigned item that inherits the baseClass (should allows selecting altimeter-Watch, TFR, ACRE radios)
  if ((_configPath >> _baseClassname) in ([(_configPath >> _x), false] call BIS_fnc_returnParents)) exitWith {
    _clickedClassName = _x;
  };
} forEach _classNamesArray;

if (isClass (_configPath >> _clickedClassName)) then {
  [(_configPath >> _clickedClassName), _mousePos, _idc] call AGM_InventoryInteraction_fnc_openItemInfoBox;
} else {
  [] call AGM_InventoryInteraction_fnc_closeItemInfoBox;
};

false
