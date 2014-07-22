class CfgPatches {
  class AGM_Vehicles {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_Vehicles {
    class AGM_Vehicles {
      file = "AGM_Vehicles\functions";
      class speedLimiter;
      class startEngine;
    };
  };
};

class AGM_Core_Default_Keys {
  class speedLimiter {
    displayName = "$STR_AGM_SpeedLimiter";
    condition = "player == driver _vehicle && {_vehicle isKindOf 'Car' || {_vehicle isKindOf 'Tank'}}";
    statement = "[_vehicle] call AGM_Vehicles_fnc_speedLimiter";
    key = 211;
    shift = 0;
    control = 0;
    alt = 0;
  };
};

class Extended_Engine_EventHandlers {
  class Car {
    class AGM_EngineStartDelay {
      clientEngine = "_this call AGM_Vehicles_fnc_startEngine";
    };
  };
};

#define FUEL_FACTOR 0.165
// fuel capacity = range in km * FUEL_FACTOR

class CfgVehicles {
  // Inheritance
  class Car;
  class Car_F: Car {
    class Turrets;
  };
  class Wheeled_APC_F: Car_F {
    class Turrets;
  };
  class Truck_F: Car_F {};

  class Tank;
  class Tank_F: Tank {
    class Turrets;
  };

  class Boat_F;
  class Boat_Armed_01_base_F: Boat_F {
    class Turrets;
  };
  class Boat_Armed_01_minigun_base_F: Boat_Armed_01_base_F {
    class Turrets: Turrets {
      class FrontTurret;
      class RearTurret;
    };
  };

  // BLUFOR Inheritance
  class MRAP_01_base_F: Car_F {
    fuelCapacity = 510 * FUEL_FACTOR;
  };
  class MRAP_01_gmg_base_F: MRAP_01_base_F {};
  class MRAP_01_hmg_base_F: MRAP_01_gmg_base_F {};

  class MBT_01_base_F: Tank_F {
    fuelCapacity = 500 * FUEL_FACTOR;
    class Turrets: Turrets {
      class MainTurret;
    };
  };
  class B_MBT_01_base_F: MBT_01_base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        weapons[] = {"cannon_120mm","AGM_LMG_coax_MBT_01"};
        magazines[] = {"32Rnd_120mm_APFSDS_shells_Tracer_Red","16Rnd_120mm_HE_shells_Tracer_Red","2000Rnd_762x51_Belt_Green","2000Rnd_762x51_Belt_Green"};
      };
    };
  };
  class MBT_01_arty_base_F: MBT_01_base_F {};
  class B_MBT_01_arty_base_F: MBT_01_arty_base_F {};
  class MBT_01_mlrs_base_F: MBT_01_base_F {};
  class B_MBT_01_mlrs_base_F: MBT_01_mlrs_base_F {};

  class APC_Wheeled_01_base_F: Wheeled_APC_F {
    fuelCapacity = 800 * FUEL_FACTOR;
    class Turrets: Turrets {
      class MainTurret;
    };
  };
  class B_APC_Wheeled_01_base_F: APC_Wheeled_01_base_F {};

  class APC_Tracked_01_base_F: Tank_F {
    fuelCapacity = 500 * FUEL_FACTOR;
  };
  class B_APC_Tracked_01_base_F: APC_Tracked_01_base_F {};

  class Truck_01_base_F: Truck_F {
    fuelCapacity = 644 * FUEL_FACTOR;
  };

  // INDEP Inheritance
  class MRAP_03_base_F: Car_F {
    fuelCapacity = 860 * FUEL_FACTOR;
    class NewTurret;
    class Turrets: Turrets {
      class CommanderTurret;
    };
  };
  class MRAP_03_hmg_base_F: MRAP_03_base_F {
    class Turrets: Turrets {
      class CommanderTurret: CommanderTurret {};
      class MainTurret;
    };
  };
  class MRAP_03_gmg_base_F: MRAP_03_hmg_base_F {
    class Turrets: Turrets {
      class CommanderTurret: CommanderTurret {};
      class MainTurret: MainTurret {};
    };
  };

  class MBT_03_base_F: Tank_F {
    fuelCapacity = 550 * FUEL_FACTOR;
    class Turrets: Turrets {
      class MainTurret;
    };
  };
  class I_MBT_03_base_F: MBT_03_base_F {};

  class APC_Wheeled_03_base_F: Wheeled_APC_F {
    fuelCapacity = 700 * FUEL_FACTOR;
    class Turrets: Turrets {
      class MainTurret;
    };
  };
  class I_APC_Wheeled_03_base_F: APC_Wheeled_03_base_F {};

  class APC_Tracked_03_base_F: Tank_F {
    fuelCapacity = 660 * FUEL_FACTOR;
    class Turrets: Turrets {
      class MainTurret;
    };
  };
  class I_APC_tracked_03_base_F: APC_Tracked_03_base_F {};

  class Truck_02_base_F: Truck_F {
    fuelCapacity = 1100 * FUEL_FACTOR;
  };

  // OPFOR Inheritance
  class MRAP_02_base_F: Car_F {
    fuelCapacity = 500 * FUEL_FACTOR; // couldn't find any data for the punisher
  };
  class MRAP_02_hmg_base_F: MRAP_02_base_F {};
  class MRAP_02_gmg_base_F: MRAP_02_hmg_base_F {};

  class MBT_02_base_F: Tank_F {
    fuelCapacity = 600 * FUEL_FACTOR; // again, couldn't find proper data
  };
  class O_MBT_02_base_F: MBT_02_base_F {};
  class MBT_02_arty_base_F: MBT_02_base_F {};
  class O_MBT_02_arty_base_F: MBT_02_arty_base_F {};

  class APC_Wheeled_02_base_F: Wheeled_APC_F {
    fuelCapacity = 700 * FUEL_FACTOR;
  };
  class O_APC_Wheeled_02_base_F: APC_Wheeled_02_base_F {};

  class APC_Tracked_02_base_F: Tank_F {
    fuelCapacity = 600 * FUEL_FACTOR; // NO FUCKING DATA
    class Turrets: Turrets {
      class MainTurret;
    };
  };
  class O_APC_Tracked_02_base_F: APC_Tracked_02_base_F {};

  class Truck_03_base_F: Truck_F {
    fuelCapacity = 900 * FUEL_FACTOR; // NO. FUCKING. DATA.
  };

  ////////////////////////////////////

  // BLUFOR
  class B_MBT_01_cannon_F: B_MBT_01_base_F {};
  class B_MBT_01_TUSK_F: B_MBT_01_cannon_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        weapons[] = {"cannon_105mm","AGM_LMG_coax_MBT_01"};
        magazines[] = {"40Rnd_105mm_APFSDS_T_Red","20Rnd_105mm_HEAT_MP_T_Red","2000Rnd_762x51_Belt_Green","2000Rnd_762x51_Belt_Green"};
      };
    };
  };
  class B_APC_Wheeled_01_cannon_F: B_APC_Wheeled_01_base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        weapons[] = {"autocannon_40mm_CTWS","AGM_LMG_coax_MBT_01"};
        magazines[] = {"60Rnd_40mm_GPR_Tracer_Red_shells","40Rnd_40mm_APFSDS_Tracer_Red_shells","2000Rnd_762x51_Belt_Green"};
      };
    };
  };
  class B_Boat_Armed_01_minigun_F: Boat_Armed_01_minigun_base_F {
    class Turrets: Turrets {
      class FrontTurret: FrontTurret {};
      class RearTurret: RearTurret {
        magazines[] = {"2000Rnd_762x51_Belt_T_Red"};
      };
    };
  };

  // INDEP
  class I_MRAP_03_F: MRAP_03_base_F {
    smokeLauncherGrenadeCount = 3;
    smokeLauncherAngle = 80;
    class Turrets: Turrets {
      class CommanderTurret: CommanderTurret {
        stabilizedInAxes = 3;
      };
    };
  };
  class I_MRAP_03_hmg_F: MRAP_03_hmg_base_F {
    smokeLauncherGrenadeCount = 3;
    smokeLauncherAngle = 80;
    class Turrets: Turrets {
      class CommanderTurret: CommanderTurret {
        stabilizedInAxes = 3;
      };
      class MainTurret: MainTurret {};
    };
  };
  class I_MRAP_03_gmg_F: MRAP_03_gmg_base_F {
    smokeLauncherGrenadeCount = 3;
    smokeLauncherAngle = 80;
    class Turrets: Turrets {
      class CommanderTurret: CommanderTurret {
        stabilizedInAxes = 3;
      };
      class MainTurret: MainTurret {};
    };
  };
  class I_APC_Wheeled_03_cannon_F: I_APC_Wheeled_03_base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        weapons[] = {"autocannon_30mm_CTWS","AGM_LMG_coax_MBT_01","missiles_titan"};
        magazines[] = {"140Rnd_30mm_MP_shells_Tracer_Yellow","60Rnd_30mm_APFSDS_shells_Tracer_Yellow","2000Rnd_762x51_Belt_Yellow","2Rnd_GAT_missiles"};
      };
    };
  };
  class I_APC_tracked_03_cannon_F: I_APC_tracked_03_base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        weapons[] = {"autocannon_30mm","AGM_LMG_coax_APC_Tracked_03"};
        magazines[] = {"140Rnd_30mm_MP_shells_Tracer_Yellow","60Rnd_30mm_APFSDS_shells_Tracer_Yellow","1000Rnd_762x51_Belt_Yellow","1000Rnd_762x51_Belt_Yellow"};
      };
    };
  };
  class I_MBT_03_cannon_F: I_MBT_03_base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        weapons[] = {"cannon_120mm_long","AGM_LMG_coax_MBT_01"};
        magazines[] = {"28Rnd_120mm_APFSDS_shells_Tracer_Yellow","14Rnd_120mm_HE_shells_Tracer_Yellow","2000Rnd_762x51_Belt_Yellow","2000Rnd_762x51_Belt_Yellow"};
      };
    };
  };
  class I_Boat_Armed_01_minigun_F: Boat_Armed_01_minigun_base_F {
    class Turrets: Turrets {
      class FrontTurret: FrontTurret {};
      class RearTurret: RearTurret {
        magazines[] = {"2000Rnd_762x51_Belt_T_Yellow"};
      };
    };
  };

  // OPFOR
  class O_APC_Tracked_02_cannon_F: O_APC_Tracked_02_base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        weapons[] = {"autocannon_30mm_CTWS","AGM_LMG_coax_MBT_01","missiles_titan"};
        magazines[] = {"140Rnd_30mm_MP_shells_Tracer_Green","60Rnd_30mm_APFSDS_shells_Tracer_Green","2000Rnd_762x51_Belt_Green","2Rnd_GAT_missiles"};
      };
    };
  };
};

