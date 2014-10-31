<<<<<<< HEAD
class CfgPatches {
	class AGM_VehicleLock {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.6;
		requiredAddons[] = {"AGM_Core", "AGM_Interaction"};

		version = "0.99";
		versionStr = "0.99";
		versionAr[] = {0, 99, 0};
		author[] = {"PabstMirror"};
		authorUrl = "bourbonwarfare.com";
	};
};

class AGM_Parameters {
	AGM_VEHICLELOCK_defaultLockpickStrength = 10;
};

class CfgFunctions {
	class AGM_VehicleLock {
		class AGM_VehicleLock {
			file = "AGM_vehicleLock\functions";
			class addKeyForVehicle;
			class getVehicleSideKey;
			class hasKeyForVehicle;
			class lockpick;
			class moduleInit;
			class moduleSync;
			class serverSetupCustomKey;
			class setVehicleLock;
		};
	};
};

class CfgMagazines {
	class CA_Magazine;
	class AGM_magazine_customKey: CA_Magazine {
		picture = "\AGM_vehicleLock\ui\keyBlack.paa";
		displayName = "AGM Vehicle Key";	//CANNONT be localized, because it is used as part of the magazineDetail string
		// displayNameShort = "Key";			//not visable
		descriptionShort = "$STR_AGM_Vehicle_Item_Custom_Description";
	};
};

class CfgWeapons {
	class InventoryItem_Base_F;
	class AGM_ItemCore;

	class AGM_item_key_master: AGM_ItemCore {
		author = "Pabst Mirror";
		displayName = "Vehicle Key: Master";
		descriptionShort = "$STR_AGM_Vehicle_Item_Master_Description";
		model = "\A3\weapons_F\ammo\mag_univ.p3d";
		picture = "\AGM_vehicleLock\ui\keyBlack.paa";
		scope = 2;
		class ItemInfo: InventoryItem_Base_F {
			mass = 0.1;
		};
	};
	class AGM_item_key_lockpick: AGM_item_key_master {
		displayName = "Lockpick";
		descriptionShort = "$STR_AGM_Vehicle_Item_Lockpick_Description";
		picture = "\AGM_vehicleLock\ui\lockpick.paa";
	};
	class AGM_item_key_west: AGM_item_key_master {
		displayName = "Vehicle Key: West";
		descriptionShort = "$STR_AGM_Vehicle_Item_West_Description";
		picture = "\AGM_vehicleLock\ui\keyBlue.paa";
	};
	class AGM_item_key_east: AGM_item_key_master {
		displayName = "Vehicle Key: East";
		descriptionShort = "$STR_AGM_Vehicle_Item_East_Description";
		picture = "\AGM_vehicleLock\ui\keyRed.paa";
	};
	class AGM_item_key_indp: AGM_item_key_master {
		displayName = "Vehicle Key: Independent";
		descriptionShort = "$STR_AGM_Vehicle_Item_Indp_Description";
		picture = "\AGM_vehicleLock\ui\keyPurple.paa";
	};
	class AGM_item_key_civ: AGM_item_key_master {
		displayName = "Vehicle Key: Civilian";
		descriptionShort = "$STR_AGM_Vehicle_Item_Civ_Description";
		picture = "\AGM_vehicleLock\ui\keyGreen.paa";
	};
};

class CfgVehicles {
	class Logic;
	class Module_F: Logic {
		class ArgumentsBaseUnits {};
		class ModuleDescription {};
	};
	class AGM_VehicleLock_ModuleSetup: Module_F {
		author = "Pabst Mirror";
		category = "AGM";
		displayName = "Vehicle Lock Setup";

