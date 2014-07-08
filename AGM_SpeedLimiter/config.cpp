class CfgPatches {
  class AGM_SpeedLimiter {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_SpeedLimiter {
    class AGM_SpeedLimiter {
      file = "AGM_SpeedLimiter\functions";
      class speedLimiter;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_SpeedLimiter {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_speedLimiter\clientInit.sqf'";
  };
};

class AGM_Core_Default_Keys {
	class AGM_SpeedLimiter {
		displayName = "AGM Speed Limiter";
		class speedLimiter {
			displayName = "$STR_AGM_SpeedLimiter";
			conditionUp = "player == driver _vehicle && {_vehicle isKindOf 'Car' || {_vehicle isKindOf 'Tank'}}";
			statementUp = "[_vehicle] call AGM_SpeedLimiter_fnc_speedLimiter";
			key = 211;
			shift = 0;
			control = 0;
			alt = 0;
		};
	};
};
