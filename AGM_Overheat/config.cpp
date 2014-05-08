class CfgPatches {
  class AGM_Overheat {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, Extended_EventHandlers, AGM_Core};
    version = 1.0;
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_Overheat {
    class AGM_Overheat {
        file = "\AGM_overheat\functions";
      class firedEH {};
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Overheat {
    clientInit = "execVM '\AGM_overheat\init.sqf'";
  };
};

class Extended_Init_EventHandlers {
  class CAManBase {
    class AGM_giveSpareBarrel {
      Init = "_this spawn {sleep 0.1; if (getNumber (configFile >> 'CfgWeapons' >> currentWeapon player >> 'AGM_Overheat_allowSwapBarrel') == 1) then {(_this select 0) addItem 'AGM_SpareBarrel'}}"; 
    };
  };
};

class Extended_Fired_EventHandlers {
  class CAManBase {
    class AGM_Overheat {
      clientFired = "if (player == (_this select 0)) then {_this call AGM_Overheat_fnc_firedEH}";
    };
  };
};

class AGM_Core_Default_Keys {
  class clearJam {
    displayName = "$STR_AGM_UnjamWeapon";
    condition = "AGM_isWeaponJammed";
    statement = "call AGM_Overheat_clearJam";
    key = 19;
    shift = 1;
    control = 0;
    alt = 0;
  };
};

class CfgVehicles {
  class Man;

  class CAManBase: Man {
    class AGM_SelfActions {
      class AGM_SwapBarrel {
        displayName = "$STR_AGM_SwapBarrel";
        condition = "'AGM_SpareBarrel' in items player && {getNumber (configFile >> 'CfgWeapons' >> currentWeapon player >> 'AGM_Overheat_allowSwapBarrel') == 1}";
        statement = "[currentWeapon player] call AGM_Overheat_swapBarrel";
        showDisabled = 0;
        priority = 4;
      };
    };
  };
};

class CfgWeapons {
  class Rifle;

  class HandGunBase: Rifle {
    AGM_JamChance = 0.005;
    AGM_Overheat_Increment = 0.03;
    AGM_Overheat_Cooldown = 0.002;
    AGM_Overheat_Dispersion = 0.04;
  };

  class Rifle_Base_F: Rifle {
    AGM_JamChance = 0.001;
    AGM_Overheat_Increment = 0.012;
    AGM_Overheat_Cooldown = 0.002;
    AGM_Overheat_Dispersion = 0.01;
  };

  class Rifle_Long_Base_F: Rifle_Base_F {
    AGM_JamChance = 0.001;
    AGM_Overheat_allowSwapBarrel = 1;
    AGM_Overheat_Increment = 0.01;
    AGM_Overheat_Cooldown = 0.002;
    AGM_Overheat_Dispersion = 0.008;
  };

  class ItemCore;
  class InventoryItem_Base_F;
  class AGM_SpareBarrel: ItemCore {
    displayname = "$STR_AGM_SpareBarrelName";
    descriptionshort = "$STR_AGM_SpareBarrelDescription";
    //model = "";
    picture = "\AGM_Overheat\UI\spare_barrel_ca.paa";
    scope = 2;
    class ItemInfo: InventoryItem_Base_F {
      mass = 5;
      type = 201;
    };
  };
};
