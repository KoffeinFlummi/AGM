class CfgPatches {
  class BWA3_Core {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {};
    version = 1.0;
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgMods {
  class BWA3_Core {
    dir = "BWA3_Core";
    name = "BWA3: Core Module";
    picture = "";
    hidePicture = "true";
    hideName = "true";
    actionName = "Github";
    action = "https://github.com/KoffeinFlummi/BWA3_Realism";
  };
};

class Extended_PostInit_EventHandlers {
  class BWA3_Core {
    init = "call compile preProcessFileLineNumbers '\BWA3_Core\init.sqf'";
  };
};