		function = "AGM_VehicleLock_fnc_moduleInit";
		scope = 2;
		isGlobal = 1;
		// icon = "\AGM_Explosives\UI\IconExplosives_ca.paa";	//todo
		functionPriority = 0;
		class Arguments {
			class SideKeysAssignment {
				displayName = "Players Start Side Keys"; // Argument label
				description = "Which players start wtih side keys (e.g.: agm_item_key_west)"; // Tooltip description
				typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
				class values {
					class Nobody		{name = "Nobody"; 		value = 0;	 default = 1;};
					class GroupLeads	{name = "Group Leads"; 	value = 1;};
					class Everyone	{name = "Everyone"; 	value = 2;};
				};
			};
			class SetLockState {
				displayName = "Set Lock State"; // Argument label
				description = "Set lock state for all vehicles on map"; // Tooltip description
				typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
				class values {
					class None		{name = "As Is";		value = 0; default = 1;}; 
					class Side		{name = "Locked"; 		value = 1;};
					class Unique		{name = "Unlocked"; 	value = 2;};
				};
			};
			class LockpickStrength {
				displayName = "Global Lockpick Strength";
				description = "Global Time to lockpick (in seconds). Default: 10";
				typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
				defaultValue = "10"; // Default text filled in the input box
			};
		};
		class ModuleDescription: ModuleDescription {
			description = "Settings for lockpick strength, auto assigment of keys at start and initial vehicle lock state.";
		};
	};

	class AGM_VehicleLock_ModuleSyncedAssign: Module_F {
		author = "Pabst Mirror";
		category = "AGM";
		displayName = "Vehicle Key Assign";

		function = "AGM_VehicleLock_fnc_moduleSync";
		scope = 2;
		isGlobal = 1;
		// icon = "\AGM_Explosives\UI\IconExplosives_ca.paa";	//todo
		functionPriority = 0;

		class Arguments {};
		class ModuleDescription: ModuleDescription {
			description = "Sync with vehicles and players.  Will handout custom keys to players for every synced vehicle.";
			sync[] = {"AnyPlayer", "AnyVehicle"};
		};
	};

