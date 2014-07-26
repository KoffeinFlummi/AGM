class CfgPatches {
  class AGM_Aircraft {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"KoffeinFlummi", "Crusty"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgAmmo {
  class BulletBase;
  class LaserBombCore;
  class MissileBase;
  class RocketBase;
  class SubmunitionBullet;
  class M_Titan_AA;

  class B_20mm: BulletBase {
    deflecting = 3;
  };

  class B_65x39_Minigun_Caseless: SubmunitionBullet {
    hit = 10;
    indirectHit = 0;
    indirectHitRange = 0;
    caliber = 1;
    deflecting = 5;
    typicalSpeed = 850;
  };

  class B_762x51_Minigun_Tracer_Red: SubmunitionBullet {
    hit = 12;
    indirectHit = 0;
    indirectHitRange = 0;
    model = "\A3\Weapons_f\Data\bullettracer\tracer_red";
    caliber = 1.6;
    deflecting = 5;
    typicalSpeed = 850;
  };

  class M_Zephyr: M_Titan_AA {
    proxyShape = "\A3\Weapons_F\Ammo\Missile_AA_02_F.p3d";
    model = "\A3\Weapons_F\Ammo\Missile_AA_02_fly_F.p3d";
    airFriction = 0.078;
    sideAirFriction = 0.18;
    maneuvrability = 24;
    class CamShakeFire {};
    class CamShakePlayerFire {};
  };

  class M_Zephyr_Mi06: M_Zephyr {
    maverickWeaponIndexOffset = 6;
  };

  class M_Air_AA: MissileBase {
    model = "\A3\Weapons_F\Ammo\Missile_AT_02_fly_F";
    proxyShape = "\A3\Weapons_F\Ammo\Missile_AT_02_F";
    hit = 280;
    indirectHit = 85;
    indirectHitRange = 10;
    maneuvrability = 27;
    simulationStep = 0.002;
    airLock = 1;
    irLock = 1;
    cost = 1500;
    //maxSpeed = 2400;
    timeToLive = 40;
    airFriction = 0.05;
    sideAirFriction = 0.1;
    trackOversteer = 1;
    trackLead = 1;
    initTime = 0;
    thrustTime = 12;
    thrust = 340;
    fuseDistance = 500;
    weaponLockSystem = "2 + 16";
    maxControlRange = 8000;
    class CamShakeExplode {};
    class CamShakeHit {};
    class CamShakeFire {};
    class CamShakePlayerFire {};
  };

  class Missile_AA_04_F: MissileBase {
    hit = 800;
    indirectHit = 60;
    indirectHitRange = 12;
    airLock = 2;
    irLock = 1;
    laserLock = 0;
    nvLock = 0;
    weaponLockSystem = "2 + 16";
    cmimmunity = 0.8;
    initTime = 0;
    thrust = 380;
    thrustTime = 9.5;
    airFriction = 0.04;
    sideAirFriction = 0.08;
    //maxSpeed = 2600;
    maneuvrability = 14;
    simulationStep = 0.002;
    fuseDistance = 500;
    timeToLive = 19;
    trackLead = 1;
    trackOversteer = 1;
  };

  class Gatling_30mm_HE_Plane_CAS_01_F: BulletBase {
    model = "\A3\Weapons_f\Data\bullettracer\tracer_red.p3d";
    cost = 20;
    hit = 80;
    indirectHit = 12;
    indirectHitRange = 3;
    caliber = 1.4;
    explosive = 0.6;
    airlock = 1;
    deflecting = 3;
    airFriction = -0.00042;
    typicalSpeed = 960;
    visibleFire = 32;
    audibleFire = 32;
    visibleFireTime = 3;
    fuseDistance = 3;
    tracerScale = 2.5;
    tracerStartTime = 0.02;
    tracerEndTime = 4.7;
    multiSoundHit[] = {"soundHit1",0.2,"soundHit2",0.2,"soundHit3",0.2,"soundHit4",0.1,"soundHit5",0.15,"soundHit6",0.15};
    soundFly[] = {"A3\Sounds_F\weapons\Explosion\cannon_fly",1,1,50};
    explosionSoundEffect = "DefaultExplosion";
    explosionEffects = "ExploAmmoExplosion";
    craterEffects = "ExploAmmoCrater";
    soundHit1[] = {"A3\Sounds_F\weapons\Explosion\gr_explosion_1",3.16228,1,1600};
    soundHit2[] = {"A3\Sounds_F\weapons\Explosion\gr_explosion_2",3.16228,1,1600};
    soundHit3[] = {"A3\Sounds_F\weapons\Explosion\gr_explosion_3",3.16228,1,1600};
    soundHit4[] = {"A3\Sounds_F\weapons\Explosion\gr_explosion_4",3.16228,1,1600};
    soundHit5[] = {"A3\Sounds_F\weapons\Explosion\gr_explosion_5",3.16228,1,1600};
    soundHit6[] = {"A3\Sounds_F\weapons\Explosion\gr_explosion_6",3.16228,1,1600};
    class CamShakeExplode {};
    class CamShakeHit {};
    class CamShakeFire {};
    class CamShakePlayerFire {};
  };

  class Cannon_30mm_HE_Plane_CAS_02_F: Gatling_30mm_HE_Plane_CAS_01_F {
    model = "\A3\Weapons_f\Data\bullettracer\tracer_green.p3d";
    hit = 70;
    indirectHit = 11;
    indirectHitRange = 3;
    caliber = 2;
    explosive = 0.6;
  };

  class Missile_AGM_02_F: MissileBase {
    model = "\A3\Weapons_F_EPC\Ammo\Missile_AGM_02_fly_F.p3d";
    proxyShape = "\A3\Weapons_F_EPC\Ammo\Missile_AGM_02_F.p3d";
    maverickWeaponIndexOffset = 2;
    cost = 1500;
    hit = 2100;
    indirectHit = 85;
    indirectHitRange = 8;
    manualControl = 0;
    maxControlRange = 8000;
    airLock = 0;
    irLock = 1;
    laserLock = 0;
    nvLock = 0;
    weaponLockSystem = "2 + 16";
    cmimmunity = 0.8;
    initTime = 0;
    thrust = 240;
    thrustTime = 5;
    airFriction = 0.05;
    sideAirFriction = 0.1;
    maxSpeed = 828;
    maneuvrability = 27;
    simulationStep = 0.002;
    fuseDistance = 500;
    timeToLive = 40;
    trackLead = 1;
    trackOversteer = 1;
    craterEffects = "AAMissileCrater";
    effectsMissile = "missile3";
    explosionEffects = "AAMissileExplosion";
    muzzleEffect = "BIS_fnc_effectFiredHeliRocket";
    whistleDist = 20;
    class CamShakeExplode {};
    class CamShakeHit {};
    class CamShakeFire {};
    class CamShakePlayerFire {};
  };

  class Bomb_04_F: LaserBombCore {
    model = "\A3\Weapons_F_EPC\Ammo\Bomb_04_fly_F.p3d";
    proxyShape = "\A3\Weapons_F_EPC\Ammo\Bomb_04_F.p3d";
    maverickWeaponIndexOffset = 8;
    hit = 6000;
    indirectHit = 1400;
    indirectHitRange = 15;
    nvLock = 1;
    weaponLockSystem = "2 + 16 + 4";
    maneuvrability = 20;
    fuseDistance = 35;
    trackLead = 0.95;
    trackOversteer = 1;
    craterEffects = "BombCrater";
    explosionEffects = "BombExplosion";
    explosionSoundEffect = "DefaultExplosion";
    explosionTime = 2;
    multiSoundHit[] = {"soundHit1",0.2,"soundHit2",0.2,"soundHit3",0.2,"soundHit4",0.2,"soundHit5",0.2};
    soundHit1[] = {"\A3\Sounds_F\weapons\Explosion\expl_big_1",2.51189,1,2400};
    soundHit2[] = {"\A3\Sounds_F\weapons\Explosion\expl_big_2",2.51189,1,2400};
    soundHit3[] = {"\A3\Sounds_F\weapons\Explosion\expl_big_3",2.51189,1,2400};
    soundHit4[] = {"\A3\Sounds_F\weapons\Explosion\expl_shell_1",2.51189,1,2400};
    soundHit5[] = {"\A3\Sounds_F\weapons\Explosion\expl_shell_2",2.51189,1,2400};
    whistleDist = 24;
  };

  class Rocket_04_HE_F: MissileBase {
    model = "\A3\Weapons_F_EPC\Ammo\Rocket_04_HE_fly_F.p3d";
    proxyShape = "\A3\Weapons_F_EPC\Ammo\Rocket_04_HE_F.p3d";
    maverickWeaponIndexOffset = 12;
    cost = 500;
    hit = 210;
    indirectHit = 55;
    indirectHitRange = 15;
    manualControl = 0;
    maxControlRange = 8000;
    airLock = 0;
    irLock = 1;
    laserLock = 0;
    nvLock = 0;
    weaponLockSystem = 0;
    cmimmunity = 1;
    initTime = 0.002;
    thrust = 1600;
    thrustTime = 0.7;
    airFriction = 0.0046;
    sideAirFriction = 0.005;
    maxSpeed = 610;
    maneuvrability = 0;
    fuseDistance = 50;
    timeToLive = 60;
    effectsMissileInit = "MissileDAR1";
    whistleDist = 30;
    class CamShakeExplode {};
    class CamShakeHit {};
    class CamShakeFire {};
    class CamShakePlayerFire {};
  };

  class Rocket_04_AP_F: Rocket_04_HE_F {
    model = "\A3\Weapons_F_EPC\Ammo\Rocket_04_AP_fly_F.p3d";
    proxyShape = "\A3\Weapons_F_EPC\Ammo\Rocket_04_AP_F.p3d";
    maverickWeaponIndexOffset = 19;
    hit = 400;
    indirectHit = 20;
    indirectHitRange = 10;
  };

  class Missile_AA_03_F: Missile_AA_04_F {
    model = "\A3\Weapons_F_EPC\Ammo\Missile_AA_03_fly_F.p3d";
    proxyShape = "\A3\Weapons_F_EPC\Ammo\Missile_AA_03_F.p3d";
    maverickWeaponIndexOffset = 0;
    hit = 900;
    indirectHit = 50;
    indirectHitRange = 15;
  };

  class Missile_AGM_01_F: Missile_AGM_02_F {
    model = "\A3\Weapons_F_EPC\Ammo\Missile_AGM_01_fly_F.p3d";
    proxyShape = "\A3\Weapons_F_EPC\Ammo\Missile_AGM_01_F.p3d";
    maverickWeaponIndexOffset = 2;
    hit = 2200;
    indirectHit = 90;
    indirectHitRange = 10;
  };

  class Bomb_03_F: Bomb_04_F {
    model = "\A3\Weapons_F_EPC\Ammo\Bomb_03_F.p3d";
    proxyShape = "\A3\Weapons_F_EPC\Ammo\Bomb_03_F.p3d";
    maverickWeaponIndexOffset = 6;
    hit = 6400;
    indirectHit = 1400;
    indirectHitRange = 16;
  };

  class Rocket_03_HE_F: Rocket_04_HE_F {
    model = "\A3\Weapons_F_EPC\Ammo\Rocket_03_HE_fly_F.p3d";
    proxyShape = "\A3\Weapons_F_EPC\Ammo\Rocket_03_HE_F.p3d";
    maverickWeaponIndexOffset = 8;
  };

  class Rocket_03_AP_F: Rocket_04_AP_F {
    model = "\A3\Weapons_F_EPC\Ammo\Rocket_03_AP_fly_F.p3d";
    proxyShape = "\A3\Weapons_F_EPC\Ammo\Rocket_03_AP_F.p3d";
    maverickWeaponIndexOffset = 28;
  };
};

class CfgMagazines {
  class VehicleMagazine;
  class 24Rnd_PG_missiles;

  class 12Rnd_PG_missiles: 24Rnd_PG_missiles {
    count = 12;
    displayName = "$STR_A3_CfgMagazines_12Rnd_PG_missiles0";
    displayNameShort = "$STR_A3_CfgMagazines_12Rnd_PG_missiles_dns";
    descriptionShort = "$STR_A3_CfgMagazines_12Rnd_PG_missiles1";
  };
  class 12Rnd_missiles: VehicleMagazine {
    scope = 2;
    count = 12;
    ammo = "M_AT";
    displayName = "$STR_A3_CfgMagazines_24Rnd_PuG_missiles0";
    displayNameShort = "$STR_A3_CfgMagazines_24Rnd_PuG_missiles_dns";
    descriptionShort = "$STR_A3_CfgMagazines_24Rnd_PuG_missiles0";
    initSpeed = 44;
    maxLeadSpeed = 800;
    nameSound = "rockets";
    sound[] = {"A3\sounds_f\weapons\rockets\explosion_missile_01",1,1,1200};
    reloadSound[] = {"",0.000316228,1};
  };

  //minigun magazines, muzzle velocities and tracercounts
  class 200Rnd_65x39_Belt: VehicleMagazine {};
  class 2000Rnd_65x39_Belt: 200Rnd_65x39_Belt {};
  class 2000Rnd_65x39_Belt_Tracer_Red: 2000Rnd_65x39_Belt {
  };
  class 2000Rnd_65x39_Belt_Green: 2000Rnd_65x39_Belt {};
  class 2000Rnd_65x39_Belt_Tracer_Green: 2000Rnd_65x39_Belt_Green {
    tracersEvery = 1;
  };
  class 2000Rnd_65x39_Belt_Yellow: 2000Rnd_65x39_Belt {
    tracersEvery = 1;
  };
  class 2000Rnd_65x39_Belt_Tracer_Yellow: 2000Rnd_65x39_Belt_Yellow {
    tracersEvery = 1;
  };

  class 5000Rnd_762x51_Belt: 2000Rnd_65x39_Belt {
    tracersEvery = 1;
    count = 5000;
  };
  class 5000Rnd_762x51_Yellow_Belt: 5000Rnd_762x51_Belt {};
  class 4000Rnd_762x51_M134 : 5000Rnd_762x51_Belt {
    count = 4000;
    tracersEvery = 1;
  };
  class 2000Rnd_762x51_M134 : 4000Rnd_762x51_M134 {
    count = 2000;
    tracersEvery = 1;
  };

  class 2Rnd_AAA_missiles: VehicleMagazine {
    scope = 2;
    displayName = "$STR_A3_CfgMagazines_2Rnd_AAA_missiles0";
    displayNameShort = "$STR_A3_CfgMagazines_2Rnd_AAA_missiles_dns";
    ammo = "M_Air_AA";
    count = 2;
    maxLeadSpeed = 950;
    nameSound = "missiles";
  };
  class 2Rnd_AAA_missiles_MI02: 2Rnd_AAA_missiles {
    ammo = "M_Air_AA_MI02";
  };
  class 4Rnd_AAA_missiles: 2Rnd_AAA_missiles {
    displayName = "$STR_A3_CfgMagazines_4Rnd_AAA_missiles0";
    displayNameShort = "$STR_A3_CfgMagazines_4Rnd_AAA_missiles_dns";
    count = 4;
  };
  class 4Rnd_AAA_missiles_MI02: 4Rnd_AAA_missiles {
    ammo = "M_Air_AA_MI02";
  };

  class 4Rnd_GAA_missiles: VehicleMagazine {
    scope = 2;
    displayName = "$STR_A3_CfgMagazines_4Rnd_GAA_missiles0";
    displayNameShort = "$STR_A3_CfgMagazines_4Rnd_GAA_missiles_dns";
    count = 4;
    ammo = "M_Zephyr";
    maxLeadSpeed = 950;
    nameSound = "missiles";
  };

  class 300Rnd_20mm_shells: VehicleMagazine {
    scope = 2;
    displayName = "$STR_A3_CfgMagazines_300Rnd_20mm_shells0";
    displayNameShort = "$STR_A3_CfgMagazines_300Rnd_20mm_shells_dns";
    ammo = "B_20mm";
    count = 300;
    deflecting = 3;
    maxLeadSpeed = 300;
    tracersEvery = 5;
    nameSound = "cannon";
  };

  class 1000Rnd_Gatling_30mm_Plane_CAS_01_F: VehicleMagazine {
    scope = 2;
    displayNameShort = "";
    ammo = "Gatling_30mm_HE_Plane_CAS_01_F";
    count = 1170;
    //initSpeed = 3852;
    maxLeadSpeed = 300;
    nameSound = "cannon";
    tracersEvery = 1;
  };

  class 2Rnd_Missile_AA_04_F: VehicleMagazine {
    scope = 2;
    displayNameShort = "$STR_A3_CFGMAGAZINES_4RND_AAA_MISSILES_DNS";
    ammo = "Missile_AA_04_F";
    count = 2;
    maxLeadSpeed = 220;
    nameSound = "missiles";
  };
  class 6Rnd_Missile_AGM_02_F: VehicleMagazine {
    scope = 2;
    displayNameShort = "$STR_A3_CFGMAGAZINES_38RND_80MM_ROCKETS_DNS";
    ammo = "Missile_AGM_02_F";
    count = 6;
    maxLeadSpeed = 450;
    nameSound = "missiles";
  };
  class 2Rnd_Missile_AGM_02_F: VehicleMagazine {
    scope = 2;
    displayNameShort = "$STR_A3_CFGMAGAZINES_38RND_80MM_ROCKETS_DNS";
    ammo = "Missile_AGM_02_F";
    count = 2;
    maxLeadSpeed = 450;
    nameSound = "missiles";
  };

  class 7Rnd_Rocket_04_HE_F: VehicleMagazine {
    scope = 2;
    displayNameShort = "$STR_A3_CFGMAGAZINES_40RND_20MM_G_BELT_DNS";
    ammo = "Rocket_04_HE_F";
    count = 7;
    maxLeadSpeed = 200;
    nameSound = "rockets";
  };
  class 7Rnd_Rocket_04_AP_F: 7Rnd_Rocket_04_HE_F {
    displayNameShort = "$STR_A3_CFGMAGAZINES_TITAN_AP_DNS";
    ammo = "Rocket_04_AP_F";
  };

  class 4Rnd_Bomb_04_F: VehicleMagazine {
    scope = 2;
    displayNameShort = "$STR_A3_CFGVEHICLES_BOMB0";
    ammo = "Bomb_04_F";
    count = 4;
    maxLeadSpeed = 1000;
    nameSound = "cannon";
  };

  class 500Rnd_Cannon_30mm_Plane_CAS_02_F: 1000Rnd_Gatling_30mm_Plane_CAS_01_F {
    displayNameShort = "";
    ammo = "Cannon_30mm_HE_Plane_CAS_02_F";
    count = 500;
  };

  class 2Rnd_Missile_AA_03_F: 2Rnd_Missile_AA_04_F {
    displayNameShort = "$STR_A3_CFGMAGAZINES_4RND_AAA_MISSILES_DNS";
    ammo = "Missile_AA_03_F";
    count = 2;
  };
  class 4Rnd_Missile_AGM_01_F: 6Rnd_Missile_AGM_02_F {
    displayNameShort = "$STR_A3_CFGMAGAZINES_38RND_80MM_ROCKETS_DNS";
    ammo = "Missile_AGM_01_F";
    count = 4;
  };

  class 20Rnd_Rocket_03_HE_F: 7Rnd_Rocket_04_HE_F {
    displayNameShort = "$STR_A3_CFGMAGAZINES_40RND_20MM_G_BELT_DNS";
    ammo = "Rocket_03_HE_F";
    count = 20;
  };
  class 20Rnd_Rocket_03_AP_F: 7Rnd_Rocket_04_AP_F {
    displayNameShort = "$STR_A3_CFGMAGAZINES_TITAN_AP_DNS";
    ammo = "Rocket_03_AP_F";
    count = 20;
  };

  class 2Rnd_Bomb_03_F: 4Rnd_Bomb_04_F {
    displayNameShort = "$STR_A3_CFGVEHICLES_BOMB0";
    ammo = "Bomb_03_F";
    count = 2;
  };

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

class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;

class CfgWeapons {
  class MissileLauncher;
  class RocketPods;
  class SmokeLauncher;
  class CannonCore;
  class MGunCore;
  class MGun: MGunCore {};
  class LMG_RCWS: MGun {};

  // Manual Switching Of Flare Mode
  class CMFlareLauncher: SmokeLauncher {
    modes[] = {"Single", "Burst", "AIBurst"};
    class Single: Mode_SemiAuto {
      reloadTime = 0.1;
    };
    class Burst: Mode_Burst {
      displayName = "$STR_AGM_Aircraft_CMFlareLauncher_Burst_Name";
    };
  };

  class gatling_20mm: CannonCore {
    magazines[] = {"2000Rnd_20mm_shells","1000Rnd_20mm_shells","300Rnd_20mm_shells","AGM_500Rnd_20mm_shells_Comanche"};

    class manual: CannonCore {
      reloadTime = 0.023;
      dispersion = 0.006;
    };
    class close: manual{};
    class short: close{};
    class medium: close{};
    class far: close{};
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
      displayName = "XM301";
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

  class LMG_Minigun: LMG_RCWS {
    magazines[] = {"5000Rnd_762x51_Belt","5000Rnd_762x51_Yellow_Belt","2000Rnd_762x51_Belt_T_Red","2000Rnd_762x51_Belt_T_Green","2000Rnd_762x51_Belt_T_Yellow", "200Rnd_65x39_belt", "200Rnd_65x39_belt_Tracer_Red", "200Rnd_65x39_belt_Tracer_Green", "200Rnd_65x39_belt_Tracer_Yellow", "2000Rnd_65x39_belt", "2000Rnd_65x39_belt_Tracer_Red", "2000Rnd_65x39_belt_Tracer_Green", "2000Rnd_65x39_belt_Tracer_Yellow", "1000Rnd_65x39_belt", "1000Rnd_65x39_belt_Tracer_Red", "1000Rnd_65x39_belt_Tracer_Green", "1000Rnd_65x39_belt_Tracer_Yellow"};
    class manual: MGun {
      reloadTime = 0.015;
      dispersion = 0.006;
    };
    class close: manual{};
    class short: close{};
    class medium: close{};
    class far: close{};
  };
  class LMG_Minigun_heli: LMG_Minigun {
    showAimCursorInternal = 0;
    class manual: manual {
      reloadTime = 0.015;
      dispersion = 0.006;
    };
    class close: manual{};
    class short: close{};
    class medium: close{};
    class far: close{};
  };
  class M134_minigun: MGunCore {
    class LowROF: Mode_FullAuto {
      reloadTime = 0.015;
      dispersion = 0.006;
    };
    class HighROF: LowROF {
      reloadTime = 0.015;
      dispersion = 0.006;
    };
    class close: HighROF{};
    class short: close{};
    class medium: LowROF{};
    class far: medium{};
  };

  class Gatling_30mm_Plane_CAS_01_F: CannonCore {
    autoFire = 1;
    burst = 1;
    reloadTime = 0.0154;
    class LowROF: Mode_FullAuto {
      autoFire = 0;
      burst = 65;
      reloadTime = 0.0154;
      //sound[] = {"A3\Sounds_F_epc\weapons\cas_02_cannon",1.77828,1,3800};
      sound[] = {"A3\Sounds_F_EPC\Weapons\gau_03_burst",2.51189,1,4500,{25704,32159}};
      weaponSoundEffect = "DefaultRifle";
      dispersion = 0.005;
      soundContinuous = 1;
      textureType = "burst";
    };
    class close: LowROF{};
    class near: close{};
    class short: close{};
    class medium: close{};
    class far: close{};
  };

  class Missile_AA_04_Plane_CAS_01_F: RocketPods {
    holdsterAnimValue = 2;
    aiRateOfFire = 5;
    aiRateOfFireDistance = 500;
    autoFire = 0;
    cursor = "EmptyCursor";
    cursorAim = "missile";
    nameSound = "MissileLauncher";
    textureType = "fullAuto";
    weaponLockDelay = 3;
    minRange = 300;
    minRangeProbab = 0.25;
    midRange = 2500;
    midRangeProbab = 0.9;
    maxRange = 9000;
    maxRangeProbab = 0.01;
  };

  class Missile_AGM_02_Plane_CAS_01_F: MissileLauncher {
    holdsterAnimValue = 3;
    magazineReloadTime = 30;
    reloadTime = 0.001;
    textureType = "semi";
    weaponLockDelay = 3;
    weaponSoundEffect = "DefaultRifle";
  };

  class Rocket_04_HE_Plane_CAS_01_F: RocketPods {
    holdsterAnimValue = 4;
    canLock = 1;
    modes[] = {"Far_AI","Medium_AI","Close_AI","Burst"};
    weaponLockDelay = 0;
    class Far_AI: RocketPods {
      canLock = 1;
      weaponLockDelay = 0;
      showToPlayer = 0;
      minRange = 800;
      minRangeProbab = 0.31;
      midRange = 2500;
      midRangeProbab = 0.71;
      maxRange = 3200;
      maxRangeProbab = 0.1;
      burst = 1;
      reloadTime = 0.001;
      autoFire = 0;
      aiRateOfFire = 5;
      aiRateOfFireDistance = 500;
    };
    class Medium_AI: Far_AI {  };
    class Close_AI: Far_AI {  };
    class Burst: RocketPods {
      burst = 1;
      reloadTime = 0.002;
      minRange = 300;
      minRangeProbab = 0.25;
      midRange = 400;
      midRangeProbab = 0.7;
      maxRange = 1300;
      maxRangeProbab = 0.1;
      aiRateOfFire = 5;
      aiRateOfFireDistance = 500;
      autoFire = 0;
      soundContinuous = 0;
      textureType = "fullAuto";
      weaponSoundEffect = "DefaultRifle";
    };
  };

  class Rocket_04_AP_Plane_CAS_01_F: Rocket_04_HE_Plane_CAS_01_F {
    holdsterAnimValue = 5;
  };

  class Bomb_04_Plane_CAS_01_F: RocketPods {
    holdsterAnimValue = 6;
    aiRateOfFire = 5;
    aiRateOfFireDistance = 500;
    missileLockCone = 180;
    nameSound = "";
    textureType = "fullAuto";
    weaponLockDelay = 1;
  };

  class Cannon_30mm_Plane_CAS_02_F: CannonCore {
    scope = 1;
    holdsterAnimValue = 1;
    ballisticsComputer = 2;
    canLock = 1;
    modes[] = {"LowROF","close","near","short","medium","far"};
    nameSound = "cannon";
    shotFromTurret = 0;
    muzzlePos = "Cannon_muzzleflash";
    muzzleEnd = "Cannon_barrel_end";
    selectionFireAnim = "Cannon_muzzleflash";
    autoFire = 1;
    burst = 5;
    reloadTime = 0.04;
    class GunParticles {
      class Effect {
        effectName = "MachineGun2";
        positionName = "Cannon_barrel_start";
        directionName = "Cannon_barrel_end";
      };
    };
    class LowROF: Mode_FullAuto {
      dispersion = 0.0055;
      reloadTime = 0.04;
    };
    class close: LowROF{};
    class near: close{};
    class short: close{};
    class medium: close{};
    class far: close{};
  };
};

class CfgVehicles {
  // Basic Inheritance
  class AllVehicles;
  class Air: AllVehicles {
    class AnimationSources;
  };
  class Helicopter: Air {
    class AnimationSources: AnimationSources {};
    class Turrets {
      class MainTurret;
    };
  };
  class Helicopter_Base_F: Helicopter {
    class Turrets: Turrets {
      class MainTurret: MainTurret {};
    };
  };
  class Helicopter_Base_H: Helicopter_Base_F {
    class AnimationSources: AnimationSources {};
    class Turrets: Turrets {
      class CopilotTurret: MainTurret {};
    };
  };
  class Plane_Base_F;

  // BLUFOR Inheritance
  class Heli_Attack_01_base_F: Helicopter_Base_F {
    class AnimationSources;
    class MFD {
      class AirplaneHUD;
    };
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
      class CopilotTurret: CopilotTurret {};
      class MainTurret: MainTurret {};
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
    lockDetectionSystem = 15;
    incomingMissileDetectionSystem = 16;
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
    class MFD: MFD {
      class AirplaneHUD: AirplaneHUD {
        helmetPosition[] = {-0.0276,0.024,0.1};
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
    lockDetectionSystem = 15;
    incomingMissileDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {
        canEject = 1;
      };
      class MainTurret: MainTurret {
        magazines[] = {"2000Rnd_762x51_Belt_T_Red"};
        canEject = 1;
      };
      class RightDoorGun: RightDoorGun {
        magazines[] = {"2000Rnd_762x51_Belt_T_Red"};
        canEject = 1;
      };
    };
  };
  class B_Heli_Light_01_F: Heli_Light_01_base_F {
    lockDetectionSystem = 15;
    incomingMissileDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {
        canEject = 1;
      };
    };
  };
  class B_Heli_Light_01_armed_F: Heli_Light_01_armed_base_F {
    lockDetectionSystem = 15;
    incomingMissileDetectionSystem = 16;
    driverCanEject = 1;
    class MFD {
      class AirplaneHUD {
        borderBottom = 0;
        borderLeft = 0;
        borderRight = 0;
        borderTop = 0;
        bottomLeft = "HUD LD";
        color[] = {0,1,0,0.1};
        helmetDown[] = {-0,-0.05,0};
        helmetMountedDisplay = 1;
        helmetPosition[] = {-0.0276,0.024,0.1};
        helmetRight[] = {0.055,0,0};
        topLeft = "HUD LH";
        topRight = "HUD PH";
        class Pos10Vector {
          pos0[] = {0.502,0.49};
          pos10[] = {1.112,1.03};
          type = "vector";
        };
        class Bones {
          /*
          class GunnerAim: Pos10Vector {
            pos0[] = {0,-0.0025};
            pos10[] = {0.01,0.0025};
            source = "weapon";
          };*/
          class ILS_H {
            pos0[] = {0.5,0.49};
            pos3[] = {0.683,0.49};
            type = "ils";
          };
          class ILS_W: ILS_H {
            pos0[] = {0.5,0.49};
            pos3[] = {0.5,0.652};
            type = "ils";
          };
          class Level0: Pos10Vector {
            angle = 0;
            pos0[] = {0.5,0.49};
            pos10[] = {1.11,1.03};
            type = "horizon";
          };
          class LevelM10: Level0 {
            angle = -10;
          };
          class LevelM20: Level0 {
            angle = -20;
          };
          class LevelM30: Level0 {
            angle = -30;
          };
          class LevelM40: Level0 {
            angle = -40;
          };
          class LevelM50: Level0 {
            angle = -50;
          };
          class LevelP10: Level0 {
            angle = 10;
          };
          class LevelP20: Level0 {
            angle = 20;
          };
          class LevelP30: Level0 {
            angle = 30;
          };
          class LevelP40: Level0 {
            angle = 40;
          };
          class LevelP50: Level0 {
            angle = 50;
          };
          class PlaneW {
            pos[] = {0.502,0.49};
            type = "fixed";
          };
          class Target: Pos10Vector {
            source = "target";
          };
          class Velocity: Pos10Vector {
            pos0[] = {0.5,0.49};
            pos10[] = {1.11,1.03};
            source = "velocity";
            type = "vector";
          };
          class WeaponAim: Pos10Vector {
            source = "weapon";
          };
        };
        class Draw {
          class AAMissile {
            condition = "AAmissile";
            class Circle {
              points[] = {{"WeaponAim",{0,-0.221311},1},{"WeaponAim",{0.125,-0.192541},1},{"WeaponAim",{0.2175,-0.110656},1},{"WeaponAim",{0.25,0},1},{"WeaponAim",{0.2175,0.110656},1},{"WeaponAim",{0.125,0.192541},1},{"WeaponAim",{0,0.221311},1},{"WeaponAim",{-0.125,0.192541},1},{"WeaponAim",{-0.2175,0.110656},1},{"WeaponAim",{-0.25,0},1},{"WeaponAim",{-0.2175,-0.110656},1},{"WeaponAim",{-0.125,-0.192541},1},{"WeaponAim",{0,-0.221311},1},{},{"Target",{0,-0.0619672},1},{"Target",{0.07,0},1},{"Target",{0,0.0619672},1},{"Target",{-0.07,0},1},{"Target",{0,-0.0619672},1}};
              type = "line";
              width = 4;
            };
          };
          class SpeedNumber {
            align = "right";
            down[] = {{0.06,0.52},1};
            pos[] = {{0.06,0.47},1};
            right[] = {{"0.14-0.02",0.47},1};
            scale = 1;
            source = "speed";
            sourceScale = 3.6;
            type = "text";
          };
          class AltNumber: SpeedNumber {
            down[] = {{"0.86-0.15",0.52},1};
            pos[] = {{"0.86-0.15",0.47},1};
            right[] = {{"0.94-0.15-0.02",0.47},1};
            source = "altitudeAGL";
            sourceScale = 1;
          };
          class AltScale {
            align = "right";
            bottom = 0.2;
            center = 0.5;
            down[] = {0.86,0.87};
            horizontal = 0;
            lineXleft = 0.825;
            lineXleftMajor = 0.825;
            lineYright = 0.835;
            lineYrightMajor = 0.845;
            majorLineEach = 5;
            max = "none";
            min = "none";
            numberEach = 5;
            pos[] = {0.86,0.82};
            right[] = {"0.94-0.02",0.82};
            scale = 1;
            source = "altitudeAGL";
            sourceScale = 1;
            step = 20;
            StepSize = "(0.85- 0.2)/20";
            top = 0.85;
            type = "scale";
            width = 4;
          };
          class ammo {
            align = "right";
            down[] = {{0.1,0.97},1};
            pos[] = {{0.1,0.93},1};
            right[] = {{"0.16-0.02",0.93},1};
            scale = 0.5;
            source = "ammo";
            sourceScale = 1;
            type = "text";
          };
          class ATMissile {
            condition = "ATmissile";
            class Circle {
              points[] = {{"WeaponAim",{-0.15,-0.15},1},{"WeaponAim",{-0.15,"-0.15+0.02"},1},{},{"WeaponAim",{-0.15,0.15},1},{"WeaponAim",{-0.15,"+0.15-0.02"},1},{},{"WeaponAim",{0.15,-0.15},1},{"WeaponAim",{0.15,"-0.15+0.02"},1},{},{"WeaponAim",{0.15,0.15},1},{"WeaponAim",{0.15,"+0.15-0.02"},1},{},{"WeaponAim",{-0.15,-0.15},1},{"WeaponAim",{"-0.15+0.02",-0.15},1},{},{"WeaponAim",{-0.15,0.15},1},{"WeaponAim",{"-0.15+0.02",0.15},1},{},{"WeaponAim",{0.15,-0.15},1},{"WeaponAim",{"0.15-0.02",-0.15},1},{},{"WeaponAim",{0.15,0.15},1},{"WeaponAim",{"0.15-0.02",0.15},1},{}};
              type = "line";
              width = 4;
            };
          };
          class Bomb {
            condition = "bomb";
            class Circle {
              points[] = {{"WeaponAim",{0,-0.0885246},1},{"WeaponAim",{0.05,-0.0770164},1},{"WeaponAim",{0.087,-0.0442623},1},{"WeaponAim",{0.1,0},1},{"WeaponAim",{0.087,0.0442623},1},{"WeaponAim",{0.05,0.0770164},1},{"WeaponAim",{0,0.0885246},1},{"WeaponAim",{-0.05,0.0770164},1},{"WeaponAim",{-0.087,0.0442623},1},{"WeaponAim",{-0.1,0},1},{"WeaponAim",{-0.087,-0.0442623},1},{"WeaponAim",{-0.05,-0.0770164},1},{"WeaponAim",{0,-0.0885246},1},{},{"Velocity",0.001,"WeaponAim",{0,0},1},{"Velocity",{0,0},1},{},{"Target",{0,-0.0619672},1},{"Target",{0.07,0},1},{"Target",{0,0.0619672},1},{"Target",{-0.07,0},1},{"Target",{0,-0.0619672},1}};
              type = "line";
              width = 4;
            };
          };/*
          class Gunner {
            points[] = {{"GunnerAim",{"0.5-0.015","0.9-0.008"},1},{"GunnerAim",{"0.5-0.015","0.9+0.008"},1},{"GunnerAim",{"0.5+0.015","0.9+0.008"},1},{"GunnerAim",{"0.5+0.015","0.9-0.008"},1},{"GunnerAim",{"0.5-0.015","0.9-0.008"},1}};
            type = "line";
            width = 4;
          };*/
          class HeadingScale {
            align = "center";
            bottom = 0.7;
            center = 0.5;
            down[] = {"0.30-0.00","0.04+0.05"};
            horizontal = 1;
            lineXleft = "0.06+0.05";
            lineXleftMajor = "0.07+0.05";
            lineYright = "0.05+0.05";
            lineYrightMajor = "0.04+0.05";
            majorLineEach = 3;
            max = "none";
            min = "none";
            numberEach = 3;
            pos[] = {"0.30-0.00","0.0+0.05"};
            right[] = {"0.36-0.00","0.0+0.05"};
            scale = 1;
            source = "Heading";
            sourceScale = 1;
            step = 10;
            StepSize = "(0.70- 0.3)/15";
            top = 0.3;
            type = "scale";
            width = 4;
          };
          class HorizontalLine {
            clipBR[] = {0.8,0.96};
            clipTL[] = {0.2,0.12};
            class HorizontalLineDraw {
              points[] = {{"Level0",{"-6*0.075/2",0.02},1},{"Level0",{"-5*0.075/2",0.02},1},{},{"Level0",{"-4*0.075/2",0.02},1},{"Level0",{"-3*0.075/2",0.02},1},{},{"Level0",{"-2*0.075/2",0.02},1},{"Level0",{"-1*0.075/2",0.02},1},{},{"Level0",{"1*0.075/2",0.02},1},{"Level0",{"2*0.075/2",0.02},1},{},{"Level0",{"3*0.075/2",0.02},1},{"Level0",{"4*0.075/2",0.02},1},{},{"Level0",{"5*0.075/2",0.02},1},{"Level0",{"6*0.075/2",0.02},1}};
              source = "Level0";
              type = "line";
            };
          };
          class MGun {
            condition = "mgun";
            class Circle {
              points[] = {{"WeaponAim",{0.05,0},1},{"WeaponAim",{0.015,0},1},{},{"WeaponAim",{0,0.0442623},1},{"WeaponAim",{0,0.0132787},1},{},{"WeaponAim",{-0.05,0},1},{"WeaponAim",{-0.015,0},1},{},{"WeaponAim",{0,-0.0442623},1},{"WeaponAim",{0,-0.0132787},1},{}};
              type = "line";
              width = 4;
            };
          };
          class PlaneHeading {
            clipBR[] = {1,0};
            clipTL[] = {0,1};
            points[] = {{"Velocity",{0,-0.0177049},1},{"Velocity",{0.014,-0.0123934},1},{"Velocity",{0.02,0},1},{"Velocity",{0.014,0.0123934},1},{"Velocity",{0,0.0177049},1},{"Velocity",{-0.014,0.0123934},1},{"Velocity",{-0.02,0},1},{"Velocity",{-0.014,-0.0123934},1},{"Velocity",{0,-0.0177049},1},{},{"Velocity",{0.04,0},1},{"Velocity",{0.02,0},1},{},{"Velocity",{-0.04,0},1},{"Velocity",{-0.02,0},1},{},{"Velocity",{0,-0.0354098},1},{"Velocity",{0,-0.0177049},1},{}};
            type = "line";
            width = 4;
          };
          class PlaneW {
            clipBR[] = {1,0};
            clipTL[] = {0,1};
            points[] = {{"PlaneW",{0,-0.0177049},1},{"PlaneW",{0.014,-0.0123934},1},{"PlaneW",{0.02,0},1},{"PlaneW",{0.014,0.0123934},1},{"PlaneW",{0,0.0177049},1},{"PlaneW",{-0.014,0.0123934},1},{"PlaneW",{-0.02,0},1},{"PlaneW",{-0.014,-0.0123934},1},{"PlaneW",{0,-0.0177049},1},{}};
            type = "line";
            width = 4;
          };
          class Rockets {
            condition = "Rocket";
            class Circle {
              points[] = {{"WeaponAim",{-0.25,-0.25},1},{"WeaponAim",{-0.25,"-0.25+0.05"},1},{},{"WeaponAim",{-0.25,0.25},1},{"WeaponAim",{-0.25,"+0.25-0.05"},1},{},{"WeaponAim",{0.25,-0.25},1},{"WeaponAim",{0.25,"-0.25+0.05"},1},{},{"WeaponAim",{0.25,0.25},1},{"WeaponAim",{0.25,"+0.25-0.05"},1},{},{"WeaponAim",{-0.25,-0.25},1},{"WeaponAim",{"-0.25+0.05",-0.25},1},{},{"WeaponAim",{-0.25,0.25},1},{"WeaponAim",{"-0.25+0.05",0.25},1},{},{"WeaponAim",{0.25,-0.25},1},{"WeaponAim",{"0.25-0.05",-0.25},1},{},{"WeaponAim",{0.25,0.25},1},{"WeaponAim",{"0.25-0.05",0.25},1},{}};
              type = "line";
              width = 4;
            };
          };
          /*
          class Static {
            clipBR[] = {1,0};
            clipTL[] = {0,0.1};
            points[] = {{{0.79,0.52},1},{{0.81,0.5},1},{{0.79,0.48},1},{},{{0.52,"0.08+0.06"},1},{{0.5,"0.06+0.06"},1},{{0.48,"0.08+0.06"},1},{},{{"0.5-0.1","0.9-0.04"},1},{{"0.5-0.1","0.9+0.04"},1},{{"0.5+0.1","0.9+0.04"},1},{{"0.5+0.1","0.9-0.04"},1},{{"0.5-0.1","0.9-0.04"},1},{},{{"0.5-0.1",0.9},1},{{"0.5-0.092",0.9},1},{},{{"0.5+0.1",0.9},1},{{"0.5+0.092",0.9},1},{},{{0.5,"0.9-0.04"},1},{{0.5,"0.9-0.032"},1},{},{{0.5,"0.9+0.04"},1},{{0.5,"0.9+0.032"},1},{}};
            type = "line";
            width = 4;
          };
          */
          class weapons {
            align = "right";
            down[] = {{0.1,0.92},1};
            pos[] = {{0.1,0.88},1};
            right[] = {{"0.16-0.02",0.88},1};
            scale = 0.5;
            source = "weapon";
            sourceScale = 1;
            type = "text";
          };
        };
      };
    };
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {
        canEject = 1;
      };
    };
  };
  class B_Plane_CAS_01_F: Plane_CAS_01_base_F {
    lockDetectionSystem = 15;
    incomingMissileDetectionSystem = 16;
  };

  // INDEP
  class I_Heli_light_03_F: I_Heli_light_03_base_F {
    weapons[] = {"M134_minigun","missiles_DAR","CMFlareLauncher"};
    magazines[] = {"5000Rnd_762x51_Yellow_Belt","24Rnd_missiles","168Rnd_CMFlare_Chaff_Magazine"};
    lockDetectionSystem = 15;
    incomingMissileDetectionSystem = 16;
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
    lockDetectionSystem = 15;
    incomingMissileDetectionSystem = 16;
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
    lockDetectionSystem = 15;
    incomingMissileDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {
        canEject = 1;
      };
    };
  };
  class I_Plane_Fighter_03_CAS_F: Plane_Fighter_03_base_F {
    lockDetectionSystem = 15;
    incomingMissileDetectionSystem = 16;
  };

  // OPFOR
  class O_Heli_Attack_02_F: Heli_Attack_02_base_F {
    lockDetectionSystem = 15;
    incomingMissileDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        canEject = 1;
      };
    };
  };
  class O_Heli_Attack_02_black_F: Heli_Attack_02_base_F {
    lockDetectionSystem = 15;
    incomingMissileDetectionSystem = 16;
    driverCanEject = 1;
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        canEject = 1;
      };
    };
  };
  class O_Heli_Light_02_F: Heli_Light_02_base_F {
    driverCanEject = 1;
    lockDetectionSystem = 15;
    incomingMissileDetectionSystem = 16;
    magazines[] = {"2000Rnd_762x51_Belt_T_Green", "12Rnd_PG_missiles", "168Rnd_CMFlare_Chaff_Magazine"};
    class Turrets: Turrets {
      class CopilotTurret: CopilotTurret {
        canEject = 1;
      };
    };
  };
  class O_Heli_Light_02_unarmed_F: Heli_Light_02_base_F {
    lockDetectionSystem = 15;
    incomingMissileDetectionSystem = 16;
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
    lockDetectionSystem = 15;
    incomingMissileDetectionSystem = 16;
  };
};
