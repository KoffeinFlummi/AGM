class CfgPatches {
  class AGM_Flares {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F};
    version = 1.0;
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgWeapons {
  class GrenadeLauncher;
  class Throw: GrenadeLauncher {
    muzzles[] += {"AGM_HandFlare_Red_Muzzle"};

    class ThrowMuzzle;
    class AGM_HandFlare_Red_Muzzle: ThrowMuzzle {
      magazines[] = {"AGM_HandFlare_Red"};
    };
  };
};

class CfgMagazines {
  class HandGrenade;
  class AGM_HandFlare_Red: HandGrenade {
    ammo = "F_20mm_Red";
    count = 1;
    displayname = "Hand Flare (Red)";
    descriptionshort = "Type: Hand Flare - Red<br />Rounds: 1<br />Used in: Hand";
    displayNameShort = "Red Flare";
    initSpeed = 22;
    mass = 6;
    maxLeadSpeed = 7;
    model = "\A3\weapons_f\ammo\flare_red";
    nameSound = "handgrenade";
    picture = "\A3\Weapons_F\Data\UI\gear_flare_red_ca.paa";
    scope = 2;
    sound[] = {"",0.000316228,1};
    type = 256;
    value = 1;
  };
};