class CfgPatches {
  class AGM_Vehicles {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {
      A3_Armor_F,
      A3_Armor_F_AMV,
      A3_Armor_F_APC_Wheeled_03,
      A3_armor_f_beta,
      A3_armor_f_beta_APC_Tracked_02,
      A3_armor_F_EPB_APC_tracked_03,
      A3_Armor_F_EPB_MBT_03,
      A3_Armor_F_Marid,
      A3_Armor_F_Panther,
      A3_Armor_F_Slammer,
      A3_Armor_F_T100K,
      A3_Soft_F,
      A3_Soft_F_MRAP_01,
      A3_Soft_F_MRAP_02,
      A3_Soft_F_MRAP_03,
      A3_Soft_F_HEMTT,
      A3_Soft_F_TruckHeavy,
      A3_Soft_F_EPC_Truck_03
    };
    version = "0.9";
    versionStr = "0.9";
    versionAr[] = {0,9,0};
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

#define FUEL_FACTOR 0.165
// fuel capacity = range in km * FUEL_FACTOR

class CfgVehicles {
  // Inheritance
  class Car_F;
  class Wheeled_APC_F: Car_F {};
  class Truck_F: Car_F {};
  class Tank_F;

  // BLUFOR Inheritance
  class MRAP_01_base_F: Car_F {
    fuelCapacity = 510 * FUEL_FACTOR;
  };
  class MRAP_01_hmg_base_F: MRAP_01_base_F {};
  class MRAP_01_gmg_base_F: MRAP_01_hmg_base_F {};

  class MBT_01_base_F: Tank_F {
    fuelCapacity = 500 * FUEL_FACTOR;
  };
  class B_MBT_01_base_F: MBT_01_base_F {};
  class MBT_01_arty_base_F: MBT_01_base_F {};
  class B_MBT_01_arty_base_F: MBT_01_arty_base_F {};
  class MBT_01_mlrs_base_F: MBT_01_base_F {};
  class B_MBT_01_mlrs_base_F: MBT_01_mlrs_base_F {};

  class APC_Wheeled_01_base_F: Wheeled_APC_F {
    fuelCapacity = 800 * FUEL_FACTOR;
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
    class Turrets {
      class CommanderTurret;
    };
  };
  class MRAP_03_hmg_base_F: MRAP_03_base_F {
    class Turrets: Turrets {
      class CommanderTurret: CommanderTurret {};
    };
  };
  class MRAP_03_gmg_base_F: MRAP_03_hmg_base_F {
    class Turrets: Turrets {
      class CommanderTurret: CommanderTurret {};
    };
  };

  class MBT_03_base_F;
  class I_MBT_03_base_F: MBT_03_base_F {
    fuelCapacity = 550 * FUEL_FACTOR;
  };

  class APC_Wheeled_03_base_F;
  class I_APC_Wheeled_03_base_F: APC_Wheeled_03_base_F {
    fuelCapacity = 700 * FUEL_FACTOR;
  };

  class APC_Tracked_03_base_F;
  class I_APC_tracked_03_base_F: APC_Tracked_03_base_F {
    fuelCapacity = 660 * FUEL_FACTOR;
  };

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
  };
  class O_APC_Tracked_02_base_F: APC_Tracked_02_base_F {};

  class Truck_03_base_F: Truck_F {
    fuelCapacity = 900 * FUEL_FACTOR; // NO. FUCKING. DATA.
  };

  ////////////////////////////////////

  // BLUFOR
  class B_MRAP_01_F: MRAP_01_base_F {
    displayName = "$STR_AGM_Vehicles_MRAP_01_Name";
  };
  class B_MRAP_01_hmg_F: MRAP_01_hmg_base_F {
    displayName = "$STR_AGM_Vehicles_MRAP_01_hmg_Name";
  };
  class B_MRAP_01_gmg_F: MRAP_01_gmg_base_F {
    displayName = "$STR_AGM_Vehicles_MRAP_01_gmg_Name";
  };

