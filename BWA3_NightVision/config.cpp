class CfgPatches {
  class BWA3_NightVision {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, Extended_EventHandlers};
    version = 1.0;
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgMods {
  class BWA3_NightVision {
    dir = "BWA3_NightVision";
    name = "BWA3: Night Vision Module";
    picture = "";
    hidePicture = "true";
    hideName = "true";
    actionName = "Github";
    action = "https://github.com/KoffeinFlummi/BWA3_Realism";
  };
};

class CfgFunctions {
  class BWA3_NightVision {
    class BWA3_NightVision {
        file = "\bwa3_nightvision\functions";
      class increaseBrightness {};
      class decreaseBrightness {};
    };
  };
};

class Extended_PostInit_EventHandlers {
  class BWA3_NightVision {
    clientInit = "execVM '\bwa3_nightvision\init.sqf'";
  };
};
