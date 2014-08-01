class CfgPatches {
  class AGM_Logistics {
    units[] = {"AGM_JerryCan", "AGM_SpareTrack", "AGM_SpareWheel"};
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
	StaticWeapons, Resupply: by commy2
	Something: by KoffeinFlummi
*/

class CfgFunctions {
	class AGM_Logistics {
		class AGM_Logistics {
			file = "\AGM_Logistics\functions";
			class canLoadItem;
			class canLoadItemCarried;
			class canLoadMagazine;
			class hasLoadedItems;
			class initLoadedObject;
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
			class spawnObject;
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
			class isCarryable;
			class isCarryingObject;
			class carryJerrycan;
			class dropJerrycan;
		};
	};
	class AGM_Repair {
		class AGM_Repair {
			file = "\AGM_Logistics\functions\Repair";
			class canRemoveWheel;
			class canRepair;
			class canRepairTrack;
			class canRepairWheel;
			class checkVehicle;
			class checkVehicleCallback;
			class getHitPointName;
			class getNearestRepairer;
			class getNearestTrack;
			class getNearestWheel;
			class openSelectWheelUI;
			class openSelectWheelUI_Salvage;
			class removeWheel;
			class removeWheelAbort;
			class removeWheelCallback;
			class repair;
			class repairAbort;
			class repairCallback;
			class repairTrack;
			class repairTrackAbort;
			class repairTrackCallback;
			class repairWheel;
			class repairWheelAbort;
			class repairWheelCallback;
			class setDamage;
			class setHitPointDamage;
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
	class AGM_Resupply {
		class AGM_Resupply {
			file = "\AGM_Logistics\functions\Resupply";
			class getFuelAmount;
			class getFuelAmountCallback;
			class getFuelAmountCargo;
			class getFuelAmountCargoCallback;
			class getFuelAmountJerrycan;
			class getNearestRefueler;
			class canDrainFuel;
			class canDrainFuelCargo;
			class canRefuel;
			class canRefuelCargo;
			class drainFuel;
			class drainFuelCallback;
			class drainFuelCargo;
			class drainFuelCargoCallback;
			class refuelVehicle;
			class refuelVehicleCallback;
			class refuelVehicleCargo;
			class refuelVehicleCargoCallback;
		};
	};
};

class Extended_PostInit_EventHandlers {
  class AGM_Logistics {
    serverInit = "call compile preprocessFileLineNumbers '\AGM_Logistics\serverInit.sqf'";
  };
};

// Drop carried item if the unit enters a vehicle, dies or assembles or disassembels a weapon
class Extended_GetIn_EventHandlers {
  class AllVehicles {
    class AGM_DropItem {
      clientGetIn = "if (player == _this select 2) then {(_this select 2) call AGM_Drag_fnc_releaseObject}";
    };
  };
};
class Extended_Killed_EventHandlers {
  class CAManBase {
    class AGM_DropItem {
      clientKilled = "if (player == _this select 0) then {(_this select 0) call AGM_Drag_fnc_releaseObject}";
    };
  };
};
class Extended_WeaponAssembled_EventHandlers {
  class CAManBase {
    class AGM_DropItem {
      clientWeaponAssembled = "if (player == _this select 0) then {(_this select 0) call AGM_Drag_fnc_releaseObject}";
    };
  };
};
class Extended_WeaponDisassembled_EventHandlers {
  class CAManBase {
    class AGM_DropItem {
      clientWeaponDisassembled = "if (player == _this select 0) then {(_this select 0) call AGM_Drag_fnc_releaseObject}";
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

#include <Macros.hpp>

class CfgVehicleClasses {
  class AGM_Repair_Items {
    displayName = "AGM";
  };
};

class CfgVehicles {
	class Man;
	class CAManBase: Man {
		class AGM_SelfActions {
			// Sometimes it is not possible to target an object that you are dragging
			// particularly noticeable on Stratis on the dock wall.
			// Adding a self option to release will fix this.
			class AGM_ReleaseItemSelf {
				displayName = "$STR_AGM_Drag_EndDrag";
				condition = "player call AGM_Drag_fnc_isDraggingObject";
				statement = "player call AGM_Drag_fnc_releaseObject";
				exceptions[] = {"AGM_Drag_isNotDragging"};
				showDisabled = 0;
				priority = 2.1;
			};
			MACRO_CHECKFUEL
		};
	};

	class LandVehicle;
	class Car: LandVehicle {
		AGM_Vehicle_Cargo = 4;
		class AGM_Actions {
			MACRO_UNLOAD
			MACRO_REFUEL
		};
	};
	class Tank: LandVehicle {
		AGM_Vehicle_Cargo = 4;
		class AGM_Actions {
			MACRO_UNLOAD
			MACRO_REFUEL
			MACRO_RELOAD_MAGS
		};
	};

	// Repair wheeled vehicles
	class Car_F: Car {
		KEY_WHEEL_4X4
		AGM_fuelCapacity = 60;  // in liter. This is guesswork and should be adjusted for all vehicles individually in the future @todo
		class AGM_Actions: AGM_Actions {
			class AGM_Repair {
				displayName = "$STR_AGM_Repair";
				distance = 4;
				condition = "alive AGM_Interaction_Target";
				statement = "'AGM_Repair' call AGM_Interaction_fnc_openMenu;";
				showDisabled = 1;
				priority = 1.4;

				class AGM_Repair_checkVehicle {
					displayName = "$STR_AGM_Repair_checkVehicle";
					distance = 4;
					condition = "alive AGM_Interaction_Target";
					statement = "[AGM_Interaction_Target] call AGM_Repair_fnc_checkVehicle";
					showDisabled = 1;
					priority = 1;
				};
				class AGM_Repair_Wheels {
					displayName = "$STR_AGM_Repair_RepairWheel";
					distance = 4;
					condition = "[AGM_Interaction_Target, ['HitLFWheel', 'HitLBWheel', 'HitLMWheel', 'HitLF2Wheel', 'HitRFWheel', 'HitRBWheel', 'HitRMWheel', 'HitRF2Wheel']] call AGM_Repair_fnc_canRepairWheel";
					statement = "[AGM_Interaction_Target, ['HitLFWheel', 'HitLBWheel', 'HitLMWheel', 'HitLF2Wheel', 'HitRFWheel', 'HitRBWheel', 'HitRMWheel', 'HitRF2Wheel']] call AGM_Repair_fnc_openSelectWheelUI";
					showDisabled = 1;
					priority = 0.9;
				};
				class AGM_Remove_Wheels {
					displayName = "$STR_AGM_Repair_RemoveWheel";
					distance = 4;
					condition = "[AGM_Interaction_Target, ['HitLFWheel', 'HitLBWheel', 'HitLMWheel', 'HitLF2Wheel', 'HitRFWheel', 'HitRBWheel', 'HitRMWheel', 'HitRF2Wheel']] call AGM_Repair_fnc_canRemoveWheel";
					statement = "[AGM_Interaction_Target, ['HitLFWheel', 'HitLBWheel', 'HitLMWheel', 'HitLF2Wheel', 'HitRFWheel', 'HitRBWheel', 'HitRMWheel', 'HitRF2Wheel']] call AGM_Repair_fnc_openSelectWheelUI_Salvage";
					showDisabled = 1;
					priority = 0.8;
				};
				class AGM_Repair_Body {
					displayName = "$STR_AGM_Repair_HitBody";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitBody'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitBody'] call AGM_Repair_fnc_repair";
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

	class Truck_F: Car_F {
		KEY_WHEEL_6X6_REAR
		AGM_fuelCapacity = 240;  // in liter. This is guesswork and should be adjusted for all vehicles individually in the future @todo
		class AGM_Actions;
	};
	class Wheeled_APC_F: Car_F {
		KEY_WHEEL_6X6_REAR
		AGM_fuelCapacity = 600;  // in liter. This is guesswork and should be adjusted for all vehicles individually in the future @todo
	};

	// Repair tracked vehicles
	class Tank_F: Tank {
		AGM_fuelCapacity = 1500;  // in liter. This is guesswork and should be adjusted for all vehicles individually in the future @todo
		class AGM_Actions: AGM_Actions {
			class AGM_Repair {
				displayName = "$STR_AGM_Repair";
				distance = 4;
				condition = "alive AGM_Interaction_Target";
				statement = "'AGM_Repair' call AGM_Interaction_fnc_openMenu;";
				showDisabled = 1;
				priority = 1.4;

				class AGM_Repair_checkVehicle {
					displayName = "$STR_AGM_Repair_checkVehicle";
					distance = 4;
					condition = "alive AGM_Interaction_Target";
					statement = "[AGM_Interaction_Target] call AGM_Repair_fnc_checkVehicle";
					showDisabled = 1;
					priority = 1;
				};
				class AGM_Repair_Hull {
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
					condition = "[AGM_Interaction_Target, 'HitLTrack'] call AGM_Repair_fnc_canRepairTrack";
					statement = "[AGM_Interaction_Target, 'HitLTrack'] call AGM_Repair_fnc_repairTrack";
					showDisabled = 0;
					priority = 0.42;
				};
				class AGM_Repair_RTrack {
					displayName = "$STR_AGM_Repair_HitRTrack";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitRTrack'] call AGM_Repair_fnc_canRepairTrack";
					statement = "[AGM_Interaction_Target, 'HitRTrack'] call AGM_Repair_fnc_repairTrack";
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
				/*class AGM_Repair_Fuel {
					displayName = "$STR_AGM_Repair_HitFuel";
					distance = 4;
					condition = "[AGM_Interaction_Target, 'HitFuel'] call AGM_Repair_fnc_canRepair";
					statement = "[AGM_Interaction_Target, 'HitFuel'] call AGM_Repair_fnc_repair";
					showDisabled = 0;
					priority = 0.3;
				};*/
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
		AGM_fuelCapacity = 240;  // in liter. This is guesswork and should be adjusted for all vehicles individually in the future @todo
		AGM_Vehicle_Cargo = 4;
		class AGM_Actions {
			MACRO_UNLOAD
			MACRO_REFUEL
			MACRO_RELOAD_MAGS
			class AGM_Repair {
				displayName = "$STR_AGM_Repair";
				distance = 4;
				condition = "alive AGM_Interaction_Target";
				statement = "'AGM_Repair' call AGM_Interaction_fnc_openMenu;";
				showDisabled = 1;
				priority = 1.4;

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
		AGM_fuelCapacity = 600;  // in liter. This is guesswork and should be adjusted for all vehicles individually in the future @todo
		AGM_Vehicle_Cargo = 4;
		class AGM_Actions {
			MACRO_UNLOAD
			MACRO_REFUEL
			MACRO_RELOAD_MAGS
			class AGM_Repair {
				displayName = "$STR_AGM_Repair";
				distance = 4;
				condition = "alive AGM_Interaction_Target";
				statement = "'AGM_Repair' call AGM_Interaction_fnc_openMenu;";
				showDisabled = 1;
				priority = 1.4;

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

	class Ship_F;
	class Boat_F: Ship_F {
		AGM_fuelCapacity = 40;  // in liter. This is guesswork and should be adjusted for all vehicles individually in the future @todo
	};

	// Static weapons
	class StaticWeapon: LandVehicle {
		AGM_Size = 2; // 1 = small, 2 = large
		class AGM_Actions {
			MACRO_DRAGABLE
			MACRO_GETIN_STATIC
			MACRO_LOADABLE
		};
	};

	class StaticMortar;
	class Mortar_01_base_F: StaticMortar {
		AGM_Size = 2; // 1 = small, 2 = large
		class AGM_Actions {
			MACRO_DRAGABLE
			MACRO_GETIN_STATIC
			MACRO_LOADABLE
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
		class AGM_Actions: AGM_Actions {
			MACRO_DRAGABLE
		};
	};
	class IND_Box_Base: ReammoBox_F {
		class AGM_Actions: AGM_Actions {
			MACRO_DRAGABLE
		};
	};
	class NATO_Box_Base: ReammoBox_F {
		class AGM_Actions: AGM_Actions {
			MACRO_DRAGABLE
		};
	};
	// Remove Larger crate dragging support.
	// Would be better to allow some sort of joint push/drag functionality
	// Requiring 2 units to access the larger crates and attaching them together (a crappy method of doing it)
	// in order to move the bigger ones. Currently simply remove support.
	// I believe these crates are currently broken (hitbox doesn't work or something) in 1.22 (2014-07-04)
	class Box_East_AmmoVeh_F: EAST_Box_Base {
		//transportAmmo = 30000;
		class AGM_Actions: AGM_Actions {
			MACRO_NOT_DRAGABLE
		};
	};
	class Box_NATO_AmmoVeh_F: NATO_Box_Base {
		//transportAmmo = 30000;
		class AGM_Actions: AGM_Actions {
			MACRO_NOT_DRAGABLE
		};
	};
	class Box_IND_AmmoVeh_F: IND_Box_Base {
		//transportAmmo = 30000;
		class AGM_Actions: AGM_Actions {
			MACRO_NOT_DRAGABLE
		};
	};

	class Helicopter_Base_F;
	class UAV_01_base_F: Helicopter_Base_F {
		class AGM_Actions {
			MACRO_DRAGABLE
			MACRO_REFUEL_UAV
		};
	};

	// New Items
	class Land_CanisterFuel_F;
	class AGM_JerryCan: Land_CanisterFuel_F {
		author = "commy2";
		AGM_Size = 1; // 1 = small, 2 = large
		class AGM_Actions {
			MACRO_LOADABLE
			MACRO_CARRYJERRYCAN
		};
		icon = "iconObject_circle";
		displayName = "$STR_AGM_Repair_JerryCan";
		mapSize = 0.7;
		accuracy = 0.2;
		vehicleClass = "AGM_Repair_Items";
		destrType = "DesturctNo";
	};

	class AGM_SpareTrack: ThingX {
		author = "Hawkins";
		AGM_Size = 1; // 1 = small, 2 = large
		AGM_CarryPosition[] = {0,1,1}; // offset from player to attach object.
		scope = 2;
		model = "\AGM_Logistics\agm_track.p3d";
		icon = "iconObject_circle";
		displayName = "$STR_AGM_Repair_SpareTrack";
		mapSize = 0.7;
		accuracy = 0.2;
		vehicleClass = "AGM_Repair_Items";
		destrType = "DesturctNo";

		class AGM_Actions {
			MACRO_DRAGABLE
			MACRO_LOADABLE
		};
	};

	class AGM_SpareWheel: ThingX {
		author = "marc_book";
		AGM_Size = 1; // 1 = small, 2 = large
		AGM_CarryPosition[] = {0,1,1}; // offset from player to attach object.
		scope = 2;
		model = "\AGM_Logistics\agm_wheel.p3d";
		icon = "iconObject_circle";
		displayName = "$STR_AGM_Repair_SpareWheel";
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

	// disable default arma refueling and repair
	class House_Small_F;
	class Land_FuelStation_Feed_F: House_Small_F {
		class AGM_Actions {
			MACRO_REFUELCARGO
		};
		AGM_fuelCapacityCargo = 50000;
		transportFuel = 0;
	};
	class  Land_fs_feed_F: House_Small_F {
		class AGM_Actions {
			MACRO_REFUELCARGO
		};
		AGM_fuelCapacityCargo = 50000;
		transportFuel = 0;
	};

	// ARV
	class APC_Tracked_01_base_F;
	class B_APC_Tracked_01_base_F: APC_Tracked_01_base_F {
		class AGM_Actions;
	};
	class B_APC_Tracked_01_CRV_F: B_APC_Tracked_01_base_F {
		class AGM_Actions: AGM_Actions {
			MACRO_REFUELCARGO
		};
		AGM_canRepair = 1;
		AGM_fuelCapacityCargo = 1500;
		transportRepair = 0;
		transportFuel = 0;
	};

	// Trucks BLU
	class Truck_01_base_F: Truck_F {
		KEY_WHEEL_8X8
		class AGM_Actions;
	};
	class B_Truck_01_transport_F: Truck_01_base_F {
		/*class AGM_Load {											@todo
			class MidLoad {
				displayName = "Middle of truck";
				loadSize = 2; // Size of object, 1 = small, 2 = large
				LoadPosition[]={0.05,-4,-0.6}; // Offset when attaching.
				memoryPoint = "exhaustEnd"; // the memory position on the vehicle to use for the attaching and offset.
			};
			UnLoadPosition[]={0,-6,-1.0}; // Position objects will be unloaded to. modelToWorld offset.
		};*/
	};
	class B_Truck_01_mover_F: B_Truck_01_transport_F {};
	class B_Truck_01_Repair_F: B_Truck_01_mover_F {
		AGM_canRepair = 1;
		transportRepair = 0;
	};
	class B_Truck_01_fuel_F: B_Truck_01_mover_F {
		class AGM_Actions: AGM_Actions {
			MACRO_REFUELCARGO
		};
		AGM_fuelCapacityCargo = 3000;
		transportFuel = 0;
	};
	/*class B_Truck_01_ammo_F: B_Truck_01_mover_F {
		transportAmmo = 30000;
	};*/

	// Trucks INDEP
	class Truck_02_base_F: Truck_F {
		KEY_WHEEL_6X6_REAR
		class AGM_Actions: AGM_Actions {};
	};
	class O_Truck_02_box_F: Truck_02_base_F {	// this is the repair variant because fuck naming conventions
		AGM_canRepair = 1;
		transportRepair = 0;
	};
	class O_Truck_02_medical_F: O_Truck_02_box_F {	// medic inherits from repairer
		AGM_canRepair = 0;
	};
	class O_Truck_02_fuel_F: Truck_02_base_F {
		class AGM_Actions: AGM_Actions {
			MACRO_REFUELCARGO
		};
		AGM_fuelCapacityCargo = 3000;
		transportFuel = 0;
	};
	/*class O_Truck_02_ammo_F: Truck_02_base_F {
		transportAmmo = 30000;
	};*/
	class I_Truck_02_box_F: Truck_02_base_F {	// this is the repair variant because fuck naming conventions
		AGM_canRepair = 1;
		transportRepair = 0;
	};
	class I_Truck_02_medical_F: I_Truck_02_box_F {	// medic inherits from repairer
		AGM_canRepair = 0;
	};
	class I_Truck_02_fuel_F: Truck_02_base_F {
		class AGM_Actions: AGM_Actions {
			MACRO_REFUELCARGO
		};
		AGM_fuelCapacityCargo = 3000;
		transportFuel = 0;
	};
	/*class I_Truck_02_ammo_F: Truck_02_base_F {
		transportAmmo = 30000;
	};*/

	// Trucks RED
	class Truck_03_base_F: Truck_F {
		KEY_WHEEL_6X6_FRONT
		class AGM_Actions: AGM_Actions {};
	};
	class O_Truck_03_repair_F: Truck_03_base_F {
		AGM_canRepair = 1;
		transportRepair = 0;
	};
	class O_Truck_03_fuel_F: Truck_03_base_F {
		class AGM_Actions: AGM_Actions {
			MACRO_REFUELCARGO
		};
		AGM_fuelCapacityCargo = 3000;
		transportFuel = 0;
	};
	/*class O_Truck_03_ammo_F: Truck_03_base_F {
		transportAmmo = 30000;
	};*/

	// Trucks CIV
	class Van_01_base_F: Truck_F {
		KEY_WHEEL_4X4
		class AGM_Actions: AGM_Actions {};
	};
	class I_G_Van_01_fuel_F: Van_01_base_F {
		class AGM_Actions: AGM_Actions {
			MACRO_REFUELCARGO
		};
		AGM_fuelCapacityCargo = 1000;
		transportFuel = 0;
	};
	class C_Van_01_fuel_F: Van_01_base_F {
		class AGM_Actions: AGM_Actions {
			MACRO_REFUELCARGO
		};
		AGM_fuelCapacityCargo = 1000;
		transportFuel = 0;
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
	class ToolKitItem;

	// disable default arma repair
	class ToolKit: ItemCore {
		class ItemInfo: ToolKitItem {
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