class CfgWeapons {
  class MGunCore;
  class MGun: MGunCore {};
  class LMG_RCWS: MGun {};
  class LMG_coax;
  class AGM_LMG_coax_MBT_01: LMG_coax {};
  class AGM_LMG_coax_APC_Tracked_03: LMG_coax {};
  class autocannon_Base_F;

  class LMG_Minigun: LMG_RCWS {
    magazines[] = {"5000Rnd_762x51_Belt","5000Rnd_762x51_Yellow_Belt","2000Rnd_762x51_Belt_T_Red","2000Rnd_762x51_Belt_T_Green","2000Rnd_762x51_Belt_T_Yellow", "200Rnd_65x39_belt", "200Rnd_65x39_belt_Tracer_Red", "200Rnd_65x39_belt_Tracer_Green", "200Rnd_65x39_belt_Tracer_Yellow", "2000Rnd_65x39_belt", "2000Rnd_65x39_belt_Tracer_Red", "2000Rnd_65x39_belt_Tracer_Green", "2000Rnd_65x39_belt_Tracer_Yellow", "1000Rnd_65x39_belt", "1000Rnd_65x39_belt_Tracer_Red", "1000Rnd_65x39_belt_Tracer_Green", "1000Rnd_65x39_belt_Tracer_Yellow"};
    class manual: MGun {
      reloadTime = 0.015;
      dispersion = 0.006;
    };
    class close: manual{};
    class short: close{};
    class medium: close{};
    class far: close{};
  };

