class CfgPatches {
  class AGM_Overheating {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"commy2", "KoffeinFlummi", "CAA-Picard"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_Overheating {
    class AGM_Overheating {
      file = "\AGM_Overheating\functions";
      class checkTemperature;
      class overheat;
      class swapBarrel;
      class swapBarrelCallback;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Overheating {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_Overheating\clientInit.sqf'";
  };
};

class Extended_Fired_EventHandlers {
  class CAManBase {
    class AGM_Overheating {
      clientFired = "if (player == _this select 0) then {_this call AGM_Overheating_fnc_overheat}";
    };
  };
};

/*class AGM_Core_Default_Keys {
  class checkTemperature {
    displayName = "$STR_AGM_Overheating_checkTemperature";
    condition = "player == _vehicle";
    statement = "[currentWeapon player] call AGM_Overheating_fnc_CheckTemperature";
    key = 20;
    shift = 0;
    control = 1;
    alt = 0;
  };
};*/

class CfgSounds {
  class AGM_BarrelSwap {
    sound[] = {"\AGM_Overheating\sounds\barrelswap.ogg", 5, 1, 200};
    titles[] = {};
  };
};


#define MACRO_ADDITEM(ITEM,COUNT) class _xx_##ITEM { \
  name = #ITEM; \
  count = COUNT; \
};

class CfgVehicles {
  class Man;

  class CAManBase: Man {
    class AGM_SelfActions {
      class AGM_SwapBarrel {
        displayName = "$STR_AGM_Overheating_SwapBarrel";
        condition = "'AGM_SpareBarrel' in items player && {getNumber (configFile >> 'CfgWeapons' >> currentWeapon player >> 'AGM_Overheating_allowSwapBarrel') == 1}";
        statement = "[currentWeapon player] call AGM_Overheating_fnc_swapBarrel";
        showDisabled = 0;
        priority = 3;
      };
      class AGM_CheckTemperature {
        displayName = "$STR_AGM_Overheating_CheckTemperatureShort";
        condition = "!(currentWeapon player in ['', ([player] call AGM_Core_fnc_getBinocular)])";
        statement = "[currentWeapon player] call AGM_Overheating_fnc_CheckTemperature";
        showDisabled = 0;
        priority = 3.1;
      };
    };
  };

  class NATO_Box_Base;
  class EAST_Box_Base;
  class IND_Box_Base;
  class ReammoBox_F;

  class Box_NATO_Support_F: NATO_Box_Base {
    class TransportItems {
      MACRO_ADDITEM(AGM_SpareBarrel,2)
    };
  };

  class B_supplyCrate_F: ReammoBox_F {
    class TransportItems {
      MACRO_ADDITEM(AGM_SpareBarrel,2)
    };
  };

  class Box_East_Support_F: EAST_Box_Base {
    class TransportItems {
      MACRO_ADDITEM(AGM_SpareBarrel,2)
    };
  };

  class O_supplyCrate_F: B_supplyCrate_F {
    class TransportItems {
      MACRO_ADDITEM(AGM_SpareBarrel,2)
    };
  };

  class Box_IND_Support_F: IND_Box_Base {
    class TransportItems {
      MACRO_ADDITEM(AGM_SpareBarrel,2)
    };
  };

  class I_supplyCrate_F: B_supplyCrate_F {
    class TransportItems {
      MACRO_ADDITEM(AGM_SpareBarrel,2)
    };
  };

  class IG_supplyCrate_F: ReammoBox_F {
    class TransportItems {
      MACRO_ADDITEM(AGM_SpareBarrel,2)
    };
  };

  class C_supplyCrate_F: ReammoBox_F {
    class TransportItems {
      MACRO_ADDITEM(AGM_SpareBarrel,2)
    };
  };
};

class CfgWeapons {
  class ItemCore;
  class InventoryItem_Base_F;

  class AGM_SpareBarrel: ItemCore {
    displayname = "$STR_AGM_Overheating_SpareBarrelName";
    descriptionshort = "$STR_AGM_Overheating_SpareBarrelDescription";
    //model = "";
    picture = "\AGM_Overheating\UI\spare_barrel_ca.paa";
    scope = 2;
    class ItemInfo: InventoryItem_Base_F {
      mass = 10;
      type = 401;
    };
  };

  class Rifle;
  class Rifle_Base_F : Rifle {
    AGM_Overheating_Increment = 0.012;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.001;
  };

  class Rifle_Long_Base_F : Rifle_Base_F {
    AGM_Overheating_Increment = 0.01;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.002;
  };

  class arifle_MX_Base_F : Rifle_Base_F {
    AGM_Overheating_Increment = 0.012;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.001;
  };

  class arifle_MX_SW_F : arifle_MX_Base_F {
    AGM_Overheating_allowSwapBarrel = 1;
    AGM_Overheating_Increment = 0.01;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.002;
  };

  class arifle_Katiba_Base_F : Rifle_Base_F {
    AGM_Overheating_Increment = 0.012;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.001;
  };

  class mk20_base_F : Rifle_Base_F {
    AGM_Overheating_Increment = 0.012;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.001;
  };

  class Tavor_base_F : Rifle_Base_F {
    AGM_Overheating_Increment = 0.012;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.001;
  };

  class SDAR_base_F : Rifle_Base_F {
    AGM_Overheating_Increment = 0.012;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.001;
  };

  class EBR_base_F : Rifle_Long_Base_F {
    AGM_Overheating_Increment = 0.012;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.001;
  };

  class DMR_01_base_F : Rifle_Long_Base_F {
    AGM_Overheating_Increment = 0.012;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.001;
  };

  class GM6_base_F : Rifle_Long_Base_F {
    AGM_Overheating_Increment = 0.012;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.001;
  };

  class LRR_base_F : Rifle_Long_Base_F {
    AGM_Overheating_Increment = 0.012;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.001;
  };

  class LMG_Mk200_F : Rifle_Long_Base_F {
    AGM_Overheating_allowSwapBarrel = 1;
    AGM_Overheating_Increment = 0.01;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.002;
  };

  /*class LMG_RCWS : MGun {
  };*/

  class LMG_Zafir_F : Rifle_Long_Base_F {
    AGM_Overheating_allowSwapBarrel = 1;
    AGM_Overheating_Increment = 0.01;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.002;
  };

  class SMG_01_Base : Rifle_Base_F {
    AGM_Overheating_Increment = 0.015;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.004;
  };

  class SMG_02_base_F : Rifle_Base_F {
    AGM_Overheating_Increment = 0.015;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.004;
  };

  class pdw2000_base_F : Rifle_Base_F {
    AGM_Overheating_Increment = 0.015;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.004;
  };
};
