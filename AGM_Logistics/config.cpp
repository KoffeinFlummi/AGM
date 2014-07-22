class CfgPatches {
  class AGM_Logistics {
    units[] = {"AGM_Repair_Track", "AGM_Repair_Wheel"};
    weapons[] = {"AGM_UAVBattery"};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"commy2", "KoffeinFlummi", "Garth 'L-H' de Wet", "marc_book", "gpgpgpgp"};
    authorUrl = "https://github.com/commy2/";
  };
};

/*
	Drag, Logistics: by Garth 'L-H' de Wet
	UAVs, Repair: by marc_book
	Wirecutter: by gpgpgpgp
	StaticWeapons: by commy2
	Something: by KoffeinFlummi
*/

class CfgFunctions {
	class AGM_Logistics {
		class AGM_Logistics {
			file = "\AGM_Logistics\functions";
			class canLoadItem;
			class canLoadMagazine;
			class hasLoadedItems;
			class getLoadableMagazines;
			class getLoadPoints;
			class getWeaponsOfMagazine;
			class loadItem;
			class loadItemAbort;
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
	class AGM_Drag {
		class AGM_Drag {
			file="\AGM_Logistics\functions\Drag";
			class initialise{postInit = 1;};
			class makeDraggable;
			class makeUndraggable;
			class dragObject;
			class releaseObject;
			class isDraggingObject;
			class handleScrollWheel;
			class isDraggable;
			class GetWeight;
		};
	};
	class AGM_Repair {
		class AGM_Repair {
			file = "\AGM_Logistics\functions\Repair";
			class canRepair;
			class canRepairWheel;
			class checkVehicle;
			class getHitPointName;
			class openSelectWheelUI;
			class repair;
			class repairAbort;
			class repairCallback;
			/*class repairTrack;
			class repairWheel;*/
		};
	};
	class AGM_StaticWeapons {
		class AGM_StaticWeapons {
			file = "\AGM_Logistics\functions\StaticWeapons";
			class canGetIn;
			class canRotate;
			class getIn;
			class rotate;
		};
	};
	class AGM_UAVs {
		class AGM_UAVs {
			file = "\AGM_Logistics\functions\UAVs";
			class refuel;
			class refuelCallback;
		};
	};
	class AGM_Wirecutter {
		class AGM_Wirecutter {
			file = "\AGM_Logistics\functions\Wirecutter";
			class cutDownFence;
			class cutDownFenceAbort;
			class cutDownFenceCallback;
		};
	};
};

class Extended_PostInit_EventHandlers {
  class AGM_Logistics {
    serverInit = "call compile preprocessFileLineNumbers '\AGM_Logistics\serverInit.sqf'";
  };
};

// Drop carried item if unit enters a vehicle
class Extended_GetIn_EventHandlers {
  class AllVehicles {
    class AGM_GetIn {
      clientGetIn = "(_this select 2) call AGM_Drag_fnc_releaseObject";
    };
  };
};

class AGM_Core_canInteractConditions {
  class AGM_Drag_isNotDragging {
    condition = "!(player getVariable ['AGM_isDragging', false])";
  };
};

class CfgAddons {
	class AGM_Repair_Items {
		list[] = {"AGM_Repair_Track", "AGM_Repair_Wheel"};
	};
};

class CfgSounds {
	class AGM_Wirecutter_sound {
		name = "AGM_wirecutter_sound";
		sound[] = {"AGM_Logistics\sound\wire_cut.ogg", "db-0", 1};
		titles[] = {};
	};
	class AGM_Wirecutter_sound_long {
		name = "AGM_wirecutter_sound_long";
		sound[] = {"AGM_Logistics\sound\wire_cut_long.ogg", "db-0", 1};
		titles[] = {};
	};
};

class CfgVehicleClasses {
	class AGM_Repair_Items {
		displayName = "AGM";
	};
};

#include <Macros.hpp>

class CfgVehicles {
	class Man;
	class CAManBase: Man {
		class AGM_SelfActions {
			// Sometimes it is not possible to target an object that you are dragging
			// particularly noticeable on Stratis on the dock wall.
			// Adding a self option to release will fix this.
			class AGM_ReleaseItemSelf {
				displayName = "$STR_AGM_Drag_EndDrag";
				condition = "(player call AGM_Drag_fnc_isDraggingObject) && {['AGM_isDragging'] call AGM_Interaction_fnc_canInteract}";
				statement = "player call AGM_Drag_fnc_releaseObject;";
				exceptions[] = {"AGM_Drag_isNotDragging"};
				showDisabled = 0;
				priority = 2.1;
			};
		};
	};

