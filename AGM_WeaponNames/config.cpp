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


};