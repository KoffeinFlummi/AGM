// SEE LICENSE.TXT FOR LICENSING INFORMATION

class CfgPatches {
  class AGM_Smallarms {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, A3_Weapons_F_beta, A3_Weapons_F_gamma, A3_Weapons_F_Acc, A3_Weapons_F_Beta_Acc, A3_Characters_F};
    version = "0.9";
    versionStr = "0.9";
    versionAr[] = {0,9,0};
    author[] = {"TaoSensai", "KoffeinFlummi"};
    authorUrl = "https://github.com/Taosenai/tmr";
  };
};

// EVERYTHING BELOW BELONGS TO TAOSENSAI

//////////////////////////////////////////////////////
// TMR strings update for weapons and magazines:
// 1. Change displayname to match TMR standards.
// 3. Add displaynameshort to TMR standards.
//////////////////////////////////////////////////////

class CfgMagazines {
  class CA_Magazine;

  // Magazine updates:
  // 1. Update all magazines with tracer mix to use 1 in 5 mix. Full tracer mags should not be changed!
  // 2. Remove tracers at bottom of magazine.
  // 3. Do string updates.

  // 5.56mm ////////////////////////////////////

  class 30Rnd_556x45_Stanag : CA_Magazine {
    displayname = "5.56mm 30Rnd Mag";
    displaynameshort = "5.56mm";

    tracersEvery = 0;
    lastRoundsTracer = 0;
  };

  class 30Rnd_556x45_Stanag_Tracer_Red: 30Rnd_556x45_Stanag {
    displayname = "5.56mm 30Rnd Tracer Mag";
    displaynameshort = "5.56mm";
  };

  class 30Rnd_556x45_Stanag_Tracer_Green: 30Rnd_556x45_Stanag {
    displayname = "5.56mm 30Rnd Tracer Mag";
    displaynameshort = "5.56mm";
  };

  class 30Rnd_556x45_Stanag_Tracer_Yellow: 30Rnd_556x45_Stanag {
    displayname = "5.56mm 30Rnd Tracer Mag";
    displaynameshort = "5.56mm";
  };

  class 20Rnd_556x45_UW_mag: 30Rnd_556x45_Stanag {
    displayname = "5.56mm 20Rnd MEA Mag";
    displaynameshort = "5.56mm MEA";
  };

  // 6.5mm //////////////////////////////////////////

  class 30Rnd_65x39_caseless_mag : CA_Magazine { // MX!!
    displayname = "6.5mm 30Rnd Mag";
    displaynameshort = "6.5mm";

    tracersEvery = 0;
    lastRoundsTracer = 0;
  };

  class 30Rnd_65x39_caseless_mag_Tracer : 30Rnd_65x39_caseless_mag { // MX!!
    displayname = "6.5mm 30Rnd Tracer Mag";
    displaynameshort = "6.5mm Tracer";
  };

  class 30Rnd_65x39_caseless_green : 30Rnd_65x39_caseless_mag { // Katiba!!
    displayname = "6.5mm 30Rnd Mag";
    displaynameshort = "6.5mm";

    tracersEvery = 0;
    lastRoundsTracer = 0;
  };

  class 30Rnd_65x39_caseless_green_Tracer : 30Rnd_65x39_caseless_green { // Katiba!!
    displayname = "6.5mm 30Rnd Tracer Magazine";
    displaynameshort = "6.5mm Tracer";
  };

  class 100Rnd_65x39_caseless_mag : CA_Magazine {
    displayname = "6.5mm 100Rnd Mag";
    displaynameshort = "6.5mm";

    tracersEvery = 5;
    lastRoundsTracer = 3;
  };

  class 100Rnd_65x39_caseless_mag_Tracer : 100Rnd_65x39_caseless_mag {
    displayname = "6.5mm 100Rnd Tracer Mag";
    displaynameshort = "6.5mm Tracer";
  };

  class 200Rnd_65x39_cased_Box : 100Rnd_65x39_caseless_mag {
    displayname = "6.5mm 200Rnd Box";
    displaynameshort = "6.5mm";

