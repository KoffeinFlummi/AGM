/////////////////////////////////////////////////////////////////////////////////
// SMALL ARMS ///////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// 1. Set the recoil profiles for all fire modes.
// 2. Set the shake multiplier. This determines the camshake for the weapon.
//     Ex: agm_recoil_shakeMultiplier = 1;

#define SHAKEMULTIPLIER_BASE            1
#define SHAKEMULTIPLIER_MX              1
#define SHAKEMULTIPLIER_MX_SW           0.95
#define SHAKEMULTIPLIER_KATIBA          1
#define SHAKEMULTIPLIER_MK20            0.9
#define SHAKEMULTIPLIER_MK20C           0.9
#define SHAKEMULTIPLIER_TAVOR           0.9
#define SHAKEMULTIPLIER_SDAR            0.9
#define SHAKEMULTIPLIER_SMG_01          0.85
#define SHAKEMULTIPLIER_SMG_02          0.85
#define SHAKEMULTIPLIER_PDW_2000        0.85
#define SHAKEMULTIPLIER_LMG_MK200       1.1
#define SHAKEMULTIPLIER_LMG_ZAFIR       1.3
#define SHAKEMULTIPLIER_EBR             1.3
#define SHAKEMULTIPLIER_LRR             2.3
#define SHAKEMULTIPLIER_GM6             2.3
#define SHAKEMULTIPLIER_DMR_01          1.4
#define SHAKEMULTIPLIER_P07             0
#define SHAKEMULTIPLIER_ROOK40          0
#define SHAKEMULTIPLIER_ACPC2           0
#define SHAKEMULTIPLIER_PISTOL_HEAVY_01 0
#define SHAKEMULTIPLIER_PISTOL_HEAVY_02 0

class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;

class CfgWeapons {
  class Rifle_Base_F;

  class arifle_MX_Base_F : Rifle_Base_F {        
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_MX;
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
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_MX_SW;
    class Single : Single {
      recoil = "agm_recoil_single_mx";
      recoilProne = "agm_recoil_single_prone_mx";
    };
    
    class manual : FullAuto {
      recoil = "agm_recoil_auto_mx";
      recoilProne = "agm_recoil_auto_prone_mx";
    };
  };

  class arifle_katiba_Base_F : Rifle_Base_F {        
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_KATIBA;
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_katiba";
      recoilProne = "agm_recoil_single_prone_katiba";
    };
    
