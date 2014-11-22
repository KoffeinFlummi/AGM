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
      class cookOff;
      class getHitPointBySelection;
      class handleDamage;
      class init;
    };
  };
};

class Extended_Init_EventHandlers {
  class AllVehicles {
    class AGM_Medical {
      init = "_this call AGM_Armour_fnc_init";
    };
  };
};

class CfgVehicles {
  // @todo: explosionEffects for all ground vehicles
  //        - cars get only flames.
  //        - armed vehicles get explosions,
  //          only triggered when appropriate

  class Land;
  class LandVehicle: Land {
    explosionEffect = "";
    AGM_Armour_AmmoLocation = "HitTurret";
    AGM_Armour_CookOffLocations[] = {{0,0,0}};
    AGM_Armour_CookOffOnTurret[]  = {0};
  };
  class Tank: LandVehicle {
    AGM_Armour_CookOffLocations[] = {{-0.6,0,1.65}, {0.5,0,1.65}};
    AGM_Armour_CookOffOnTurret[]  = {1,             1         };
    //AGM_Armour_CookOffLocations[] = {{-0.6,2.4,1.65}, {0.5,2.4,1.65}}; // leopard
  };

  class MRAP_01_gmg_base_F;
  class B_MRAP_01_gmg_F: MRAP_01_gmg_base_F {
    explosionEffect = "FuelExplosion";
  };
  class MRAP_02_gmg_base_F;
  class O_MRAP_01_gmg_F: MRAP_02_gmg_base_F {
    explosionEffect = "FuelExplosion";
  };
  class MRAP_03_gmg_base_F;
  class I_MRAP_03_gmg_F: MRAP_03_gmg_base_F {
    explosionEffect = "FuelExplosion";
  };

  class Tank_F: Tank {
    explosionEffect = "FuelExplosionBig";
  };

  class Wheeled_APC_F;
  class APC_Wheeled_03_base_F: Wheeled_APC_F {
    explosionEffect = "FuelExplosionBig";
  };
  class APC_Wheeled_01_base_F: Wheeled_APC_F {
    explosionEffect = "FuelExplosionBig";
  };
  class APC_Wheeled_02_base_F: Wheeled_APC_F {
    explosionEffect = "FuelExplosionBig";
  };
};
