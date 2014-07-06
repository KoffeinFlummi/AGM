/////////////////////////////////////////////////////////////////////////////////
// SMALL ARMS ///////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// 1. Set the recoil profiles for all fire modes.
// 2. Set the shake multiplier. This determines the camshake for the weapon.
//     Ex: agm_recoil_shakeMultiplier = 1;

// disabled currently
#define SHAKEMULTIPLIER_BASE            0

class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;

class CfgWeapons {
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