	//Vehicles
	class Truck_01_base_F;
	class B_Truck_01_transport_F: Truck_01_base_F {
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
	class LandVehicle: AllVehicles {
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
	class Car: LandVehicle {
		class AGM_Actions;
	};
	class Tank: LandVehicle {
		class AGM_Actions: AGM_Actions {
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

	// Repair wheeled vehicles
	class Car_F: Car {
		class AGM_Actions: AGM_Actions {
			class AGM_Repair {
				displayName = "$STR_AGM_Repair";
				distance = 4;
				condition = "alive AGM_Interaction_Target";
				statement = "'AGM_Repair' call AGM_Interaction_fnc_openMenu;";
				showDisabled = 1;
				priority = 1;

				class AGM_Repair_checkVehicle {
					displayName = "$STR_AGM_Repair_checkVehicle";
					distance = 4;
					condition = "alive AGM_Interaction_Target";
					statement = "[AGM_Interaction_Target] call AGM_Repair_fnc_checkVehicle";
					showDisabled = 1;
					priority = 1;
				};
				class AGM_Repair_Wheels {
					displayName = "$STR_AGM_Repair_Wheels";
					distance = 4;
					condition = "[AGM_Interaction_Target, ['HitLFWheel', 'HitLBWheel', 'HitLMWheel', 'HitLF2Wheel', 'HitRFWheel', 'HitRBWheel', 'HitRMWheel', 'HitRF2Wheel']] call AGM_Repair_fnc_canRepairWheel";
					statement = "[AGM_Interaction_Target, ['HitLFWheel', 'HitLBWheel', 'HitLMWheel', 'HitLF2Wheel', 'HitRFWheel', 'HitRBWheel', 'HitRMWheel', 'HitRF2Wheel']] call AGM_Repair_fnc_openSelectWheelUI";
					showDisabled = 0;
					priority = 0.9;
				};
				class AGM_Repair_Body {
					displayName = "$STR_AGM_Repair_HitHull";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitHull'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitHull'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.5;
				};
				class AGM_Repair_Engine {
					displayName = "$STR_AGM_Repair_HitEngine";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitEngine'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitEngine'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.4;
				};
				class AGM_Repair_Fuel {
					displayName = "$STR_AGM_Repair_HitFuel";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitFuel'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitFuel'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.3;
				};
				class AGM_Repair_Gun {
					displayName = "$STR_AGM_Repair_HitGun";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitGun'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitGun'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.2;
				};
				class AGM_Repair_Turret {
					displayName = "$STR_AGM_Repair_HitTurret";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitTurret'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitTurret'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.1;
				};
				class AGM_OpenUIDummy {
					displayName = "";
					condition = "false";
					statement = "";
					showDisabled = 1;
					priority = -9;
				};
			};
		};
	};

	// Repair tracked vehicles
	class Tank_F: Tank {
		class AGM_Actions: AGM_Actions {
			class AGM_Repair {
				displayName = "$STR_AGM_Repair";
				distance = 4;
				condition = "alive AGM_Interaction_Target";
				statement = "'AGM_Repair' call AGM_Interaction_fnc_openMenu;";
				showDisabled = 1;
				priority = 1;

