// by commy2 (from AGM_Disposable)

// The Arma InventoryOpened EH fires actually before the inventory dialog is opened (findDisplay 602 => displayNull).
if (isNil "AGM_InventoryInteraction_setupInv_EHID") then {
  AGM_InventoryInteraction_setupInv_EHID = [{_this call AGM_InventoryInteraction_fnc_inventoryOpened}] call AGM_Core_fnc_addInventoryDisplayLoadedEventHandler;
};
