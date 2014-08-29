class CfgPatches {
  class AGM_StriderFix {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.931";
    versionStr = "0.931";
    versionAr[] = {0,931,0};
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_StriderFix {
    class AGM_StriderFix {
      file = "AGM_StriderFix\functions";
      class displayAzimuth;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_StriderFix {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_StriderFix\clientInit.sqf'";
  };
};

class CfgVehicles {
  class Car_F;
  class MRAP_03_base_F: Car_F {
    AGM_DisplayType = "Strider";
  };
};

class RscInGameUI {
  class RscOptics_strider_commander {
    onLoad = "uiNamespace setVariable ['AGM_ctrlStrider', (_this select 0) displayCtrl 156]";
  };
};
