class CfgPatches {
  class BWA3_Goggles {
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
  class BWA3_Goggles {
    dir = "BWA3_Goggles";
    name = "BWA3: Goggles Module";
    picture = "";
    hidePicture = "true";
    hideName = "true";
    actionName = "Github";
    action = "https://github.com/KoffeinFlummi/BWA3_Realism";
  };
};

class CfgFunctions {
  class BWA3_Goggles {
    class BWA3_Goggles {
        file = "\bwa3_goggles\functions";
      class gogglesEffect {};
    };
  };
};

class Extended_PostInit_EventHandlers {
  class BWA3_Goggles {
    clientInit = "execVM '\bwa3_goggles\init.sqf'";
  };
};
