// PATCH CONFIG
class CfgPatches {
  class AGM_Fatigue {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.10;
    requiredAddons[] = {"A3_Misc_F", "A3_Data_F", "AGM_Core"};
    version = "0.9";
    versionStr = "0.9";
    versionAr[] = {0,9,0};
    author[] = {"commy2"};
    authorUrl = "https://github.com/commy2/";
  };
};

/*class CfgFunctions {
  class AGM_Fatigue {
    class AGM_Fatigue {
      file = "AGM_Fatigue\functions";
      class bandage;
    };
  };
};*/

class Extended_PostInit_EventHandlers {
  class AGM_Fatigue {
    clientInit = "execVM '\AGM_Fatigue\init.sqf'";
  };
};

class CfgFatigue {
  MinValue1 = 0.1;
  MinValue2 = 0.8;
  NormalRunSpeed = 7.2;
  TiredRunSpeedLimit = 0.5;
  FrequencyMin = 0.2;
  FrequencyMax = 1.0;
  TotalLoadCoef = 1.1;
  MaxDuty = 10;
};
/*class CfgInventoryGlobalVariable {
  maxSoldierLoad = 1200;
};*/


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
