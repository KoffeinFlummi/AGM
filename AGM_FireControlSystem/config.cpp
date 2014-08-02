class CfgPatches {
  class AGM_FireControlSystem {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"KoffeinFlummi","BadGuy (simon84)"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_FCS {
    class AGM_FCS {
      file = "AGM_FireControlSystem\functions";
      class adjustRange;
      class firedEH;
      class getAngle;
      class keyDown;
      class keyUp;
      class reset;
      class vehicleInit;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_FCS {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_FireControlSystem\clientInit.sqf'";
  };
};

class Extended_Init_EventHandlers {
  class AllVehicles {
    class AGM_FCS {
      clientInit = "_this call AGM_FCS_fnc_vehicleInit";
    };
  };
};

class AGM_Core_Default_Keys {
  class laseTarget {
    displayName = "$STR_AGM_FireControlSystem_LaseTarget";
    condition = "!AGM_FCSEnabled && {player == gunner _vehicle} && {getNumber (configFile >> 'CfgVehicles' >> (typeOf _vehicle) >> 'AGM_FCSEnabled') == 1}";
    statement = "[_vehicle] call AGM_FCS_fnc_keyDown";
    conditionUp = "player == gunner _vehicle && {getNumber (configFile >> 'CfgVehicles' >> (typeOf _vehicle) >> 'AGM_FCSEnabled') == 1}";
    statementUp = "[_vehicle] call AGM_FCS_fnc_keyUp";
    key = 15;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class adjustRangeUp {
    displayName = "$STR_AGM_FireControlSystem_AdjustRangeUp";
    condition = "player == gunner _vehicle && {getNumber (configFile >> 'CfgVehicles' >> (typeOf _vehicle) >> 'AGM_FCSEnabled') == 1}";
    statement = "[_vehicle, 50] call AGM_FCS_fnc_adjustRange";
    key = 201;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class adjustRangeDown: adjustRangeUp {
    displayName = "$STR_AGM_FireControlSystem_AdjustRangeDown";
    statement = "[_vehicle, -50] call AGM_FCS_fnc_adjustRange";
    key = 209;
  };
};

class CfgVehicles {
  class All;
  class AllVehicles: All {
    class NewTurret;
    AGM_FCSEnabled = 0;
    AGM_FCSMinDistance = 200;
    AGM_FCSMaxDistance = 9990;
    AGM_FCSDistanceInterval = 5;

    class AGM_SelfActions {
      class AGM_LeaveGroup {
        displayName = "$STR_AGM_FireControlSystem_ResetFCS";
        condition = "(count (vehicle player getVariable ['AGM_FCSMagazines', []]) > 1) and (player == gunner (vehicle player))";
        statement = "[vehicle player] call AGM_FCS_fnc_reset;";
        showDisabled = 0;
        priority = -1;
      };
    };
  };

  class Land: AllVehicles {};
  class LandVehicle: Land {};
  class Tank: LandVehicle {
    AGM_FCSEnabled = 1; // all tracked vehicles get one by default
  };
  class Tank_F: Tank {
    class Turrets {
      class MainTurret: NewTurret {};
    };
  };
  class Car: LandVehicle {};
  class Car_F: Car {};
  class Wheeled_APC_F: Car_F {
    class Turrets;
  };
  class Helicopter;
  class Helicopter_Base_F: Helicopter {
    class Turrets;
  };

  // REMOVE STANDARD ZEROING FOR AFFECTED VEHICLES

  // BLUFOR Inheritance
  class MBT_01_base_F: Tank_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
    };
  };
  class B_MBT_01_base_F: MBT_01_base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
    };
  };
  class B_MBT_01_mlrs_base_F;
  class B_MBT_01_arty_base_F;

  class APC_Tracked_01_base_F: Tank_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
    };
  };
  class B_APC_Tracked_01_base_F: APC_Tracked_01_base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
    };
  };

  class APC_Wheeled_01_base_F: Wheeled_APC_F {
    class Turrets: Turrets {
      class MainTurret;
    };
  };
  class B_APC_Wheeled_01_base_F: APC_Wheeled_01_base_F {};

  class Heli_Attack_01_base_F: Helicopter_Base_F {
    class Turrets: Turrets {
      class MainTurret;
    };
  };

  // Independent Inheritance
  class MBT_03_base_F: Tank_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
    };
  };
  class I_MBT_03_base_F: MBT_03_base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
    };
  };

  class APC_Wheeled_03_base_F: Wheeled_APC_F {
    class Turrets: Turrets {
      class MainTurret;
    };
  };
  class I_APC_Wheeled_03_base_F: APC_Wheeled_03_base_F {};

  class APC_Tracked_03_base_F: Tank_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
    };
  };
  class I_APC_tracked_03_base_F: APC_Tracked_03_base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
    };
  };

  // OPFOR Inheritance
  class MBT_02_base_F: Tank_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
    };
  };
  class O_MBT_02_base_F: MBT_02_base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
    };
  };
  class O_MBT_02_arty_base_F;

  class APC_Tracked_02_base_F: Tank_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        discreteDistance[] = {};
        discreteDistanceInitIndex = 0;
      };
    };
  };
  class O_APC_Tracked_02_base_F: APC_Tracked_02_base_F {};

  class Heli_Attack_02_base_F: Helicopter_Base_F {
    class Turrets: Turrets {
      class MainTurret;
    };
  };

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
    AGM_FCSEnabled = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        discreteDistance[] = {};
        discreteDistanceInitIndex = 0;
      };
    };
  };
  class B_MBT_01_arty_F: B_MBT_01_arty_base_F {
    AGM_FCSEnabled = 0;
  };
  class B_MBT_01_mlrs_F: B_MBT_01_mlrs_base_F {
    AGM_FCSEnabled = 0;
  };
  class B_APC_Tracked_01_rcws_F: B_APC_Tracked_01_base_F {
    AGM_FCSEnabled = 0;
  };
  class B_APC_Tracked_01_CRV_F: B_APC_Tracked_01_base_F {
    AGM_FCSEnabled = 0;
  };
  class B_Heli_Attack_01_F: Heli_Attack_01_base_F {
    AGM_FCSEnabled = 1;
    AGM_FCSMinDistance = 200;
    AGM_FCSMaxDistance = 9990;
    AGM_FCSDistanceInterval = 5;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        discreteDistance[] = {};
        discreteDistanceInitIndex = 0;
      };
    };
  };

  // Independent
  class I_MBT_03_cannon_F: I_MBT_03_base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        discreteDistance[] = {};
        discreteDistanceInitIndex = 0;
      };
    };
  };
  class I_APC_tracked_03_cannon_F: I_APC_tracked_03_base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        discreteDistance[] = {};
        discreteDistanceInitIndex = 0;
      };
    };
  };
  class I_APC_Wheeled_03_cannon_F: I_APC_Wheeled_03_base_F {
    AGM_FCSEnabled = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        discreteDistance[] = {};
        discreteDistanceInitIndex = 0;
      };
    };
  };

  // OPFOR
  class O_MBT_02_cannon_F: O_MBT_02_base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        discreteDistance[] = {};
        discreteDistanceInitIndex = 0;
      };
    };
  };
  /*
  class O_APC_Tracked_02_cannon_F: O_APC_Tracked_02_base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        discreteDistance[] = {};
        discreteDistanceInitIndex = 0;
      };
    };
  };*/
  class O_APC_Tracked_02_cannon_F: O_APC_Tracked_02_base_F {};
  class O_APC_Tracked_02_AA_F: O_APC_Tracked_02_base_F {};
  class O_MBT_02_arty_F: O_MBT_02_arty_base_F {
    AGM_FCSEnabled = 0;
  };
  class O_Heli_Attack_02_F: Heli_Attack_02_base_F {
    AGM_FCSEnabled = 1;
    AGM_FCSMinDistance = 200;
    AGM_FCSMaxDistance = 9990;
    AGM_FCSDistanceInterval = 5;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        discreteDistance[] = {};
        discreteDistanceInitIndex = 0;
      };
    };
  };
  class O_Heli_Attack_02_black_F: Heli_Attack_02_base_F {
    AGM_FCSEnabled = 1;
    AGM_FCSMinDistance = 200;
    AGM_FCSMaxDistance = 9990;
    AGM_FCSDistanceInterval = 5;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        discreteDistance[] = {};
        discreteDistanceInitIndex = 0;
      };
    };
  };
};
