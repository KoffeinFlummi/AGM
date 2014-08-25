// NEW CLASSES
/*

// CFGAmmo

AGM_B_65x39_Caseless_Tracer_Dim
AGM_B_65x39_Caseless_SD
AGM_B_65x39_Caseless_AP

AGM_B_65x39_Case_Tracer_Dim
AGM_B_65x39_Case_SD
AGM_B_65x39_Case_AP

AGM_B_556x45_Ball_Tracer_Dim
AGM_B_556x45_Ball_SD
AGM_B_556x45_Ball_AP

AGM_B_762x51_Tracer_Dim
AGM_B_762x51_Ball_SD
AGM_B_762x51_Ball_AP
AGM_B_762x51_M118LR


// CFGMagazines

AGM_30Rnd_65x39_caseless_mag_Tracer_Dim
AGM_30Rnd_65x39_caseless_mag_SD
AGM_30Rnd_65x39_caseless_mag_AP

AGM_30Rnd_65x39_caseless_green_mag_Tracer_Dim
AGM_30Rnd_65x39_caseless_green_mag_SD
AGM_30Rnd_65x39_caseless_green_mag_AP

AGM_30Rnd_556x45_Stanag_Tracer_Dim
AGM_30Rnd_556x45_Stanag_SD
AGM_30Rnd_556x45_Stanag_AP

AGM_20Rnd_762x51_Mag_Tracer
AGM_20Rnd_762x51_Mag_Tracer_Dim
AGM_20Rnd_762x51_Mag_SD
AGM_20Rnd_762x51_Mag_AP
*/


// SEE LICENSE.TXT FOR LICENSING INFORMATION

class CfgPatches {
	class AGM_Ballistics {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.60;
		requiredAddons[] = {AGM_Core};
    version = "0.931";
    versionStr = "0.931";
    versionAr[] = {0,931,0};
    author[] = {"TaoSensai"};
    authorUrl = "https://github.com/Taosenai/tmr";
  };
};

// EVERYTHING BELOW BELONGS TO TAOSENSAI

class CfgAmmo {
  class BulletBase;


  /* 6.5x39mm Grendel */

  class B_65x39_Caseless : BulletBase {
    typicalSpeed = 724;
    airFriction = -0.000915;
  };

  // IR Dim
  class B_65x39_Caseless_yellow;
  class AGM_B_65x39_Caseless_Tracer_Dim : B_65x39_Caseless_yellow {
    nvgOnly = 1;
  };
  class B_65x39_Case_yellow;
  class AGM_B_65x39_Case_Tracer_Dim : B_65x39_Case_yellow {
    nvgOnly = 1;
  };

  // sub sonic
  class AGM_B_65x39_Caseless_SD : B_65x39_Caseless {
    airFriction = -0.00054;
    hit = 8.75;
    supersonicCrackFar[] = {};
    supersonicCrackNear[] = {};
    typicalSpeed = 320;
    audibleFire = 0.8;
    visibleFire = 2.5;
  };
  class B_65x39_Case;
  class AGM_B_65x39_Case_SD : B_65x39_Case {
    airFriction = -0.00054;
    hit = 8.75;
    supersonicCrackFar[] = {};
    supersonicCrackNear[] = {};
    typicalSpeed = 320;
    audibleFire = 0.8;
    visibleFire = 2.5;
  };

  // armor piercing
  class AGM_B_65x39_Caseless_AP : B_65x39_Caseless {
    caliber = 1.8;
    hit = 10.5;
  };
  class AGM_B_65x39_Case_AP : B_65x39_Case {
    caliber = 1.8;
    hit = 10.5;
  };


  /* 5.56x45mm NATO */

  class B_556x45_Ball : BulletBase {
    typicalSpeed = 911;
    airFriction = -0.001335;
  };

  // IR Dim
  class B_556x45_Ball_Tracer_Red;
  class AGM_B_556x45_Ball_Tracer_Dim : B_556x45_Ball_Tracer_Red {
    nvgOnly = 1;
  };

  // sub sonic
  class AGM_B_556x45_Ball_SD : B_556x45_Ball {
    airFriction = -0.0006;
    hit = 7;
    supersonicCrackFar[] = {};
    supersonicCrackNear[] = {};
    typicalSpeed = 320;
    audibleFire = 0.6;
    visibleFire = 2.0;
  };

