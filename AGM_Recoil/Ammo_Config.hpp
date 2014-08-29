
class CfgAmmo {
  class MissileCore;
  class MissileBase: MissileCore {
    AGM_Recoil_shakeMultiplier = 2;
  };

  class BombCore;
  class LaserBombCore: BombCore {
    AGM_Recoil_shakeMultiplier = 2;
  };
  class Bo_Mk82: BombCore {
    AGM_Recoil_shakeMultiplier = 2;
  };

  class RocketCore;
  class ArtilleryRocketCore: RocketCore {
    AGM_Recoil_shakeMultiplier = 1.4;
  };
  class RocketBase: RocketCore {
    AGM_Recoil_shakeMultiplier = 1.4;
  };

  class BulletCore;
  class BulletBase: BulletCore {
    AGM_Recoil_shakeMultiplier = 1;
  };

  class ShotgunCore;
  class ShotgunBase: ShotgunCore {
    AGM_Recoil_shakeMultiplier = 1.1;
  };

  class ShellCore;
  class ShellBase: ShellCore {
    AGM_Recoil_shakeMultiplier = 3;
  };

  class SubmunitionCore;
  class SubmunitionBase: SubmunitionCore {
    AGM_Recoil_shakeMultiplier = 3;
  };

  class ShotDeployCore;
  class ShotDeployBase: ShotDeployCore {
    AGM_Recoil_shakeMultiplier = 3;
  };
};

