class CfgPatches {
  class AGM_Armour {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.94.1";
    versionStr = "0.94.1";
    versionAr[] = {0,94,1};
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_Armour {
    class AGM_Armour {
      file = "AGM_Armour\functions";
      class handleDamage;
      class cookOff;
    };
  };
};

class Extended_HandleDamage_EventHandlers {
  class AllVehicles {
    class AGM_Armour {
      handleDamage = "_this call AGM_Armour_fnc_handleDamage";
    };
  };
};

class CfgVehicles {
  // @todo: default config values:
  //        - AGM_Armour_AmmoLocation: name of hitpoint class that stores ammo.
  // @todo: explosionEffects for all ground vehicles
  //        - cars get only flames.
  //        - armed vehicles get explosions,
  //          only triggered when appropriate
};