	class LandVehicle;
	class Car: LandVehicle {
		class AGM_Actions {
			class AGM_unlockVehicle {
				displayName = "$STR_AGM_Vehicle_Action_UnLock";
				distance = 4;
				condition = "([player, AGM_Interaction_Target] call AGM_VehicleLock_fnc_hasKeyForVehicle) && ((locked AGM_Interaction_Target) in [2, 3])";
				statement = "[AGM_Interaction_Target, false] call AGM_VehicleLock_fnc_setVehicleLock";
				showDisabled = 1;
				priority = 0.3;
				icon = "\AGM_vehicleLock\ui\key_menuIcon_ca.paa";
			};
			class AGM_lockVehicle {
				displayName = "$STR_AGM_Vehicle_Action_Lock";
				distance = 4;
				condition = "([player, AGM_Interaction_Target] call AGM_VehicleLock_fnc_hasKeyForVehicle) && ((locked AGM_Interaction_Target) in [0, 1])";
				statement = "[AGM_Interaction_Target, true] call AGM_VehicleLock_fnc_setVehicleLock";
				showDisabled = 1;
				priority = 0.2;
				icon = "\AGM_vehicleLock\ui\key_menuIcon_ca.paa";
			};
			class AGM_lockpickVehicle {
				displayName = "$STR_AGM_Vehicle_Action_Lockpick";
				distance = 4;
				condition = "[player, AGM_Interaction_Target, 'canLockpick'] call AGM_VehicleLock_fnc_lockpick";
				statement = "[player, AGM_Interaction_Target, 'startLockpick'] call AGM_VehicleLock_fnc_lockpick";
				showDisabled = 0;
				priority = 0.1;
			};
		};
	};
	class Tank: LandVehicle {
		class AGM_Actions {
			class AGM_unlockVehicle {
				displayName = "$STR_AGM_Vehicle_Action_UnLock";
				distance = 4;
				condition = "([player, AGM_Interaction_Target] call AGM_VehicleLock_fnc_hasKeyForVehicle) && ((locked AGM_Interaction_Target) in [2, 3])";
				statement = "[AGM_Interaction_Target, false] call AGM_VehicleLock_fnc_setVehicleLock";
				showDisabled = 1;
				priority = 0.3;
				icon = "\AGM_vehicleLock\ui\key_menuIcon_ca.paa";
			};
			class AGM_lockVehicle {
				displayName = "$STR_AGM_Vehicle_Action_Lock";
				distance = 4;
				condition = "([player, AGM_Interaction_Target] call AGM_VehicleLock_fnc_hasKeyForVehicle) && ((locked AGM_Interaction_Target) in [0, 1])";
				statement = "[AGM_Interaction_Target, true] call AGM_VehicleLock_fnc_setVehicleLock";
				showDisabled = 1;
				priority = 0.2;
				icon = "\AGM_vehicleLock\ui\key_menuIcon_ca.paa";
			};
			class AGM_lockpickVehicle {
				displayName = "$STR_AGM_Vehicle_Action_Lockpick";
				distance = 4;
				condition = "[player, AGM_Interaction_Target, 'canLockpick'] call AGM_VehicleLock_fnc_lockpick";
				statement = "[player, AGM_Interaction_Target, 'startLockpick'] call AGM_VehicleLock_fnc_lockpick";
				showDisabled = 0;
				priority = 0.1;
			};
		};
	};
	class Air;
	class Helicopter: Air {
		class AGM_Actions {
			class AGM_unlockVehicle {
				displayName = "$STR_AGM_Vehicle_Action_UnLock";
				distance = 4;
				condition = "([player, AGM_Interaction_Target] call AGM_VehicleLock_fnc_hasKeyForVehicle) && ((locked AGM_Interaction_Target) in [2, 3])";
				statement = "[AGM_Interaction_Target, false] call AGM_VehicleLock_fnc_setVehicleLock";
				showDisabled = 1;
				priority = 0.3;
				icon = "\AGM_vehicleLock\ui\key_menuIcon_ca.paa";
			};
			class AGM_lockVehicle {
				displayName = "$STR_AGM_Vehicle_Action_Lock";
				distance = 4;
				condition = "([player, AGM_Interaction_Target] call AGM_VehicleLock_fnc_hasKeyForVehicle) && ((locked AGM_Interaction_Target) in [0, 1])";
				statement = "[AGM_Interaction_Target, true] call AGM_VehicleLock_fnc_setVehicleLock";
				showDisabled = 1;
				priority = 0.2;
				icon = "\AGM_vehicleLock\ui\key_menuIcon_ca.paa";
			};
			class AGM_lockpickVehicle {
				displayName = "$STR_AGM_Vehicle_Action_Lockpick";
				distance = 4;
				condition = "[player, AGM_Interaction_Target, 'canLockpick'] call AGM_VehicleLock_fnc_lockpick";
				statement = "[player, AGM_Interaction_Target, 'startLockpick'] call AGM_VehicleLock_fnc_lockpick";
				showDisabled = 0;
				priority = 0.1;
			};
		};
	};
};
=======
class CfgPatches{
  class AGM_VehicleLock {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.6;
    requiredAddons[] = {"AGM_Core","AGM_Interaction"};

    version = "0.99";
    versionStr = "0.99";
    versionAr[] = {0,99,0};
    author[] = {"PabstMirror"};
    authorUrl = "bourbonwarfare.com";
  };
};

class AGM_Parameters
{
  AGM_VEHICLELOCK_defaultLockpickStrength = 10;
};

class CfgFunctions {
  class AGM_VehicleLock {
    class AGM_VehicleLock {
      file = "AGM_vehicleLock\functions";
      class hasKeyForVehicle;
      class getVehiclesKeyName;
      class lockpick;
      class setVehicleLock;
      class moduleInit;
      class moduleSync;
    };
  };
};

