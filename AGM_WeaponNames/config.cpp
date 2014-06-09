class CfgPatches {
  class AGM_WeaponNames {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Vehicles, AGM_Aircraft, A3_Weapons_F, A3_Weapons_F_beta, A3_Weapons_F_gamma, A3_Weapons_F_Acc, A3_Weapons_F_Beta_Acc, A3_Characters_F};
    version = "0.9";
    versionStr = "0.9";
    versionAr[] = {0,9,0};
    author[] = {"KoffeinFlummi", "TaoSensai"};
    authorUrl = "https://github.com/KoffeinFlummi";
  };
};

class Mode_FullAuto;

class CfgWeapons {
  class Rifle_Base_F;
  class CannonCore;
  class RocketPods;
  class MissileLauncher;
  class MGunCore;
  class MGun;
  class LMG_RCWS;
  class GMG_F;
  class Bomb_04_Plane_CAS_01_F;
  class autocannon_Base_F;

  // INFANTRY STUFF
  // (I indented this on purpose, so you can collapse it in ST)
    class arifle_MX_Base_F;
    class arifle_MX_F : arifle_MX_Base_F {
      displayName = "MX";
    };
    class arifle_MXC_F : arifle_MX_Base_F {
      displayName = "MXC";
    };
    class arifle_MX_GL_F : arifle_MX_Base_F {
      displayName = "MX 3GL";
    };
    class arifle_MX_SW_F : arifle_MX_Base_F {
      displayName = "MX LSW";
    };
    class arifle_MXM_F : arifle_MX_Base_F {
      displayName = "MXM";
    };

    class arifle_katiba_Base_F;
    class arifle_Katiba_F : arifle_katiba_Base_F {
      displayName = "KT2002 Katiba";
    };
    class arifle_Katiba_GL_F : arifle_katiba_Base_F {
      displayName = "KT2002 Katiba KGL";
    };
    class arifle_Katiba_C_F : arifle_katiba_Base_F {
      displayName = "KT2002C Katiba";
    };

    class SDAR_base_F;
    class arifle_SDAR_F : SDAR_base_F {
      displayName = "CFB SDAR";
    };

    class Tavor_base_F;
    class arifle_TRG21_F : Tavor_base_F {
      displayName = "TAR-21";
    };
    class arifle_TRG21_GL_F : arifle_TRG21_F {
      displayName = "TAR-21 EGLM";
    };
    class arifle_TRG20_F : Tavor_base_F {
      displayName = "CTAR-21";
    };

    class mk20_base_F;
    class arifle_Mk20_F : mk20_base_F {
      displayName = "F2000A";
    };
    class arifle_Mk20C_F : mk20_base_F {
      displayName = "F2000A Tactical";
    };
    class arifle_Mk20_GL_F : mk20_base_F {
      displayName = "F2000A EGLM";
    };

    class SMG_01_Base : Rifle_Base_F {
      displayName = "Vector SMG";
    };
    class SMG_01_F : SMG_01_Base {
      displayName = "Vector SMG";
    };

    class SMG_02_base_F;
    class SMG_02_F : SMG_02_base_F {
      displayName = "Scorpion Evo 3A1";
    };

    class pdw2000_base_F;
    class hgun_pdw2000_F : pdw2000_base_F {
      displayName = "CPW-CZ";
    };

    class Pistol_Base_F;
    class hgun_P07_F : Pistol_Base_F {
      displayName = "P99G";
    };

    class hgun_Rook40_F : Pistol_Base_F {
      displayName = "MP-443G";
    };

    class hgun_ACPC2_F : Pistol_Base_F {
      displayName = "ACP-C2";
    };

    class Rifle_Long_Base_F;
    class LMG_Mk200_F : Rifle_Long_Base_F {
      displayName = "Mk200 LMG";
    };

    class LMG_Zafir_F: Rifle_Long_Base_F {
      displayName = "Negev NG7";
    };

    class EBR_base_F;
    class srifle_EBR_F : EBR_base_F {
      displayName = "Mk14 Mod 1 EBR";
    };

    class LRR_base_F;
    class srifle_LRR_F : LRR_base_F {
      displayName = "M200 Intervention";
    };

    class GM6_base_F;
    class srifle_GM6_F : GM6_base_F {
      displayName = "GM6 Lynx";
    };

