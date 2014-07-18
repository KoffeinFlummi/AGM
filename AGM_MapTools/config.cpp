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

class CfgWeapons {
  class ItemCore;
  class InventoryItem_Base_F;

  class AGM_MapTool_Item: ItemCore {
    displayName = "$STR_AGM_MapTool_Name";
    descriptionShort = "$STR_AGM_MapTool_Description";
    model = "\A3\weapons_F\ammo\mag_univ.p3d";
    picture = "\AGM_MapTools\UI\maptool_item.paa";
    scope = 2;
    class ItemInfo: InventoryItem_Base_F {
      mass = 1;
      type = 401;
    };
  };
};

#define MACRO_ADDITEM(ITEM,COUNT) class _xx_##ITEM { \
  name = #ITEM; \
  count = COUNT; \
};

class CfgVehicles {
  class NATO_Box_Base;
  class EAST_Box_Base;
  class IND_Box_Base;

  class Box_NATO_Support_F: NATO_Box_Base {
    class TransportItems {
      MACRO_ADDITEM(AGM_MapTool_Item,12)
    };
  };

  class Box_East_Support_F: EAST_Box_Base {
    class TransportItems {
      MACRO_ADDITEM(AGM_MapTool_Item,12)
    };
  };

  class Box_IND_Support_F: IND_Box_Base {
    class TransportItems {
      MACRO_ADDITEM(AGM_MapTool_Item,12)
    };
  };

  class AGM_Box_Misc: Box_NATO_Support_F {
    class TransportItems {
      MACRO_ADDITEM(AGM_MapTool_Item,24)
    };
  };
};