class CfgVehicles {
  class Logic;
  class Module_F: Logic {
    class ArgumentsBaseUnits {};
    class {};
  };
  class AGM_VehicleLock_ModuleSetup: Module_F {
    author = "Pabst Mirror";
    category = "AGM";
    displayName = "Vehicle Lock Setup";
    function = "AGM_VehicleLock_fnc_moduleInit";
    scope = 2;
    isGlobal = 1;
    // icon = "\AGM_Explosives\UI\IconExplosives_ca.paa"; //todo
    functionPriority = 0;
    class Arguments
    {
      class InitType {
        displayName = "Automatic Key Setup"; // Argument label
        description = "[side: every side's vehicles use the same key][unique: different keys for every vehicle]"; // Tooltip description
        typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
        class values {
          class Side    {name = "Side Keys";    value = 0;   default = 1;};
          class Unique  {name = "Unique Keys";  value = 1;};
        };
      };
      class SetLockState {
        displayName = "Set Lock State"; // Argument label
        description = "Set lock state for all vehicles on map"; // Tooltip description
        typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
        class values
        {
          class None    {name = "As Is";    value = 0; default = 1;};
          class Side    {name = "Locked";   value = 1;};
          class Unique  {name = "Unlocked"; value = 2;};
        };
      };
      class LockpickStrength {
        displayName = "Global Lockpick Strength";
        description = "Global Time to lockpick (in seconds). Default: 10";
        typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
        defaultValue = "10"; // Default text filled in the input box
      };
      class KeysInInventory {
        displayName = "Spare Keys In Car";
        description = "Number of spare keys to put in vehicles Default: 0";
        typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
        defaultValue = "0"; // Default text filled in the input box
      };
    };
    class ModuleDescription: ModuleDescription {
      description = "Can setup vehicle keys automaticly"; // Short description, will be formatted as structured text
    };
  };

  class AGM_VehicleLock_ModuleSyncedAssign: Module_F {
    author = "Pabst Mirror";
    category = "AGM";
    displayName = "Vehicle Lock Sync";
    function = "AGM_VehicleLock_fnc_moduleSync";
    scope = 2;
    isGlobal = 1;
    // icon = "\AGM_Explosives\UI\IconExplosives_ca.paa"; //todo
    functionPriority = 100;

    class Arguments {};
    class ModuleDescription: ModuleDescription {
      description = "Sync with vehicles and players, gives player's keys to each synced vehicle"; // Short description, will be formatted as structured text
      sync[] = {"AnyPlayer", "AnyVehicle"};
    };
  };


  class LandVehicle;
  class Car: LandVehicle {
    class AGM_Actions {
      class AGM_unlockVehicle {
        displayName = "$STR_AGM_VehicleUnLock";
        distance = 4;
        condition = "([player, AGM_Interaction_Target] call AGM_VehicleLock_fnc_hasKeyForVehicle) && ((locked AGM_Interaction_Target) in [2, 3])";
        statement = "[AGM_Interaction_Target, false] call AGM_VehicleLock_fnc_setVehicleLock";
        showDisabled = 1;
        priority = 0.3;
        icon = "\AGM_vehicleLock\ui\key_menuIcon_ca.paa";
        // hotkey = "V";
      };
      class AGM_lockVehicle {
        displayName = "$STR_AGM_VehicleLock";
        distance = 4;
        condition = "([player, AGM_Interaction_Target] call AGM_VehicleLock_fnc_hasKeyForVehicle) && ((locked AGM_Interaction_Target) in [0, 1])";
        statement = "[AGM_Interaction_Target, true] call AGM_VehicleLock_fnc_setVehicleLock";
        showDisabled = 1;
        priority = 0.2;
        icon = "\AGM_vehicleLock\ui\key_menuIcon_ca.paa";
        // hotkey = "V";
      };
      class AGM_lockpickVehicle {
        displayName = "$STR_AGM_VehicleLockpick";
        distance = 4;
        condition = "[player, AGM_Interaction_Target, 'canLockpick'] call AGM_VehicleLock_fnc_lockpick";
        statement = "[player, AGM_Interaction_Target, 'startLockpick'] call AGM_VehicleLock_fnc_lockpick";
        showDisabled = 0;
        priority = 0.1;
      };
    };
  };
  class Tank: LandVehicle {
    class AGM_Actions {
      class AGM_unlockVehicle {
        displayName = "$STR_AGM_VehicleUnLock";
        distance = 4;
        condition = "([player, AGM_Interaction_Target] call AGM_VehicleLock_fnc_hasKeyForVehicle) && ((locked AGM_Interaction_Target) in [2, 3])";
        statement = "[AGM_Interaction_Target, false] call AGM_VehicleLock_fnc_setVehicleLock";
        showDisabled = 1;
        priority = 0.3;
        icon = "\AGM_vehicleLock\ui\key_menuIcon_ca.paa";
        // hotkey = "V";
      };
      class AGM_lockVehicle {
        displayName = "$STR_AGM_VehicleLock";
        distance = 4;
        condition = "([player, AGM_Interaction_Target] call AGM_VehicleLock_fnc_hasKeyForVehicle) && ((locked AGM_Interaction_Target) in [0, 1])";
        statement = "[AGM_Interaction_Target, true] call AGM_VehicleLock_fnc_setVehicleLock";
        showDisabled = 1;
        priority = 0.2;
        icon = "\AGM_vehicleLock\ui\key_menuIcon_ca.paa";
        // hotkey = "V";
      };
      class AGM_lockpickVehicle {
        displayName = "$STR_AGM_VehicleLockpick";
        distance = 4;
        condition = "[player, AGM_Interaction_Target, 'canLockpick'] call AGM_VehicleLock_fnc_lockpick";
        statement = "[player, AGM_Interaction_Target, 'startLockpick'] call AGM_VehicleLock_fnc_lockpick";
        showDisabled = 0;
        priority = 0.1;
      };
    };
  };

