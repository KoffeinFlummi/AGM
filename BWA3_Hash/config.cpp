class CfgPatches {
  class BWA3_Hash {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {Extended_EventHandlers};
    version = 1.0;
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgMods {
  class BWA3_Hash {
    dir = "BWA3_Hash";
    name = "BWA3: Hash Module";
    picture = "";
    hidePicture = "true";
    hideName = "true";
    actionName = "Github";
    action = "https://github.com/KoffeinFlummi/BWA3_Realism";
  };
};

class CfgFunctions {
  class BWA3_Hash {
    class BWA3_Hash {
        file = "\bwa3_hash\functions";
      class getHash {};
    };
  };
};

class Extended_PostInit_EventHandlers {
  class BWA3_Hash {
    clientInit = "execVM '\bwa3_hash\init.sqf'";
  };
};