  // VEHICLE STUFF
    class gatling_20mm: CannonCore {
      class manual;
    };
    class Twin_Cannon_20mm: gatling_20mm {
      displayName = "Plamen PL-20";
      class manual: manual {
        displayName = "Plamen PL-20";
      };
    };
    class gatling_30mm: CannonCore { // This is a fictional veresion of the GSh-6-30, with 3 barrels
      displayName = "GSh-3-30";
      class LowROF: Mode_FullAuto {
        displayName = "GSh-3-30";
      };
    };
    class Gatling_30mm_Plane_CAS_01_F: CannonCore {
      displayName = "GAU-8";
      class LowROF: Mode_FullAuto {
        displayName = "GAU-8";
      };
    };
    class Cannon_30mm_Plane_CAS_02_F: CannonCore {
      displayName = "GSh-301";
      class LowROF: Mode_FullAuto {
        displayName = "GSh-301";
      };
    };
    class Missile_AA_04_Plane_CAS_01_F: RocketPods {
      displayName = "AIM-9 Sidewinder";
    };
    class Missile_AA_03_Plane_CAS_02_F: Missile_AA_04_Plane_CAS_01_F {
      displayName = "Wympel R-73";
    };
    class Missile_AGM_02_Plane_CAS_01_F: MissileLauncher {
      displayName = "AGM-65 Maverick";
    };
    class Missile_AGM_01_Plane_CAS_02_F: Missile_AGM_02_Plane_CAS_01_F {
      displayName = "Kh-25MTP";
    };
    class Rocket_04_HE_Plane_CAS_01_F: RocketPods {
      displayName = "Hydra 70";
      class Burst: RocketPods {
        displayName = "Hydra 70";
      };
    };
    class Rocket_04_AP_Plane_CAS_01_F: Rocket_04_HE_Plane_CAS_01_F {
      displayName = "Hydra 70";
      class Burst: RocketPods {
        displayName = "Hydra 70";
      };
    };
    class Rocket_03_HE_Plane_CAS_02_F: Rocket_04_HE_Plane_CAS_01_F {
      displayName = "S-8";
      class Burst: Burst {
        displayName = "S-8";
      };
    };
    class Rocket_03_AP_Plane_CAS_02_F: Rocket_04_AP_Plane_CAS_01_F {
      displayName = "S-8";
      class Burst: Burst {
        displayName = "S-8";
      };
    };
    class rockets_Skyfire: RocketPods {
      displayName = "Skyfire-70";
      class Burst: RocketPods {
        displayName = "Skyfire-70";
      };
    };
    class missiles_DAR: RocketPods {
      displayName = "Hydra 70";
      class Burst: RocketPods {
        displayName = "Hydra 70";
      };
    };
    class missiles_DAGR: RocketPods {
      displayName = "DAGR";
      class Burst: RocketPods {
        displayName = "DAGR";
      };
    };
    class missiles_ASRAAM: MissileLauncher {
      displayName = "AIM-132 ASRAAM";
    };
    class missiles_Zephyr: MissileLauncher {
      displayName = "AIM-120A AMRAAM";
    };
    class missiles_SCALPEL: RocketPods { // according to zGuba, this is what it's based on
      displayName = "9K121 Vikhr";
    };
    class Bomb_03_Plane_CAS_02_F: Bomb_04_Plane_CAS_01_F {
      displayName = "FAB-250M-54";
    };

    class M134_minigun: MGunCore {
      displayName = "2x M134 Minigun";
    };
    class LMG_Minigun: LMG_RCWS {
      displayName = "M134 Minigun";
      class manual: MGun {
        displayName = "M134 Minigun";
      };
    };
    class HMG_127: LMG_RCWS {
      displayName = "M2";
      class manual: MGun {
        displayName = "M2";
      };
    };
    class HMG_01: HMG_127 {};
    class HMG_M2: HMG_01 {
      displayName = "M2";
    };
    class HMG_NSVT: HMG_127 {
      displayName = "NSVT";
      class manual: manual {
        displayName = "NSVT";
      };
    };
    class GMG_40mm: GMG_F {
      displayName = "Mk 19";
      class manual: GMG_F {
        displayName = "Mk 19";
      };
    };

