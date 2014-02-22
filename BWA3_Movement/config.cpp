class CfgPatches {
  class BWA3_Movement {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Data_F, A3_Anims_F, A3_Anims_F_Config_Sdr};
    version = 1.0;
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgMods {
  class BWA3_Movement {
    dir = "BWA3_Movement";
    name = "BWA3: Movement Module";
    picture = "";
    hidePicture = "true";
    hideName = "true";
    actionName = "Github";
    action = "https://github.com/KoffeinFlummi/BWA3_Realism";
  };
};


// WHAT DO THESE VALUES EVEN DO?
class CfgFatigue {
  FrequencyMax = 1;
  FrequencyMin = 0.2;
  MaxDuty = 10;
  MinValue1 = 0.1;
  MinValue2 = 0.8;
  NormalRunSpeed = 7.2; // seems to have no effect
  TiredRunSpeedLimit = 1;
  TotalLoadCoef = 1.1; // seems to have no effect
};


class CfgMovesBasic {
  class Actions;
};

class CfgMovesMaleSdr: CfgMovesBasic {
  class Actions: Actions {
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

    // WEAPON LOWERED - WALKING
    /*
    class RifleLowStandActionsWlkF: RifleLowStandActionsNoAdjust {
      PlayerWalkF = "AmovPercMwlkSlowWrflDf_v2";
      WalkF = "AmovPercMwlkSlowWrflDf_v2";
    };
    */
  };
  class States {
    class AmovPercMstpSrasWrflDnon;
    class AmovPercMstpSlowWrflDnon;

    class AmovPercMrunSrasWrflDf: AmovPercMstpSrasWrflDnon { 
      InterpolateTo[] = {"AovrPercMrunSrasWrflDf",0.22,"AmovPercMrunSlowWrflDf",0.025,"AmovPercMwlkSrasWrflDf",0.025,"AmovPknlMrunSrasWrflDf",0.03,"AmovPercMrunSlowWrflDf_AmovPpneMstpSrasWrflDnon",0.02,"AmovPercMevaSrasWrflDf",0.025,"AmovPercMrunSlowWrflDf_AmovPercMevaSrasWrflDl",0.05,"AmovPercMrunSlowWrflDf_AmovPercMevaSrasWrflDr",0.05,"AmovPercMrunSlowWrflDf_AmovPercMevaSrasWrflDb",0.05,"Unconscious",0.01,"AmovPercMtacSrasWrflDf",0.02,"AmovPercMrunSrasWrflDfl",0.02,"AmovPercMrunSrasWrflDfl_ldst",0.02,"AmovPercMrunSrasWrflDfr",0.02,"AmovPercMrunSrasWrflDfr_ldst",0.02,"AmovPercMstpSrasWrflDnon",0.02,"AmovPercMrunSrasWrflDl",0.02,"AmovPercMrunSrasWrflDbl",0.02,"AmovPercMrunSrasWrflDb",0.02,"AmovPercMrunSrasWrflDbr",0.02,"AmovPercMrunSrasWrflDr",0.02,"AmovPknlMstpSlowWrflDnon_relax",0.1,"AmovPercMrunSrasWrflDf_ldst",0.02,"AmovPercMrunSrasWrflDf",0.02};
    };

    class AmovPercMwlkSlowWrflDf: AmovPercMstpSlowWrflDnon {
      speed = 0.206897;
      file = "\A3\anims_f\Data\Anim\Sdr\Mov\Erc\Wlk\Low\Rfl\AmovPercMwlkSlowWrflDf_ver2";
      leftHandIKCurve[] = {1};
    };
  };
};