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
  };
};

class RadioProtocolBase {
  class CuratorWaypointPlaced;
  class CuratorWaypointPlacedAttack;
  class CuratorObjectPlaced;
  class curatorObjectDestroyed;
  class curatorModuleCAS;
};

class CfgVoice {
  class Base;
  class ENG: Base {
    protocol = "RadioProtocolBase";
  };
  class ENGB: Base {
    protocol = "RadioProtocolBase";
  };
  class ENVR: Base {
    protocol = "RadioProtocolBase";
  };
  class GRE: Base {
    protocol = "RadioProtocolBase";
  };
  class PER: Base {
    protocol = "RadioProtocolBase";
  };
};