  class HMG_127: LMG_RCWS {
    class manual: MGun {};
  };

  class HMG_01: HMG_127 {
    reloadTime = 0.23;
    class manual: manual {
      reloadTime = 0.23;
    };
    class close: manual {
      reloadTime = 0.23;
    };
    class short: close {
      reloadTime = 0.23;
    };
    class medium: close {
      reloadTime = 0.23;
    };
    class far: close {
      reloadTime = 0.23;
    };
  };

  class autocannon_30mm_CTWS: autocannon_Base_F {
    class AP: autocannon_Base_F {
      magazines[] = {"60Rnd_30mm_APFSDS_shells","60Rnd_30mm_APFSDS_shells_Tracer_Red","60Rnd_30mm_APFSDS_shells_Tracer_Green","60Rnd_30mm_APFSDS_shells_Tracer_Yellow","140Rnd_30mm_MP_shells","140Rnd_30mm_MP_shells_Tracer_Red","140Rnd_30mm_MP_shells_Tracer_Green","140Rnd_30mm_MP_shells_Tracer_Yellow"};
      magazineReloadTime = 0;
    };
    muzzles[] = {"AP"};
  };
  class autocannon_40mm_CTWS: autocannon_Base_F {
    class AP: autocannon_Base_F {
      magazines[] = {"40Rnd_40mm_APFSDS_shells","40Rnd_40mm_APFSDS_Tracer_Red_shells","40Rnd_40mm_APFSDS_Tracer_Green_shells","40Rnd_40mm_APFSDS_Tracer_Yellow_shells","60Rnd_40mm_GPR_shells","60Rnd_40mm_GPR_Tracer_Red_shells","60Rnd_40mm_GPR_Tracer_Green_shells","60Rnd_40mm_GPR_Tracer_Yellow_shells"};
      magazineReloadTime = 0;
    };
    muzzles[] = {"AP"};
  };
};

class CfgAmmo {
  class MissileBase;

  class M_Mo_120mm_AT: MissileBase {
    cost = 400000; // Stop it from aiming at FUCKING RABBITS.
    weaponLockSystem = 2;
  };
  class M_Mo_120mm_AT_LG: M_Mo_120mm_AT {
    cost = 400000;
    weaponLockSystem = 4;
  };

  class M_Mo_82mm_AT: MissileBase {
    cost = 400000;
    weaponLockSystem = 2;
  };
  class M_Mo_82mm_AT_LG: M_Mo_82mm_AT {
    cost = 400000;
    weaponLockSystem = 4;
  };
};
