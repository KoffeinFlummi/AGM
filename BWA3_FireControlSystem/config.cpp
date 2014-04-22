class CfgPatches {
  class BWA3_FireControlSystem {
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
      A3_Armor_F_T100K
    };
    version = 1.0;
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class BWA3_FCS {
    class BWA3_FCS {
      file = "BWA3_FireControlSystem\functions";
      class firedEH;
      class getAngle;
      class init;
      class keyDown;
      class keyUp;
      class vehicleInit;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class BWA3_FCS {
    clientInit = "_this call BWA3_FCS_fnc_init";
  };
};

class Extended_Init_EventHandlers {
  class AllVehicles {
    class BWA3_FCS {
      clientInit = "_this call BWA3_FCS_fnc_vehicleInit";
    };
  };
};

class CfgVehicles {

  // PROVIDE DEFAULT VALUES FOR OTHER MODS
  class All;
  class AllVehicles: All {
    BWA3_FCSEnabled = 0; // FCS defaults to off
  };
  class Land: AllVehicles {};
  class LandVehicle: Land {};
  class Tank: LandVehicle {
    BWA3_FCSEnabled = 1; // all tracked vehicles get one by default
  };

  // REMOVE STANDARD ZEROING FOR AFFECTED VEHICLES
  // BLUFOR Inheritance
  class MBT_01_base_F;
  class B_MBT_01_base_F: MBT_01_base_F {
    class Turrets {
      class MainTurret;
    };
  };
  class APC_Tracked_01_base_F;
  class B_APC_Tracked_01_base_F: APC_Tracked_01_base_F {
    class Turrets {
      class MainTurret;
    };
  };
  class APC_Wheeled_01_base_F;
  class B_APC_Wheeled_01_base_F: APC_Wheeled_01_base_F {
    class Turrets {
      class MainTurret;
    };
  };
  class B_MBT_01_mlrs_base_F;
  class B_MBT_01_arty_base_F;

  // BLUFOR
  class B_MBT_01_cannon_F: B_MBT_01_base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        discreteDistance[] = {};
        discreteDistanceInitIndex = 0;
      };
    };
  };
  class B_MBT_01_TUSK_F: B_MBT_01_cannon_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        discreteDistance[] = {};
        discreteDistanceInitIndex = 0;
      };
    };
  };
  class B_APC_Tracked_01_AA_F: B_APC_Tracked_01_base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        discreteDistance[] = {};
        discreteDistanceInitIndex = 0;
      };
    };
  };
  class B_APC_Wheeled_01_cannon_F: B_APC_Wheeled_01_base_F {
    BWA3_FCSEnabled = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        discreteDistance[] = {};
        discreteDistanceInitIndex = 0;
      };
    };
  };
  class B_MBT_01_arty_F: B_MBT_01_arty_base_F {
    BWA3_FCSEnabled = 0;
  };
  class B_MBT_01_mlrs_F: B_MBT_01_mlrs_base_F {
    BWA3_FCSEnabled = 0;
  };
  class B_APC_Tracked_01_rcws_F: B_APC_Tracked_01_base_F {
    BWA3_FCSEnabled = 0;
  };
  class B_APC_Tracked_01_CRV_F: B_APC_Tracked_01_base_F {
    BWA3_FCSEnabled = 0;
  };
};