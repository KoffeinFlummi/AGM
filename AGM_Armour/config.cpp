class CfgPatches {
  class AGM_Armour {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.94.1";
    versionStr = "0.94.1";
    versionAr[] = {0,94,1};
    author[] = {"KoffeinFlummi", "Adanteh"};
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
    class AGM_Armour {
      init = "_this call AGM_Armour_fnc_init";
    };
  };
};

class CfgVehicles {
  /*
   * AGM_Armour_AmmoLocation:
   *   HitPoint classname that holds the magazine of the vehicle
   * AGM_Armour_CookOffLocations:
   *   Positions to spawn cookoff particle effects at
   * AGM_Armour_CookOffOnTurret:
   *   Positions placed on turret?
   * AGM_Armour_TurretObject:
   *   Object to spawn to simulate turret flying off; "" to not spawn enything
   * AGM_Armour_TurretPosition:
   *   Position to spawn turret at
   *
   * All positions are Y-up, just like in Oxygen/Object Builder.
   */

  class Land;
  class LandVehicle: Land {
    AGM_Armour_AmmoLocation = "HitTurret";
    AGM_Armour_CookOffLocations[] = {{0,-0.2,0}};
    AGM_Armour_CookOffOnTurret[]  = {0};
    explosionEffect = "";
  };
  class Tank: LandVehicle {
    // 2 hatches on the turret; fits most tanks
    AGM_Armour_CookOffLocations[] = {{-0.6,-0.3,1.65}, {0.5,-0.3,1.65}};
    AGM_Armour_CookOffOnTurret[]  = {1,                1              };
  };

  // Small explosions for cars with explosive ammunition
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

  // Big explosions for tracked vehicles and wheeled APCs
  class Tank_F: Tank {
    explosionEffect = "FuelExplosionBig";
  };
  class Car_F;
  class Wheeled_APC_F: Car_F {
    explosionEffect = "FuelExplosionBig";
  };
  class APC_Wheeled_03_base_F: Wheeled_APC_F {
    explosionEffect = "FuelExplosionBig";
  };
  class APC_Wheeled_01_base_F: Wheeled_APC_F {
    explosionEffect = "FuelExplosionBig";
  };
  class APC_Wheeled_02_base_F: Wheeled_APC_F {
    explosionEffect = "FuelExplosionBig";
  };


  class B_MBT_01_base_F;
  class B_MBT_01_cannon_F: B_MBT_01_base_F {
    AGM_Armour_AmmoLocation = "HitHull";
    AGM_Armour_TurretObject = "AGM_Turret_MBT_01";
    AGM_Armour_TurretPosition[] = {3,3,0};
    AGM_Armour_CookOffLocations[] = {{0,-0.3,1.65}};
    AGM_Armour_CookOffOnTurret[]  = {1};
  };

  class O_MBT_02_base_F;
  class O_MBT_02_cannon_F: O_MBT_02_base_F {
    AGM_Armour_TurretObject = "AGM_Turret_MBT_02";
    AGM_Armour_TurretPosition[] = {0.9,3,1.5};
  };

  // Turret Objects
  class thingX;
  class AGM_Turret_MBT_01: thingX {
    scope = 1;
    model = "\A3\Structures_F\Wrecks\Wreck_Slammer_turret_F.p3d";
  };
  class AGM_Turret_MBT_02: thingX {
    scope = 1;
    model = "\A3\Structures_F\Wrecks\Wreck_T72_turret_F.p3d";
  };

  // Compatibility
  // @todo: move to AGM_Comp once inheritance for BWMod is sorted out
  class BWA3_Leopard2A6M_Fleck: B_MBT_01_cannon_F {
    AGM_Armour_AmmoLocation = "HitTurret";
    AGM_Armour_TurretObject = "";
    AGM_Armour_CookOffLocations[] = {{-0.6,2.2,1.65}, {0.5,2.2,1.65}};
  };
};

class CfgCloudlets {
  class FireBallBright;
  class AGM_CookOff: FireBallBright {
    interval = 0.004;
    circleRadius = 0;
    circleVelocity[] = {2,2,2};
    angle =0;
    angleVar =0;
    animationName = "";
    particleType = "Billboard";
    timerPeriod = 1 ;
    lifeTime = 1;
    moveVelocity[] = {0, 4, 0};
    moveVelocityVar[] = {1, 2, 1};
    rotationVelocity = 1;
    weight = 0.4;
    volume = 0.45;
    rubbing = 0;
    animationSpeed[] = {1};
    lifeTimeVar = 0;
    positionVar[] = {0, 0, 0};
    positionVarConst[] = {0, 0, 0};
    moveVelocityVarConst[] = {0, 0, 0};
    rotationVelocityVar = 3;
    sizeVar = 0.1;
    randomDirectionPeriodVar = 1;
    randomDirectionIntensityVar = 2;
    sizeCoef = 1;
    animationSpeedCoef = 1;
    destroyOnWaterSurface = 0;
    destroyOnWaterSurfaceOffset = 0;
    onSurface = 1;
    keepOnSurface = 0;
    surfaceOffset = 0;
    bounceOnSurface = 0.6;
    bounceOnSurfaceVar = 0.0;
    postEffects = "";
    particleEffects = "";
    size[] = {0.01, 0.5, 1, 1, 1.5, 0.01, 0.001};
    randomDirectionPeriod = 5;
    randomDirectionIntensity = 1;
    onTimerScript = "";
    beforeDestroyScript = "";
  };
};
