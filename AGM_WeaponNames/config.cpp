class CfgPatches {
  class AGM_WeaponNames {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, A3_Weapons_F, A3_Weapons_F_beta, A3_Weapons_F_gamma, A3_Weapons_F_Acc, A3_Weapons_F_Beta_Acc, A3_Characters_F};
    version = "0.9";
    versionStr = "0.9";
    versionAr[] = {0,9,0};
    author[] = {"KoffeinFlummi", "TaoSensai"};
    authorUrl = "https://github.com/KoffeinFlummi";
  };
};

class CfgWeapons {
  class Rifle_Base_F;
  class CannonCore;
  class RocketPods;
  class MissileLauncher;
  class MGunCore;
  class MGun;
  class LMG_RCWS;

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
    class Gatling_30mm_Plane_CAS_01_F: CannonCore {
      displayName = "GAU-8";
    };
    class Missile_AA_04_Plane_CAS_01_F: RocketPods {
      displayName = "AIM-9 Sidewinder";
    };
    class Missile_AGM_02_Plane_CAS_01_F: MissileLauncher {
      displayName = "AGM-65 Maverick";
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
    class missiles_DAGR: RocketPods {
      displayName = "DAGR";
      class Burst: RocketPods {
        displayName = "DAGR";
      };
    };
    class missiles_ASRAAM: MissileLauncher {
      displayName = "AIM-132 ASRAAM";
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
};

class CfgMagazines {
  class VehicleMagazine;
  class 2000Rnd_65x39_Belt;

  class 1000Rnd_Gatling_30mm_Plane_CAS_01_F: VehicleMagazine {
    displayNameShort = "30mm";
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
};