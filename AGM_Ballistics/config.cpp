// SEE LICENSE.TXT FOR LICENSING INFORMATION

class CfgPatches {
	class AGM_Ballistics {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.60;
		requiredAddons[] = {
      AGM_Core,
      A3_Weapons_F,
      A3_Weapons_F_Items,
      A3_Weapons_F_beta,
      A3_Weapons_F_Acc,
      A3_Weapons_F_Beta_Acc,
      A3_Characters_F
    };
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"TaoSensai"};
    authorUrl = "https://github.com/Taosenai/tmr";
  };
};

class CfgWeapons {
  class ItemCore;
  class VestItem;

  // basically we are reducing the amount of shots a vest can take from something like 5 to 2.
  class Vest_Camo_Base: ItemCore {
    class ItemInfo;
  };
  class Vest_NoCamo_Base: ItemCore {
    class ItemInfo;
  };

  // plate carriers
  class V_PlateCarrier1_blk: Vest_Camo_Base {
    class ItemInfo: ItemInfo {
      armor = 8;
      passThrough = 0.75;
    };
  };
  class V_PlateCarrier1_rgr: Vest_NoCamo_Base {
    class ItemInfo: ItemInfo {
      armor = 8;
      passThrough = 0.75;
    };
  };
  class V_PlateCarrier2_rgr: V_PlateCarrier1_rgr {
    class ItemInfo: ItemInfo {
      armor = 12;
      passThrough = 0.75;
    };
  };
  class V_PlateCarrierL_CTRG: V_PlateCarrier1_rgr {
    class ItemInfo: ItemInfo {
      armor = 8;
      passThrough = 0.75;
    };
  };
  class V_PlateCarrier3_rgr: Vest_NoCamo_Base {
    class ItemInfo: ItemInfo {
      armor = 12;
      passThrough = 0.75;
    };
  };
  class V_PlateCarrier_Kerry: V_PlateCarrier1_rgr {
    class ItemInfo: ItemInfo {
      armor = 12;
      passThrough = 0.75;
    };
  };
  class V_PlateCarrierGL_rgr: Vest_NoCamo_Base {
    class ItemInfo: ItemInfo {
      armor = 24;
      passThrough = 0.75;
    };
  };
  class V_PlateCarrierH_CTRG: V_PlateCarrier2_rgr {
    class ItemInfo: ItemInfo {
      armor = 12;
      passThrough = 0.75;
    };
  };
  class V_PlateCarrierIA1_dgtl: Vest_NoCamo_Base {
    class ItemInfo: VestItem {
      armor = 8;
      passThrough = 0.75;
    };
  };
  class V_PlateCarrierIA2_dgtl: V_PlateCarrierIA1_dgtl {
    class ItemInfo: VestItem {
      armor = 12;
      passThrough = 0.6;
    };
  };
  class V_PlateCarrierIAGL_dgtl: V_PlateCarrierIA2_dgtl {
    class ItemInfo: VestItem {
      armor = 20;
      passThrough = 0.75;
    };
  };
  class V_PlateCarrierSpec_rgr: Vest_NoCamo_Base {
    class ItemInfo: ItemInfo {
      armor = 16;
      passThrough = 0.45;
    };
  };

  // rebreathers (WHY ARE THESE ARMOURED ANYWAYS?!)
  class V_RebreatherB: Vest_Camo_Base {
    class ItemInfo: ItemInfo {
      armor = 0;
    };
  };
  class V_RebreatherIA: V_RebreatherB {
    class ItemInfo: ItemInfo {
      armor = 0;
    };
  };
  class V_RebreatherIR: V_RebreatherB {
    class ItemInfo: ItemInfo {
      armor = 0;
    };
  };

  // tac vests
  class V_TacVest_camo: Vest_Camo_Base {
    class ItemInfo: ItemInfo {
      armor = 8;
    };
  };
  class V_TacVest_khk: Vest_Camo_Base {
    class ItemInfo: ItemInfo {
      armor = 8;
    };
  };
  class V_TacVest_brn: V_TacVest_khk {
    class ItemInfo: ItemInfo {
      armor = 8;
    };
  };
  class V_TacVest_oli: V_TacVest_khk {
    class ItemInfo: ItemInfo {
      armor = 8;
    };
  };
  class V_TacVest_blk: V_TacVest_khk {
    class ItemInfo: ItemInfo {
      armor = 8;
    };
  };
  class V_TacVest_blk_POLICE: Vest_Camo_Base {
    class ItemInfo: ItemInfo {
      armor = 8;
    };
  };
  class V_TacVest_RU: Vest_Camo_Base {
    class ItemInfo: ItemInfo {
      armor = 8;
    };
  };
  class V_TacVestCamo_khk: Vest_Camo_Base {
    class ItemInfo: VestItem {
      armor = 8;
    };
  };
};