  class B_MBT_01_cannon_F: B_MBT_01_base_F {
    displayName = "$STR_AGM_Vehicles_MBT_01_cannon_Name";
  };
  class B_MBT_01_TUSK_F: B_MBT_01_cannon_F {
    displayName = "$STR_AGM_Vehicles_MBT_01_TUSK_Name";
  };
  class B_MBT_01_arty_F: B_MBT_01_arty_base_F {
    displayName = "$STR_AGM_Vehicles_MBT_01_arty_Name";
  };
  class B_MBT_01_mlrs_F: B_MBT_01_mlrs_base_F {
    displayName = "$STR_AGM_Vehicles_MBT_01_mlrs_Name"; // Fictional name, (probably wrong) hebrew translation of storm.
  };
  class B_APC_Tracked_01_rcws_F: B_APC_Tracked_01_base_F {
    displayName = "$STR_AGM_Vehicles_APC_Tracked_01_rcws_Name";
  };
  class B_APC_Tracked_01_AA_F: B_APC_Tracked_01_base_F {
    displayName = "$STR_AGM_Vehicles_APC_Tracked_01_AA_Name"; // Fictional name, (probably wrong) hebrew translation of cheetah.
  };
  class B_APC_Wheeled_01_cannon_F: B_APC_Wheeled_01_base_F {
    displayName = "$STR_AGM_Vehicles_APC_Wheeled_cannon_Name";
  };
  class B_APC_Tracked_01_CRV_F: B_APC_Tracked_01_base_F {
    displayName = "$STR_AGM_Vehicles_APC_Tracked_01_CRV_Name";
  };

  // WHY THE FUCK ARE THERE SO MANY OF THESE
  class B_Truck_01_transport_F: Truck_01_base_F {
    displayName = "$STR_AGM_Vehicles_Truck_01_transport_Name";
  };
  class B_Truck_01_covered_F: B_Truck_01_transport_F {
    displayName = "$STR_AGM_Vehicles_Truck_01_covered_Name";
  };
  class B_Truck_01_mover_F: B_Truck_01_transport_F {
    displayName = "$STR_AGM_Vehicles_Truck_01_mover_Name";
  };
  class B_Truck_01_box_F: B_Truck_01_mover_F {
    displayName = "$STR_AGM_Vehicles_Truck_01_box_Name";
  };
  class B_Truck_01_medical_F: B_Truck_01_transport_F {
    displayName = "$STR_AGM_Vehicles_Truck_01_medical_Name";
  };
  class B_Truck_01_ammo_F: B_Truck_01_mover_F {
    displayName = "$STR_AGM_Vehicles_Truck_01_ammo_Name";
  };
  class B_Truck_01_fuel_F: B_Truck_01_mover_F {
    displayName = "$STR_AGM_Vehicles_Truck_01_fuel_Name";
  };
  class B_Truck_01_Repair_F: B_Truck_01_mover_F {
    displayName = "$STR_AGM_Vehicles_Truck_01_Repair_Name";
  };


  // INDEP
  class I_MRAP_03_F: MRAP_03_base_F {
    displayName = "$STR_AGM_Vehicles_MRAP_03_Name";
    smokeLauncherGrenadeCount = 3;
    smokeLauncherAngle = 80;
    class Turrets: Turrets {
      class CommanderTurret: CommanderTurret {
        stabilizedInAxes = 3;
      };
    };
  };
  class I_MRAP_03_hmg_F: MRAP_03_hmg_base_F {
    displayName = "$STR_AGM_Vehicles_MRAP_03_hmg_Name";
    smokeLauncherGrenadeCount = 3;
    smokeLauncherAngle = 80;
    class Turrets: Turrets {
      class CommanderTurret: CommanderTurret {
        stabilizedInAxes = 3;
      };
    };
  };
  class I_MRAP_03_gmg_F: MRAP_03_gmg_base_F {
    displayName = "$STR_AGM_Vehicles_MRAP_03_gmg_Name";
    smokeLauncherGrenadeCount = 3;
    smokeLauncherAngle = 80;
    class Turrets: Turrets {
      class CommanderTurret: CommanderTurret {
        stabilizedInAxes = 3;
      };
    };
  };

  class I_MBT_03_cannon_F: I_MBT_03_base_F {
    displayName = "$STR_AGM_Vehicles_MBT_03_cannon_Name";
  };
  class I_APC_tracked_03_cannon_F: I_APC_tracked_03_base_F {
    displayName = "$STR_AGM_Vehicles_APC_tracked_03_cannon_Name";
  };
  class I_APC_Wheeled_03_cannon_F: I_APC_Wheeled_03_base_F {
    displayName = "$STR_AGM_Vehicles_APC_Wheeled_03_cannon_Name";
  };

