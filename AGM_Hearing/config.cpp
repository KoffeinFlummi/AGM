class CfgPatches {
  class AGM_Hearing {
    units[] = {};
    weapons[] = {"AGM_EarBuds"};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"KoffeinFlummi", "CAA-Picard", "HopeJ", "commy2"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_Hearing {
    class AGM_Hearing {
      file = "AGM_Hearing\functions";
      class earRinging;
      class explosionEH;
      class firedNearEH;
      class putInEarplugs;
      class removeEarplugs;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Hearing {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_Hearing\clientInit.sqf'";
  };
};

/*class AGM_Core_Default_Keys {
  class Earplugs {
    displayName = "$STR_AGM_Hearing_Earbuds_On";
    condition = "alive player && {!(player getVariable ['AGM_Unconscious', false])}";
    statement = "[] call AGM_Hearing_fnc_Earplugs";
    key = 18;
    shift = 0;
    control = 0;
    alt = 1;
  };
};*/

#define MACRO_ADDITEM(ITEM,COUNT) class _xx_##ITEM { \
  name = #ITEM; \
  count = COUNT; \
};

class CfgVehicles {
  class Man;
  class CAManBase: Man {
    class AGM_SelfActions {
      class AGM_PutInEarplugs {
        displayName = "$STR_AGM_Hearing_Earbuds_On";
        condition = "!AGM_EarPlugsIn && {'AGM_EarBuds' in items player} && {alive player} && {!(player getVariable ['AGM_Unconscious', false])}";
        statement = "call AGM_Hearing_fnc_putInEarplugs";
        showDisabled = 0;
        priority = 2.5;
      };
      class AGM_RemoveEarplugs {
        displayName = "$STR_AGM_Hearing_Earbuds_Off";
        condition = "AGM_EarPlugsIn && {alive player} && {!(player getVariable ['AGM_Unconscious', false])}";
        statement = "call AGM_Hearing_fnc_removeEarplugs";
        showDisabled = 0;
        priority = 2.5;
      };
    };
  };

  class NATO_Box_Base;
  class EAST_Box_Base;
  class IND_Box_Base;
  class ReammoBox_F;

  class Box_NATO_Support_F: NATO_Box_Base {
    class TransportItems {
      MACRO_ADDITEM(AGM_EarBuds,12)
    };
  };

  class B_supplyCrate_F: ReammoBox_F {
    class TransportItems {
      MACRO_ADDITEM(AGM_EarBuds,12)
    };
  };

  class Box_East_Support_F: EAST_Box_Base {
    class TransportItems {
      MACRO_ADDITEM(AGM_EarBuds,12)
    };
  };

  class O_supplyCrate_F: B_supplyCrate_F {
    class TransportItems {
      MACRO_ADDITEM(AGM_EarBuds,12)
    };
  };

  class Box_IND_Support_F: IND_Box_Base {
    class TransportItems {
      MACRO_ADDITEM(AGM_EarBuds,12)
    };
  };

  class I_supplyCrate_F: B_supplyCrate_F {
    class TransportItems {
      MACRO_ADDITEM(AGM_EarBuds,12)
    };
  };

  class IG_supplyCrate_F: ReammoBox_F {
    class TransportItems {
      MACRO_ADDITEM(AGM_EarBuds,12)
    };
  };

  class C_supplyCrate_F: ReammoBox_F {
    class TransportItems {
      MACRO_ADDITEM(AGM_EarBuds,12)
    };
  };

  class AGM_Box_Misc: Box_NATO_Support_F {
    class TransportItems {
      MACRO_ADDITEM(AGM_EarBuds,24)
    };
  };
};

class CfgSounds {
  class AGM_EarRinging_Weak {
    sound[] = {"\AGM_Hearing\sounds\agm_earringing_weak.wav",8,1.7};
    titles[] = {};
  };
  class AGM_EarRinging_Medium {
    sound[] = {"\AGM_Hearing\sounds\agm_earringing_medium.wav",8,1.7};
    titles[] = {};
  };
  class AGM_EarRinging_Heavy {
    sound[] = {"\AGM_Hearing\sounds\agm_earringing_heavy.wav",8,1.7};
    titles[] = {};
  };
};

class CfgWeapons {
  class ItemCore;
  class InventoryItem_Base_F;

  class AGM_EarBuds: ItemCore {
    displayName = "$STR_AGM_Hearing_Earbuds_Name";
    descriptionShort = "$STR_AGM_Hearing_Earbuds_Description";
    model = "\AGM_Hearing\agm_earplugs.p3d";
    picture = "\AGM_Hearing\UI\agm_earplugs_x_ca.paa";
    scope = 2;
    class ItemInfo: InventoryItem_Base_F {
      mass = 1;
      type = 401;
    };
  };
};
