class CfgPatches {
  class AGM_NightVision {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, Extended_EventHandlers, AGM_Core};
    version = 1.0;
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_NightVision {
    class AGM_NightVision {
        file = "\AGM_nightvision\functions";
      class increaseNVGBrightness {};
      class decreaseNVGBrightness {};
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_NightVision {
    clientInit = "execVM '\AGM_nightvision\init.sqf'";
  };
};

class AGM_Core_Default_Keys {
  class increaseNVGBrightness {
    displayName = "Increase NVG Brightness";
    key = 201;
    shift = 0;
    control = 1;
    alt = 0;
  };
  class decreaseNVGBrightness {
    displayName = "Decrease NVG Brightness";
    key = 209;
    shift = 0;
    control = 1;
    alt = 0;
  };
};
