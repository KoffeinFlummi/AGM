class CfgPatches {
  class AGM_Overheating {
    units[] = {};
    weapons[] = {"AGM_SpareBarrel"};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction};
    version = "0.931";
    versionStr = "0.931";
    versionAr[] = {0,931,0};
    author[] = {"commy2", "KoffeinFlummi", "CAA-Picard"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_Overheating {
    class AGM_Overheating {
      file = "\AGM_Overheating\functions";
      class checkTemperature;
      class clearJam;
      class jamWeapon;
      class overheat;
      class swapBarrel;
      class swapBarrelCallback;
    };
  };
};

class Extended_Fired_EventHandlers {
  class CAManBase {
    class AGM_Overheating {
      clientFired = "if (player == _this select 0) then {_this call AGM_Overheating_fnc_overheat};";
    };
  };
};

class Extended_Take_EventHandlers {
  class CAManBase {
    class AGM_UnjamReload {
      clientTake = "if (player == _this select 0 && {player == _this select 1} && {_this select 2 == currentMagazine player} && {_this select 2 in [primaryWeaponMagazine player select 0, secondaryWeaponMagazine player select 0, handgunMagazine player select 0]}) then {_vehicle = vehicle player; [_vehicle, currentWeapon _vehicle, true] call AGM_Overheating_fnc_clearJam};";
    };
  };
};

class AGM_Core_Default_Keys {
  /*class checkTemperature {
    displayName = "$STR_AGM_Overheating_checkTemperature";
    condition = "player == _vehicle";
    statement = "[currentWeapon player] call AGM_Overheating_fnc_CheckTemperature";
    key = 20;
    shift = 0;
    control = 1;
    alt = 0;
  };*/
  class clearJam {
    displayName = "$STR_AGM_Overheating_UnjamWeapon";
    condition = "player == _vehicle && {currentWeapon _vehicle in (_vehicle getVariable ['AGM_Overheating_jammedWeapons', []])}";
    statement = "[_vehicle, currentWeapon _vehicle, false] call AGM_Overheating_fnc_clearJam";
    key = 19;
    shift = 1;
    control = 0;
    alt = 0;
  };
};

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
		icon = "AGM_Overheating\UI\spare_barrel_ca.paa";
      };
      class AGM_CheckTemperature {
        displayName = "$STR_AGM_Overheating_CheckTemperatureShort";
        condition = "!(currentWeapon player in ['', ([player] call AGM_Core_fnc_getBinocular)])";
        statement = "[currentWeapon player] call AGM_Overheating_fnc_CheckTemperature";
        showDisabled = 0;
        priority = 3.1;
		icon = "AGM_Overheating\UI\temp_ca.paa";
      };
    };
  };

  class ReammoBox_F;
  class NATO_Box_Base;
  class EAST_Box_Base;
  class IND_Box_Base;
  class FIA_Box_Base_F;

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

  class Box_FIA_Support_F: FIA_Box_Base_F {
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

  class AGM_Box_Misc: Box_NATO_Support_F {
    class TransportItems {
      MACRO_ADDITEM(AGM_SpareBarrel,6)
    };
  };

  // Add AGM_SpareBarrel to every machine gunner.
  #define MACRO_ADDSPAREBARREL \
    items[] = {"FirstAidKit","AGM_SpareBarrel"}; \
    respawnitems[] = {"FirstAidKit","AGM_SpareBarrel"};

  // NATO
  class B_Soldier_base_F; class B_soldier_AR_F:B_Soldier_base_F {MACRO_ADDSPAREBARREL};
  class B_Soldier_support_base_F; class B_soldier_AAR_F:B_Soldier_support_base_F {MACRO_ADDSPAREBARREL};
  class B_CTRG_soldier_AR_A_F:B_Soldier_base_F {MACRO_ADDSPAREBARREL};

  // Guerrilla
  class I_G_Soldier_base_F; class I_G_Soldier_AR_F:I_G_Soldier_base_F {MACRO_ADDSPAREBARREL};
  class B_G_Soldier_AR_F:I_G_Soldier_AR_F {MACRO_ADDSPAREBARREL};
  class O_G_Soldier_AR_F:I_G_Soldier_AR_F {MACRO_ADDSPAREBARREL};

  // Iran
  class O_Soldier_base_F; class O_Soldier_AR_F:O_Soldier_base_F {MACRO_ADDSPAREBARREL};
  class O_Soldier_support_base_F; class O_Soldier_AAR_F:O_Soldier_support_base_F {MACRO_ADDSPAREBARREL};
  class O_Soldier_Urban_base; class O_soldierU_AR_F:O_Soldier_Urban_base {MACRO_ADDSPAREBARREL};
  class O_soldierU_AAR_F:O_Soldier_Urban_base {MACRO_ADDSPAREBARREL};

  // Czech
  class I_Soldier_base_F; class I_Soldier_AR_F:I_Soldier_base_F {MACRO_ADDSPAREBARREL};
  class I_Soldier_support_base_F; class I_Soldier_AAR_F:I_Soldier_support_base_F {MACRO_ADDSPAREBARREL};
};