  // armor piercing
  class AGM_B_556x45_Ball_AP : B_556x45_Ball {
    caliber = 1.4;
    hit = 8.4;
  };


  /* 7.62x51mm NATO */

  class B_762x51_Ball: BulletBase {
    typicalSpeed = 853;
    //airfriction =
  };

  // IR Dim
  class B_762x51_Tracer_Red;
  class AGM_B_762x51_Tracer_Dim : B_762x51_Tracer_Red {
    nvgOnly = 1;
  };

  // sub sonic
  class AGM_B_762x51_Ball_SD : B_762x51_Ball {
    airFriction = -0.00048;
    hit = 10.5;
    supersonicCrackFar[] = {};
    supersonicCrackNear[] = {};
    typicalSpeed = 320;
    audibleFire = 0.9;
    visibleFire = 3.0;
  };

  // armor piercing
  class AGM_B_762x51_Ball_AP : B_762x51_Ball {
    caliber = 2.4;
    hit = 12.6;
  };

  // M118 LR
  class AGM_B_762x51_M118LR : B_762x51_Ball {
    typicalspeed = 792;
    airfriction = -0.0008577;
  };


  /* Other */

  class B_9x21_Ball;
  class B_9x19_Ball : B_9x21_Ball {
    typicalSpeed = 381;
    airfriction = -0.00213;
  };

  class B_45ACP_Ball: BulletBase {
    typicalSpeed = 250;
    airfriction = -0.0009;
  };
};

class CfgMagazines {
  class CA_Magazine;


  /* 6.5x39mm Grendel - MX */

  class 30Rnd_65x39_caseless_mag : CA_Magazine {
    initSpeed = 724;
  };
  class 30Rnd_65x39_caseless_mag_Tracer;
  class 100Rnd_65x39_caseless_mag : CA_Magazine {
    initSpeed = 724;
  };

  class AGM_30Rnd_65x39_caseless_mag_Tracer_Dim : 30Rnd_65x39_caseless_mag_Tracer {
    ammo = "AGM_B_65x39_Caseless_Tracer_Dim";
    displayName = "$STR_AGM_30Rnd_65x39_caseless_mag_Tracer_DimName";
    displayNameShort = "$STR_AGM_30Rnd_65x39_caseless_mag_Tracer_DimNameShort";
    descriptionShort = "$STR_AGM_30Rnd_65x39_caseless_mag_Tracer_DimDescription";
    picture = "\A3\weapons_f\data\ui\m_30stanag_caseless_yellow_CA.paa";
  };
  class AGM_30Rnd_65x39_caseless_mag_SD : 30Rnd_65x39_caseless_mag {
    ammo = "AGM_B_65x39_Caseless_SD";
    displayName = "$STR_AGM_30Rnd_65x39_caseless_mag_SDName";
    displayNameShort = "$STR_AGM_30Rnd_65x39_caseless_mag_SDNameShort";
    descriptionShort = "$STR_AGM_30Rnd_65x39_caseless_mag_SDDescription";
    picture = "\A3\weapons_f\data\ui\m_30stanag_caseless_green_CA.paa";
    initSpeed = 320;
  };
  class AGM_30Rnd_65x39_caseless_mag_AP : 30Rnd_65x39_caseless_mag {
    ammo = "AGM_B_65x39_Caseless_AP";
    displayName = "$STR_AGM_30Rnd_65x39_caseless_mag_APName";
    displayNameShort = "$STR_AGM_30Rnd_65x39_caseless_mag_APNameShort";
    descriptionShort = "$STR_AGM_30Rnd_65x39_caseless_mag_APDescription";
  };


  /* 6.5x39mm Grendel - Katiba */

  class 30Rnd_65x39_caseless_green : 30Rnd_65x39_caseless_mag {
    initSpeed = 724;
  };
  class 30Rnd_65x39_caseless_green_mag_Tracer;
  class 200Rnd_65x39_cased_Box : 100Rnd_65x39_caseless_mag {
    initSpeed = 691;
  };

