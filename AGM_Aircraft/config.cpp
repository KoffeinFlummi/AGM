class CfgPatches {
  class AGM_Aircraft {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {
      A3_Air_F,
      A3_Air_F_Heli_Light_01,
      A3_Air_F_Heli_Light_02,
      A3_Air_F_Beta,
      A3_Air_F_Beta_Heli_attack_01,
      A3_Air_F_Beta_Heli_Attack_02,
      A3_Air_F_Beta_Heli_Transport_01,
      A3_Air_F_Beta_Heli_Transport_02,
      A3_Air_F_Gamma_Plane_Fighter_03,
      A3_Air_F_EPC_Plane_CAS_01,
      A3_Air_F_EPC_Plane_CAS_02,
      A3_Air_F_EPC_Plane_Fighter_03
    };
    version = "0.9";
    versionStr = "0.9";
    versionAr[] = {0,9,0};
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Aircraft {
    clientInit = "execVM '\AGM_aircraft\init.sqf'";
  };
};

/*class AGM_Core_Default_Keys {
  class autopilot {
    displayName = "Autopilot";
    conditionUp = "player == driver _vehicle && {_vehicle isKindOf 'Plane'}";
    statementUp = "[_vehicle] spawn AGM_Aircraft_autopilot";
    key = 211;
    shift = 0;
    control = 0;
    alt = 0;
  };
};*/

class Mode_Burst;

// Manual Switching Of Flare Mode
class CfgWeapons {
  class SmokeLauncher;

  class CMFlareLauncher: SmokeLauncher {
    modes[] = {"Single", "Burst", "AIBurst"};
    class Burst: Mode_Burst {
      displayName = "$STR_AGM_Aircraft_CMFlareLauncher_Burst_Name";
    };
  };
};


class CfgVehicles {
  // Basic Inheritance
  class AllVehicles;
  class Air: AllVehicles {
    class AnimationSources;
    class Turrets;
  };
  class Helicopter: Air {
    class AnimationSources: AnimationSources {};
    class Turrets: Turrets {
      class MainTurret;
    };
  };
  class Helicopter_Base_F: Helicopter {
    class AnimationSources: AnimationSources {};
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
    };
  };
  class Helicopter_Base_H: Helicopter_Base_F {
    class AnimationSources: AnimationSources {};
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
      class CopilotTurret;
    };
  };

  // BLUFOR Inheritance
  class Heli_Attack_01_base_F: Helicopter_Base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
    };
  };
  class Heli_Light_01_base_F: Helicopter_Base_H {
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {};
    };
  };
  class Heli_Light_01_armed_base_F: Heli_Light_01_base_F {
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {};
    };
  };
  class Heli_Transport_01_base_F: Helicopter_Base_H {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
      class CopilotTurret: CopilotTurret {};
      class RightDoorGun;
    };
  };
  class Plane_CAS_01_base_F;

  // INDEP Inheritance
  class I_Heli_light_03_base_F: Helicopter_Base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
    };
  };
  class I_Heli_light_03_unarmed_base_F: I_Heli_light_03_base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
    };
  };
  class Heli_Transport_02_base_F: Helicopter_Base_H {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
      class CopilotTurret: CopilotTurret {};
    };
  };
  class Plane_Fighter_03_base_F;

  // OPFOR Inheritance
  class Heli_Light_02_base_F: Helicopter_Base_H {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
      class CopilotTurret: CopilotTurret {};
    };
  };
  class Heli_Attack_02_base_F: Helicopter_Base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
    };
  };
  class Plane_CAS_02_base_F;

  ////////////////////////////////////////////////////////////

  // BLUFOR
  class B_Heli_Attack_01_F: Heli_Attack_01_base_F {
    displayName = "$STR_AGM_Aircraft_Heli_Attack_01_Name";
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        canEject = 1;
      };
    };
  };
  class B_Heli_Transport_01_F: Heli_Transport_01_base_F {
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        canEject = 1;
      };
      class CopilotTurret: CopilotTurret {
        canEject = 1;
      };
      class RightDoorGun: RightDoorGun {
        canEject = 1;
      };
    };
  };
  class B_Heli_Light_01_F: Heli_Light_01_base_F {
    displayName = "$STR_AGM_Aircraft_Heli_Light_01_Name";
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {
        canEject = 1;
      };
    };
  };
  class B_Heli_Light_01_armed_F: Heli_Light_01_armed_base_F {
    displayName = "$STR_AGM_Aircraft_Heli_Light_01_armed_Name";
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {
        canEject = 1;
      };
    };
  };
  class B_Plane_CAS_01_F: Plane_CAS_01_base_F {
    displayName = "$STR_AGM_Aircraft_Plane_CAS_01_Name";
    lockDetectionSystem = 16;
  };

  // INDEP
  class I_Heli_light_03_F: I_Heli_light_03_base_F {
    displayName = "$STR_AGM_Aircraft_Heli_light_03_Name";
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        canEject = 1;
      };
    };
  };
  class I_Heli_light_03_unarmed_F: I_Heli_light_03_unarmed_base_F {
    displayName = "$STR_AGM_Aircraft_Heli_light_03_unarmed_Name";
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        canEject = 1;
      };
    };
  };
  class I_Heli_Transport_02_F: Heli_Transport_02_base_F {
    displayName = "$STR_AGM_Aircraft_Heli_Transport_02_Name";
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        canEject = 1;
      };
      class CopilotTurret: CopilotTurret {
        canEject = 1;
      };
    };
  };
  class I_Plane_Fighter_03_CAS_F: Plane_Fighter_03_base_F {
    displayName = "$STR_AGM_Aircraft_Plane_Fighter_03_CAS_Name";
    lockDetectionSystem = 16;
  };
  class I_Plane_Fighter_03_AA_F: I_Plane_Fighter_03_CAS_F {
    displayName = "$STR_AGM_Aircraft_Plane_Fighter_03_AA_Name";
  };

  // OPFOR
  class O_Heli_Attack_02_F: Heli_Attack_02_base_F {
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        canEject = 1;
      };
    };
  };
  class O_Heli_Attack_02_black_F: Heli_Attack_02_base_F {
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        canEject = 1;
      };
    };
  };
  class O_Heli_Light_02_F: Heli_Light_02_base_F {
    displayName = "$STR_AGM_Aircraft_Heli_Light_02_Name";
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        canEject = 1;
      };
      class CopilotTurret: CopilotTurret {
        canEject = 1;
      };
    };
  };
  class O_Heli_Light_02_unarmed_F: Heli_Light_02_base_F {
    displayName = "$STR_AGM_Aircraft_Heli_Light_02_unarmed_Name";
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        canEject = 1;
      };
      class CopilotTurret: CopilotTurret {
        canEject = 1;
      };
    };
  };
  class O_Plane_CAS_02_F: Plane_CAS_02_base_F {
    displayName = "$STR_AGM_Aircraft_Plane_CAS_02_Name";
    lockDetectionSystem = 16;
  };
};
