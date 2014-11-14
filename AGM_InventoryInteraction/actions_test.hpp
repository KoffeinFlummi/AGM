
	//AGM_Attach
	class AGM_IR_Strobe_Item: AGM_ItemCore {
		class AGM_InventoryActions {
			class AGM_Attach {
				displayName = "$STR_AGM_Attach_Attach";
				condition = "[_player, _classname] call AGM_Attach_fnc_canAttach";
				statement = "[_player, _classname] call AGM_Attach_fnc_attach";
				closeInventory = 0;
			};
		};
	};
	
	//AGM_Hearing
	class AGM_EarBuds: AGM_ItemCore {
		class AGM_InventoryActions {
			class AGM_EarbudsIn {
				displayName = "$STR_AGM_Hearing_Earbuds_On";
				condition = "!([_player] call AGM_Hearing_fnc_hasEarPlugsIn) && {'AGM_EarBuds' in items _player}";
				statement = "[_player] call AGM_Hearing_fnc_putInEarPlugs";
				closeInventory = 0;
			};
		};
	};
	
	//AGM_Overheating
	class AGM_SpareBarrel: AGM_ItemCore {
		class AGM_InventoryActions {
			class AGM_OpenClackerMenu {
				displayName = "$STR_AGM_Overheating_SwapBarrel";
				condition = "'AGM_SpareBarrel' in items _player && {getNumber (configFile >> 'CfgWeapons' >> currentWeapon _player >> 'AGM_Overheating_allowSwapBarrel') == 1}";
				statement = "[_player, currentWeapon _player] call AGM_Overheating_fnc_swapBarrel;";
				closeInventory = 1;
			};
		};
	};
	
	//AGM_Explosives
	class AGM_Clacker: AGM_ItemCore {
		class AGM_InventoryActions {
			class AGM_OpenClackerMenu {
				displayName = "Open Clacker Menu";
				condition = "true";
				statement = "[_player, _classname] call AGM_Explosives_fnc_openDetonateUI;";
				closeInventory = 1;
			};
		};
	};
	
	//AGM_wind
	class AGM_ItemKestrel: AGM_ItemCore {
		class AGM_InventoryActions {
			class AGM_OpenKestrel {
				displayName = "$STR_AGM_Wind_OpenKestrel";
				condition = "'AGM_ItemKestrel' in items player && {!underwater player} && {cameraView != 'Gunner'} && {!AGM_isKestrel}";
				statement = "call AGM_Wind_fnc_openKestrel";        
				closeInventory = 0;
			};
			class AGM_CloseKestrel {
				displayName = "$STR_AGM_Wind_CloseKestrel";
				condition = "AGM_isKestrel";
				statement = "AGM_isKestrel = false";        
				closeInventory = 0;
			};
		};
	};
};

class CfgVehicles {
	class ReammoBox;
	class Bag_Base: ReammoBox {
		class AGM_InventoryActions {
			class AGM_LockBackpack {
				displayName = "$STR_AGM_Backpacks_LockBackpack";
				condition = "[backpackContainer _player] call AGM_Backpacks_fnc_isBackpack && {!((backpackContainer _player) getVariable ['AGM_LockedInventory', false])}";
				statement = "(backpackContainer _player) setVariable ['AGM_LockedInventory', true, true]";
				closeInventory = 0;
			};
			class AGM_UnlockBackpack {
				displayName = "$STR_AGM_Backpacks_UnlockBackpack";
				condition = "[backpackContainer _player] call AGM_Backpacks_fnc_isBackpack && {(backpackContainer _player) getVariable ['AGM_LockedInventory', false]}";
				statement = "(backpackContainer _player) setVariable ['AGM_LockedInventory', false, true]";
				closeInventory = 0;
			};
		};
	};
};



class CfgMagazines {
	/* 	class CA_Magazine;

	//AGM_Explosives
	class ATMine_Range_Mag:CA_Magazine { */
	
	class Default;
	class CA_Magazine: Default {
		class AGM_InventoryActions {
			class OpenTriggerSelection {  
				displayName = "$STR_AGM_Explosives_Place";
				condition = "(vehicle _player == _player) && (getNumber(configFile >> 'CfgMagazines' >> _classname >> 'AGM_Placeable') == 1)";
				statement = "[_classname] call AGM_Explosives_fnc_openTriggerSelectionUI;";
				closeInventory = 1;
			};
		};
	};
	
	//AGM_Attach
	class B_IR_Grenade: CA_Magazine {
		class AGM_InventoryActions {
			class AGM_Attach {
				displayName = "$STR_AGM_Attach_Attach";
				condition = "[_player, _classname] call AGM_Attach_fnc_canAttach";
				statement = "[_player, _classname] call AGM_Attach_fnc_attach";
				closeInventory = 0;
			};
		};
	};	
	
	class Chemlight_green: SmokeShell {
		class AGM_InventoryActions {
			class AGM_Attach {
				displayName = "$STR_AGM_Attach_Attach";
				condition = "[_player, _classname] call AGM_Attach_fnc_canAttach";
				statement = "[_player, _classname] call AGM_Attach_fnc_attach";
				closeInventory = 0;
			};
		};
	};
};
