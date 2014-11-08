// by commy2

// The Arma InventoryOpened EH fires actually before the inventory dialog is opened (findDisplay 602 => displayNull).
if (isNil "AGM_Disposable_UpdateInventoryDisplay_EHID") then {
	AGM_Disposable_UpdateInventoryDisplay_EHID = [{[call AGM_Core_fnc_player, _this select 0] spawn AGM_Disposable_fnc_updateInventoryDisplay}] call AGM_Core_fnc_addInventoryDisplayLoadedEventHandler;
};