    tracersEvery = 5;
    lastRoundsTracer = 3;
  };
  class 200Rnd_65x39_cased_Box_Tracer: 200Rnd_65x39_cased_Box {
    displayname = "6.5mm 200Rnd Tracer Box";
    displaynameshort = "6.5mm Tracer";
  };

  // 7.62mm //////////////////////////////////////////

  class 20Rnd_762x51_Mag: CA_Magazine {
    displayname = "7.62mm 20Rnd Mag";
    displaynameshort = "7.62mm";
  };

  class 150Rnd_762x51_Box : CA_Magazine {
    displayname = "7.62mm 150Rnd Box";

    tracersEvery = 5;
    lastRoundsTracer = 3;
  };

  class 150Rnd_762x51_Box_Tracer : 150Rnd_762x51_Box {
    displayname = "7.62mm 150Rnd Tracer Box";
  };

  // Anti-materiel ///////////////////////////////

  class 7Rnd_408_Mag: CA_Magazine {
    displayname = ".408 7Rnd Mag";
  };

  class 5Rnd_127x108_Mag: CA_Magazine {
    displayname = "12.7mm 5Rnd Mag";
  };

  // SMG & Pistol ////////////////////////////

  class 30Rnd_9x21_Mag : CA_Magazine {
    displayname = "9mm 30Rnd Mag";
    displaynameshort = "9mm";

    lastRoundsTracer = 0;
  };

  class 16Rnd_9x21_Mag: 30Rnd_9x21_Mag {
    displayname = "9mm 17Rnd Mag";
    displaynameshort = "9mm";

    count = 17;
  };

  class 30Rnd_45ACP_Mag_SMG_01 : 30Rnd_9x21_Mag {
    displayname = ".45 25Rnd Mag";
    displaynameshort = ".45";

    picture = "\A3\weapons_f\data\ui\M_30Rnd_9x21_CA.paa";

    count = 25;

    tracersEvery = 0;
    lastRoundsTracer = 0;
  };

  class 9Rnd_45ACP_Mag : 30Rnd_45ACP_Mag_SMG_01 {
    displayname = ".45 8Rnd Mag";
    displaynameshort = ".45";

    count = 8;
  };

  class 30Rnd_45ACP_Mag_SMG_01_Tracer_Green: 30Rnd_45ACP_Mag_SMG_01 {
    displayname = ".45 25Rnd Tracer Mag";
  };
};

class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;

class CfgWeapons {
  class WeaponSlotsInfo;
  class SlotInfo;
  class Rifle_Base_F;

  ///////////////////////////////////////////////////////////////////////////////
  //////////// SMALL ARMS WEAPONS ///////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////

  // Weapon updates:
  // 1. Do string update.
  // 2. Fix magazine compatibility as needed.
  // 3. Fix firing modes as needed.
  // 4. Fix accessory compatibility as needed.

  // Grenade launchers /////////////////////////////////////
  // Updated strings are in weapon configs.
  class GrenadeLauncher;
  class UGL_F : GrenadeLauncher {};

  // MXs ////////////////////////////////////////////////////

  class arifle_MX_Base_F : Rifle_Base_F {
    magazines[] = {"30Rnd_65x39_caseless_mag", "30Rnd_65x39_caseless_mag_Tracer", "100Rnd_65x39_caseless_mag", "100Rnd_65x39_caseless_mag_Tracer"};

    // http://www.bushmaster.com/acr/#/intro
    // 800 rpm (whatever, fictional lol)

    //class Single : Mode_SemiAuto {};
    class Single : Mode_SemiAuto {
      reloadTime = 0.075;
    };

    class FullAuto: Mode_FullAuto {
      reloadTime = 0.075;
    };
  };

  class arifle_MX_F : arifle_MX_Base_F {
    displayName = "MX";
  };

  class arifle_MXC_F : arifle_MX_Base_F {
    displayName = "MXC";
  };


  class arifle_MX_GL_F : arifle_MX_Base_F {
    displayName = "MX 3GL";

    // class GL_3GL_F : UGL_F {
    //   displayName = "3GL";
    // };
  };

  class arifle_MX_SW_F : arifle_MX_Base_F {
    displayName = "MX LSW";