  class I_Truck_02_transport_F: Truck_02_base_F {
    displayName = "$STR_AGM_Vehicles_Truck_02_transport_Name";
  };
  class I_Truck_02_covered_F: Truck_02_base_F {
    displayName = "$STR_AGM_Vehicles_Truck_02_covered_Name";
  };
  class I_Truck_02_ammo_F: Truck_02_base_F {
    displayName = "$STR_AGM_Vehicles_Truck_02_ammo_Name";
  };
  class I_Truck_02_fuel_F: Truck_02_base_F {
    displayName = "$STR_AGM_Vehicles_Truck_02_fuel_Name";
  };
  class I_Truck_02_box_F: Truck_02_base_F {
    displayName = "$STR_AGM_Vehicles_Truck_02_box_Name";
  };
  class I_Truck_02_medical_F: I_Truck_02_box_F {
    displayName = "$STR_AGM_Vehicles_Truck_02_medical_Name";
  };


  //OPFOR
  class O_MRAP_02_F: MRAP_02_base_F {
    displayName = "$STR_AGM_Vehicles_MRAP_02_Name";
  };
  class O_MRAP_02_hmg_F: MRAP_02_hmg_base_F {
    displayName = "$STR_AGM_Vehicles_MRAP_02_hmg_Name";
  };
  class O_MRAP_02_gmg_F: MRAP_02_gmg_base_F {
    displayName = "$STR_AGM_Vehicles_MRAP_02_gmg_Name";
  };

  class O_MBT_02_cannon_F: O_MBT_02_base_F {
    displayName = "$STR_AGM_Vehicles_MBT_02_cannon_Name";
  };
  class O_MBT_02_arty_F: O_MBT_02_arty_base_F {
    displayName = "$STR_AGM_Vehicles_MBT_02_arty_Name";
  };
  class O_APC_Tracked_02_cannon_F: O_APC_Tracked_02_base_F {
    displayName = "$STR_AGM_Vehicles_APC_Tracked_02_cannon_Name";
  };
  class O_APC_Tracked_02_AA_F: O_APC_Tracked_02_base_F {
    displayName = "$STR_AGM_Vehicles_APC_Tracked_02_AA_Name";
  };
  class O_APC_Wheeled_02_rcws_F: O_APC_Wheeled_02_base_F {
    displayName = "$STR_AGM_Vehicles_APC_Wheeled_02_rcws_Name";
  };

  class O_Truck_02_transport_F: Truck_02_base_F {
    displayName = "$STR_AGM_Vehicles_Truck_02_transport_Name";
  };
  class O_Truck_02_covered_F: Truck_02_base_F {
    displayName = "$STR_AGM_Vehicles_Truck_02_covered_Name";
  };
  class O_Truck_02_ammo_F: Truck_02_base_F {
    displayName = "$STR_AGM_Vehicles_Truck_02_ammo_Name";
  };
  class O_Truck_02_fuel_F: Truck_02_base_F {
    displayName = "$STR_AGM_Vehicles_Truck_02_fuel_Name";
  };
  class O_Truck_02_box_F: Truck_02_base_F {
    displayName = "$STR_AGM_Vehicles_Truck_02_box_Name";
  };
  class O_Truck_02_medical_F: I_Truck_02_box_F {
    displayName = "$STR_AGM_Vehicles_Truck_02_medical_Name";
  };

  class O_Truck_03_transport_F: Truck_03_base_F {
    displayName = "$STR_AGM_Vehicles_Truck_03_transport_Name";
  };
  class O_Truck_03_covered_F: Truck_03_base_F {
    displayName = "$STR_AGM_Vehicles_Truck_03_covered_Name";
  };
  class O_Truck_03_device_F: Truck_03_base_F {
    displayName = "$STR_AGM_Vehicles_Truck_03_device_Name";
  };
  class O_Truck_03_ammo_F: Truck_03_base_F {
    displayName = "$STR_AGM_Vehicles_Truck_03_ammo_Name";
  };
  class O_Truck_03_fuel_F: Truck_03_base_F {
    displayName = "$STR_AGM_Vehicles_Truck_03_fuel_Name";
  };
  class O_Truck_03_repair_F: Truck_03_base_F {
    displayName = "$STR_AGM_Vehicles_Truck_03_repair_Name";
  };
  class O_Truck_03_medical_F: Truck_03_base_F {
    displayName = "$STR_AGM_Vehicles_Truck_03_medical_Name";
  };
};
