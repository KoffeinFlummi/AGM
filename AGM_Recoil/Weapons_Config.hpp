/////////////////////////////////////////////////////////////////////////////////
// SMALL ARMS ///////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// 1. Set the recoil profiles for all fire modes.
// 2. Set the shake multiplier. This determines the camshake for the weapon.
//     Ex: agm_recoil_shakeMultiplier = 1;

#define SHAKEMULTIPLIER_BASE            5

class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;

class CfgWeapons {
  class Pistol;
  class Pistol_Base_F: Pistol {
    recoil = "agm_pistolBase";
    recoilProne = "agm_pistolBase";
  };

  class Rifle;
  class Rifle_Base_F: Rifle {
    recoil = "agm_assaultRifleBase";
    recoilProne = "agm_assaultRifleBase";
  };

  class Rifle_Long_Base_F: Rifle_Base_F {};

// PISTOLS
  class hgun_P07_F : Pistol_Base_F {
    recoil = "agm_recoil_pistol_light";
    recoilProne = "agm_recoil_prone_pistol_light";
  };
  class hgun_Rook40_F : Pistol_Base_F {
    recoil = "agm_recoil_pistol_light";
    recoilProne = "agm_recoil_prone_pistol_light";
  };
  class hgun_ACPC2_F : Pistol_Base_F {
    recoil = "agm_recoil_pistol_heavy";
    recoilProne = "agm_recoil_prone_pistol_heavy";
  };
  class hgun_Pistol_heavy_01_F : Pistol_Base_F {
    recoil = "agm_recoil_pistol_heavy";
    recoilProne = "agm_recoil_prone_pistol_heavy";
  };
  class hgun_Pistol_heavy_02_F : Pistol_Base_F {
    recoil = "agm_recoil_pistol_heavy";
    recoilProne = "agm_recoil_prone_pistol_heavy";
  };

// SUBMACHINE GUNS
  class SMG_01_Base : Rifle_Base_F {
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_smg_01";
      recoilProne = "agm_recoil_single_prone_smg_01";
    };
    class Burst : Mode_Burst {
      recoil = "agm_recoil_burst_smg_01";
      recoilProne = "agm_recoil_burst_smg_01";
    };
    class FullAuto : Mode_FullAuto {
      recoil = "agm_recoil_auto_smg_01";
      recoilProne = "agm_recoil_auto_prone_smg_01";
    };
  };
  class SMG_02_Base_F : Rifle_Base_F {
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_smg_02";
      recoilProne = "agm_recoil_single_prone_smg_02";
    };
    class Burst : Mode_Burst {
      recoil = "agm_recoil_burst_smg_02";
      recoilProne = "agm_recoil_burst_smg_02";
    };
    class FullAuto : Mode_FullAuto {
      recoil = "agm_recoil_auto_smg_02";
      recoilProne = "agm_recoil_auto_prone_smg_02";
    };
  };
  class pdw2000_base_F: Rifle_Base_F {
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_pdw";
      recoilProne = "agm_recoil_single_prone_pdw";
    };
    class FullAuto : Mode_FullAuto {
      recoil = "agm_recoil_auto_pdw";
      recoilProne = "agm_recoil_auto_prone_pdw";
    };
  };

