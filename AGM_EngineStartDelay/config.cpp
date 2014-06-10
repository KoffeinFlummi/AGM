class CfgPatches {
  class AGM_EngineStartDelay {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Dubbing_Radio_F};
    version = "0.9";
    versionStr = "0.9";
    versionAr[] = {0,9,0};
    author[] = {"commy2"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_EngineStartDelay {
    class AGM_EngineStartDelay {
      file = "\AGM_EngineStartDelay\functions";
      class startEngine;
    };
  };
};

class Extended_Engine_EventHandlers {
  class Car {
    class AGM_EngineStartDelay {
      clientEngine = "_this call AGM_EngineStartDelay_fnc_startEngine";
    };
  };
};
