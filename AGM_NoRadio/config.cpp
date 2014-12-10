class CfgPatches {
  class AGM_NoRadio {
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

class Extended_PostInit_EventHandlers {
    class AGM_NoRadio {
        clientInit = "call compile preprocessFileLineNumbers '\AGM_NoRadio\clientInit.sqf'";
        serverInit = "call compile preprocessFileLineNumbers '\AGM_NoRadio\serverInit.sqf'";
    };
};