  class AGM_30Rnd_65x39_caseless_green_mag_Tracer_Dim : 30Rnd_65x39_caseless_green_mag_Tracer {
    ammo = "AGM_B_65x39_Caseless_Tracer_Dim";
    displayName = "$STR_AGM_30Rnd_65x39_caseless_green_mag_Tracer_DimName";
    displayNameShort = "$STR_AGM_30Rnd_65x39_caseless_green_mag_Tracer_DimNameShort";
    descriptionShort = "$STR_AGM_30Rnd_65x39_caseless_green_mag_Tracer_DimDescription";
  };
  class AGM_30Rnd_65x39_caseless_green_mag_SD : 30Rnd_65x39_caseless_green {
    ammo = "AGM_B_65x39_Caseless_SD";
    displayName = "$STR_AGM_30Rnd_65x39_caseless_green_mag_SDName";
    displayNameShort = "$STR_AGM_30Rnd_65x39_caseless_green_mag_SDNameShort";
    descriptionShort = "$STR_AGM_30Rnd_65x39_caseless_green_mag_SDDescription";
    initSpeed = 320;
  };
  class AGM_30Rnd_65x39_caseless_green_mag_AP : 30Rnd_65x39_caseless_green {
    ammo = "AGM_B_65x39_Caseless_AP";
    displayName = "$STR_AGM_30Rnd_65x39_caseless_green_mag_APName";
    displayNameShort = "$STR_AGM_30Rnd_65x39_caseless_green_mag_APNameShort";
    descriptionShort = "$STR_AGM_30Rnd_65x39_caseless_green_mag_APDescription";
  };


  /* 5.56x45mm NATO */

  class 30Rnd_556x45_Stanag : CA_Magazine {
    initSpeed = 911;
  };
  class 30Rnd_556x45_Stanag_Tracer_Red; //picture = "\A3\weapons_f\data\ui\m_30stanag_red_ca.paa";

  class AGM_30Rnd_556x45_Stanag_Tracer_Dim : 30Rnd_556x45_Stanag_Tracer_Red {
    ammo = "AGM_B_556x45_Ball_Tracer_Dim";
    displayName = "$STR_AGM_30Rnd_556x45_mag_Tracer_DimName";
    displayNameShort = "$STR_AGM_30Rnd_556x45_mag_Tracer_DimNameShort";
    descriptionShort = "$STR_AGM_30Rnd_556x45_mag_Tracer_DimDescription";
    picture = "\A3\weapons_f\data\ui\m_30stanag_yellow_ca.paa";
  };
  class AGM_30Rnd_556x45_Stanag_SD : 30Rnd_556x45_Stanag {
    ammo = "AGM_B_556x45_Ball_SD";
    displayName = "$STR_AGM_30Rnd_556x45_mag_SDName";
    displayNameShort = "$STR_AGM_30Rnd_556x45_mag_SDNameShort";
    descriptionShort = "$STR_AGM_30Rnd_556x45_mag_SDDescription";
    initSpeed = 320;
    picture = "\A3\weapons_f\data\ui\m_30stanag_green_ca.paa";
  };
  class AGM_30Rnd_556x45_Stanag_AP : 30Rnd_556x45_Stanag {
    ammo = "AGM_B_556x45_Ball_AP";
    displayName = "$STR_AGM_30Rnd_556x45_mag_APName";
    displayNameShort = "$STR_AGM_30Rnd_556x45_mag_APNameShort";
    descriptionShort = "$STR_AGM_30Rnd_556x45_mag_APDescription";
  };


  /* 7.62x51mm NATO */

  class 20Rnd_762x51_Mag: CA_Magazine {
    descriptionshort = "$STR_AGM_Ballistics_20Rnd_762x51_Mag_Description";
    initSpeed = 792; // 18" M14 EBR barrel
    ammo = "AGM_B_762x51_M118LR"; // Use M118LR
  };
  class 150Rnd_762x51_Box : CA_Magazine {
    ammo = "B_762x51_Ball";
    initSpeed = 853; // Typical MV for M240
  };

