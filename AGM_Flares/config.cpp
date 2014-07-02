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
};
