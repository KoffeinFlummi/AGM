/*
Name: AGM_InventoryInteraction_fnc_inventoryOpened

Author: Pabst Mirror

Description:
  Handles opening inventory event from AGM_Core_fnc_addInventoryDisplayLoadedEventHandler
  Adds the required event handlers to the inventory display.

Parameters:
  0: DISPLAY - from RscDisplayInventory's onLoad

Returns:
  Nothing

Example:
  internal use
*/
#include "\AGM_InventoryInteraction\scriptDefines.sqf"

private ["_index", "_idc", "_display"];

disableSerialization;
_display = _this select 0;

if (isNil "_display" || {isNull _display}) exitWith { 
  ["AGM_InventoryInteraction_fnc_inventoryOpened - _display null"] call BIS_fnc_error;
};

// Uniform Listbox
(_display displayCtrl IDC_CONTAINER_UNIFORM) ctrlAddEventHandler ["MouseButtonUp", {_this call AGM_InventoryInteraction_fnc_handleClickInvList;}];
(_display displayCtrl IDC_CONTAINER_UNIFORM) ctrlAddEventHandler ["LBSelChanged", {[_this, false] call AGM_InventoryInteraction_fnc_handleSelChangeInvList;}];
(_display displayCtrl IDC_CONTAINER_UNIFORM) ctrlAddEventHandler ["LBDblClick", {[_this, true] call AGM_InventoryInteraction_fnc_handleSelChangeInvList;}];

// Backpack Listbox
(_display displayCtrl IDC_CONTAINER_BACKPACK) ctrlAddEventHandler ["MouseButtonUp", {_this call AGM_InventoryInteraction_fnc_handleClickInvList;}];
(_display displayCtrl IDC_CONTAINER_BACKPACK) ctrlAddEventHandler ["LBSelChanged", {[_this, false] call AGM_InventoryInteraction_fnc_handleSelChangeInvList;}];
(_display displayCtrl IDC_CONTAINER_BACKPACK) ctrlAddEventHandler ["LBDblClick", {[_this, true] call AGM_InventoryInteraction_fnc_handleSelChangeInvList;}];

// Vest Listbox
(_display displayCtrl IDC_CONTAINER_VEST) ctrlAddEventHandler ["MouseButtonUp", {_this call AGM_InventoryInteraction_fnc_handleClickInvList;}];
(_display displayCtrl IDC_CONTAINER_VEST) ctrlAddEventHandler ["LBSelChanged", {[_this, false] call AGM_InventoryInteraction_fnc_handleSelChangeInvList;}];
(_display displayCtrl IDC_CONTAINER_VEST) ctrlAddEventHandler ["LBDblClick", {[_this, true] call AGM_InventoryInteraction_fnc_handleSelChangeInvList;}];

//Assigned Items Slots
(_display displayCtrl IDC_SLOT_MAP) ctrlAddEventHandler ["MouseButtonClick",     {[_this, false] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];
(_display displayCtrl IDC_SLOT_MAP) ctrlAddEventHandler ["MouseButtonDblClick",   {[_this, true] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];  

(_display displayCtrl IDC_SLOT_GPS) ctrlAddEventHandler ["MouseButtonClick",     {[_this, false] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];
(_display displayCtrl IDC_SLOT_GPS) ctrlAddEventHandler ["MouseButtonDblClick",   {[_this, true] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];  

(_display displayCtrl IDC_SLOT_RADIO) ctrlAddEventHandler ["MouseButtonClick",     {[_this, false] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];
(_display displayCtrl IDC_SLOT_RADIO) ctrlAddEventHandler ["MouseButtonDblClick",   {[_this, true] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];

(_display displayCtrl IDC_SLOT_COMPASS) ctrlAddEventHandler ["MouseButtonClick",     {[_this, false] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];
(_display displayCtrl IDC_SLOT_COMPASS) ctrlAddEventHandler ["MouseButtonDblClick",   {[_this, true] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];  

(_display displayCtrl IDC_SLOT_WATCH) ctrlAddEventHandler ["MouseButtonClick",     {[_this, false] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];
(_display displayCtrl IDC_SLOT_WATCH) ctrlAddEventHandler ["MouseButtonDblClick",   {[_this, true] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];

//Player's Containers Slots (Uniform, Vest, Backpack)
(_display displayCtrl IDC_SLOT_BACKPACK) ctrlAddEventHandler ["MouseButtonClick",     {[_this, false] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];
(_display displayCtrl IDC_SLOT_BACKPACK) ctrlAddEventHandler ["MouseButtonDblClick",   {[_this, true] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];


//Clicking on ANYTHING else will close the menu (so it's not in the way)
for "_index" from 0 to ((count (configFile >> "RscDisplayInventory" >> "controls")) - 1) do {
  _idc = getNumber (((configFile >> "RscDisplayInventory" >> "controls") select _index) >> "IDC");
  if (!(_idc in [
        IDC_ACTION_CONTROLGROUP, 
        IDC_CONTAINER_UNIFORM, IDC_CONTAINER_BACKPACK, IDC_CONTAINER_VEST, 
        IDC_SLOT_MAP, IDC_SLOT_GPS, IDC_SLOT_RADIO, IDC_SLOT_COMPASS, IDC_SLOT_WATCH,
        IDC_SLOT_BACKPACK
        ])) then {
    (_display displayCtrl _idc) ctrlAddEventHandler ["MouseButtonDown", {[] call AGM_InventoryInteraction_fnc_closeItemInfoBox;}];
  };
  (_display displayCtrl _idc) ctrlAddEventHandler ["LBDrag", {[] call AGM_InventoryInteraction_fnc_closeItemInfoBox;}];
};  
