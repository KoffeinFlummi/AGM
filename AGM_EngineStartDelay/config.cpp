class CfgPatches {
  class AGM_EngineStartDelay {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {Extended_EventHandlers};
    version = "0.91";
    versionStr = "0.91";
    versionAr[] = {0,91,0};
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
