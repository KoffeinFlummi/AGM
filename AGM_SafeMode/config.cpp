class CfgPatches {
  class AGM_SafeMode {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {"A3_Weapons_F_Items", "A3_Weapons_F_gamma", "A3_Weapons_F_gamma_Acc", "A3_Weapons_F_EPC", "Extended_EventHandlers", "AGM_Core"};
    //requiredAddons[] = {};
    version = 1.0;
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_SafeMode {
    clientInit = "execVM '\AGM_SafeMode\init.sqf'";
  };
};

class AGM_Core_Default_Keys {
  class safeMode {
    displayName = "Safe Mode";
    condition = "player == _vehicle && {currentWeapon player == primaryWeapon player} && {!dialog}";
    statement = "call AGM_SafeMode_toggleSafeMode";
    key = 19;
    shift = 0;
    control = 1;
    alt = 0;
  };
};

class Extended_Fired_EventHandlers {
  class CAManBase {
    class AGM_SafeModeFired {
      clientFired = "if (player == (_this select 0)) then {call AGM_SafeMode_firedEH}";
    };
  };
};

class Extended_Take_EventHandlers {
  class CAManBase {
    class AGM_SafeModeTake {
      clientTake = "if (player == (_this select 0)) then {call AGM_SafeMode_takeEH}";
    };
  };
};

class SlotInfo;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;

class CfgWeapons {
  class muzzle_snds_H;

  class AGM_muzzle_snds_SAFE: muzzle_snds_H {
    displayName = "Safe mode dummy";
    model = "";
    picture = "\agm_safemode\ui\empty_ca.paa";

    class GunClouds {
      access = 0;
      cloudletAccY = 0;
      cloudletAlpha = 0;
      cloudletAnimPeriod = 0;
      cloudletColor[] = {0,0,0,0};
      cloudletDuration = 0;
      cloudletFadeIn = 0;
      cloudletFadeOut = 0;
      cloudletGrowUp = 0;
      cloudletMaxYSpeed = 0;
      cloudletMinYSpeed = 0;
      cloudletShape = "cloudletClouds";
      cloudletSize = 0;
      deltaT = 0;
      initT = 0;
      interval = 0;
      size = 0;
      sourceSize = 0;
      timeToLive = 0;
      class Table {
        class T0 {
          color[] = {0,0,0,0};
          maxT = 0;
        };
      };
    };

    class GunFire {
      access = 0;
      cloudletAccY = 0;
      cloudletAlpha = 0;
      cloudletAnimPeriod = 0;
      cloudletColor[] = {0,0,0,0};
      cloudletDensityCoef = 0;
      cloudletDuration = 0;
      cloudletFadeIn = 0;
      cloudletFadeOut = 0;
      cloudletGrowUp = 0;
      cloudletMaxYSpeed = 0;
      cloudletMinYSpeed = 0;
      cloudletShape = "cloudletFire";
      cloudletSize = 0;
      deltaT = 0;
      initT = 0;
      interval = 0;
      size = 0;
      sourceSize = 0;
      timeToLive = 0;
      class Table {
        class T0 {
          color[] = {0,0,0,0};
          maxT = 0;
        };
      };
    };

    class ItemInfo {
      scope = 0;
      type = 101;
      mass = 0;
      alternativeFire = "";
      muzzleEnd = "";
      modes[] = {"Single","Burst","FullAuto"};
      mountAction = "";
      unmountAction = "";

      class MagazineCoef {
        initSpeed = 0;
      };

      class AmmoCoef {
        hit = 0;
        visibleFire = 0;
        audibleFire = 0;
        visibleFireTime = 0;
        audibleFireTime = 0;
        cost = 0;
        typicalSpeed = 0;
        airFriction = 0;
      };

      class Single: Mode_SemiAuto {
        aiDispersionCoefX = 0;
        aiDispersionCoefY = 0;
        aiRateOfFire = 0;
        aiRateOfFireDistance = 0;
        ffCount = 0;
        ffFrequency = 0;
        ffMagnitude = 0;
        flash = "";
        flashSize = 0;
        dispersion = 0;
        maxRange = 0;
        maxRangeProbab = 0;
        midRange = 0;
        midRangeProbab = 0;
        minRange = 0;
        minRangeProbab = 0;
        recoil = "empty";
        recoilProne = "empty";
        reloadTime = 999999;
        sound[] = {};
        soundBegin[] = {};
        soundBeginWater[] = {};
        soundClosure[] = {};
        weaponSoundEffect = "";
      };
      class Burst: Mode_Burst {
        aiDispersionCoefX = 0;
        aiDispersionCoefY = 0;
        aiRateOfFire = 0;
        aiRateOfFireDistance = 0;
        ffCount = 0;
        ffFrequency = 0;
        ffMagnitude = 0;
        flash = "";
        flashSize = 0;
        dispersion = 0;
        maxRange = 0;
        maxRangeProbab = 0;
        midRange = 0;
        midRangeProbab = 0;
        minRange = 0;
        minRangeProbab = 0;
        recoil = "empty";
        recoilProne = "empty";
        reloadTime = 999999;
        sound[] = {};
        soundBegin[] = {};
        soundBeginWater[] = {};
        soundClosure[] = {};
        weaponSoundEffect = "";
      };
      class FullAuto: Mode_FullAuto {
        aiDispersionCoefX = 0;
        aiDispersionCoefY = 0;
        aiRateOfFire = 0;
        aiRateOfFireDistance = 0;
        ffCount = 0;
        ffFrequency = 0;
        ffMagnitude = 0;
        flash = "";
        flashSize = 0;
        dispersion = 0;
        maxRange = 0;
        maxRangeProbab = 0;
        midRange = 0;
        midRangeProbab = 0;
        minRange = 0;
        minRangeProbab = 0;
        recoil = "empty";
        recoilProne = "empty";
        reloadTime = 999999;
        sound[] = {};
        soundBegin[] = {};
        soundBeginWater[] = {};
        soundClosure[] = {};
        weaponSoundEffect = "";
      };
    };
  };

  class WeaponSlotsInfo;
  class Rifle_Base_F;
  class Rifle_Long_Base_F;

  class arifle_MX_Base_F : Rifle_Base_F {
    class WeaponSlotsInfo: WeaponSlotsInfo {
      class MuzzleSlot: SlotInfo {
        compatibleItems[] += {"AGM_muzzle_snds_SAFE"};
      };
    };
  };

  class arifle_MX_SW_F : arifle_MX_Base_F {
    class WeaponSlotsInfo: WeaponSlotsInfo {
      class MuzzleSlot: SlotInfo {
        compatibleItems[] += {"AGM_muzzle_snds_SAFE"};
      };
    };
  };

  class arifle_Katiba_Base_F : Rifle_Base_F {
    class WeaponSlotsInfo: WeaponSlotsInfo {
      class MuzzleSlot: SlotInfo {
        compatibleItems[] += {"AGM_muzzle_snds_SAFE"};
      };
    };
  };

  class mk20_base_F : Rifle_Base_F {
    class WeaponSlotsInfo: WeaponSlotsInfo {
      class MuzzleSlot: SlotInfo {
        compatibleItems[] += {"AGM_muzzle_snds_SAFE"};
      };
    };
  };

  class Tavor_base_F : Rifle_Base_F {
    class WeaponSlotsInfo: WeaponSlotsInfo {
      class MuzzleSlot: SlotInfo {
        compatibleItems[] += {"AGM_muzzle_snds_SAFE"};
      };
    };
  };

  class SDAR_base_F : Rifle_Base_F {
    class WeaponSlotsInfo: WeaponSlotsInfo {
      class MuzzleSlot: SlotInfo {
        compatibleItems[] += {"AGM_muzzle_snds_SAFE"};
      };
    };
  };

  class EBR_base_F : Rifle_Long_Base_F {
    class WeaponSlotsInfo: WeaponSlotsInfo {
      class MuzzleSlot: SlotInfo {
        compatibleItems[] += {"AGM_muzzle_snds_SAFE"};
      };
    };
  };

  class DMR_01_base_F : Rifle_Long_Base_F {
    class WeaponSlotsInfo: WeaponSlotsInfo {
      class MuzzleSlot: SlotInfo {
        compatibleItems[] += {"AGM_muzzle_snds_SAFE"};
      };
    };
  };

  class GM6_base_F;
  class srifle_GM6_F: GM6_base_F {
    class WeaponSlotsInfo: WeaponSlotsInfo {
      class MuzzleSlot: SlotInfo {
        compatibleItems[] += {"AGM_muzzle_snds_SAFE"};
      };
    };
  };

  class LRR_base_F;
  class srifle_LRR_F: LRR_base_F {
    class WeaponSlotsInfo: WeaponSlotsInfo {
      class MuzzleSlot: SlotInfo {
        compatibleItems[] += {"AGM_muzzle_snds_SAFE"};
      };
    };
  };

  class LMG_Mk200_F : Rifle_Long_Base_F {
    class WeaponSlotsInfo: WeaponSlotsInfo {
      class MuzzleSlot: SlotInfo {
        compatibleItems[] += {"AGM_muzzle_snds_SAFE"};
      };
    };
  };

  class LMG_Zafir_F : Rifle_Long_Base_F {
    class WeaponSlotsInfo: WeaponSlotsInfo {
      class MuzzleSlot: SlotInfo {
        compatibleItems[] += {"AGM_muzzle_snds_SAFE"};
      };
    };
  };

  class SMG_01_Base : Rifle_Base_F {
    class WeaponSlotsInfo: WeaponSlotsInfo {
      class MuzzleSlot: SlotInfo {
        compatibleItems[] += {"AGM_muzzle_snds_SAFE"};
      };
    };
  };

  class SMG_02_base_F : Rifle_Base_F {
    class WeaponSlotsInfo: WeaponSlotsInfo {
      class MuzzleSlot: SlotInfo {
        compatibleItems[] += {"AGM_muzzle_snds_SAFE"};
      };
    };
  };

  class pdw2000_base_F : Rifle_Base_F {
    class WeaponSlotsInfo: WeaponSlotsInfo {
      class MuzzleSlot: SlotInfo {
        compatibleItems[] += {"AGM_muzzle_snds_SAFE"};
      };
    };
  };
};
