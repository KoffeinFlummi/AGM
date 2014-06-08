class CfgPatches {
  class AGM_Wind {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, A3_Anims_F};
    version = "0.9";
    versionStr = "0.9";
    versionAr[] = {0,9,0};
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_Wind {
    class AGM_Wind {
      file = "AGM_Wind\functions";
      class firedEH;
      class init;
    };
  };
};

class Extended_Init_EventHandlers {
  class CAManBase {
    class AGM_Wind {
      init = "_this call AGM_Wind_fnc_init";
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Wind {
    Init = "if (isServer && {call AGM_Core_fnc_isAutoWind}) then {setWind [wind select 0, wind select 1, true]};";
  };
};

class Extended_Fired_EventHandlers {
  class CAManBase {
    class AGM_Wind {
      clientFired = "_this call AGM_Wind_fnc_firedEH";
    };
  };
};