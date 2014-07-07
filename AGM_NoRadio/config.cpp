class CfgPatches {
  class AGM_NoRadio {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"commy2"};
    authorUrl = "https://github.com/commy2/";
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_NoRadio {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_NoRadio\clientInit.sqf'";
  };
};

/*
class CfgVoice {
  class Base;
  class ENG: Base {
    protocol = "";
  };
  class ENGB: Base {
    protocol = "";
  };
  class GRE: Base {
    protocol = "";
  };
  class PER: Base {
    protocol = "";
  };
};
*/
