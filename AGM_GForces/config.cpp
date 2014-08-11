class CfgPatches {
  class AGM_GForces {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.93";
    versionStr = "0.93";
    versionAr[] = {0,93,0};
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_GForces {
    class AGM_GForces {
      file = "AGM_GForces\functions";
      class init;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_GForces {
    Init = "_this call AGM_GForces_fnc_init";
  };
};

class CfgWeapons {
  class ItemCore;
  class Uniform_Base: ItemCore {
    AGM_GForceCoef = 1;
  };

  class U_B_PilotCoveralls: Uniform_Base {
    AGM_GForceCoef = 0.8;
  };
  class U_I_pilotCoveralls: Uniform_Base {
    AGM_GForceCoef = 0.8;
  };
  class U_O_PilotCoveralls: Uniform_Base {
    AGM_GForceCoef = 0.8;
  };
};

class CfgVehicles {
  class Man;
  class CAManBase: Man {
    AGM_GForceCoef = 1;
  };

  class B_Helipilot_F;
  class B_Pilot_F: B_Helipilot_F {
    AGM_GForceCoef = 0.75;
  };
  class I_helipilot_F;
  class I_pilot_F: I_helipilot_F {
    AGM_GForceCoef = 0.75;
  };
  class O_helipilot_F;
  class O_Pilot_F: O_helipilot_F {
    AGM_GForceCoef = 0.75;
  };
};
