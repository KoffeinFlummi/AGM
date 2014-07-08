class CfgPatches {
  class AGM_Respawn {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"jodav"};
    authorUrl = "https://github.com/jodav/";
  };
};

class CfgFunctions {
  class AGM_Respawn {
    class AGM_Respawn {
      file = "AGM_Respawn\functions";
      class getAllGear;
      class restoreGear;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Respawn {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_Respawn\clientInit.sqf'";
  };
};