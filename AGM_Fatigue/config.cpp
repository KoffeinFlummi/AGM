// PATCH CONFIG
class CfgPatches {
  class AGM_Fatigue {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.10;
    requiredAddons[] = {AGM_Core};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"commy2"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_Fatigue {
    class AGM_Fatigue {
      file = "AGM_Fatigue\functions";
      class blinking;
      class heartbeat;
      class recoil;
      class stumble;
      class vision;
      class module;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Fatigue {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_Fatigue\clientInit.sqf'";
  };
};

class CfgFatigue {
  MinValue1 = 0.1;
  MinValue2 = 0.8;
  NormalRunSpeed = 7.2;
  TiredRunSpeedLimit = 0.8;
  FrequencyMin = 0.2;
  FrequencyMax = 1.0;
  TotalLoadCoef = 1.1;
  MaxDuty = 10;
};

/*class CfgInventoryGlobalVariable {
  maxSoldierLoad = 1200;
};*/

class CfgSounds {
  class AGM_Heartbeat {
    name = "AGM_Heartbeat";
    sound[] = {"AGM_Fatigue\sounds\heartbeat.ogg",1,1};
    titles[] = {};
  };
};

//DEFAULT
/*
MinValue1 = 0.1;
MinValue2 = 0.8;
NormalRunSpeed = 7.2;
TiredRunSpeedLimit = 1;
FrequencyMin = 0.2;
FrequencyMax = 1.0;
TotalLoadCoef = 1.1;
MaxDuty = 10;
*/

class CfgVehicles {
  class Module_F;
  class AGM_ModuleFatigue: Module_F {
    author = "AGM Team";
    category = "AGM";
    displayName = "Fatigue System";
    function = "AGM_Fatigue_fnc_module";
    scope = 2;
    isGlobal = 1;
    class Arguments {
      class CoefFatigue {
        displayName = "Getting Tired Coef.";
        description = "Multiplier for the rate of getting tired. Default: 1";
        defaultValue = 1;
      };
      class CoefRecover {
        displayName = "Recover Coef.";
        description = "Multiplier for the time to rest after getting tired. Default: 1";
        defaultValue = 1;
      };
    };
  };
};
