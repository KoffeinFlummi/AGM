class CfgPatches {
  class AGM_StriderFix {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {Extended_EventHandlers, AGM_Core};
    version = "0.9";
    versionStr = "0.9";
    versionAr[] = {0,9,0};
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_StriderFix {
    clientInit = "execVM '\AGM_StriderFix\init.sqf'";
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
