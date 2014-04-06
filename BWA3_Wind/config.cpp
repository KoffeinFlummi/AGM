class CfgPatches {
  class BWA3_Wind {
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
  class BWA3_Wind {
    class BWA3_Wind {
      file = "BWA3_Wind\functions";
      class firedEH;
      class init;
    };
  };
};

class Extended_Init_EventHandlers {
  class CAManBase {
    class BWA3_Wind {
      init = "_this call BWA3_Wind_fnc_init";
    };
  };
};

class Extended_FiredBIS_EventHandlers {
  class CAManBase {
    class BWA3_Wind {
      clientFiredBISPlayer = "_this spawn BWA3_Wind_fnc_firedEH";
    };
  };
};