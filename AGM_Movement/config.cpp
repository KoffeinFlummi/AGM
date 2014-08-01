// PATCH CONFIG
class CfgPatches {
  class AGM_Movement {
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
  class AGM_Movement {
    class AGM_Movement {
      file = "AGM_Movement\functions";
      class blinking;
      class fatigueModule;
      class heartbeat;
      class getWeight;
      class recoil;
      class stumble;
      class vision;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Movement {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_Movement\clientInit.sqf'";
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
    sound[] = {"AGM_Movement\sounds\heartbeat.ogg",1,1};
    titles[] = {};
  };
};

class AGM_Core_Options {
  class useImperial {
    displayName = "$STR_AGM_Movement_UseImperial";
    default = 0;
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
    function = "AGM_Movement_fnc_fatigueModule";
    scope = 2;
    isGlobal = 1;
    icon = "\AGM_Movement\UI\IconFatigue_ca.paa";
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

class CfgMovesBasic {
  class Actions {
    class RifleStandActionsNoAdjust;
    class RifleLowStandActionsNoAdjust;

    // WEAPON RAISED - RUNNING
    class RifleStandActionsRunF: RifleStandActionsNoAdjust {
      getOver = "AovrPercMrunSrasWrflDf";
    };
    class RifleStandActionsRunFL: RifleStandActionsNoAdjust {
      getOver = "AovrPercMrunSrasWrflDf";
    };
    class RifleStandActionsRunFR: RifleStandActionsNoAdjust {
      getOver = "AovrPercMrunSrasWrflDf";
    };
    // WEAPON RAISED - SPRINTING
    class RifleStandEvasiveActionsF: RifleStandActionsNoAdjust {
      getOver = "AovrPercMrunSrasWrflDf";
    };
    class RifleStandEvasiveActionsFL: RifleStandActionsNoAdjust {
      getOver = "AovrPercMrunSrasWrflDf";
    };
    class RifleStandEvasiveActionsFR: RifleStandActionsNoAdjust {
      getOver = "AovrPercMrunSrasWrflDf";
    };
    // WEAPON LOWERED - RUNNING
    class RifleLowStandActionsRunF: RifleLowStandActionsNoAdjust {
      getOver = "AovrPercMrunSrasWrflDf";
    };
    class RifleLowStandActionsRunFL: RifleLowStandActionsNoAdjust {
      getOver = "AovrPercMrunSrasWrflDf";
    };
    class RifleLowStandActionsRunFR: RifleLowStandActionsNoAdjust {
      getOver = "AovrPercMrunSrasWrflDf";
    };
  };
};

class CfgMovesMaleSdr: CfgMovesBasic {
  class States {
    class AmovPercMstpSrasWrflDnon;
    class AmovPercMstpSlowWrflDnon;

    class AmovPercMrunSrasWrflDf: AmovPercMstpSrasWrflDnon {
      InterpolateTo[] = {"AovrPercMrunSrasWrflDf",0.22,"AmovPercMrunSlowWrflDf",0.025,"AmovPercMwlkSrasWrflDf",0.025,"AmovPknlMrunSrasWrflDf",0.03,"AmovPercMrunSlowWrflDf_AmovPpneMstpSrasWrflDnon",0.02,"AmovPercMevaSrasWrflDf",0.025,"AmovPercMrunSlowWrflDf_AmovPercMevaSrasWrflDl",0.05,"AmovPercMrunSlowWrflDf_AmovPercMevaSrasWrflDr",0.05,"AmovPercMrunSlowWrflDf_AmovPercMevaSrasWrflDb",0.05,"Unconscious",0.01,"AmovPercMtacSrasWrflDf",0.02,"AmovPercMrunSrasWrflDfl",0.02,"AmovPercMrunSrasWrflDfl_ldst",0.02,"AmovPercMrunSrasWrflDfr",0.02,"AmovPercMrunSrasWrflDfr_ldst",0.02,"AmovPercMstpSrasWrflDnon",0.02,"AmovPercMrunSrasWrflDl",0.02,"AmovPercMrunSrasWrflDbl",0.02,"AmovPercMrunSrasWrflDb",0.02,"AmovPercMrunSrasWrflDbr",0.02,"AmovPercMrunSrasWrflDr",0.02,"AmovPknlMstpSlowWrflDnon_relax",0.1,"AmovPercMrunSrasWrflDf_ldst",0.02,"AmovPercMrunSrasWrflDf",0.02};
    };

    class AmovPercMwlkSlowWrflDf: AmovPercMstpSlowWrflDnon {
      //speed = "1.3*0.206897";
      file = "\A3\anims_f\Data\Anim\Sdr\Mov\Erc\Wlk\Low\Rfl\AmovPercMwlkSlowWrflDf_ver2";
      leftHandIKCurve[] = {1};
    };
    class AmovPercMwlkSlowWrflDfl: AmovPercMwlkSlowWrflDf {
      leftHandIKCurve[] = {};
    };
    class AmovPercMwlkSlowWrflDfr: AmovPercMwlkSlowWrflDf {
      leftHandIKCurve[] = {};
    };
    class AmovPercMwlkSlowWrflDb: AmovPercMwlkSlowWrflDf {
      leftHandIKCurve[] = {};
    };
    class AmovPercMwlkSlowWrflDbl: AmovPercMwlkSlowWrflDf {
      leftHandIKCurve[] = {};
    };
    class AmovPercMwlkSlowWrflDbr: AmovPercMwlkSlowWrflDf {
      leftHandIKCurve[] = {};
    };
    class AmovPercMwlkSlowWrflDl: AmovPercMwlkSlowWrflDf {
      leftHandIKCurve[] = {};
    };
    class AmovPercMwlkSlowWrflDr: AmovPercMwlkSlowWrflDf {
      leftHandIKCurve[] = {};
    };
  };
};
