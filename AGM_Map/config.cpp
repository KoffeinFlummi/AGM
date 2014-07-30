class CfgPatches {
  class AGM_Map {
    units[] = {};
    weapons[] = {"AGM_MapTools"};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"KoffeinFlummi","CAA-Picard"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_Map {
    class AGM_Map {
      file = "AGM_Map\functions";
      class blueForceTracking;
      class handleMouseButton;
      class handleMouseMove;
      class isInsideMapTool;
      class updateMapToolMarkers;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Map {
    clientInit = "call compile preprocessFileLineNumbers 'AGM_Map\clientInit.sqf'";
  };
};

class CfgWeapons {
  class ItemCore;
  class InventoryItem_Base_F;

  class AGM_MapTools: ItemCore {
    displayName = "$STR_AGM_MapTools_Name";
    descriptionShort = "$STR_AGM_MapTools_Description";
    model = "\A3\weapons_F\ammo\mag_univ.p3d";
    picture = "\AGM_Map\UI\maptool_item.paa";
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
      MACRO_ADDITEM(AGM_MapTools,12)
    };
  };

  class Box_East_Support_F: EAST_Box_Base {
    class TransportItems {
      MACRO_ADDITEM(AGM_MapTools,12)
    };
  };

  class Box_IND_Support_F: IND_Box_Base {
    class TransportItems {
      MACRO_ADDITEM(AGM_MapTools,12)
    };
  };

  class AGM_Box_Misc: Box_NATO_Support_F {
    class TransportItems {
      MACRO_ADDITEM(AGM_MapTools,24)
    };
  };

  class Module_F;
  class AGM_ModuleBlueForceTracking: Module_F {
    author = "AGM Team";
    category = "AGM";
    displayName = "Blue Force Tracking";
    function = "AGM_Map_fnc_blueForceTracking";
    scope = 2;
    isGlobal = 1;
    icon = "\AGM_Map\UI\IconBFTracking_ca.paa";
    class Arguments {
      class Interval {
        displayName = "Interval";
        description = "How often the markers should be refreshed (in seconds)";
        defaultValue = 1;
      };
    };
  };
};

class RscControlsGroup;
class RscActiveText;
class RscPicture;
class RscText;
class RscObject;

class RscMapControl {
  sizeExGrid = 0.032;
};

// REGULAR MAP
class RscDisplayMainMap {
  // get rid of the "center to player position" - button (as it works even on elite)
  class controls {
    class TopRight: RscControlsGroup {
      class controls {
        class ButtonPlayer: RscActiveText {
          text = "";
          w = 0;
          h = 0;
          sizeEx = 0;
          onButtonClick = "";
        };
        class CA_PlayerName: RscText {
          x = "2 *    ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
        class ProfilePicture: RscPicture {
          x = "13.5 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
        class ProfileBackground: RscText {
          x = "13.3 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
        class Separator1: RscPicture {
          x = "14.5 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
      };
    };
  };
  // scale up the compass
  class objects {
    class Compass: RscObject {
      scale = 0.7;
      zoomDuration = 0;
    };
  };
};

// DIARY
class RscDisplayDiary {
  // get rid of the "center to player position" - button (as it works even on elite)
  class controls {
    class TopRight: RscControlsGroup {
      class controls {
        class ButtonPlayer: RscActiveText {
          text = "";
          w = 0;
          h = 0;
          sizeEx = 0;
          onButtonClick = "";
        };
        class CA_PlayerName: RscText {
          x = "2 *    ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
        class ProfilePicture: RscPicture {
          x = "13.5 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
        class ProfileBackground: RscText {
          x = "13.3 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
        class Separator1: RscPicture {
          x = "14.5 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
      };
    };
  };
  // scale up the compass
  class objects {
    class Compass: RscObject {
      scale = 0.7;
      zoomDuration = 0;
    };
  };
};

// BRIEFING SCREEN
class RscDisplayGetReady: RscDisplayMainMap {
  // get rid of the "center to player position" - button (as it works even on elite)
  class controls {
    class TopRight: RscControlsGroup {
      class controls {
        class ButtonPlayer: RscActiveText {
          text = "";
          w = 0;
          h = 0;
          sizeEx = 0;
          onButtonClick = "";
        };
        class CA_PlayerName: RscText {
          x = "2 *    ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
        class ProfilePicture: RscPicture {
          x = "13.5 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
        class ProfileBackground: RscText {
          x = "13.3 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
        class Separator1: RscPicture {
          x = "14.5 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
      };
    };
  };
  // scale up the compass
  class objects {
    class Compass: RscObject {
      scale = 0.7;
      zoomDuration = 0;
    };
  };
};
class RscDisplayClientGetReady: RscDisplayGetReady {
  // get rid of the "center to player position" - button (as it works even on elite)
  class controls {
    class TopRight: RscControlsGroup {
      class controls {
        class ButtonPlayer: RscActiveText {
          text = "";
          w = 0;
          h = 0;
          sizeEx = 0;
          onButtonClick = "";
        };
        class CA_PlayerName: RscText {
          x = "2 *    ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
        class ProfilePicture: RscPicture {
          x = "13.5 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
        class ProfileBackground: RscText {
          x = "13.3 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
        class Separator1: RscPicture {
          x = "14.5 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
      };
    };
  };
  // scale up the compass
  class objects {
    class Compass: RscObject {
      scale = 0.7;
      zoomDuration = 0;
    };
  };
};
class RscDisplayServerGetReady: RscDisplayGetReady {
  // get rid of the "center to player position" - button (as it works even on elite)
  class controls {
    class TopRight: RscControlsGroup {
      class controls {
        class ButtonPlayer: RscActiveText {
          text = "";
          w = 0;
          h = 0;
          sizeEx = 0;
          onButtonClick = "";
        };
        class CA_PlayerName: RscText {
          x = "2 *    ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
        class ProfilePicture: RscPicture {
          x = "13.5 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
        class ProfileBackground: RscText {
          x = "13.3 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
        class Separator1: RscPicture {
          x = "14.5 * ( ((safezoneW / safezoneH) min 1.2) / 40)";
        };
      };
    };
  };
  // scale up the compass
  class objects {
    class Compass: RscObject {
      scale = 0.7;
      zoomDuration = 0;
    };
  };
};

// MARKERS
class CfgMarkers {
  class Flag;

  class hd_objective: Flag {
    name = "$STR_CFG_MARKERS_dot";
    icon = "\A3\ui_f\data\map\markers\handdrawn\dot_CA.paa";
  };

  class hd_dot: hd_objective {
    name = "$STR_CFG_MARKERS_FLAG";
    icon = "\A3\ui_f\data\map\markers\handdrawn\objective_CA.paa";
  };

  class MapToolFixed {
    name = "MapToolFixed";
    icon = "\AGM_Map\data\mapToolFixed.paa";
    scope = 0;
    color[] = {1,1,1,1};
    size = 32;
  };

  class MapToolRotating {
    name = "MapToolRotating";
    icon = "\AGM_Map\data\mapToolRotating.paa";
    scope = 0;
    color[] = {1,1,1,1};
    size = 32;
  };
};