  class AGM_20Rnd_762x51_Mag_Tracer : 20Rnd_762x51_Mag {  //@todo Green tracers for opfor and yellow tracers for independent
    ammo = "B_762x51_Tracer_Red";
    displayName = "$STR_AGM_20Rnd_762x51_mag_TracerName";
    displayNameShort = "$STR_AGM_20Rnd_762x51_mag_TracerNameShort";
    descriptionShort = "$STR_AGM_20Rnd_762x51_mag_TracerDescription";
    tracersEvery = 1;
  };
  class AGM_20Rnd_762x51_Mag_Tracer_Dim : AGM_20Rnd_762x51_Mag_Tracer {
    ammo = "AGM_B_762x51_Tracer_Dim";
    displayName = "$STR_AGM_20Rnd_762x51_mag_Tracer_DimName";
    displayNameShort = "$STR_AGM_20Rnd_762x51_mag_Tracer_DimNameShort";
    descriptionShort = "$STR_AGM_20Rnd_762x51_mag_Tracer_DimDescription";
  };
  class AGM_20Rnd_762x51_Mag_SD : 20Rnd_762x51_Mag {
    ammo = "AGM_B_762x51_Ball_SD";
    displayName = "$STR_AGM_20Rnd_762x51_mag_SDName";
    displayNameShort = "$STR_AGM_20Rnd_762x51_mag_SDNameShort";
    descriptionShort = "$STR_AGM_20Rnd_762x51_mag_SDDescription";
    initSpeed = 320;
  };
  class AGM_20Rnd_762x51_Mag_AP : 20Rnd_762x51_Mag {
    ammo = "AGM_B_762x51_Ball_AP";
    displayName = "$STR_AGM_20Rnd_762x51_mag_APName";
    displayNameShort = "$STR_AGM_20Rnd_762x51_mag_APNameShort";
    descriptionShort = "$STR_AGM_20Rnd_762x51_mag_APDescription";
  };


  /* Other */

  class 30Rnd_9x21_Mag : CA_Magazine {
    ammo = "B_9x19_Ball";
    initSpeed = 370;
  };
  class 16Rnd_9x21_Mag : 30Rnd_9x21_Mag {
    ammo = "B_9x19_Ball";
    initSpeed = 381;
  };
  class 30Rnd_45ACP_Mag_SMG_01 : 30Rnd_9x21_Mag {
    initSpeed = 259;
  };
  class 9Rnd_45ACP_Mag : 30Rnd_45ACP_Mag_SMG_01 {
    initSpeed = 250;
  };
};

class Mode_SemiAuto;
class Mode_FullAuto;

class CfgWeapons {
  class Rifle_Base_F;
  class Rifle_Long_Base_F;


  /* MX */

  class arifle_MX_Base_F : Rifle_Base_F {
    magazines[] += {
      "AGM_30Rnd_65x39_caseless_mag_Tracer_Dim",
      "AGM_30Rnd_65x39_caseless_mag_SD",
      "AGM_30Rnd_65x39_caseless_mag_AP",
      "100Rnd_65x39_caseless_mag",
      "100Rnd_65x39_caseless_mag_Tracer"
    };
    class Single : Mode_SemiAuto {
      dispersion = 0.000800; // radians. Equal to 2.75 MOA.
      // Based on widely cited 2 MOA figure for new 5.56 ACR.
    };
    class FullAuto : Mode_FullAuto {
      dispersion = 0.00147; // radians. Equal to 5.1 MOA.
    };
  };
  class arifle_MX_SW_F : arifle_MX_Base_F {
    magazines[] += {
      "30Rnd_65x39_caseless_mag",
      "30Rnd_65x39_caseless_mag_Tracer"
    };
    class Single : Mode_SemiAuto {
      dispersion = 0.000800; // radians. Equal to 2.75 MOA.
      // Based on widely cited 2 MOA figure for new 5.56 ACR.
    };
    class manual : FullAuto {
      dispersion = 0.00147; // radians. Equal to 5.1 MOA.
    };
  };
  class arifle_MXM_F : arifle_MX_Base_F {
    magazines[] += {
      "30Rnd_65x39_caseless_mag",
      "30Rnd_65x39_caseless_mag_Tracer"
    };
    class Single : Single {
      dispersion = 0.00029; // radians. Equal to 1 MOA.
      // 6.5mm is easily capable of this in a half-tuned rifle.
    };
    class FullAuto : FullAuto {
      dispersion = 0.000800; // radians. Equal to 2.75 MOA.
    };
  };