    class autocannon_35mm: CannonCore {
      displayName = "GDF-001";
      class manual: CannonCore {
        displayName = "GDF-001";
      };
    };
    class missiles_titan: MissileLauncher {
      displayName = "Mini-Spike";
    };
    class mortar_155mm_AMOS: CannonCore {
      displayName = "L/52";
    };
    class rockets_230mm_GAT: RocketPods {
      displayName = "M269";
    };
    class cannon_120mm: CannonCore {
      class player;
      displayName = "MG251";
    };
    class cannon_120mm_long: cannon_120mm {
      displayName = "L/55";
      class player: player {};
    };
    class cannon_105mm: cannon_120mm {
      displayName = "M68";
      class player: player {
        displayName = "M68";
      };
    };
    class cannon_125mm: cannon_120mm {
      displayName = "2A46";
    };
    class LMG_coax: LMG_RCWS {
      displayName = "PKT";
    };
    class AGM_LMG_coax_MBT_01: LMG_coax {
      displayName = "MAG 58";
    };
    class AGM_LMG_coax_APC_Tracked_03: LMG_coax {
      displayName = "L94A1";
    };
    class autocannon_40mm_CTWS: autocannon_Base_F {
      displayName = "Mk44 Bushmaster II";
      class AP: autocannon_Base_F {
        displayName = "Mk44 Bushmaster II";
      };
      class HE: autocannon_Base_F {
        displayName = "Mk44 Bushmaster II";
      };
    };
    class autocannon_30mm_CTWS: autocannon_Base_F {
      displayName = "Mk44 Bushmaster II";
      class AP: autocannon_Base_F {
        displayName = "Mk44 Bushmaster II";
      };
      class HE: autocannon_Base_F {
        displayName = "Mk44 Bushmaster II";
      };
    };
    class autocannon_30mm: autocannon_30mm_CTWS {
      displayName = "L21A1 RARDEN";
      class AP: AP {
        displayName = "L21A1 RARDEN";
      };
      class HE: HE {
        displayName = "L21A1 RARDEN";
      };
    };
};

class CfgMagazines {
  class VehicleMagazine;
  class 2000Rnd_65x39_Belt;