// EVERYTHING BELOW BELONGS TO TAOSENSAI

class CfgAmmo {
  class BulletBase;

  class B_65x39_Caseless : BulletBase {
    // Nosler 120gr Ballistic Tip
    // http://www.nosler.com/ballistic-tip/
    // 0.264 bullet diameter
    // BC 0.458
    // SD 0.246
    // Fired from 14.5 in barrel
    // Ref data calculated by Shooter Android app at alt: 0ft, hg: 29.92, temp 80 F, 0% humidity

    // Pretend MX has 1:7.5 twist barrel
    typicalSpeed = 724;

    // Determining experimentally with arma_bal.py (best match to subsonic using Shooter)
    airFriction = -0.000915;
  };

  class B_556x45_Ball : BulletBase {
    // SS109 bullet steel core light penetrator
    // M855 load data
    // Muzzle velocity based on 16" barrel (standard for F2000)
    typicalSpeed = 911; // http://counterstrikefox.freeservers.com/mv.htm
    airFriction = -0.001335;
  };

  class B_762x51_Ball: BulletBase {
    typicalSpeed = 853; // Typical muzzle velocity of M240

    // TODO: Correct airfriction for 7.62x51mm M80
  };

  class AGM_B_762x51_M118LR : B_762x51_Ball {
    // http://www.snipercentral.com/m118.phtml
    // 175gr Sierra HPBT MatchKing
    // 1:12" rifling twist (probably, some civilian shooters like 1:10" for heavies)
    // Mk14 Mod 1 barrel velocity of about 2600fps (18")
    // http://www.militaryfactory.com/smallarms/detail.asp?smallarms_id=377

    typicalspeed = 792;

    // Determining experimentally with arma_bal.py (close match at 500m to ballistic calc data)
    airfriction = -0.0008577;
  };

  // I will never understand WTF BI was thinking when they did this 9x21mm IMI bullshit.
  class B_9x21_Ball;
  class B_9x19_Ball : B_9x21_Ball {
    // Cartridge: 9mm US M882 ball
    // Bullet weight: 124 grains
    // Bullet velocity: 1251fps +/- 25
    // BC 0.160 123 gr round nose FMJ

    typicalSpeed = 381;

    // Determined with armabal.py (close ballistic match at 100 meters)
    airfriction = -0.00213;
  };

  class B_45ACP_Ball: BulletBase {
    // 230 gr (15 g) US Army Ball FMJ  830 ft/s (250 m/s)

    // 230gr round nose FMJ
    // Ballistic Coefficient (G1)  0.184
    // Sectional Density  0.162
    typicalSpeed = 250;

    // Determined with armabal.py (close ballistic match at 100 meters)
    airfriction = -0.0009;
  };
};

class CfgMagazines {
  class CA_Magazine;

  class 30Rnd_65x39_caseless_mag : CA_Magazine {
    initSpeed = 724; // initial MV for 14.5in barrel
  };

  class 30Rnd_65x39_caseless_green : 30Rnd_65x39_caseless_mag {
    initSpeed = 724; // initial MV for 14.5in barrel
  };

  class 100Rnd_65x39_caseless_mag : CA_Magazine {
    initSpeed = 724; // initial MV for 14.5in barrel
    // TODO: the MX SW has a longer barrel so should have a higher initial MV
  };

  class 200Rnd_65x39_cased_Box : 100Rnd_65x39_caseless_mag {
    initSpeed = 691; // initial MV for 12.5in barrel (estimated)
  };

  class 30Rnd_556x45_Stanag : CA_Magazine {
    initSpeed = 911; // Initial MV for a 16" barrel
  };

  class 20Rnd_762x51_Mag: CA_Magazine {
    descriptionshort = "$STR_AGM_Ballistics_20Rnd_762x51_Mag_Description";
    initSpeed = 792; // 18" M14 EBR barrel
    ammo = "AGM_B_762x51_M118LR"; // Use M118LR
  };

  class 150Rnd_762x51_Box : CA_Magazine {
    ammo = "B_762x51_Ball";
    initSpeed = 853; // Typical MV for M240
  };