  /* Katiba */

  class arifle_katiba_Base_F : Rifle_Base_F {
    magazines[] += {
      "AGM_30Rnd_65x39_caseless_green_mag_Tracer_Dim",
      "AGM_30Rnd_65x39_caseless_green_mag_SD",
      "AGM_30Rnd_65x39_caseless_green_mag_AP"
    };
    class Single : Mode_SemiAuto {
      dispersion = 0.000800; // radians. Equal to 2.75 MOA.
      // Based on widely cited 2 MOA figure for new 5.56 ACR?
      // Use your imagination for fictional weapons!
    };
    class FullAuto : Mode_FullAuto {
      dispersion = 0.00147; // radians. Equal to 5.1 MOA.
    };
  };


  /* Other */

  class LMG_Mk200_F : Rifle_Long_Base_F {
    class manual : Mode_FullAuto {
      dispersion = 0.00175; // radians. Equal to 6 MOA.
    };
    class Single : manual {
      dispersion = 0.00175; // radians. Equal to 6 MOA.
    };
  };

  class LMG_Zafir_F : Rifle_Long_Base_F {
    class FullAuto : Mode_FullAuto {
      dispersion = 0.00175; // radians. Equal to 6 MOA.
    };
    class Single : Mode_SemiAuto {
      dispersion = 0.00175; // radians. Equal to 6 MOA.
    };
  };

  class Tavor_base_F : Rifle_Base_F {
    magazines[] += {
      "AGM_30Rnd_556x45_Stanag_Tracer_Dim",
      "AGM_30Rnd_556x45_Stanag_SD",
      "AGM_30Rnd_556x45_Stanag_AP"
    };
    class Single : Mode_SemiAuto {
      dispersion = 0.000727; // radians. Equal to 2.5 MOA, about the limit of mass-produced M855.
      //
    };
    class FullAuto : Mode_FullAuto {
      dispersion = 0.00147; // radians. Equal to 5.1 MOA.
    };
  };

  class mk20_base_F : Rifle_Base_F {
    magazines[] += {
      "AGM_30Rnd_556x45_Stanag_Tracer_Dim",
      "AGM_30Rnd_556x45_Stanag_SD",
      "AGM_30Rnd_556x45_Stanag_AP"
    };
    class Single : Mode_SemiAuto {
      dispersion = 0.0008727; // radians. Equal to 3 MOA, about the limit of mass-produced M855 plus
      // some extra for these worn out Greek Army service rifles.
    };
    class FullAuto : Mode_FullAuto {
      dispersion = 0.00147; // radians. Equal to 5.1 MOA.
    };
  };

  class SDAR_base_F : Rifle_Base_F {
    magazines[] += {
      "AGM_30Rnd_556x45_Stanag_Tracer_Dim",
      "AGM_30Rnd_556x45_Stanag_SD",
      "AGM_30Rnd_556x45_Stanag_AP"
    };
    class Single : Mode_SemiAuto {
      dispersion = 0.0008727; // radians. Equal to 3 MOA, about the limit of mass-produced M855 plus
      // some extra because Kel-Tec.
    };
    class FullAuto : Mode_FullAuto {
      dispersion = 0.00147; // radians. Equal to 5.1 MOA.
    };
  };


  /* Silencers */

  class ItemCore;
  class InventoryMuzzleItem_Base_F;

  class muzzle_snds_H: ItemCore {
    class ItemInfo: InventoryMuzzleItem_Base_F {
      class MagazineCoef {
        initSpeed = 1.0;
      };

      class AmmoCoef {
        hit = 0.9;
        visibleFire = 0.5;
        audibleFire = 0.1;
        visibleFireTime = 0.5;
        audibleFireTime = 0.5;
        cost = 1.0;
        typicalSpeed = 1.0;
        airFriction = 1.0;
      };
    };
  };

  class muzzle_snds_L: muzzle_snds_H {
    class ItemInfo: ItemInfo {
      class MagazineCoef {
        initSpeed = 1.0;
      };

