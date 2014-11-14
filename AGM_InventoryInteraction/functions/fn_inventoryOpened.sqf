/*
Name: AGM_InventoryInteraction_fnc_inventoryOpened

Author: Pabst Mirror

Description:
  Handles opening inventory event from CBA's Extended_inventoryOpened_EventHandlers

Parameters:
  0: OBJECT - ?
  //todo
  
Returns:
  BOOL - handeled, always false

Example:
  internal use
*/
#include "\AGM_InventoryInteraction\scriptDefines.sqf"

if((_this select 0) == (call AGM_Core_fnc_player)) then {
  [] spawn {
    private ["_maxWait", "_path", "_index", "_idc"];
    
    _maxWait = diag_tickTime + 3;
    //If inventory is locked, display will never open
    waitUntil {
      (diag_tickTime > _maxWait) || !(isNull DISPLAY_INVENTORY)
    };
    
    if (isNull DISPLAY_INVENTORY) exitWith {};  //systemChat "must be locked???";
    
    // Uniform Listbox
    (DISPLAY_INVENTORY displayCtrl IDC_CONTAINER_UNIFORM) ctrlAddEventHandler ["MouseButtonUp", {_this call AGM_InventoryInteraction_fnc_handleClickInvList;}];
    (DISPLAY_INVENTORY displayCtrl IDC_CONTAINER_UNIFORM) ctrlAddEventHandler ["LBSelChanged", {[_this, false] call AGM_InventoryInteraction_fnc_handleSelChangeInvList;}];
    (DISPLAY_INVENTORY displayCtrl IDC_CONTAINER_UNIFORM) ctrlAddEventHandler ["LBDblClick", {[_this, true] call AGM_InventoryInteraction_fnc_handleSelChangeInvList;}];
    
    // Backpack Listbox
    (DISPLAY_INVENTORY displayCtrl IDC_CONTAINER_BACKPACK) ctrlAddEventHandler ["MouseButtonUp", {_this call AGM_InventoryInteraction_fnc_handleClickInvList;}];
    (DISPLAY_INVENTORY displayCtrl IDC_CONTAINER_BACKPACK) ctrlAddEventHandler ["LBSelChanged", {[_this, false] call AGM_InventoryInteraction_fnc_handleSelChangeInvList;}];
    (DISPLAY_INVENTORY displayCtrl IDC_CONTAINER_BACKPACK) ctrlAddEventHandler ["LBDblClick", {[_this, true] call AGM_InventoryInteraction_fnc_handleSelChangeInvList;}];
    
    // Vest Listbox
    (DISPLAY_INVENTORY displayCtrl IDC_CONTAINER_VEST) ctrlAddEventHandler ["MouseButtonUp", {_this call AGM_InventoryInteraction_fnc_handleClickInvList;}];
    (DISPLAY_INVENTORY displayCtrl IDC_CONTAINER_VEST) ctrlAddEventHandler ["LBSelChanged", {[_this, false] call AGM_InventoryInteraction_fnc_handleSelChangeInvList;}];
    (DISPLAY_INVENTORY displayCtrl IDC_CONTAINER_VEST) ctrlAddEventHandler ["LBDblClick", {[_this, true] call AGM_InventoryInteraction_fnc_handleSelChangeInvList;}];
    
    //Assigned Items Slots
    (DISPLAY_INVENTORY displayCtrl IDC_SLOT_MAP) ctrlAddEventHandler ["MouseButtonClick",     {[_this, false] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];
    (DISPLAY_INVENTORY displayCtrl IDC_SLOT_MAP) ctrlAddEventHandler ["MouseButtonDblClick",   {[_this, true] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];  

    (DISPLAY_INVENTORY displayCtrl IDC_SLOT_GPS) ctrlAddEventHandler ["MouseButtonClick",     {[_this, false] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];
    (DISPLAY_INVENTORY displayCtrl IDC_SLOT_GPS) ctrlAddEventHandler ["MouseButtonDblClick",   {[_this, true] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];  
    
    (DISPLAY_INVENTORY displayCtrl IDC_SLOT_RADIO) ctrlAddEventHandler ["MouseButtonClick",     {[_this, false] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];
    (DISPLAY_INVENTORY displayCtrl IDC_SLOT_RADIO) ctrlAddEventHandler ["MouseButtonDblClick",   {[_this, true] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];
    
    (DISPLAY_INVENTORY displayCtrl IDC_SLOT_COMPASS) ctrlAddEventHandler ["MouseButtonClick",     {[_this, false] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];
    (DISPLAY_INVENTORY displayCtrl IDC_SLOT_COMPASS) ctrlAddEventHandler ["MouseButtonDblClick",   {[_this, true] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];  
    
    (DISPLAY_INVENTORY displayCtrl IDC_SLOT_WATCH) ctrlAddEventHandler ["MouseButtonClick",     {[_this, false] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];
    (DISPLAY_INVENTORY displayCtrl IDC_SLOT_WATCH) ctrlAddEventHandler ["MouseButtonDblClick",   {[_this, true] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];

    //Player's Containers Slots (Uniform, Vest, Backpack)
    (DISPLAY_INVENTORY displayCtrl IDC_SLOT_BACKPACK) ctrlAddEventHandler ["MouseButtonClick",     {[_this, false] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];
    (DISPLAY_INVENTORY displayCtrl IDC_SLOT_BACKPACK) ctrlAddEventHandler ["MouseButtonDblClick",   {[_this, true] call AGM_InventoryInteraction_fnc_handleClickEquiped;}];

    
    //Clicking on ANYTHING else will close the menu
    for "_index" from 0 to ((count (configFile >> "RscDisplayInventory" >> "controls")) - 1) do {
      _path = (configFile >> "RscDisplayInventory" >> "controls") select _index;
      _idc = getNumber (_path >> "IDC");
      if (!(_idc in [
            IDC_ACTION_CONTROLGROUP, 
            IDC_CONTAINER_UNIFORM, IDC_CONTAINER_BACKPACK, IDC_CONTAINER_VEST, 
            IDC_SLOT_MAP, IDC_SLOT_GPS, IDC_SLOT_RADIO, IDC_SLOT_COMPASS, IDC_SLOT_WATCH,
            IDC_SLOT_BACKPACK
            ])) then {
        (DISPLAY_INVENTORY displayCtrl _idc) ctrlAddEventHandler ["MouseButtonDown", {[] call AGM_InventoryInteraction_fnc_closeItemInfoBox;}];
      };
      (DISPLAY_INVENTORY displayCtrl _idc) ctrlAddEventHandler ["LBDrag", {[] call AGM_InventoryInteraction_fnc_closeItemInfoBox;}];
    };      
  };
};

false
