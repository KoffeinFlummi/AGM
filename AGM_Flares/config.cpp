class CfgPatches {
  class AGM_Flares {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgAmmo {
  class FlareCore;
  class FlareBase: FlareCore {
    intensity = 20000;
    flareSize = 12;
  };
  class F_40mm_White: FlareBase {
    intensity = 40000;
    flareSize = 12;
  };
  class F_20mm_White: FlareBase {
    intensity = 20000;
    flareSize = 12;
  };
  class F_Signal_Green: FlareBase {
    intensity = 20000;
    flareSize = 12;
  };
  class Flare_82mm_AMOS_White: FlareCore {
    intensity = 80000;
    flareSize = 12;
  };

  class F_20mm_Red: F_20mm_White {};
  class F_20mm_Green: F_20mm_White {};
  class F_20mm_Yellow: F_20mm_White {};

  class AGM_F_Hand_White: F_20mm_White {
    timeToLive = 60;
  };
  class AGM_F_Hand_Red: F_20mm_Red {
    timeToLive = 60;
  };
  class AGM_F_Hand_Green: F_20mm_Green {
    timeToLive = 60;
  };
  class AGM_F_Hand_Yellow: F_20mm_Yellow {
    timeToLive = 60;
  };
};

class CfgMagazines {
  class HandGrenade;

  class AGM_HandFlare_White: HandGrenade {
    ammo = "AGM_F_Hand_White";
    displayname = "Hand Flare (White)";
    descriptionshort = "White Hand Flare";
    displayNameShort = "White Flare";
    model = "\A3\weapons_f\ammo\flare_white";
    picture = "\A3\Weapons_F\Data\UI\gear_flare_white_ca.paa";
  };
  class AGM_HandFlare_Red: HandGrenade {
    ammo = "AGM_F_Hand_Red";
    displayname = "Hand Flare (Red)";
    descriptionshort = "Red Hand Flare";
    displayNameShort = "Red Flare";
    model = "\A3\weapons_f\ammo\flare_red";
    picture = "\A3\Weapons_F\Data\UI\gear_flare_red_ca.paa";
  };
  class AGM_HandFlare_Green: HandGrenade {
    ammo = "AGM_F_Hand_Green";
    displayname = "Hand Flare (Green)";
    descriptionshort = "Green Hand Flare";
    displayNameShort = "Green Flare";
    model = "\A3\weapons_f\ammo\flare_green";
    picture = "\A3\Weapons_F\Data\UI\gear_flare_green_ca.paa";
  };
  class AGM_HandFlare_Yellow: HandGrenade {
    ammo = "AGM_F_Hand_Yellow";
    displayname = "Hand Flare (Yellow)";
    descriptionshort = "Yellow Hand Flare";
    displayNameShort = "Yellow Flare";
    model = "\A3\weapons_f\ammo\flare_yellow";
    picture = "\A3\Weapons_F\Data\UI\gear_flare_yellow_ca.paa";
  };
};

class CfgWeapons {
  class GrenadeLauncher;

  class Throw: GrenadeLauncher {
    muzzles[] += {"AGM_HandFlare_WhiteMuzzle", "AGM_HandFlare_RedMuzzle", "AGM_HandFlare_GreenMuzzle", "AGM_HandFlare_YellowMuzzle"};
    class ThrowMuzzle;
    class AGM_HandFlare_WhiteMuzzle: ThrowMuzzle {
      magazines[] = {"AGM_HandFlare_White"};
    };
    class AGM_HandFlare_RedMuzzle: ThrowMuzzle {
      magazines[] = {"AGM_HandFlare_Red"};
    };
    class AGM_HandFlare_GreenMuzzle: ThrowMuzzle {
      magazines[] = {"AGM_HandFlare_Green"};
    };
    class AGM_HandFlare_YellowMuzzle: ThrowMuzzle {
      magazines[] = {"AGM_HandFlare_Yellow"};
    };
  };
};
