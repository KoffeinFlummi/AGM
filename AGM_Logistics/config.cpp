class CfgPatches {
  class AGM_Logistics {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Logistics {
    serverInit = "call compile preprocessFileLineNumbers '\AGM_Logistics\serverInit.sqf'";
  };
};


class CfgFunctions {
	class AGM_Logistics {
		class AGM_Logistics {
			file = "\AGM_logistics\functions";
			
			class canLoadItem;
			class hasLoadedItems;
			class getLoadPoints;
			class loadItem;
			class loadItemCallback;
			
			class openLoadUI;
			class openUnloadUI;
			
			class remainingSpace;
			
			class unloadItem;
			class unloadItemCallback;
		};
	};
};

/*class CfgFunctions {
  class AGM_Logistics {
    class AGM_Logistics {
      file = "\AGM_logistics\functions";
      class canLoadMagazine;
      class reloadMagazine;
      class getLoadableMagazines;
      class applyMagazineNames;
      class getWeaponsOfMagazine;
    };
  };
};*/

#define MACRO_LOADABLE class AGM_loadItem { \
				displayName = "Load Item"; \
				distance = 4; \
				condition = "[AGM_Interaction_Target] call AGM_Logistics_fnc_canLoadItem"; \
				statement = "[AGM_Interaction_Target, AGM_Logistics_targetVehicle] call AGM_Logistics_fnc_openLoadUI;"; \
				showDisabled = 1; \
				priority = 2.26; \
			};

class CfgVehicles {
	//Jerry Can
	class Items_base_F;
	class Land_CanisterFuel_F: Items_base_F {
		class AGM_Actions {
			MACRO_LOADABLE
			class AGM_CarryJerryCan {
				displayName = "Carry jerry can";
				distance = 4;
				condition = "call AGM_Interaction_fnc_canInteract";
				statement = "[AGM_Interaction_Target] spawn AGM_Logistics_carryJerryCan";
				showDisabled = 1;
				priority = 1.5;
			};
			class AGM_DropJerryCan {
				displayName = "Drop jerry can";
				distance = 4;
				condition = "!isNil {player getVariable 'AGM_Logisitcs_carriedItem'} && {call AGM_Interaction_fnc_canInteract}";
				statement = "0 spawn AGM_Logistics_dropJerryCan";
				showDisabled = 0;
				priority = 1.5;
			};
		};
	};

	//Crates
	class thingX;
	class ReammoBox_F: thingX {
		AGM_Size = 2; // 1 = small, 2 = large
		AGM_CarryPosition[] = {0,1,1}; // offset from player to attach object.
		class AGM_Actions {
			MACRO_LOADABLE
		};
	};

  //Men
  /*class Man;
  class CAManBase: Man {
    class AGM_SelfActions {
    };
  };*/

  //Vehicles
	class Truck_01_base_F;
	class B_Truck_01_transport_F:Truck_01_base_F {
		class AGM_Load {
			class MidLoad {
				displayName = "Middle of truck";
				loadSize = 2; // Size of object, 1 = small, 2 = large
				LoadPosition[]={0.05,-4,-0.6}; // Offset when attaching.
				memoryPoint = "exhaustEnd"; // the memory position on the vehicle to use for the attaching and offset.
			};
			UnLoadPosition[]={0,-6,-1.0}; // Position objects will be unloaded to. modelToWorld offset.
		};
	};
	class AllVehicles;
	class LandVehicle:AllVehicles {
		AGM_Vehicle_Cargo = 4;
		class AGM_Actions {
			class AGM_unloadBox {
				displayName = "Unload >>";
				distance = 8;
				condition = "[AGM_Interaction_Target] call AGM_Logistics_fnc_hasLoadedItems";
				statement = "[AGM_Interaction_Target] call AGM_Logistics_fnc_openUnloadUI;";
				showDisabled = 1;
				priority = 2.25;
			};
		};
	};
  class Tank: LandVehicle {
    class AGM_Actions {
      class AGM_reloadMagazines {
        displayName = "Magazines >>";
        distance = 8;
        condition = "true";
        statement = "AGM_Logistics_loadableMagazines = [cursorTarget] call AGM_Logistics_getLoadableMagazines; AGM_Logistics_loadableMagazines resize 10; 'AGM_reloadMagazines' call AGM_Interaction_fnc_openMenu; [AGM_Logistics_loadableMagazines] call AGM_Logistics_applyMagazineNames";
        showDisabled = 1;
        priority = 1;

