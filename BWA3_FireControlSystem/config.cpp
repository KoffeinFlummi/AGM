class CfgPatches {
  class BWA3_FireControlSystem {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, A3_Anims_F};
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
  class All;
  class AllVehicles: All {
    BWA3_FCSEnabled = 0; // FCS defaults to off
  };
  class Land: AllVehicles {};
  class LandVehicle: Land {};
  class Tank: LandVehicle {
    BWA3_FCSEnabled = 1; // all tracked vehicles get one by default
  };
};