    modes[] = {"Single", "manual", "close", "short", "medium", "far_optic1", "far_optic2"};

    class Single : Single {};
    class manual : FullAuto {};
  };

  class arifle_MXM_F : arifle_MX_Base_F {
    displayName = "MXM";
  };

  // Katibas ////////////////////////////////////////////////////

  class arifle_katiba_Base_F : Rifle_Base_F {
    // http://world.guns.ru/assault/iran/khaybar-kh2002-e.html
    // 800 rpm

    class Single : Mode_SemiAuto {
      reloadTime = 0.075;
    };

    class FullAuto: Mode_FullAuto {
      reloadTime = 0.075;
    };
  };

  class arifle_Katiba_F : arifle_katiba_Base_F {
    displayName = "KT2002 Katiba";
  };

  class arifle_Katiba_GL_F : arifle_katiba_Base_F {
    displayName = "KT2002 Katiba KGL";

    //class EGLM : UGL_F {
    //  displayName = "KGL";
    //};
  };

  class arifle_Katiba_C_F : arifle_katiba_Base_F {
    displayName = "KT2002C Katiba";
  };

  // SDAR //////////////////////////////////////////////////

  class SDAR_base_F : Rifle_Base_F {
    modes[] = {"Single", "FullAuto"}; // Leave in the imaginary full-auto mode because, whatever.
  };

  class arifle_SDAR_F : SDAR_base_F {
    displayName = "CFB SDAR";

  };

  // Tavor TRG ////////////////////////////////////////////////

  class Tavor_base_F : Rifle_Base_F {
    // http://www.israel-weapon.com/files/brochure_2012/IWI_TAVOR_AR.pdf
    // 700 ~1000 rpm (850)
    class Single : Mode_SemiAuto {
      reloadTime = 0.07;
    };

    class FullAuto: Mode_FullAuto {
      reloadTime = 0.07;
    };
  };

  class arifle_TRG21_F : Tavor_base_F {
    displayName = "TAR-21";
  };

  class arifle_TRG21_GL_F : arifle_TRG21_F {
    displayName = "TAR-21 EGLM";

    // class EGLM : UGL_F {
    //   displayName = "EGLM";
    // };
  };

  class arifle_TRG20_F : Tavor_base_F {
    displayName = "CTAR-21";
  };

  // Mk20 (F2000) //////////////////////////////////////////////////

  class mk20_base_F : Rifle_Base_F {
    // http://www.fnherstal.com/primary-menu/products-capabilities/rifles/technical-data/product/182/232/182/1/_/fn-f2000R-standard.html
    // 850 rpm
    class Single : Mode_SemiAuto {
      reloadTime = 0.07;
    };

    class FullAuto: Mode_FullAuto {
      reloadTime = 0.07;
    };
  };

  class arifle_Mk20_F : mk20_base_F {
    displayName = "F2000A";
  };

  class arifle_Mk20C_F : mk20_base_F {
    displayName = "F2000A Tactical";
  };

  class arifle_Mk20_GL_F : mk20_base_F {
    displayName = "F2000A EGLM";

    // class EGLM : UGL_F {
    //   displayName = "EGLM";
    // };
  };

  // SMG Vermin ////////////////////////////////////////////////////

  class SMG_01_Base : Rifle_Base_F {
    displayName = "Vector SMG";

    // http://kriss-usa.com/pdf/operatormanual/
    // 1200 rpm
    class Single : Mode_SemiAuto {
      reloadTime = 0.05;
    };

    class Burst : Mode_Burst {
      burst = 2;
      reloadTime = 0.05;
    };

    class FullAuto: Mode_FullAuto {
      reloadTime = 0.05;
    };
  };

  class SMG_01_F : SMG_01_Base {
    displayName = "Vector SMG";
    
  };

  // SMG Scorpion ////////////////////////////////////////////////////

  class SMG_02_base_F : Rifle_Base_F {
    //http://www.czub.cz/zbrojovka/cz-manual/Instruction-Manual-Scorpion-EVO-3-A1_en.pdf
    // 1150 rpm

    class Single : Mode_SemiAuto {
      // http://www.stengg.com/upload/915fGdhTi3ggnnGQGGL.pdf
      // 900-1100 rpm (1000rpm)
      reloadTime = 0.052;
    };