  class 1000Rnd_Gatling_30mm_Plane_CAS_01_F: VehicleMagazine {
    displayNameShort = "30mm HEI";
  };
  class 7Rnd_Rocket_04_HE_F: VehicleMagazine {
    displayNameShort = "70mm HE";
  };
  class 7Rnd_Rocket_04_AP_F: 7Rnd_Rocket_04_HE_F {
    displayNameShort = "70mm AP";
  };
  class 24Rnd_PG_missiles: VehicleMagazine {
    displayNameShort = "70mm HE";
  };
  class 12Rnd_PG_missiles: 24Rnd_PG_missiles {
    displayNameShort = "70mm HE";
  };
  class 5000Rnd_762x51_Belt: 2000Rnd_65x39_Belt {
    displayNameShort = "7.62mm";
  };
  class 5000Rnd_762x51_Yellow_Belt: 5000Rnd_762x51_Belt {
    displayNameShort = "7.62mm";
  };
  class 500Rnd_127x99_mag: VehicleMagazine {
    displayNameShort = "12.7mm";
  };
  class 500Rnd_127x99_mag_Tracer_Green: 500Rnd_127x99_mag {
    displayNameShort = "12.7mm";
  };
  class 500Rnd_127x99_mag_Tracer_Red: 500Rnd_127x99_mag {
    displayNameShort = "12.7mm";
  };
  class 500Rnd_127x99_mag_Tracer_Yellow: 500Rnd_127x99_mag {
    displayNameShort = "12.7mm";
  };
  class 200Rnd_127x99_mag: 500Rnd_127x99_mag {
    displayNameShort = "12.7mm";
  };
  class 200Rnd_127x99_mag_Tracer_Green: 200Rnd_127x99_mag {
    displayNameShort = "12.7mm";
  };
  class 200Rnd_127x99_mag_Tracer_Red: 200Rnd_127x99_mag {
    displayNameShort = "12.7mm";
  };
  class 200Rnd_127x99_mag_Tracer_Yellow: 200Rnd_127x99_mag {
    displayNameShort = "12.7mm";
  };
  class 100Rnd_127x99_mag: 500Rnd_127x99_mag {
    displayNameShort = "12.7mm";
  };
  class 100Rnd_127x99_mag_Tracer_Green: 100Rnd_127x99_mag {
    displayNameShort = "12.7mm";
  };
  class 100Rnd_127x99_mag_Tracer_Red: 100Rnd_127x99_mag {
    displayNameShort = "12.7mm";
  };
  class 100Rnd_127x99_mag_Tracer_Yellow: 100Rnd_127x99_mag {
    displayNameShort = "12.7mm";
  };
  class 200Rnd_40mm_G_belt: VehicleMagazine {
    displayNameShort = "40mm HE";
  };
  class 24Rnd_missiles: VehicleMagazine {
    displayNameShort = "70mm HE";
  };
  class 300Rnd_20mm_shells: VehicleMagazine {
    displayNameShort = "20mm HE";
  };
  class 14Rnd_80mm_rockets: VehicleMagazine {
    displayNameShort = "70mm HE";
  };
  class 250Rnd_30mm_HE_shells: VehicleMagazine {
    displayNameShort = "30mm HE";
  };
  class 250Rnd_30mm_APDS_shells: 250Rnd_30mm_HE_shells {
    displayNameShort = "30mm APDS";
  };
  class 20Rnd_Rocket_03_HE_F: 7Rnd_Rocket_04_HE_F {
    displayNameShort = "80mm HE";
  };
  class 20Rnd_Rocket_03_AP_F: 7Rnd_Rocket_04_AP_F {
    displayNameShort = "80mm AP";
  };
  class 500Rnd_Cannon_30mm_Plane_CAS_02_F: 1000Rnd_Gatling_30mm_Plane_CAS_01_F {
    displayNameShort = "30mm HEI-T";
  };
  class 680Rnd_35mm_AA_shells: VehicleMagazine {
    displayNameShort = "35mm HEI";
  };
  class 680Rnd_35mm_AA_shells_Tracer_Red: 680Rnd_35mm_AA_shells {
    displayNameShort = "35mm HEI-T";
  };
  class 680Rnd_35mm_AA_shells_Tracer_Green: 680Rnd_35mm_AA_shells {
    displayNameShort = "35mm HEI-T";
  };
  class 680Rnd_35mm_AA_shells_Tracer_Yellow: 680Rnd_35mm_AA_shells {
    displayNameShort = "35mm HEI-T";
  };
  class 32Rnd_155mm_Mo_shells: VehicleMagazine {
    displayNameShort = "155mm HE";
  };
  class 6Rnd_155mm_Mo_smoke: 32Rnd_155mm_Mo_shells {
    displayNameShort = "155mm Smoke";
  };
  class 6Rnd_155mm_Mo_mine: 6Rnd_155mm_Mo_smoke {
    displayNameShort = "155mm Mines";
  };
  class 6Rnd_155mm_Mo_AT_mine: 6Rnd_155mm_Mo_smoke {
    displayNameShort = "155mm AT Mines";
  };
  class 2Rnd_155mm_Mo_Cluster: 6Rnd_155mm_Mo_smoke {
    displayNameShort = "155mm Cluster";
  };
  class 2Rnd_155mm_Mo_guided: 6Rnd_155mm_Mo_smoke {
    displayNameShort = "155mm Guided";
  };
  class 2Rnd_155mm_Mo_LG: 6Rnd_155mm_Mo_smoke {
    displayNameShort = "155mm Laser Guided";
  };
  class 12Rnd_230mm_rockets: 14Rnd_80mm_rockets {
    displayName = "227mm HE Missile";
    displayNameShort = "227mm HE";
  };
  class 30Rnd_120mm_HE_shells: VehicleMagazine {
    displayNameShort = "120mm HE";
  };
  class 30Rnd_120mm_HE_shells_Tracer_Red: 30Rnd_120mm_HE_shells {
    displayNameShort = "120mm HE-T";
  };
  class 30Rnd_120mm_HE_shells_Tracer_Green: 30Rnd_120mm_HE_shells {
    displayNameShort = "120mm HE-T";
  };
  class 30Rnd_120mm_HE_shells_Tracer_Yellow: 30Rnd_120mm_HE_shells {
    displayNameShort = "120mm HE-T";
  };
  class 30Rnd_120mm_APFSDS_shells: 30Rnd_120mm_HE_shells {
    displayNameShort = "120mm AP";
  };
  class 30Rnd_120mm_APFSDS_shells_Tracer_Red: 30Rnd_120mm_APFSDS_shells {
    displayNameShort = "120mm AP-T";
  };
  class 30Rnd_120mm_APFSDS_shells_Tracer_Green: 30Rnd_120mm_APFSDS_shells {
    displayNameShort = "120mm AP-T";
  };
  class 30Rnd_120mm_APFSDS_shells_Tracer_Yellow: 30Rnd_120mm_APFSDS_shells {
    displayNameShort = "120mm AP-T";
  };
  class 200Rnd_762x51_Belt: VehicleMagazine {
    displayNameShort = "7.62mm";
  };
  class 200Rnd_762x51_Belt_Red: 200Rnd_762x51_Belt {};
  class 200Rnd_762x51_Belt_Green: 200Rnd_762x51_Belt {};
  class 200Rnd_762x51_Belt_Yellow: 200Rnd_762x51_Belt {};
  class 200Rnd_762x51_Belt_T_Red: 200Rnd_762x51_Belt_Red {
    displayNameShort = "7.62mm";
  };
  class 200Rnd_762x51_Belt_T_Green: 200Rnd_762x51_Belt_Green {
    displayNameShort = "7.62mm";
  };
  class 200Rnd_762x51_Belt_T_Yellow: 200Rnd_762x51_Belt_Yellow {
    displayNameShort = "7.62mm";
  };
  class 2000Rnd_762x51_Belt_Red;
  class 2000Rnd_762x51_Belt_T_Red: 2000Rnd_762x51_Belt_Red {
    displayNameShort = "7.62mm";
  };
  class 2000Rnd_762x51_Belt_Green;
  class 2000Rnd_762x51_Belt_T_Green: 2000Rnd_762x51_Belt_Green {
    displayNameShort = "7.62mm";
  };
  class 2000Rnd_762x51_Belt_Yellow;
  class 2000Rnd_762x51_Belt_T_Yellow: 2000Rnd_762x51_Belt_Yellow {
    displayNameShort = "7.62mm";
  };
  class 1000Rnd_762x51_Belt_Red;
  class 1000Rnd_762x51_Belt_T_Red: 1000Rnd_762x51_Belt_Red {
    displayNameShort = "7.62mm";
  };
  class 1000Rnd_762x51_Belt_Green;
  class 1000Rnd_762x51_Belt_T_Green: 1000Rnd_762x51_Belt_Green {
    displayNameShort = "7.62mm";
  };
  class 1000Rnd_762x51_Belt_Yellow;
  class 1000Rnd_762x51_Belt_T_Yellow: 1000Rnd_762x51_Belt_Yellow {
    displayNameShort = "7.62mm";
  };

