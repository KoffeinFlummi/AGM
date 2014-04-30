class CfgPatches {
  class AGM_SpeedLimiter {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {Extended_EventHandlers, AGM_Core};
    version = 1.0;
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_SpeedLimiter {
    clientInit = "execVM '\AGM_speedLimiter\init.sqf'";
  };
};

class AGM_Core_Default_Keys {
  class speedLimiter {
    displayName = "Speed Limiter";
    conditionUp = "player == driver _vehicle && {_vehicle isKindOf 'Car' || {_vehicle isKindOf 'Tank'}}";
    statementUp = "[_vehicle] spawn AGM_SpeedLimiter_speedLimiter";
    key = 211;
    shift = 0;
    control = 0;
    alt = 0;
  };
};
