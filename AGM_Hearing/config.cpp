class CfgPatches {
  class AGM_Hearing {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.9";
    versionStr = "0.9";
    versionAr[] = {0,9,0};
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
      class earplugs;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Hearing {
    clientInit = "execVM '\AGM_Hearing\init.sqf'";
  };
};

class AGM_Core_Default_Keys {
  class Earplugs {
    displayName = "$STR_AGM_Hearing_Earbuds_On";
    condition = "true";
    statement = "[] call AGM_Hearing_fnc_Earplugs";
    key = 18;
    shift = 0;
    control = 0;
    alt = 1;
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
    model = "\A3\weapons_F\ammo\mag_univ.p3d";
    picture = "\AGM_Hearing\UI\bwa3_earplugs_x_ca.paa";
    scope = 2;
    class ItemInfo: InventoryItem_Base_F {
      mass = 1;
      type = 201;
    };
  };
};