				class AGM_Repair_checkVehicle {
					displayName = "$STR_AGM_Repair_checkVehicle";
					distance = 4;
					condition = "alive AGM_Interaction_Target";
					statement = "[AGM_Interaction_Target] call AGM_Repair_fnc_checkVehicle";
					showDisabled = 1;
					priority = 1;
				};
				class AGM_Repair_Body {
					displayName = "$STR_AGM_Repair_HitHull";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitHull'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitHull'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.5;
				};
				class AGM_Repair_LTrack {
					displayName = "$STR_AGM_Repair_HitLTrack";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitLTrack'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitLTrack'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.42;
				};
				class AGM_Repair_RTrack {
					displayName = "$STR_AGM_Repair_HitRTrack";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitRTrack'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitRTrack'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.41;
				};
				class AGM_Repair_Engine {
					displayName = "$STR_AGM_Repair_HitEngine";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitEngine'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitEngine'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.4;
				};
				class AGM_Repair_Fuel {
					displayName = "$STR_AGM_Repair_HitFuel";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitFuel'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitFuel'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.3;
				};
				class AGM_Repair_Gun {
					displayName = "$STR_AGM_Repair_HitGun";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitGun'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitGun'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.2;
				};
				class AGM_Repair_Turret {
					displayName = "$STR_AGM_Repair_HitTurret";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitTurret'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitTurret'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.1;
				};
				class AGM_OpenUIDummy {
					displayName = "";
					condition = "false";
					statement = "";
					showDisabled = 1;
					priority = -9;
				};
			};
		};
	};

	// Repair helicopters
	class Air;
	class Helicopter: Air {
		class AGM_Actions {
			class AGM_Repair {
				displayName = "$STR_AGM_Repair";
				distance = 4;
				condition = "alive AGM_Interaction_Target";
				statement = "'AGM_Repair' call AGM_Interaction_fnc_openMenu;";
				showDisabled = 1;
				priority = 1;

				class AGM_Repair_checkVehicle {
					displayName = "$STR_AGM_Repair_checkVehicle";
					distance = 4;
					condition = "alive AGM_Interaction_Target";
					statement = "[AGM_Interaction_Target] call AGM_Repair_fnc_checkVehicle";
					showDisabled = 1;
					priority = 1;
				};
				class AGM_Repair_Body {
					displayName = "$STR_AGM_Repair_HitHull";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitHull'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitHull'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.5;
				};
				class AGM_Repair_Engine {
					displayName = "$STR_AGM_Repair_HitEngine";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitEngine'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitEngine'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.4;
				};
				class AGM_Repair_Fuel {
					displayName = "$STR_AGM_Repair_HitFuel";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitFuel'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitFuel'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.3;
				};
				class AGM_Repair_Avionics {
					displayName = "$STR_AGM_Repair_HitAvionics";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitAvionics'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitAvionics'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.2;
				};
				class AGM_Repair_HRotor {
					displayName = "$STR_AGM_Repair_HitHRotor";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitHRotor'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitHRotor'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.15;
				};
				class AGM_Repair_VRotor {
					displayName = "$STR_AGM_Repair_HitVRotor";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitVRotor'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitVRotor'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.1;
				};
				class AGM_OpenUIDummy {
					displayName = "";
					condition = "false";
					statement = "";
					showDisabled = 1;
					priority = -9;
				};
			};
		};
	};

	// Repair fixed wing aircraft
	class Plane: Air {
		class AGM_Actions {
			class AGM_Repair {
				displayName = "$STR_AGM_Repair";
				distance = 4;
				condition = "alive AGM_Interaction_Target";
				statement = "'AGM_Repair' call AGM_Interaction_fnc_openMenu;";
				showDisabled = 1;
				priority = 1;

