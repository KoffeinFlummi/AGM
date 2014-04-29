class CfgPatches {
  class AGM_Hash {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {Extended_EventHandlers};
    version = 1.0;
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_Hash {
    class AGM_Hash {
        file = "\AGM_hash\functions";
      class getHash {};
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Hash {
    clientInit = "execVM '\AGM_hash\init.sqf'";
  };
};
