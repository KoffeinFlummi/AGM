class CfgPatches {
  class BWA3_QuickSelect {
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
  class BWA3_QuickSelect {
    dir = "BWA3_QuickSelect";
    name = "BWA3: Quick Select Module";
    picture = "";
    hidePicture = "true";
    hideName = "true";
    actionName = "Github";
    action = "https://github.com/KoffeinFlummi/BWA3_Realism";
  };
};

class Extended_PostInit_EventHandlers {
  class BWA3_QuickSelect {
    Init = "call compile preProcessFileLineNumbers '\BWA3_QuickSelect\init.sqf'";
  };
};
