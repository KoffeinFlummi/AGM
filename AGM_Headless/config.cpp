class CfgPatches {
  class AGM_Headless {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.94.1";
    versionStr = "0.94.1";
    versionAr[] = {0,94,1};
    author[] = {"commy2"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_Headless {
    class AGM_Headless {
      file = "\AGM_Headless\functions";
      class getData;
      class logLongString;
      class spawnGroups;
    };
  };
};