  class 16Rnd_120mm_HE_shells;
  class 16Rnd_120mm_HE_shells_Tracer_Red;
  class 16Rnd_120mm_HE_shells_Tracer_Green;
  class 16Rnd_120mm_HE_shells_Tracer_Yellow;
  class 12Rnd_125mm_HE: 16Rnd_120mm_HE_shells {
    displayNameShort = "125mm HE";
  };
  class 12Rnd_125mm_HE_T_Red: 16Rnd_120mm_HE_shells_Tracer_Red {
    displayNameShort = "125mm HE-T";
  };
  class 12Rnd_125mm_HE_T_Green: 16Rnd_120mm_HE_shells_Tracer_Green {
    displayNameShort = "125mm HE-T";
  };
  class 12Rnd_125mm_HE_T_Yellow: 16Rnd_120mm_HE_shells_Tracer_Yellow {
    displayNameShort = "125mm HE-T";
  };

  class 12Rnd_125mm_HEAT: 12Rnd_125mm_HE {
    displayNameShort = "125mm MP";
  };
  class 12Rnd_125mm_HEAT_T_Red: 12Rnd_125mm_HEAT {
    displayNameShort = "125mm MP-T";
  };
  class 12Rnd_125mm_HEAT_T_Green: 12Rnd_125mm_HEAT {
    displayNameShort = "125mm MP-T";
  };
  class 12Rnd_125mm_HEAT_T_Yellow: 12Rnd_125mm_HEAT {
    displayNameShort = "125mm MP-T";
  };

  class 32Rnd_120mm_APFSDS_shells;
  class 32Rnd_120mm_APFSDS_shells_Tracer_Red;
  class 32Rnd_120mm_APFSDS_shells_Tracer_Green;
  class 32Rnd_120mm_APFSDS_shells_Tracer_Yellow;
  class 24Rnd_125mm_APFSDS: 32Rnd_120mm_APFSDS_shells {
    displayNameShort = "125mm AP";
  };
  class 24Rnd_125mm_APFSDS_T_Red: 32Rnd_120mm_APFSDS_shells_Tracer_Red {
    displayNameShort = "125mm AP-T";
  };
  class 24Rnd_125mm_APFSDS_T_Green: 32Rnd_120mm_APFSDS_shells_Tracer_Green {
    displayNameShort = "125mm AP-T";
  };
  class 24Rnd_125mm_APFSDS_T_Yellow: 32Rnd_120mm_APFSDS_shells_Tracer_Yellow {
    displayNameShort = "125mm AP-T";
  };

