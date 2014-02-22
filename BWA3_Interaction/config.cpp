class CfgPatches {
  class BWA3_Interaction {
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
  class BWA3_Interaction {
    dir = "BWA3_Interaction";
    name = "BWA3: Interaction Module";
    picture = "";
    hidePicture = "true";
    hideName = "true";
    actionName = "Github";
    action = "https://github.com/KoffeinFlummi/BWA3_Realism";
  };
};

class Extended_PostInit_EventHandlers {
  class BWA3_Interaction {
    Init = "call compile preProcessFileLineNumbers '\BWA3_Interaction\init.sqf'";
  };
};
