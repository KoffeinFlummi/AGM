class CfgPatches {
  class BWA3_SpeedLimiter {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {Extended_EventHandlers, BWA3_Core};
    version = 1.0;
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class Extended_PostInit_EventHandlers {
  class BWA3_SpeedLimiter {
    clientInit = "execVM '\bwa3_speedLimiter\init.sqf'";
  };
};

class BWA3_Core_Default_Keys {
  class speedLimiter {
    displayName = "Speed Limiter";
    key = 211;
    shift = 0;
    control = 0;
    alt = 0;
  };
};