				class AGM_Repair_checkVehicle {
					displayName = "$STR_AGM_Repair_checkVehicle";
					distance = 4;
					condition = "alive AGM_Interaction_Target";
					statement = "[AGM_Interaction_Target] call AGM_Repair_fnc_checkVehicle";
					showDisabled = 1;
					priority = 1;
				};
				class AGM_Repair_Body {
					displayName = "$STR_AGM_Repair_HitHull";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitHull'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitHull'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.5;
				};
				/*class AGM_Repair_Engine {
					displayName = "$STR_AGM_Repair_HitEngine";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitEngine'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitEngine'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.4;
				};
				class AGM_Repair_Fuel {
					displayName = "$STR_AGM_Repair_HitFuel";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitFuel'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitFuel'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.3;
				};
				class AGM_Repair_Avionics {
					displayName = "$STR_AGM_Repair_HitAvionics";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitAvionics'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitAvionics'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.2;
				};*/
				class AGM_OpenUIDummy {
					displayName = "";
					condition = "false";
					statement = "";
					showDisabled = 1;
					priority = -9;
				};
			};
		};
	};

	// Static weapons
	class StaticWeapon: LandVehicle {
		class AGM_Actions {
			MACRO_DRAGABLE
			MACRO_GETIN_STATIC
		};
	};

	class StaticMortar;
	class Mortar_01_base_F: StaticMortar {
		class AGM_Actions {
			MACRO_DRAGABLE
			MACRO_GETIN_STATIC
		};
	};

	// Ammo boxes
	class ThingX;
	class ReammoBox_F: ThingX {
		AGM_Size = 2; // 1 = small, 2 = large
		AGM_CarryPosition[] = {0,1,1}; // offset from player to attach object.
		class AGM_Actions {
			MACRO_LOADABLE
		};
	};

	class EAST_Box_Base: ReammoBox_F {
		class AGM_Actions {
			MACRO_DRAGABLE
		};
	};
	class IND_Box_Base: ReammoBox_F {
		class AGM_Actions {
			MACRO_DRAGABLE
		};
	};
	class NATO_Box_Base: ReammoBox_F {
		class AGM_Actions {
			MACRO_DRAGABLE
		};
	};
	// Remove Larger crate dragging support.
	// Would be better to allow some sort of joint push/drag functionality
	// Requiring 2 units to access the larger crates and attaching them together (a crappy method of doing it)
	// in order to move the bigger ones. Currently simply remove support.
	// I believe these crates are currently broken (hitbox doesn't work or something) in 1.22 (2014-07-04)
	class Box_East_AmmoVeh_F: EAST_Box_Base {
		class AGM_Actions {
			MACRO_NOT_DRAGABLE
		};
	};
	class Box_NATO_AmmoVeh_F: NATO_Box_Base {
		class AGM_Actions {
			MACRO_NOT_DRAGABLE
		};
	};
	class Box_IND_AmmoVeh_F: IND_Box_Base {
		class AGM_Actions {
			MACRO_NOT_DRAGABLE
		};
	};

	class Helicopter_Base_F;
	class UAV_01_base_F: Helicopter_Base_F {
		class AGM_Actions {
			MACRO_DRAGABLE
			class AGM_Refuel {
				displayName = "$STR_AGM_UAVs_Recharge";
				distance = 4;
				condition = "'AGM_UAVBattery' in items player && {fuel cursorTarget < 1}";
				statement = "[cursorTarget, player] call AGM_UAVs_fnc_refuel";
				showDisabled = 1;
				priority = -2.5;
			};
		};
	};

	// New Items
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
				condition = "!isNil {player getVariable 'AGM_Logisitcs_carriedItem'}";
				statement = "0 spawn AGM_Logistics_dropJerryCan";
				showDisabled = 0;
				priority = 1.5;
			};
		};
	};

	class AGM_Repair_Track: ThingX {
		AGM_Size = 1; // 1 = small, 2 = large
		AGM_CarryPosition[] = {0,1,1}; // offset from player to attach object.
		scope = 2;
		model = "\AGM_Logistics\track.p3d";
		icon = "iconObject_circle";
		displayName = "Track";
		mapSize = 0.7;
		accuracy = 0.2;
		vehicleClass = "AGM_Repair_Items";
		destrType = "DesturctNo";

		class AGM_Actions {
			MACRO_DRAGABLE
			MACRO_LOADABLE
		};
	};