    class FullAuto : Mode_FullAuto {
      recoil = "agm_recoil_auto_katiba";
      recoilProne = "agm_recoil_auto_prone_katiba";
    };
  };

  class mk20_base_F : Rifle_Base_F {
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_MK20;
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
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_MK20C;
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_mk20";
      recoilProne = "agm_recoil_single_prone_mk20";
    };
    
    class FullAuto : Mode_FullAuto {
      recoil = "agm_recoil_auto_mk20";
      recoilProne = "agm_recoil_auto_prone_mk20";
    };
  };

  class Tavor_base_F : Rifle_Base_F {
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_TAVOR;
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_mk20";
      recoilProne = "agm_recoil_single_prone_mk20";
    };
    
    class FullAuto : Mode_FullAuto {
      recoil = "agm_recoil_auto_mk20";
      recoilProne = "agm_recoil_auto_prone_mk20";
    };
  };

  class SDAR_base_F : Rifle_Base_F {
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_SDAR;
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_mk20";
      recoilProne = "agm_recoil_single_prone_mk20";
    };
    
    class FullAuto : Mode_FullAuto {
      recoil = "agm_recoil_auto_mk20";
      recoilProne = "agm_recoil_auto_prone_mk20";
    };
  };

  ////////////////////////////////////////////////

  class SMG_01_Base : Rifle_Base_F {
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_SMG_01;
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_vermin";
      recoilProne = "agm_recoil_single_prone_vermin";
    };

    class Burst : Mode_Burst {
      recoil = "agm_recoil_auto_vermin";
      recoilProne = "agm_recoil_auto_vermin";
    };
    
    class FullAuto : Mode_FullAuto {
      recoil = "agm_recoil_auto_vermin";
      recoilProne = "agm_recoil_auto_prone_vermin";
    };
  };

  class SMG_02_Base_F : Rifle_Base_F {
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_SMG_02;
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_scorpion";
      recoilProne = "agm_recoil_single_prone_scorpion";
    };

    class Burst : Mode_Burst {
      recoil = "agm_recoil_auto_scorpion";
      recoilProne = "agm_recoil_auto_scorpion";
    };
    
    class FullAuto : Mode_FullAuto {
      recoil = "agm_recoil_auto_scorpion";
      recoilProne = "agm_recoil_auto_prone_scorpion";
    };
  };

  class pdw2000_base_F: Rifle_Base_F {
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_PDW_2000;
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_scorpion";
      recoilProne = "agm_recoil_single_prone_scorpion";
    };
    
    class FullAuto : Mode_FullAuto {
      recoil = "agm_recoil_auto_scorpion";
      recoilProne = "agm_recoil_auto_prone_scorpion";
    };
  };

  ////////////////////////////////////////////////

  class Rifle_Long_Base_F;

  class LMG_Mk200_F : Rifle_Long_Base_F {
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_LMG_MK200;
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
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_LMG_ZAFIR;
    class Single: Mode_SemiAuto {
      recoil = "agm_recoil_single_zafir";
      recoilprone = "agm_recoil_single_prone_zafir";
    };
    class FullAuto: Mode_FullAuto {
      recoil = "agm_recoil_auto_zafir";
      recoilprone = "agm_recoil_auto_prone_zafir";
    };
  };

  ////////////////////////////////////////////////

  class EBR_base_F : Rifle_Long_Base_F {
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_EBR;
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
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_LRR;
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_lrr";
      recoilProne = "agm_recoil_single_prone_lrr";
    };
  };

  class GM6_base_F : Rifle_Long_Base_F {
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_GM6;
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_gm6";
      recoilProne = "agm_recoil_single_prone_gm6";
    };
  };

  class DMR_01_base_F : Rifle_Long_Base_F {
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_DMR_01;
    class Single : Mode_SemiAuto {
      recoil = "agm_recoil_single_ebr";
      recoilProne = "agm_recoil_single_prone_ebr";
    };
    
    class FullAuto : Mode_FullAuto {
      recoil = "agm_recoil_auto_ebr";
      recoilProne = "agm_recoil_auto_prone_ebr";
    };
  };

  /////////////////////////////////////////////////

  class Pistol_Base_F;
  class hgun_P07_F : Pistol_Base_F {
    recoil = "agm_recoil_single_pistol9mm";
    recoilProne = "agm_recoil_single_pistol9mm";
  };

  class hgun_Rook40_F : Pistol_Base_F {
    recoil = "agm_recoil_single_pistol9mm";
    recoilProne = "agm_recoil_single_pistol9mm";
  };

  class hgun_ACPC2_F : Pistol_Base_F {
    recoil = "agm_recoil_single_pistol45";
    recoilProne = "agm_recoil_single_pistol45";
  };

  class hgun_Pistol_heavy_01_F : Pistol_Base_F {
    recoil = "agm_recoil_single_pistol45";
    recoilProne = "agm_recoil_single_pistol45";
  };

  class hgun_Pistol_heavy_02_F : Pistol_Base_F {
    // Use 9mm recoil due to low centerline
    recoil = "agm_recoil_single_pistol9mm";
    recoilProne = "agm_recoil_single_pistol9mm";
  };

  /////////////////////////////////////////////////

  class CannonCore;
  class gatling_20mm: CannonCore {
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_BASE;
  };
  class gatling_25mm: CannonCore {
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_BASE;
  };
  class gatling_30mm: CannonCore {
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_BASE;
  };
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

  class MGunCore;
  class MGun: MGunCore {
    agm_recoil_shakeMultiplier = SHAKEMULTIPLIER_BASE;
  };
  class SmokeLauncher: MGun {
    agm_recoil_shakeMultiplier = 0;
  };
};