  class Air;
  class Helicopter: Air {
    class AGM_Actions {
      class AGM_unlockVehicle {
        displayName = "$STR_AGM_VehicleUnLock";
        distance = 4;
        condition = "([player, AGM_Interaction_Target] call AGM_VehicleLock_fnc_hasKeyForVehicle) && ((locked AGM_Interaction_Target) in [2, 3])";
        statement = "[AGM_Interaction_Target, false] call AGM_VehicleLock_fnc_setVehicleLock";
        showDisabled = 1;
        priority = 0.3;
        icon = "\AGM_vehicleLock\ui\key_menuIcon_ca.paa";
        // hotkey = "V";
      };
      class AGM_lockVehicle {
        displayName = "$STR_AGM_VehicleLock";
        distance = 4;
        condition = "([player, AGM_Interaction_Target] call AGM_VehicleLock_fnc_hasKeyForVehicle) && ((locked AGM_Interaction_Target) in [0, 1])";
        statement = "[AGM_Interaction_Target, true] call AGM_VehicleLock_fnc_setVehicleLock";
        showDisabled = 1;
        priority = 0.2;
        icon = "\AGM_vehicleLock\ui\key_menuIcon_ca.paa";
        // hotkey = "V";
      };
      class AGM_lockpickVehicle {
        displayName = "$STR_AGM_VehicleLockpick";
        distance = 4;
        condition = "[player, AGM_Interaction_Target, 'canLockpick'] call AGM_VehicleLock_fnc_lockpick";
        statement = "[player, AGM_Interaction_Target, 'startLockpick'] call AGM_VehicleLock_fnc_lockpick";
        showDisabled = 0;
        priority = 0.1;
      };
    };
  };
};


class CfgWeapons {
  class InventoryItem_Base_F;
  class ItemCore;

  class AGM_item_key_lockpick: ItemCore {
    author = "Pabst Mirror";
    displayName = "Lockpick";
    descriptionShort = "A lockpick set, can open most vehicles";

    model = "\A3\weapons_F\ammo\mag_univ.p3d";
    picture = "\AGM_vehicleLock\ui\lockpick.paa";
    scope = 2;
    class ItemInfo {
      mass = 0.1;
      type = 201;
    };
  };