    class Burst : Mode_Burst {
      reloadTime = 0.052;
    };

    class FullAuto: Mode_FullAuto {
      reloadTime = 0.052;
    };
  };  

  class SMG_02_F : SMG_02_base_F {
    displayName = "Scorpion Evo 3A1";
  };

  // SMG PDW2000 ///////////////////////////////////////////////////

  class pdw2000_base_F: Rifle_Base_F {
    magazines[] = {"30Rnd_9x21_Mag"};

    modes[] = {"Single", "FullAuto"}; // No burst on this thing

    class Single : Mode_SemiAuto {
      // http://www.stengg.com/upload/915fGdhTi3ggnnGQGGL.pdf
      // 900-1100 rpm (1000rpm)
      reloadTime = 0.06;
    };

    class FullAuto: Mode_FullAuto {
      reloadTime = 0.06;
    };
  };
  class hgun_pdw2000_F : pdw2000_base_F {
    displayName = "CPW-CZ";
  };

  // Pistols //////////////////////////////////////////////

  class Pistol_Base_F;
  class hgun_P07_F : Pistol_Base_F {
    displayName = "P99G";
    magazines[] = {"16Rnd_9x21_Mag"};
  };

  class hgun_Rook40_F : Pistol_Base_F {
    displayName = "MP-443G";
    magazines[] = {"16Rnd_9x21_Mag"};
  };

  class hgun_ACPC2_F : Pistol_Base_F {
    displayName = "ACP-C2";
  };

  // LMGs //////////////////////////////////////////////

  class Rifle_Long_Base_F;

  class LMG_Mk200_F : Rifle_Long_Base_F {
    displayName = "Mk200 LMG";

    modes[] = {"manual", "Single", "close", "short", "medium", "far_optic1", "far_optic2"};

    class manual : Mode_FullAuto {
      // http://www.defensereview.com/kac-stoner-lmg-belt-fed-5-56mm-nato-lightweight-light-machine-gun-squad-automatic-weapon-lmgsaw-displayed-at-sofic-2010/
      // 550 rpm
      reloadTime = 0.109;
    };

    // Add semi-auto mode.
    // Inherit from 'manual' for sound reasons.
    class Single : manual {
      reloadTime = 0.109;
      dispersion = 0.00175; // radians. Equal to 6 MOA.
      autofire = 0;
      burst = 1;
      displayname = "Semi";
      texturetype = "semi";
      showToPlayer = 1;
    };
  };

  class LMG_Zafir_F: Rifle_Long_Base_F {
    displayName = "Negev NG7";

    modes[] = {"FullAuto", "Single",  "close", "short", "medium", "far_optic1", "far_optic2"};

    class FullAuto : Mode_FullAuto {
      reloadTime = 0.070; // 850 RPM on gas position 1
    };
  };

  // Sniper and anti-materiel rifles /////////////////////////////////

  class EBR_base_F : Rifle_Long_Base_F {
    // EMR/EBR is typically issued semi-auto AFAIK
    modes[] = {"Single", "single_close_optics1", "single_medium_optics1", "single_far_optics1"};
    cursor = "arifle";
  };

  class srifle_EBR_F : EBR_base_F {
    displayName = "Mk14 Mod 1 EBR";
  };

  class LRR_base_F : Rifle_Long_Base_F {
    cursor = "arifle";
  };

  class srifle_LRR_F : LRR_base_F {
    displayName = "M200 Intervention";
  };

  class GM6_base_F : Rifle_Long_Base_F {
    cursor = "arifle";

    // Fuck your balancing, BI.
    class Single : Mode_SemiAuto {
      // 250 rpm is probably the limit of the finger on a heavy bullpup trigger like this thing must have.
      reloadTime = 0.24;
    };
  };

  class srifle_GM6_F : GM6_base_F {
    displayName = "GM6 Lynx";
  };

  ///////////////////////////////////////////////////////////////////////////////
  //////////// WEAPON ATTACHMENTS ///////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////

  class ItemCore;
  class InventoryItem_Base_F;
  class InventoryMuzzleItem_Base_F;

};