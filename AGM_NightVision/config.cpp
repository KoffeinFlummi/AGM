class CfgPatches {
  class AGM_NightVision {
    units[] = {};
    weapons[] = {"AGN_NVG_Gen1", "AGN_NVG_Gen2", "AGN_NVG_Gen3", "AGN_NVG_Gen4", "AGN_NVG_WIDE"};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.94.1";
    versionStr = "0.94.1";
    versionAr[] = {0,94,1};
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_NightVision {
    class AGM_NightVision {
      file = "\AGM_nightvision\functions";
      class blending;
      class decreaseNVGBrightness;
      class increaseNVGBrightness;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_NightVision {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_NightVision\clientInit.sqf'";
  };
};

class Extended_FiredBIS_EventHandlers {
  class AllVehicles {
    class AGM_NightVision_Blending {
      clientFiredBIS = "if (_this select 0 == vehicle AGM_player && {currentVisionMode (_this select 0) == 1}) then {_this call AGM_NightVision_fnc_blending};";
    };
  };
};

class AGM_Core_Default_Keys {
  class increaseNVGBrightness {
    displayName = "$STR_AGM_NightVision_IncreaseNVGBrightness";
    condition = "currentVisionMode _player == 1";
    statement = "[_player, _vehicle] call AGM_NightVision_fnc_increaseNVGBrightness";
    key = 201;
    shift = 0;
    control = 0;
    alt = 1;
    allowHolding = 1;
  };
  class decreaseNVGBrightness {
    displayName = "$STR_AGM_NightVision_DecreaseNVGBrightness";
    condition = "currentVisionMode _player == 1";
    statement = "[_player, _vehicle] call AGM_NightVision_fnc_decreaseNVGBrightness";
    key = 209;
    shift = 0;
    control = 0;
    alt = 1;
    allowHolding = 1;
  };
};

class cfgWeapons {
  class Binocular;
  class NVGoggles: Binocular {
    AGN_NightVision_grain = 0.75;
    AGN_NightVision_blur = 0;
  };
  class NVGoggles_OPFOR: NVGoggles {};
  class NVGoggles_INDEP: NVGoggles {};

  class AGN_NVG_Gen1: NVGoggles_OPFOR {
    author = "AGM Team";
    modelOptics = "\A3\weapons_f\reticle\optics_night";
    displayName = "$STR_AGM_NightVision_NVG_Gen1";
    AGN_NightVision_grain = 2.25;
    AGN_NightVision_blur = 0.22;
  };
  class AGN_NVG_Gen2: NVGoggles_INDEP {
    author = "AGM Team";
    modelOptics = "\A3\weapons_f\reticle\optics_night";
    displayName = "$STR_AGM_NightVision_NVG_Gen2";
    AGN_NightVision_grain = 1.5;
    AGN_NightVision_blur = 0.11;
  };
  class AGN_NVG_Gen3: NVGoggles {
    author = "AGM Team";
    modelOptics = "\A3\weapons_f\reticle\optics_night";
    displayName = "$STR_AGM_NightVision_NVG_Gen3";
    AGN_NightVision_grain = 0.75;
    AGN_NightVision_blur = 0.055;
  };
  class AGN_NVG_Gen4: NVGoggles {
    author = "AGM Team";
    modelOptics = "\A3\weapons_f\reticle\optics_night";
    displayName = "$STR_AGM_NightVision_NVG_Gen4";
    AGN_NightVision_grain = 0.0;
    AGN_NightVision_blur = 0.0;
  };
  class AGN_NVG_WIDE: NVGoggles {
    author = "AGM Team";
    modelOptics = "\A3\weapons_f\reticle\optics_empty";
    displayName = "$STR_AGM_NightVision_NVG_FullScreen";
    AGN_NightVision_grain = 0.75;
    AGN_NightVision_blur = 0.05;
  };
};