#include <WeaponReliability.hpp>

class CfgWeapons {
  class AGM_ItemCore;
  class InventoryItem_Base_F;

  class AGM_SpareBarrel: AGM_ItemCore {
    displayname = "$STR_AGM_Overheating_SpareBarrelName";
    descriptionshort = "$STR_AGM_Overheating_SpareBarrelDescription";
    //model = "";
    picture = "\AGM_Overheating\UI\spare_barrel_ca.paa";
    scope = 2;
    class ItemInfo: InventoryItem_Base_F {
      mass = 10;
    };
  };

  class Rifle;
  class Rifle_Base_F : Rifle {
    AGM_Jamming_Reliability = 0.004;    // 40 malfunctions on 10,000 rounds fired.
    AGM_Overheating_Increment = 0.012;  // How much the weapon heats up for every shot. Max temperature is 3. 250 shots for max temp.
    AGM_Overheating_Cooldown = 0.002;   // How fast the weapon cools down every second. 1500 seconds / 25 minutes for a complete cooldown from max temp.
    AGM_Overheating_Dispersion = 0.001;
  };

  class Rifle_Long_Base_F : Rifle_Base_F {
    AGM_Jamming_Reliability = 0.003;    // 30 malfunctions on 10,000 rounds fired.
    AGM_Overheating_Increment = 0.01;   // 300 shots for max temp.
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.002;
  };

  class arifle_MX_Base_F : Rifle_Base_F {
    AGM_clearJamAction = "GestureReloadMX";   // Custom jam clearing action. Default uses reload animation
    AGM_Jamming_Reliability = AGM_RELIABILITY_MX;
    AGM_Overheating_Increment = 0.012;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.001;
  };

  class arifle_MX_SW_F : arifle_MX_Base_F {
    AGM_clearJamAction = "";                 // Custom jam clearing action. Use empty string to undefine.
    AGM_Jamming_Reliability = AGM_RELIABILITY_MX_SW;
    AGM_Overheating_allowSwapBarrel = 1;  // This weapon can use spare barrels.
    AGM_Overheating_Increment = 0.01;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.002;
  };

  class arifle_Katiba_Base_F : Rifle_Base_F {
    AGM_Jamming_Reliability = AGM_RELIABILITY_KATIBA;
    AGM_Overheating_Increment = 0.012;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.001;
  };

  class mk20_base_F : Rifle_Base_F {
    AGM_Jamming_Reliability = AGM_RELIABILITY_F2000A;
    AGM_Overheating_Increment = 0.012;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.001;
  };

  class Tavor_base_F : Rifle_Base_F {
    AGM_Jamming_Reliability = AGM_RELIABILITY_TAR;
    AGM_Overheating_Increment = 0.012;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.001;
  };

  class SDAR_base_F : Rifle_Base_F {
    AGM_Jamming_Reliability = AGM_RELIABILITY_SDAR;
    AGM_Overheating_Increment = 0.012;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.001;
  };

  class EBR_base_F : Rifle_Long_Base_F {
    AGM_Jamming_Reliability = AGM_RELIABILITY_EBR;
    AGM_Overheating_Increment = 0.012;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.001;
  };

  class DMR_01_base_F : Rifle_Long_Base_F {
    AGM_Jamming_Reliability = AGM_RELIABILITY_RAHIM;
    AGM_Overheating_Increment = 0.012;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.001;
  };

  class GM6_base_F : Rifle_Long_Base_F {
    AGM_Jamming_Reliability = AGM_RELIABILITY_LYNX;
    AGM_Overheating_Increment = 0.012;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.001;
  };

  class LRR_base_F : Rifle_Long_Base_F {
    AGM_Jamming_Reliability = AGM_RELIABILITY_M200;
    AGM_Overheating_Increment = 0.012;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.001;
  };

  class LMG_Mk200_F : Rifle_Long_Base_F {
    AGM_Jamming_Reliability = AGM_RELIABILITY_MK200;
    AGM_Overheating_allowSwapBarrel = 1;
    AGM_Overheating_Increment = 0.01;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.002;
  };

  class LMG_Zafir_F : Rifle_Long_Base_F {
    AGM_Jamming_Reliability = AGM_RELIABILITY_NEGEV;
    AGM_Overheating_allowSwapBarrel = 1;
    AGM_Overheating_Increment = 0.01;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.002;
  };

  class SMG_01_Base : Rifle_Base_F {
    AGM_Jamming_Reliability = AGM_RELIABILITY_VECTOR;
    AGM_Overheating_Increment = 0.015;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.004;
  };

  class SMG_02_base_F : Rifle_Base_F {
    AGM_Jamming_Reliability = AGM_RELIABILITY_SCORPION;
    AGM_Overheating_Increment = 0.015;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.004;
  };

  class pdw2000_base_F : Rifle_Base_F {
    AGM_Jamming_Reliability = AGM_RELIABILITY_CPWCZ;
    AGM_Overheating_Increment = 0.015;
    AGM_Overheating_Cooldown = 0.002;
    AGM_Overheating_Dispersion = 0.004;
  };
};
