class CfgPatches {
  class AGM_Laz0rpointer {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.95";
    versionStr = "0.95";
    versionAr[] = {0,95,0};
    author[] = {"commy2"};
    authorUrl = "https://github.com/commy2";
  };
};

class CfgFunctions {
  class AGM_Laz0rpointer {
    class AGM_Laz0rpointer {
      file = "AGM_Laz0rpointer\functions";
      class drawLaserpoint;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Laz0rpointer {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_Laz0rpointer\clientInit.sqf';";
  };
};

/*class RscPicture;

class RscControlsGroup {
  class VScrollbar;
  class HScrollbar;
};

class RscInGameUI {
  class RscUnitInfo {
    class WeaponInfoControlsGroupLeft: RscControlsGroup {
      class controls {
        class CA_BackgroundWeapon: RscPicture {
          idc = 1713777;
          text = "\a3\weapons_f\acc\data\collimdot_red_ca.paa";
          colorText[] = {1,1,1,1};
          x = 0;
          y = 0;
          w = 0;
          h = 0;
        };
      };
    };
  };
};*/