      class AmmoCoef {
        hit = 0.9;
        visibleFire = 0.5;
        audibleFire = 0.1;
        visibleFireTime = 0.5;
        audibleFireTime = 0.5;
        cost = 1.0;
        typicalSpeed = 1.0;
        airFriction = 1.0;
      };
    };
  };

  class muzzle_snds_M: muzzle_snds_H {
    class ItemInfo: ItemInfo {
      class MagazineCoef {
        initSpeed = 1.0;
      };

      class AmmoCoef {
        hit = 0.9;
        visibleFire = 0.5;
        audibleFire = 0.1;
        visibleFireTime = 0.5;
        audibleFireTime = 0.5;
        cost = 1.0;
        typicalSpeed = 1.0;
        airFriction = 1.0;
      };
    };
  };

  class muzzle_snds_B: muzzle_snds_H {
    class ItemInfo: ItemInfo {
      class MagazineCoef {
        initSpeed = 1.0;
      };

      class AmmoCoef {
        hit = 0.9;
        visibleFire = 0.5;
        audibleFire = 0.1;
        visibleFireTime = 0.5;
        audibleFireTime = 0.5;
        cost = 1.0;
        typicalSpeed = 1.0;
        airFriction = 1.0;
      };
    };
  };

  class muzzle_snds_H_MG: muzzle_snds_H {
    class ItemInfo: ItemInfo {
      class MagazineCoef {
        initSpeed = 1.0;
      };

      class AmmoCoef {
        hit = 0.9;
        visibleFire = 0.5;
        audibleFire = 0.1;
        visibleFireTime = 0.5;
        audibleFireTime = 0.5;
        cost = 1.0;
        typicalSpeed = 1.0;
        airFriction = 1.0;
      };
    };
  };

  class muzzle_snds_H_SW: muzzle_snds_H_MG {
    class ItemInfo: ItemInfo {
      class MagazineCoef {
        initSpeed = 1.0;
      };

      class AmmoCoef {
        hit = 0.9;
        visibleFire = 0.5;
        audibleFire = 0.1;
        visibleFireTime = 0.5;
        audibleFireTime = 0.5;
        cost = 1.0;
        typicalSpeed = 1.0;
        airFriction = 1.0;
      };
    };
  };


  /* Vests */

  class VestItem;
  #include <VestNerf.hpp>
};


#define MACRO_ADDMAGAZINE(MAGAZINE,COUNT) class _xx_##MAGAZINE { \
  magazine = #MAGAZINE; \
  count = COUNT; \
};

class CfgVehicles {
  #include <UniformNerf.hpp>

  class NATO_Box_Base;
  class EAST_Box_Base;
  class IND_Box_Base;
  class FIA_Box_Base_F;
  class ReammoBox_F;

