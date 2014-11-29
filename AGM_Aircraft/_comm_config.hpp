





class Turrets: Turrets {
  class MainTurret: MainTurret {
    isCopilot = 1;
    showHMD = 1;
    CanEject = 0;
    startEngine = 0;
    minElev = -51;
    maxElev = 9;
    initElev = 6;
    minTurn = -120;
    maxTurn = 120;
    initTurn = 0;
    class OpticsIn {
      class WideNGS {
        opticsDisplayName = "W";
        initAngleX = 0;
        minAngleX = -35;
        maxAngleX = 10;
        initAngleY = 0;
        minAngleY = -100;
        maxAngleY = 100;
        initFov = 0.466;
        minFov = 0.466;
        maxFov = 0.466;
        visionMode[] = {"Normal","Ti"};
        thermalMode[] = {0,1};
        gunnerOpticsColor[] = {0.15,1,0.15,1};
        gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
        directionStabilized = 0;
        opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
      };

      class Wide {
        opticsDisplayName = "W";
        initAngleX = 0;
        minAngleX = -35;
        maxAngleX = 10;
        initAngleY = 0;
        minAngleY = -100;
        maxAngleY = 100;
        initFov = 0.466;
        minFov = 0.466;
        maxFov = 0.466;
        visionMode[] = {"Normal","Ti"};
        thermalMode[] = {0,1};
        gunnerOpticsColor[] = {0.15,1,0.15,1};
        gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_w_F.p3d";
        directionStabilized = 1;
        opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
        gunnerOpticsEffect[] = {"TankCommanderOptics1","AGM_BWTV"};
      };

      class WideL: Wide {
        opticsDisplayName = "WL";
        initFov = 0.2;
        minFov = 0.2;
        maxFov = 0.2;
        gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_m_F.p3d";
        gunnerOpticsColor[] = {0,0,0,1};
        directionStabilized = 1;
        opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
      };

      class Medium: Wide {
        opticsDisplayName = "M";
        initFov = 0.1;
        minFov = 0.1;
        maxFov = 0.1;
        directionStabilized = 1;
        gunnerOpticsColor[] = {0,0,0,1};
        gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_m_F.p3d";
      };

      class Narrow: Wide {
        opticsDisplayName = "N";
        gunnerOpticsColor[] = {0,0,0,1};
        gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_n_F.p3d";
        directionStabilized = 1;
        initFov = 0.02;
        minFov = 0.02;
        maxFov = 0.02;
      };

      class Narrower: Wide {
        opticsDisplayName = "N";
        gunnerOpticsColor[] = {0,0,0,1};
        gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_n_F.p3d";
        directionStabilized = 1;
        initFov = 0.01;
        minFov = 0.01;
        maxFov = 0.01;
      };

    };

    class OpticsOut {
      class Monocular {
        initAngleX = 0;
        minAngleX = -30;
        maxAngleX = 30;
        initAngleY = 0;
        minAngleY = -100;
        maxAngleY = 100;
        initFov = 1.1;
        minFov = 0.133;
        maxFov = 1.1;
        visionMode[] = {"Normal","NVG","Ti"};
        thermalMode[] = {2,3};
        gunnerOpticsModel = "";
        gunnerOpticsEffect[] = {};
        hideUnitInfo = 1;
      };

    };

    soundServo[] = {"",0.01,1};
    outGunnerMayFire = 1;
    commanding = -1;
    primaryGunner = 1;
    memoryPointsGetInGunner = "Pos_Gunner";
    memoryPointsGetInGunnerDir = "Pos_Gunner_dir";
    gunnerLeftHandAnimName = "lever_copilot";
    gunnerRightHandAnimName = "stick_copilot";
    memoryPointGun = "machinegun";
    gunBeg = "usti hlavne";
    gunEnd = "konec hlavne";
    memoryPointGunnerOptics = "pip0_pos";
    selectionFireAnim = "zasleh";
    castGunnerShadow = 1;
    viewGunnerShadow = 1;
    gunnerAction = "Heli_Attack_01_Gunner";
    gunnerInAction = "Heli_Attack_01_Gunner";
    gunnerGetInAction = "Heli_Attack_01_Gunner_Enter";
    gunnerGetOutAction = "Heli_Attack_01_Gunner_Exit";
    precisegetinout = 1;
    gunnerOpticsModel = "";
    gunnerOpticsEffect[] = {"TankCommanderOptics1","AGM_BWTV"};
    gunnerForceOptics = 0;
    turretInfoType = "Rsc_Kimi_UI_01";
    showAllTargets = 2;
    discretedistance[] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600,2700,2800,2900,3000};
    discretedistanceinitindex = 3;
    copilotHasFlares = 1;
    LockDetectionSystem = "1 + 2 + 4 + 8";
    incomingMissileDetectionSystem = 16;
    TurretCanSee = "1+2+4+8+16";
    weapons[] = {"gatling_20mm","missiles_DAGR","missiles_ASRAAM","KIMI_HELO_CMFlareLauncher","Jammer_Kimi","Laserdesignator_mounted"};
    magazines[] = {"1000Rnd_20mm_shells","4Rnd_AAA_missiles","24Rnd_PG_missiles","168Rnd_CMFlare_Chaff_Magazine","Laserbatteries","Jammer_Magazine_Kimi","Jammer_Magazine_Kimi","Jammer_Magazine_Kimi","Jammer_Magazine_Kimi","Jammer_Magazine_Kimi","Jammer_Magazine_Kimi","Jammer_Magazine_Kimi","Jammer_Magazine_Kimi","Jammer_Magazine_Kimi","Jammer_Magazine_Kimi","Jammer_Magazine_Kimi","Jammer_Magazine_Kimi","Jammer_Magazine_Kimi","Jammer_Magazine_Kimi","Jammer_Magazine_Kimi"};
    class HitPoints {
      class HitTurret {
        armor = 1;
        material = -1;
        name = "main_turret_hit";
        visual = "gun1";
        passThrough = 0.3;
        radius = 0.2;
      };

      class HitGun {
        armor = 1;
        material = -1;
        name = "main_gun_hit";
        visual = "gun2";
        passThrough = 0.3;
        radius = 0.2;
      };

    };

  };

};