  class AGM_item_key_master: ItemCore {
    author = "Pabst Mirror";
    displayName = "Vehicle Key: Master";
    descriptionShort = "Master Key will open any lock, no matter what!";
    model = "\A3\weapons_F\ammo\mag_univ.p3d";
    picture = "\AGM_vehicleLock\ui\keyBlack.paa";
    scope = 2;
    class ItemInfo {
      mass = 0.1;
      type = 201;
    };
  };

  class AGM_item_key_west: AGM_item_key_master {
    displayName = "Vehicle Key: West";
    descriptionShort = "Key will open any WEST vehicle<br/>As long as it doesn't have a custom lock set";
    picture = "\AGM_vehicleLock\ui\keyBlue.paa";
  };
  class AGM_item_key_east: AGM_item_key_master {
    displayName = "Vehicle Key: East";
    descriptionShort = "Key will open any EAST vehicle<br/>As long as it doesn't have a custom lock set";
    picture = "\AGM_vehicleLock\ui\keyRed.paa";
  };
  class AGM_item_key_indp: AGM_item_key_master {
    displayName = "Vehicle Key: Independent";
    descriptionShort = "Key will open any INDP vehicle<br/>As long as it doesn't have a custom lock set";
    picture = "\AGM_vehicleLock\ui\keyPurple.paa";
  };
  class AGM_item_key_civ: AGM_item_key_master {
    displayName = "Vehicle Key: Civilian";
    descriptionShort = "Key will open any CIV vehicle<br/>As long as it doesn't have a custom lock set";
    picture = "\AGM_vehicleLock\ui\keyPurple.paa";
  };

  #define CUSTOM_KEY(KEYNUMBER) class AGM_item_key_##KEYNUMBER : AGM_item_key_master \
    { \
      displayName = Vehicle Key: KEYNUMBER; \
      descriptionShort = Custom Key for a specific vehicle lock<br/>This will open the vehicle that has AGM_vehicleLock_type set to KEYNUMBER ; \
      picture = "\AGM_vehicleLock\ui\keyBlack.paa"; \
      scope = 1; \
    };

  CUSTOM_KEY(0)
  CUSTOM_KEY(1)
  CUSTOM_KEY(2)
  CUSTOM_KEY(3)
  CUSTOM_KEY(4)
  CUSTOM_KEY(5)
  CUSTOM_KEY(6)
  CUSTOM_KEY(7)
  CUSTOM_KEY(8)
  CUSTOM_KEY(9)
  CUSTOM_KEY(10)
  CUSTOM_KEY(11)
  CUSTOM_KEY(12)
  CUSTOM_KEY(13)
  CUSTOM_KEY(14)
  CUSTOM_KEY(15)
  CUSTOM_KEY(16)
  CUSTOM_KEY(17)
  CUSTOM_KEY(18)
  CUSTOM_KEY(19)
  CUSTOM_KEY(20)
  CUSTOM_KEY(21)
  CUSTOM_KEY(22)
  CUSTOM_KEY(23)
  CUSTOM_KEY(24)
  CUSTOM_KEY(25)
  CUSTOM_KEY(26)
  CUSTOM_KEY(27)
  CUSTOM_KEY(28)
  CUSTOM_KEY(29)
  CUSTOM_KEY(30)
  CUSTOM_KEY(31)
  CUSTOM_KEY(32)
  CUSTOM_KEY(33)
  CUSTOM_KEY(34)
  CUSTOM_KEY(35)
  CUSTOM_KEY(36)
  CUSTOM_KEY(37)
  CUSTOM_KEY(38)
  CUSTOM_KEY(39)
  CUSTOM_KEY(40)
  CUSTOM_KEY(41)
  CUSTOM_KEY(42)
  CUSTOM_KEY(43)
  CUSTOM_KEY(44)
  CUSTOM_KEY(45)
  CUSTOM_KEY(46)
  CUSTOM_KEY(47)
  CUSTOM_KEY(48)
  CUSTOM_KEY(49)
};
>>>>>>> origin/master