        class AGM_reloadMagazine0 {
          displayName = "Magazine 0";
          condition = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 0] call AGM_Logistics_canLoadMagazine";
          statement = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 0] call AGM_Logistics_reloadMagazine";
          showDisabled = 1;
          priority = 1;
        };
        class AGM_reloadMagazine1 {
          displayName = "Magazine 1";
          condition = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 1] call AGM_Logistics_canLoadMagazine";
          statement = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 1] call AGM_Logistics_reloadMagazine";
          showDisabled = 1;
          priority = 0.9;
        };
        class AGM_reloadMagazine2 {
          displayName = "Magazine 2";
          condition = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 2] call AGM_Logistics_canLoadMagazine";
          statement = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 2] call AGM_Logistics_reloadMagazine";
          showDisabled = 1;
          priority = 0.8;
        };
        class AGM_reloadMagazine3 {
          displayName = "Magazine 3";
          condition = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 3] call AGM_Logistics_canLoadMagazine";
          statement = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 3] call AGM_Logistics_reloadMagazine";
          showDisabled = 1;
          priority = 0.7;
        };
        class AGM_reloadMagazine4 {
          displayName = "Magazine 4";
          condition = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 4] call AGM_Logistics_canLoadMagazine";
          statement = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 4] call AGM_Logistics_reloadMagazine";
          showDisabled = 1;
          priority = 0.6;
        };
        class AGM_reloadMagazine5 {
          displayName = "Magazine 5";
          condition = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 5] call AGM_Logistics_canLoadMagazine";
          statement = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 5] call AGM_Logistics_reloadMagazine";
          showDisabled = 1;
          priority = 0.5;
        };
        class AGM_reloadMagazine6 {
          displayName = "Magazine 6";
          condition = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 6] call AGM_Logistics_canLoadMagazine";
          statement = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 6] call AGM_Logistics_reloadMagazine";
          showDisabled = 1;
          priority = 0.4;
        };
        class AGM_reloadMagazine7 {
          displayName = "Magazine 7";
          condition = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 7] call AGM_Logistics_canLoadMagazine";
          statement = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 7] call AGM_Logistics_reloadMagazine";
          showDisabled = 1;
          priority = 0.3;
        };
        class AGM_reloadMagazine8 {
          displayName = "Magazine 8";
          condition = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 8] call AGM_Logistics_canLoadMagazine";
          statement = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 8] call AGM_Logistics_reloadMagazine";
          showDisabled = 1;
          priority = 0.2;
        };
        class AGM_reloadMagazine9 {
          displayName = "Magazine 9";
          condition = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 9] call AGM_Logistics_canLoadMagazine";
          statement = "[AGM_Interaction_Target, AGM_Logistics_loadableMagazines select 9] call AGM_Logistics_reloadMagazine";
          showDisabled = 1;
          priority = 0.1;
        };
      };
    };
  };
};


// Handle vehicle magazines

class CfgMagazines {
  class CA_LauncherMagazine;
  class Titan_AA : CA_LauncherMagazine {
    AGM_MagazineReloadType = 1;
    AGM_Magazines[] = {"4Rnd_Titan_long_missiles"};
  };

  class Titan_AP : Titan_AA {
    AGM_Magazines[] = {};
  };

  class Titan_AT : Titan_AA {
    AGM_Magazines[] = {};
  };
};

class CfgWeapons {
  class MissileLauncher;
  class missiles_titan : MissileLauncher {
    AGM_Magazines[] = {"Titan_AA"};
  };
};
