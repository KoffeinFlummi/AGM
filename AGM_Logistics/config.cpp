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
    clientInit = "call compile preprocessFileLineNumbers '\AGM_Logistics\clientInit.sqf'";
  };
};


class CfgFunctions {
	class AGM_Logistics {
		class AGM_Logistics {
			file = "\AGM_logistics\functions";
			
			class canLoadItem;
			class canLoadMagazine;
			class hasLoadedItems;
			class getLoadableMagazines;
			class getLoadPoints;
			class getWeaponsOfMagazine;
			class loadItem;
			class loadItemCallback;
			class loadMagazine;
			class loadMagazineCallback;
			class loadMagazineRemote;
			
			class openLoadUI;
			class openMagazineMenu;
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
		AGM_Vehicle_Cargo = 2;
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
				condition = "count ([player, AGM_Interaction_Target] call AGM_Logistics_fnc_getLoadableMagazines) > 0";
				statement = "[AGM_Interaction_Target] call AGM_Logistics_fnc_openMagazineMenu;"
				showDisabled = 1;
				priority = 1;
			};
		};
	};
};

// Handle vehicle magazines
class CfgMagazines {
	class CA_LauncherMagazine;
	class Titan_AA : CA_LauncherMagazine {
		AGM_LoadTime = 10;
		AGM_MagazineReloadType = 1;
	};

	class Titan_AP : Titan_AA {
	};

	class Titan_AT : Titan_AA {
	};
};

class CfgWeapons {
	class MissileLauncher;
	class missiles_titan : MissileLauncher {
		AGM_Magazines[] = {"Titan_AA"};
	};
};