  class Box_NATO_Wps_F: NATO_Box_Base {
    class TransportMagazines {
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_mag_AP,2)
    };
  };

  class Box_NATO_WpsSpecial_F: NATO_Box_Base {
    class TransportMagazines {
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_mag_Tracer_Dim,2)
      MACRO_ADDMAGAZINE(AGM_30Rnd_556x45_Stanag_Tracer_Dim,1)
    };
  };

  class Box_NATO_Ammo_F: NATO_Box_Base {
    class TransportMagazines {
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_mag_AP,2)
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_mag_SD,2)
    };
  };

  class Box_NATO_Support_F: NATO_Box_Base {
    class TransportMagazines {
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_mag_SD,6)
      MACRO_ADDMAGAZINE(AGM_30Rnd_556x45_Stanag_SD,3)
    };
  };

  class B_supplyCrate_F: ReammoBox_F {
    class TransportMagazines {
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_mag_AP,2)
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_mag_SD,2)
    };
  };

  class Box_East_Wps_F: EAST_Box_Base {
    class TransportMagazines {
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_green_mag_AP,2)
    };
  };

  class Box_East_WpsSpecial_F: EAST_Box_Base {
    class TransportMagazines {
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_green_mag_Tracer_Dim,2)
      MACRO_ADDMAGAZINE(AGM_30Rnd_556x45_Stanag_Tracer_Dim,1)
    };
  };

  class Box_East_Ammo_F: EAST_Box_Base {
    class TransportMagazines {
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_green_mag_AP,2)
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_green_mag_SD,2)
    };
  };

  class Box_East_Support_F: EAST_Box_Base {
    class TransportMagazines {
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_green_mag_SD,6)
      MACRO_ADDMAGAZINE(AGM_30Rnd_556x45_Stanag_SD,3)
    };
  };

  class O_supplyCrate_F: B_supplyCrate_F {
    class TransportMagazines {
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_green_mag_AP,2)
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_green_mag_SD,2)
    };
  };

  class Box_IND_Wps_F: IND_Box_Base {
    class TransportMagazines {
      MACRO_ADDMAGAZINE(AGM_30Rnd_556x45_Stanag_AP,2)
    };
  };

  class Box_IND_WpsSpecial_F: IND_Box_Base {
    class TransportMagazines {
      MACRO_ADDMAGAZINE(AGM_30Rnd_556x45_Stanag_Tracer_Dim,2)
    };
  };

  class Box_IND_Ammo_F: IND_Box_Base {
    class TransportMagazines {
      MACRO_ADDMAGAZINE(AGM_30Rnd_556x45_Stanag_AP,2)
      MACRO_ADDMAGAZINE(AGM_30Rnd_556x45_Stanag_SD,2)
    };
  };

  class Box_IND_Support_F: IND_Box_Base {
    class TransportMagazines {
      MACRO_ADDMAGAZINE(AGM_30Rnd_556x45_Stanag_SD,6)
    };
  };

  class Box_FIA_Wps_F: FIA_Box_Base_F {
    class TransportMagazines {
      MACRO_ADDMAGAZINE(AGM_30Rnd_556x45_Stanag_AP,2)
    };
  };

  class Box_FIA_Ammo_F: FIA_Box_Base_F {
    class TransportMagazines {
      MACRO_ADDMAGAZINE(AGM_30Rnd_556x45_Stanag_AP,2)
      MACRO_ADDMAGAZINE(AGM_30Rnd_556x45_Stanag_SD,2)
    };
  };

  class Box_FIA_Support_F: FIA_Box_Base_F {
    class TransportMagazines {
      MACRO_ADDMAGAZINE(AGM_30Rnd_556x45_Stanag_SD,6)
    };
  };

  class I_supplyCrate_F: B_supplyCrate_F {
    class TransportMagazines {
      MACRO_ADDMAGAZINE(AGM_30Rnd_556x45_Stanag_AP,2)
      MACRO_ADDMAGAZINE(AGM_30Rnd_556x45_Stanag_SD,2)
    };
  };

  class IG_supplyCrate_F: ReammoBox_F {
    class TransportMagazines {
      MACRO_ADDMAGAZINE(AGM_30Rnd_556x45_Stanag_AP,2)
      MACRO_ADDMAGAZINE(AGM_30Rnd_556x45_Stanag_SD,2)
    };
  };

  class C_supplyCrate_F: ReammoBox_F {
    class TransportMagazines {
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_green_mag_AP,2)
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_green_mag_SD,2)
    };
  };

  class AGM_Box_Misc: Box_NATO_Support_F {
    class TransportMagazines {
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_mag_Tracer_Dim,2)
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_mag_SD,2)
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_mag_AP,2)
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_green_mag_Tracer_Dim,2)
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_green_mag_SD,2)
      MACRO_ADDMAGAZINE(AGM_30Rnd_65x39_caseless_green_mag_AP,2)
      MACRO_ADDMAGAZINE(AGM_30Rnd_556x45_Stanag_Tracer_Dim,2)
      MACRO_ADDMAGAZINE(AGM_30Rnd_556x45_Stanag_SD,2)
      MACRO_ADDMAGAZINE(AGM_30Rnd_556x45_Stanag_AP,2)
      /*MACRO_ADDMAGAZINE(AGM_20Rnd_762x51_Mag_Tracer,2)
      MACRO_ADDMAGAZINE(AGM_20Rnd_762x51_Mag_Tracer_Dim,2)
      MACRO_ADDMAGAZINE(AGM_20Rnd_762x51_Mag_SD,2)
      MACRO_ADDMAGAZINE(AGM_20Rnd_762x51_Mag_AP,2)*/
    };
  };
};
