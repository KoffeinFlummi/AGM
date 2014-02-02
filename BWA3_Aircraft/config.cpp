class CfgPatches {
  class BWA3_Aircraft {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, A3_Anims_F};
    version = 1.0;
    author[] = {"KoffeinFLummi"};
    authorUrl = "http://www.bwmod.de";
  };
};

class CfgMods {
  class BWA3_Aircraft {
    dir = "BWA3_Aircraft";
    name = "BWA3: Aircraft Module";
    picture = "";
    hidePicture = "true";
    hideName = "true";
    actionName = "Website";
    action = "http://www.bwmod.de";
  };
};

class Mode_Burst;

// Manual Switching Of Flare Mode
class CfgWeapons {
  class SmokeLauncher;

  class CMFlareLauncher: SmokeLauncher {
    modes[] = {"Single", "Burst", "AIBurst"};
    class Burst: Mode_Burst {
      displayName = "Burst";
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
    gearRetracting = 0;
    class AnimationSources: AnimationSources {
      class RearRightCover {
        source = "::gear";
        initPhase = 1;
        animPeriod = 1;
      };
      class RearLeftCover {
        source = "::gear";
        initPhase = 1;
        animPeriod = 1;
      };
      class RightGear {
        source = "::gear";
        initPhase = 1;
        animPeriod = 1;
      };
      class LeftGear {
        source = "::gear";
        initPhase = 1;
        animPeriod = 1;
      };
      class RightGear_hide {
        source = "::gear";
        initPhase = 1;
        animPeriod = 1;
      };
      class LeftGear_hide {
        source = "::gear";
        initPhase = 1;
        animPeriod = 1;
      };
    };
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
      class CopilotTurret: CopilotTurret {};
      class RightDoorGun;
    };

  };

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

  // -------- //

  // BLUFOR
  class B_Heli_Attack_01_F: Heli_Attack_01_base_F {
    displayName = "RAH-66 Comanche";
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
    displayName = "MH-6 Little Bird";
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {
        canEject = 1;
      };
    };
  };
  class B_Heli_Light_01_armed_F: Heli_Light_01_armed_base_F {
    displayName = "AH-6 Little Bird";
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {
        canEject = 1;
      };
    };
  };

  // INDEP
  class I_Heli_light_03_F: I_Heli_light_03_base_F {
    displayName = "AW159 Wildcat";
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        canEject = 1;
      };
    };
  };
  class I_Heli_light_03_unarmed_F: I_Heli_light_03_unarmed_base_F {
    displayName = "AW159 Wildcat (unarmed)";
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        canEject = 1;
      };
    };
  };
  class I_Heli_Transport_02_F: Heli_Transport_02_base_F {
    displayName = "AW101 Merlin";
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
    displayName = "L-39 Albatros (CAS)";
    lockDetectionSystem = 16;
  };
  class I_Plane_Fighter_03_AA_F: I_Plane_Fighter_03_CAS_F {
    displayName = "L-39 Albatros (AA)";
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
    displayName = "Ka-60 Kasatka";
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
    displayName = "Ka-60 Kasatka (unarmed)";
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
};