	class AGM_Repair_Wheel: ThingX {
		AGM_Size = 1; // 1 = small, 2 = large
		AGM_CarryPosition[] = {0,1,1}; // offset from player to attach object.
		scope = 2;
		model = "\AGM_Logistics\wheel.p3d";
		icon = "iconObject_circle";
		displayName = "Wheel";
		mapSize = 0.7;
		accuracy = 0.2;
		vehicleClass = "AGM_Repair_Items";
		destrType = "DesturctNo";

		class AGM_Actions {
			MACRO_DRAGABLE
			MACRO_LOADABLE
		};
	};

	// Misc box content
	class Box_NATO_Support_F;
	class AGM_Box_Misc: Box_NATO_Support_F {
		class TransportItems {
			class _xx_AGM_UAVBattery {
				count = 24;
				name = "AGM_UAVBattery";
			};
		};
	};

	// wire cutter
	class Wall_F;
	class Land_Net_Fence_4m_F: Wall_F {
		class AGM_Actions {
			MACRO_CUTWIRE
		};
	};
	class Land_Net_Fence_8m_F: Wall_F {
		class AGM_Actions {
			MACRO_CUTWIRE_LONG
		};
	};
	class Land_Net_FenceD_8m_F: Wall_F {
		class AGM_Actions {
			MACRO_CUTWIRE
		};
	};
	class Land_New_WiredFence_5m_F: Wall_F {
		class AGM_Actions {
			MACRO_CUTWIRE
		};
	};
	class Land_New_WiredFence_10m_Dam_F: Wall_F {
		class AGM_Actions {
			MACRO_CUTWIRE
		};
	};
	class Land_New_WiredFence_10m_F: Wall_F {
		class AGM_Actions {
			MACRO_CUTWIRE_LONG
		};
	};
	class Land_Pipe_fence_4m_F: Wall_F {
		class AGM_Actions {
			MACRO_CUTWIRE
		};
	};
	class Land_Pipe_fence_4mNoLC_F: Wall_F {
		class AGM_Actions {
			MACRO_CUTWIRE
		};
	};
	class Land_SportGround_fence_F: Wall_F {
		class AGM_Actions {
			MACRO_CUTWIRE
		};
	};
	class Land_Wired_Fence_4m_F: Wall_F {
		class AGM_Actions {
			MACRO_CUTWIRE
		};
	};
	class Land_Wired_Fence_4mD_F: Wall_F {
		class AGM_Actions {
			MACRO_CUTWIRE
		};
	};
	class Land_Wired_Fence_8m_F: Wall_F {
		class AGM_Actions {
			MACRO_CUTWIRE_LONG
		};
	};
	class Land_Wired_Fence_8mD_F: Wall_F {
		class AGM_Actions {
			MACRO_CUTWIRE
		};
	};

	class NonStrategic;
	class Land_Razorwire_F: NonStrategic {
		class AGM_Actions {
			MACRO_CUTWIRE
		};
	};
};

// Handle vehicle magazines
class CfgMagazines {
	class CA_LauncherMagazine;
	class Titan_AA: CA_LauncherMagazine {
		AGM_LoadTime = 10;
		AGM_MagazineReloadType = 1;
	};

	class Titan_AP: Titan_AA {
	};

	class Titan_AT: Titan_AA {
	};
};

class CfgWeapons {
	class MissileLauncher;
	class missiles_titan: MissileLauncher {
		AGM_Magazines[] = {"Titan_AA"};
	};

	class ItemCore;
	class InventoryItem_Base_F;

	class ToolKit: ItemCore {
		class ItemInfo: InventoryItem_Base_F {
			mass = 80;
			type = 401;
		};
	};

	class AGM_UAVBattery: ItemCore {
		scope = 2;
		displayName = "$STR_AGM_UAVs_Battery_Name";
		descriptionShort = "$STR_AGM_UAVs_Battery_Description";
		model = "\A3\weapons_F\ammo\mag_univ.p3d";
		picture = "\AGM_Logistics\ui\AGM_battery.paa";
		class ItemInfo: InventoryItem_Base_F {
			mass = 20;
			type = 401;
		};
	};
};

#include <DiagnoseDialog.hpp>
