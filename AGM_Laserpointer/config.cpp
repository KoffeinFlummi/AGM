class CfgPatches {
  class AGM_Laserpointer {
    units[] = {};
    weapons[] = {"AGM_acc_pointer_red", "AGM_acc_pointer_green"};
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
  class AGM_Laserpointer {
    class AGM_Laserpointer {
      file = "AGM_Laserpointer\functions";
      class drawLaserpoint;
      class onDraw;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Laserpointer {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_Laserpointer\clientInit.sqf';";
  };
};

class SlotInfo;
class PointerSlot: SlotInfo {
  compatibleItems[] += {"AGM_acc_pointer_red","AGM_acc_pointer_green"};
};

class CfgWeapons {
  class ItemCore;
  class InventoryFlashLightItem_Base_F;
  class AGM_acc_pointer_red: ItemCore {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_acc_pointer_red";
    scope = 2;
    displayName = "$STR_AGM_Laserpointer_red";
    descriptionUse = "$STR_AGM_Laserpointer_useLaser";
    picture = "\A3\weapons_F\Data\UI\gear_accv_pointer_CA.paa";
    model = "\A3\weapons_f\acc\accv_pointer_F";
    descriptionShort = "$STR_AGM_Laserpointer_Description";

    class ItemInfo: InventoryFlashLightItem_Base_F {
      mass = 6;

      class Pointer {};

      class FlashLight {
        color[] = {0,0,0};
        ambient[] = {0,0,0};
        intensity = 0;
        size = 0;
        innerAngle = 0;
        outerAngle = 0;
        coneFadeCoef = 5;
        position = "flash dir";
        direction = "flash";
        useFlare = 0;
        flareSize = 0;
        flareMaxDistance = "100.0f";
        dayLight = 0;

        class Attenuation {
          start = 0;
          constant = 0;
          linear = 0;
          quadratic = 0;
          hardLimitStart = 0;
          hardLimitEnd = 0;
        };

        scale[] = {0};
      };
    };

    inertia = 0.1;
  };

  class AGM_acc_pointer_green: AGM_acc_pointer_red {
    author = "$STR_A3_Bohemia_Interactive";
    _generalMacro = "AGM_acc_pointer_green";
    displayName = "$STR_AGM_Laserpointer_green";
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
  class FIA_Box_Base_F;

  class Box_NATO_Support_F: NATO_Box_Base {
    class TransportItems {
      MACRO_ADDITEM(AGM_acc_pointer_red,4)
    };
  };

  class Box_East_Support_F: EAST_Box_Base {
    class TransportItems {
      MACRO_ADDITEM(AGM_acc_pointer_green,4)
    };
  };

  class Box_IND_Support_F: IND_Box_Base {
    class TransportItems {
      MACRO_ADDITEM(AGM_acc_pointer_green,4)
    };
  };

  class Box_FIA_Support_F: FIA_Box_Base_F {
    class TransportItems {
      MACRO_ADDITEM(AGM_acc_pointer_red,4)
    };
  };

  class AGM_Box_Misc: Box_NATO_Support_F {
    class TransportItems {
      MACRO_ADDITEM(AGM_acc_pointer_red,4)
      MACRO_ADDITEM(AGM_acc_pointer_green,4)
    };
  };
};
