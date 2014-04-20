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
      class getAngle;
    };
  };
};

class Extended_Init_EventHandlers {
  class CAManBase {
    class BWA3_FCS {
      init = "_this call BWA3_FCS_fnc_init";
    };
  };
};

class Extended_FiredBIS_EventHandlers {
  class CAManBase {
    class BWA3_FCS {
      clientFiredBISPlayer = "_this spawn BWA3_FCS_fnc_firedEH";
    };
  };
};