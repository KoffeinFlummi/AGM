class CfgPatches {
  class AGM_NightVision {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, Extended_EventHandlers};
    version = 1.0;
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_NightVision {
    class AGM_NightVision {
        file = "\AGM_nightvision\functions";
      class convertKeyCode {};
      class increaseBrightness {};
      class decreaseBrightness {};
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_NightVision {
    clientInit = "execVM '\AGM_nightvision\init.sqf'";
  };
};