  class 20Rnd_105mm_HEAT_MP: 12Rnd_125mm_HEAT {
    displayNameShort = "105mm MP";
  };
  class 20Rnd_105mm_HEAT_MP_T_Red: 20Rnd_105mm_HEAT_MP {
    displayNameShort = "105mm MP-T";
  };
  class 20Rnd_105mm_HEAT_MP_T_Green: 20Rnd_105mm_HEAT_MP {
    displayNameShort = "105mm MP-T";
  };
  class 20Rnd_105mm_HEAT_MP_T_Yellow: 20Rnd_105mm_HEAT_MP {
    displayNameShort = "105mm MP-T";
  };
  class 40Rnd_105mm_APFSDS: 24Rnd_125mm_APFSDS {
    displayNameShort = "105mm AP";
  };
  class 40Rnd_105mm_APFSDS_T_Red: 40Rnd_105mm_APFSDS {
    displayNameShort = "105mm AP-T";
  };
  class 40Rnd_105mm_APFSDS_T_Green: 40Rnd_105mm_APFSDS {
    displayNameShort = "105mm AP-T";
  };
  class 40Rnd_105mm_APFSDS_T_Yellow: 40Rnd_105mm_APFSDS {
    displayNameShort = "105mm AP-T";
  };
  class 60Rnd_40mm_GPR_shells: VehicleMagazine {
    displayNameShort = "40mm GPR";
  };
  class 60Rnd_40mm_GPR_Tracer_Red_shells: 60Rnd_40mm_GPR_shells {
    displayNameShort = "40mm GPR-T";
  };
  class 60Rnd_40mm_GPR_Tracer_Green_shells: 60Rnd_40mm_GPR_shells {
    displayNameShort = "40mm GPR-T";
  };
  class 60Rnd_40mm_GPR_Tracer_Yellow_shells: 60Rnd_40mm_GPR_shells {
    displayNameShort = "40mm GPR-T";
  };
  class 40Rnd_40mm_APFSDS_shells: 60Rnd_40mm_GPR_shells {
    displayNameShort = "40mm AP";
  };
  class 40Rnd_40mm_APFSDS_Tracer_Red_shells: 40Rnd_40mm_APFSDS_shells {
    displayNameShort = "40mm AP-T";
  };
  class 40Rnd_40mm_APFSDS_Tracer_Green_shells: 40Rnd_40mm_APFSDS_shells {
    displayNameShort = "40mm AP-T";
  };
  class 40Rnd_40mm_APFSDS_Tracer_Yellow_shells: 40Rnd_40mm_APFSDS_shells {
    displayNameShort = "40mm AP-T";
  };
  class 450Rnd_127x108_Ball: VehicleMagazine {
    displayNameShort = "12.7mm";
  };

  class 140Rnd_30mm_MP_shells: 250Rnd_30mm_HE_shells {
    displayNameShort = "30mm MP";
  };
  class 140Rnd_30mm_MP_shells_Tracer_Red: 140Rnd_30mm_MP_shells {
    displayNameShort = "30mm MP-T";
  };
  class 140Rnd_30mm_MP_shells_Tracer_Green: 140Rnd_30mm_MP_shells_Tracer_Red {
    displayNameShort = "30mm MP-T";
  };
  class 140Rnd_30mm_MP_shells_Tracer_Yellow: 140Rnd_30mm_MP_shells_Tracer_Red {
    displayNameShort = "30mm MP-T";
  };
  class 60Rnd_30mm_APFSDS_shells: 250Rnd_30mm_HE_shells {
    displayNameShort = "30mm AP";
  };
  class 60Rnd_30mm_APFSDS_shells_Tracer_Red: 60Rnd_30mm_APFSDS_shells {
    displayNameShort = "30mm AP-T";
  };
  class 60Rnd_30mm_APFSDS_shells_Tracer_Green: 60Rnd_30mm_APFSDS_shells {
    displayNameShort = "30mm AP-T";
  };
  class 60Rnd_30mm_APFSDS_shells_Tracer_Yellow: 60Rnd_30mm_APFSDS_shells {
    displayNameShort = "30mm AP-T";
  };
};