// ASSAULT RIFLE
  class arifle_MX_Base_F : Rifle_Base_F {
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_mx";
      recoilProne = "agm_recoil_single_prone_mx";
    };
    class FullAuto : Mode_FullAuto {
      recoil = "agm_recoil_auto_mx";
      recoilProne = "agm_recoil_auto_prone_mx";
    };
  };
  class arifle_MX_SW_F : arifle_MX_Base_F {
    class Single : Mode_SemiAuto {//Single
      recoil = "agm_recoil_single_mx";
      recoilProne = "agm_recoil_single_prone_mx";
    };
    class manual : FullAuto {
      recoil = "agm_recoil_auto_mx";
      recoilProne = "agm_recoil_auto_prone_mx";
    };
  };
  class arifle_katiba_Base_F : Rifle_Base_F {
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_ktb";
      recoilProne = "agm_recoil_single_prone_ktb";
    };
    class FullAuto : Mode_FullAuto {
      recoil = "agm_recoil_auto_ktb";
      recoilProne = "agm_recoil_auto_prone_ktb";
    };
  };
  class mk20_base_F : Rifle_Base_F {
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_mk20";
      recoilProne = "agm_recoil_single_prone_mk20";
    };
    class FullAuto : Mode_FullAuto {
      recoil = "agm_recoil_auto_mk20";
      recoilProne = "agm_recoil_auto_prone_mk20";
    };
  };
  class arifle_Mk20C_F : mk20_base_F {
    class Single : Single {
      recoil = "agm_recoil_single_mk20";
      recoilProne = "agm_recoil_single_prone_mk20";
    };
    class FullAuto : FullAuto {
      recoil = "agm_recoil_auto_mk20";
      recoilProne = "agm_recoil_auto_prone_mk20";
    };
  };
  class Tavor_base_F : Rifle_Base_F {
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_trg";
      recoilProne = "agm_recoil_single_prone_trg";
    };
    class FullAuto : Mode_FullAuto {
      recoil = "agm_recoil_auto_trg";
      recoilProne = "agm_recoil_auto_prone_trg";
    };
  };
  class SDAR_base_F : Rifle_Base_F {
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_sdar";
      recoilProne = "agm_recoil_single_prone_sdar";
    };
    class FullAuto : Mode_FullAuto {
      recoil = "agm_recoil_auto_sdar";
      recoilProne = "agm_recoil_auto_prone_sdar";
    };
  };

// MACHINE GUNS
  class LMG_Mk200_F : Rifle_Long_Base_F {
    class manual : Mode_FullAuto {
      recoil = "agm_recoil_auto_mk200";
      recoilprone = "agm_recoil_auto_prone_mk200";
    };
    class Single : manual {
      recoil = "agm_recoil_single_mk200";
      recoilprone = "agm_recoil_single_prone_mk200";
    };
  };
  class LMG_Zafir_F: Rifle_Long_Base_F {
    class Single: Mode_SemiAuto {
      recoil = "agm_recoil_single_zafir";
      recoilprone = "agm_recoil_single_prone_zafir";
    };
    class FullAuto: Mode_FullAuto {
      recoil = "agm_recoil_auto_zafir";
      recoilprone = "agm_recoil_auto_prone_zafir";
    };
  };

// PRECISION RIFLES
  class DMR_01_base_F : Rifle_Long_Base_F {
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_dmr";
      recoilProne = "agm_recoil_single_prone_dmr";
    };
    class FullAuto : Mode_FullAuto {
      recoil = "agm_recoil_auto_dmr";
      recoilProne = "agm_recoil_auto_prone_dmr";
    };
  };
  class EBR_base_F : Rifle_Long_Base_F {
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_ebr";
      recoilProne = "agm_recoil_single_prone_ebr";
    };
    class FullAuto : Mode_FullAuto {
      recoil = "agm_recoil_auto_ebr";
      recoilProne = "agm_recoil_auto_prone_ebr";
    };
  };
  class LRR_base_F : Rifle_Long_Base_F {
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_gm6";
      recoilProne = "agm_recoil_single_prone_gm6";
    };
  };
  class GM6_base_F : Rifle_Long_Base_F {
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_gm6";
      recoilProne = "agm_recoil_single_prone_gm6";
    };
  };

  /////////////////////////////////////////////////

  class CannonCore;
  class autocannon_Base_F: CannonCore {
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_BASE;
  };
  class autocannon_35mm: CannonCore {
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_BASE;
  };
  class cannon_120mm: CannonCore {
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_BASE;
  };
  class mortar_155mm_AMOS: CannonCore {
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_BASE;
  };
  class mortar_82mm: CannonCore {
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_BASE;
  };

  // No camshake for gatlings
  class gatling_20mm: CannonCore {
    agm_recoil_shakeMultiplier = 0;
  };
  class gatling_25mm: CannonCore {
    agm_recoil_shakeMultiplier = 0;
  };
  class gatling_30mm: CannonCore {
    agm_recoil_shakeMultiplier = 0;
  };

  class MGunCore;
  class MGun: MGunCore {
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_BASE;
  };
  // No camshake for smoke launchers
  class SmokeLauncher: MGun {
    agm_recoil_shakeMultiplier = 0;
  };

  // No camshake for coax machine guns
  class LMG_RCWS;
  class LMG_M200: LMG_RCWS {
    agm_recoil_shakeMultiplier = 0;
  };
  class LMG_coax: LMG_RCWS {
    agm_recoil_shakeMultiplier = 0;
  };
  class LMG_Minigun: LMG_RCWS {
    agm_recoil_shakeMultiplier = 0;
  };
};
