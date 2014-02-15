// PATCH CONFIG
class CfgPatches {
  class BWA3_Resting {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {Extended_EventHandlers};
    version = 1.0;
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgMods {
  class BWA3_Resting {
    dir = "BWA3_Resting";
    name = "BWA3: Resting Module";
    picture = "";
    hidePicture = "true";
    hideName = "true";
    actionName = "Github";
    action = "https://github.com/KoffeinFlummi/BWA3_Realism";
  };
};

class CfgFunctions {
  class BWA3_Resting {
    class BWA3_Resting {
      file = "BWA3_Resting\functions";
      class keyInput {};
      class restWeapon {};
      class unRestWeapon {};
    };
  };
};

class Extended_PostInit_EventHandlers {
  class BWA3_Resting {
    clientInit = "call compile preProcessFileLineNumbers '\BWA3_Resting\init.sqf'";
  };
};