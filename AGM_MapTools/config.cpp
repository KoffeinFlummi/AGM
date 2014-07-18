class CfgPatches {
  class AGM_Map {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"CAA-Picard"};
    authorUrl = "https://github.com/esteldunedain/";
  };
};

class CfgFunctions {
  class AGM_MapTools {
    class AGM_MapTools {
      file = "AGM_MapTools\functions";
      class handleMouseButton;
      class handleMouseMove;
      class isInsideMapTool;
      class updateMapToolMarkers;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_MapTools {
    clientInit = "call compile preprocessFileLineNumbers 'AGM_MapTools\clientInit.sqf'";
  };
};

// MARKERS
class CfgMarkers {

  class MapToolFixed {
    name = "MapToolFixed";
    icon = "\AGM_MapTools\data\mapToolFixed.paa";
    scope = 0;
    color[] = {1,1,1,1};
    size = 32;
  };

  class MapToolRotating {
    name = "MapToolRotating";
    icon = "\AGM_MapTools\data\mapToolRotating.paa";
    scope = 0;
    color[] = {1,1,1,1};
    size = 32;
  };
};
