class CfgPatches {
  class AGM_Aircraft {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {
      AGM_Core, 
      A3_Air_F,
      A3_Air_F_Heli_Light_01,
      A3_Air_F_Heli_Light_02,
      A3_Air_F_Beta,
      A3_Air_F_Beta_Heli_attack_01,
      A3_Air_F_Beta_Heli_Attack_02,
      A3_Air_F_Beta_Heli_Transport_01,
      A3_Air_F_Beta_Heli_Transport_02,
      A3_Air_F_Gamma_Plane_Fighter_03,
      A3_Air_F_EPC_Plane_CAS_01,
      A3_Air_F_EPC_Plane_CAS_02,
      A3_Air_F_EPC_Plane_Fighter_03,
      A3_Weapons_F_NATO
    };
    version = "0.9";
    versionStr = "0.9";
    versionAr[] = {0,9,0};
    author[] = {"KoffeinFlummi", "Crusty"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_Aircraft {
    class AGM_Aircraft {
      file = "AGM_Aircraft\functions";
      class autopilot;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Aircraft {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_aircraft\clientInit.sqf'";
  };
};

/*class AGM_Core_Default_Keys {
  class autopilot {
    displayName = "Autopilot";
    conditionUp = "player == driver _vehicle && {_vehicle isKindOf 'Plane'}";
    statementUp = "[_vehicle] call AGM_Aircraft_fnc_autopilot";
    key = 211;
    shift = 0;
    control = 0;
    alt = 0;
  };
};*/

class CfgAmmo {
  class BulletBase;
  class LaserBombCore;
  class MissileBase;
  class RocketBase;
  class B_65x39_Caseless;

  class B_20mm: BulletBase {
    deflecting = 3;
  };
  class B_65x39_Minigun_Caseless: B_65x39_Caseless {
    hit = 10;
    indirectHit = 0;
    indirectHitRange = 0;
    caliber = 1;
    deflecting = 5;
    typicalSpeed = 850;
  };
  
};

class Mode_Burst;
class CfgWeapons {
  class SmokeLauncher;
  class CannonCore;

  // Manual Switching Of Flare Mode
  class CMFlareLauncher: SmokeLauncher {
    modes[] = {"Single", "Burst", "AIBurst"};
    class Burst: Mode_Burst {
      displayName = "$STR_AGM_Aircraft_CMFlareLauncher_Burst_Name";
    };
  };

  class gatling_20mm: CannonCore {
    class close;
    class far;
    class manual;
    class medium;
    class short;
    magazines[] = {"2000Rnd_20mm_shells","1000Rnd_20mm_shells","300Rnd_20mm_shells","AGM_500Rnd_20mm_shells_Comanche"};
  };

  class AGM_gatling_20mm_Comanche: gatling_20mm {
    displayName = "XM301";
    class close: close {
      reloadTime = 0.04;
      dispersion = 0.0022;
    };
    class far: far {
      reloadTime = 0.04;
      dispersion = 0.0022;
    };
    class manual: manual {
      reloadTime = 0.04;
      dispersion = 0.0022;
    };
    class medium: medium {
      reloadTime = 0.04;
      dispersion = 0.0022;
    };
    class short: short {
      reloadTime = 0.04;
      dispersion = 0.0022;
    };
  };
};

class CfgMagazines {
  class 300Rnd_20mm_shells;
  class AGM_500Rnd_20mm_shells_Comanche: 300Rnd_20mm_shells {
    displayName = "20mm";
    displayNameShort = "20mm";
    ammo = "B_20mm";
    count = 500;
    deflecting = 3;
    initSpeed = 1030;
    maxLeadSpeed = 300;
    tracersEvery = 5;
  };
};

class CfgVehicles {
  // Basic Inheritance
  class AllVehicles;
  class Air: AllVehicles {
    class AnimationSources;
    class Turrets;
  };
  class Helicopter: Air {
    class AnimationSources: AnimationSources {};
    class Turrets: Turrets {
      class MainTurret;
    };
  };
  class Helicopter_Base_F: Helicopter {
    class AnimationSources: AnimationSources {};
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
    };
  };
  class Helicopter_Base_H: Helicopter_Base_F {
    class AnimationSources: AnimationSources {};
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
      class CopilotTurret;
    };
  };
  class Plane_Base_F;

  // BLUFOR Inheritance
  class Heli_Attack_01_base_F: Helicopter_Base_F {
    class AnimationSources;
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
    };
  };
  class Heli_Light_01_base_F: Helicopter_Base_H {
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {};
    };
  };
  class Heli_Light_01_armed_base_F: Heli_Light_01_base_F {
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {};
    };
  };
  class Heli_Transport_01_base_F: Helicopter_Base_H {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
      class CopilotTurret: CopilotTurret {};
      class RightDoorGun;
    };
  };
  class Plane_CAS_01_base_F: Plane_Base_F {
    maxSpeed = 736;
    aileronSensitivity = 0.85;
    elevatorSensitivity = 0.75;
    rudderInfluence = 0.001;
    aileronControlsSensitivityCoef = 3;
    elevatorControlsSensitivity = 2;
    rudderControlsSensitivityoef = 4;
    elevatorCoef[] = {0.7,0.75,0.75,0.65,0.55,0.45,0.35};
    aileronCoef[] = {0.6,0.85,0.88,0.92,0.95,0.97,1};
    rudderCoef[] = {0.8,0.75,0.65,0.5,0.4,0.33,0.3};
    flapsFrictionCoef = 0.35;
    angleOfIndicence = 0.0523599;
    draconicForceXCoef = 9.5;
    draconicForceYCoef = 0.56;
    draconicForceZCoef = 0.1;
    draconicTorqueXCoef = 0.58;
    draconicTorqueYCoef = 0.00013;
    envelope[] = {0,0,0.75,2.4,3.6,3.8,3.7,3.2,2.2,1.7,0.9};
    thrustCoef[] = {1,1.2,1.3,1.25,1.06,1.01,1,0.92,0.75,0.65,0.5,0.25,0};
    acceleration = 265;
    landingSpeed = 220;
    gunAimDown = 0.087266463;
  };

  // INDEP Inheritance
  class I_Heli_light_03_base_F: Helicopter_Base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
    };
  };
  class I_Heli_light_03_unarmed_base_F: I_Heli_light_03_base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
    };
  };
  class Heli_Transport_02_base_F: Helicopter_Base_H {
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {};
    };
  };
  class Plane_Fighter_03_base_F: Plane_Base_F {
    acceleration = 300;
    maxSpeed = 936;
    irScanRangeMin = 500;
    irScanRangeMax = 5000;
    aileronSensitivity = 0.64;
    elevatorSensitivity = 0.682;
    rudderInfluence = 0.001;
    aileronControlsSensitivityCoef = 3;
    elevatorControlsSensitivity = 2;
    rudderControlsSensitivityoef = 4;
    elevatorCoef[] = {0.6,0.73,0.62,0.52,0.39,0.33,0.28};
    aileronCoef[] = {0.5,0.68,0.75,0.86,0.92,0.96,1};
    rudderCoef[] = {0.9,0.75,0.58,0.45,0.38,0.35,0.3};
    envelope[] = {0,0.06,1.2,3,3.6,3.75,3.65,3.45,3.3,2.8,2.4,1.9,1.5};
    angleOfIndicence = 0.0523599;
    //determines velocity vector behaviour, how quickly it catches up with where your nose is pointing, I think
    draconicForceXCoef = 7.5;
    //max angle of attack, lower value gives higher aoa
    draconicForceYCoef = 0.2198;
    //Something to do with bleed off of speed, low values seem to increase bleed off
    draconicForceZCoef = 5.12;
    //????
    draconicTorqueXCoef = 0.18;
    //resistance to elevator input, also impacts speed degradation
    draconicTorqueYCoef = 0.000017;
    thrustCoef[] = {1.3,1.27,1.24,1.2,1.17,1.15,1.13,1.1,1.06,1,0.94,0.72,0.51,0.4,0.25,0};
    gunAimDown = 0.029;
    flapsFrictionCoef = 0.32;
  };

  // OPFOR Inheritance
  class Heli_Light_02_base_F: Helicopter_Base_H {
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {};
    };
  };
  class Heli_Attack_02_base_F: Helicopter_Base_F {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
    };
  };
  class Plane_CAS_02_base_F: Plane_Base_F {
    maxSpeed = 1059;
    acceleration = 300;
    aileronSensitivity = 0.635;
    elevatorSensitivity = 0.814;
    rudderInfluence = 0.001;
    aileronControlsSensitivityCoef = 3;
    elevatorControlsSensitivity = 2;
    rudderControlsSensitivityoef = 4;
    elevatorCoef[] = {0.6,0.76,0.7,0.65,0.58,0.47,0.43};
    aileronCoef[] = {0.5,0.85,0.87,0.89,0.92,0.95,1};
    rudderCoef[] = {0.8,0.7,0.6,0.5,0.4,0.32,0.27};
    angleOfIndicence = 0.0523599;
    draconicForceXCoef = 7.6;
    draconicForceYCoef = 0.75;
    draconicForceZCoef = 0.085;
    draconicTorqueXCoef = 0.815;
    draconicTorqueYCoef = 0.000152;
    envelope[] = {0,0.446,1.5,3.9,5.2,4.8,4.2,3.5,2,1,0.5};
    thrustCoef[] = {1,1.2,1.7,1.7,1.65,1.54,1.32,1.1,0.95,0.75,0.5,0.35,0};
    flapsFrictionCoef = 0.32;
  };

  ////////////////////////////////////////////////////////////

  // BLUFOR
  class B_Heli_Attack_01_F: Heli_Attack_01_base_F {
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class AnimationSources: AnimationSources {
      class HitGlass1 {
        source = "Hit";
        hitpoint = "HitGlass1";
        raw = 1;
      };
      class HitGlass2: HitGlass1 {
        hitpoint = "HitGlass2";
      };
      class HitGlass3: HitGlass1 {
        hitpoint = "HitGlass3";
      };
      class HitGlass4: HitGlass1 {
        hitpoint = "HitGlass4";
      };
      class Gatling {
        source = "revolving";
        weapon = "AGM_gatling_20mm_Comanche";
      };
      class Hide {
        source = "user";
        animPeriod = 0;
        initPhase = 0;
      };
      class Muzzle_flash {
        source = "ammorandom";
        weapon = "AGM_gatling_20mm_Comanche";
      };
    };
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        canEject = 1;
        weapons[] = {"AGM_gatling_20mm_Comanche","missiles_DAGR","missiles_ASRAAM"};
        magazines[] = {"AGM_500Rnd_20mm_shells_Comanche","4Rnd_AAA_missiles","24Rnd_PG_missiles"};
      };
    };
  };
  class B_Heli_Transport_01_F: Heli_Transport_01_base_F {
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        canEject = 1;
      };
      class CopilotTurret: CopilotTurret {
        canEject = 1;
      };
      class RightDoorGun: RightDoorGun {
        canEject = 1;
      };
    };
  };
  class B_Heli_Light_01_F: Heli_Light_01_base_F {
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {
        canEject = 1;
      };
    };
  };
  class B_Heli_Light_01_armed_F: Heli_Light_01_armed_base_F {
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {
        canEject = 1;
      };
    };
  };
  class B_Plane_CAS_01_F: Plane_CAS_01_base_F {
    lockDetectionSystem = 16;
  };

  // INDEP
  class I_Heli_light_03_F: I_Heli_light_03_base_F {
    weapons[] = {"M134_minigun","missiles_DAR","CMFlareLauncher"};
    magazines[] = {"5000Rnd_762x51_Yellow_Belt","24Rnd_missiles","168Rnd_CMFlare_Chaff_Magazine"};
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        canEject = 1;
        gunBeg = "commanderview";
        gunEnd = "laserstart";
        memoryPointGun = "laserstart";
        stabilizedInAxes = 3;
        weapons[] = {"Laserdesignator_mounted"};
        soundServo[] = {"",0.01,1,30};
        magazines[] = {"Laserbatteries"};
        inGunnerMayFire = 1;
      };
    };
  };
  class I_Heli_light_03_unarmed_F: I_Heli_light_03_unarmed_base_F {
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        canEject = 1;
        gunBeg = "commanderview";
        gunEnd = "laserstart";
        memoryPointGun = "laserstart";
        stabilizedInAxes = 3;
        weapons[] = {"Laserdesignator_mounted"};
        soundServo[] = {"",0.01,1,30};
        magazines[] = {"Laserbatteries"};
        inGunnerMayFire = 1;
      };
    };
  };
  class I_Heli_Transport_02_F: Heli_Transport_02_base_F {
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {
        canEject = 1;
      };
    };
  };
  class I_Plane_Fighter_03_CAS_F: Plane_Fighter_03_base_F {
    lockDetectionSystem = 16;
  };

  // OPFOR
  class O_Heli_Attack_02_F: Heli_Attack_02_base_F {
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        canEject = 1;
      };
    };
  };
  class O_Heli_Attack_02_black_F: Heli_Attack_02_base_F {
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        canEject = 1;
      };
    };
  };
  class O_Heli_Light_02_F: Heli_Light_02_base_F {
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {
        canEject = 1;
      };
    };
  };
  class O_Heli_Light_02_unarmed_F: Heli_Light_02_base_F {
    lockDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        canEject = 1;
      };
      class CopilotTurret: CopilotTurret {
        canEject = 1;
      };
    };
  };
  class O_Plane_CAS_02_F: Plane_CAS_02_base_F {
    lockDetectionSystem = 16;
  };
};