  // Override the 9x21 mags to have 9x19 in them. Banish 9x21 to hell.
  class 30Rnd_9x21_Mag : CA_Magazine {
    ammo = "B_9x19_Ball";
    initSpeed = 370; // Scorpion Evo 3A1 muzzle velocity according to CZ's manual
    // Why is it so low, lower than a Glock? I'm not sure, but I have no choice but to believe them...!
    // Maybe they are shooting some heavier bullet and not saying.
  };
  class 16Rnd_9x21_Mag : 30Rnd_9x21_Mag {
    ammo = "B_9x19_Ball";
    // M9 initial MV. Close enough for horseshoes and handguns.
    initSpeed = 381;
  };
  class 30Rnd_45ACP_Mag_SMG_01 : 30Rnd_9x21_Mag {
    initSpeed = 259; // From Vector manual (5.5" barrel)
  };

  class 9Rnd_45ACP_Mag : 30Rnd_45ACP_Mag_SMG_01 {
    initSpeed = 250; // 1911
  };
};

// TMR Dispersion values.
// Based on the general specifications of the corresponding real world weapon
// plus a bit of inaccuracy to reflect that it's a service rifle,
// not a finely tuned civilian weapon (except for Marksman rifles).

// Full auto dispersion is increased even though fire mode
// obviously doesn't affect inherent accuracy.

// What it does affect is trigger pull, and a sloppy full auto
// trigger is easily worth the increase in dispersion here even
// when firing single shots with Auto selected.
// That's what I think.

// Use Wolfram Alpha to convert radians to MOA easily.

class Mode_SemiAuto;
class Mode_FullAuto;

class CfgWeapons {
  class Rifle_Base_F;
  class Rifle_Long_Base_F;

  class arifle_MX_Base_F : Rifle_Base_F {
    class Single : Mode_SemiAuto {
      dispersion = 0.000800; // radians. Equal to 2.75 MOA.
      // Based on widely cited 2 MOA figure for new 5.56 ACR.
    };
    class FullAuto : Mode_FullAuto {
      dispersion = 0.00147; // radians. Equal to 5.1 MOA.
    };
  };

  class arifle_MX_SW_Base_F : arifle_MX_Base_F {
    class Single : Single {
      dispersion = 0.000800; // radians. Equal to 2.75 MOA.
      // Based on widely cited 2 MOA figure for new 5.56 ACR.
    };
    class manual : FullAuto {
      dispersion = 0.00147; // radians. Equal to 5.1 MOA.
    };
  };

  class arifle_MXM_Base_F : arifle_MX_Base_F {
    class Single : Single {
      dispersion = 0.00029; // radians. Equal to 1 MOA.
      // 6.5mm is easily capable of this in a half-tuned rifle.
    };
    class FullAuto : FullAuto {
      dispersion = 0.000800; // radians. Equal to 2.75 MOA.
    };
  };

  class arifle_katiba_Base_F : Rifle_Base_F {
    class Single : Mode_SemiAuto {
      dispersion = 0.000800; // radians. Equal to 2.75 MOA.
      // Based on widely cited 2 MOA figure for new 5.56 ACR?
      // Use your imagination for fictional weapons!
    };
    class FullAuto : Mode_FullAuto {
      dispersion = 0.00147; // radians. Equal to 5.1 MOA.
    };
  };

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
    class Single : Mode_SemiAuto {
      dispersion = 0.000727; // radians. Equal to 2.5 MOA, about the limit of mass-produced M855.
      //
    };
    class FullAuto : Mode_FullAuto {
      dispersion = 0.00147; // radians. Equal to 5.1 MOA.
    };
  };

  class mk20_base_F : Rifle_Base_F {
    class Single : Mode_SemiAuto {
      dispersion = 0.0008727; // radians. Equal to 3 MOA, about the limit of mass-produced M855 plus
      // some extra for these worn out Greek Army service rifles.
    };
    class FullAuto : Mode_FullAuto {
      dispersion = 0.00147; // radians. Equal to 5.1 MOA.
    };
  };

  class SDAR_base_F : Rifle_Base_F {
    class Single : Mode_SemiAuto {
      dispersion = 0.0008727; // radians. Equal to 3 MOA, about the limit of mass-produced M855 plus
      // some extra because Kel-Tec.
    };
    class FullAuto : Mode_FullAuto {
      dispersion = 0.00147; // radians. Equal to 5.1 MOA.
    };
  };

};
