// PATCH CONFIG
class CfgPatches {
  class AGM_Resting {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {Extended_EventHandlers, AGM_Core};
    version = 1.0;
    author[] = {"KoffeinFlummi", "TaoSensai"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_Resting {
    class AGM_Resting {
      file = "AGM_Resting\functions";
      class keyInput;
      class restWeapon;
      class unRestWeapon;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Resting {
    clientInit = "call compile preProcessFileLineNumbers '\AGM_Resting\init.sqf'";
  };
};

class CfgWeapons {
  class Rifle_Long_Base_F;
  class arifle_MX_Base_F;

  class arifle_MX_SW_F : arifle_MX_Base_F {
    AGM_Bipod = 1;
  };

  class LMG_Mk200_F : Rifle_Long_Base_F {
    AGM_Bipod = 1;
  };
  class LMG_Zafir_F: Rifle_Long_Base_F {
    AGM_Bipod = 1;
  };

  class LRR_base_F : Rifle_Long_Base_F {
    AGM_Bipod = 1;
  };
  class GM6_base_F : Rifle_Long_Base_F {
    AGM_Bipod = 1;
  };
};

// CODE BELOW TAKEN FROM TMR, PREFIXES EDITED FOR COMPATABILITY

#define AGM_SWAY_DEPLOY 0.06
#define AGM_SWAY_DEPLOYPRONE 0.03
#define AGM_SWAY_RESTED 0.16
#define AGM_SWAY_RESTEDPRONE 0.08
#define AGM_DEPLOY_TURNSPEED 0.1

// Arma 3 doesn't respect turnSpeed.

class CfgMovesBasic {
  class Default;

  class Actions {
    class RifleStandActions;
    class RifleStandActions_bwa3_deploy : RifleStandActions {
      stop =    "AmovPercMstpSrasWrflDnon_bwa3_deploy";
      default = "AmovPercMstpSrasWrflDnon_bwa3_deploy";
      turnL =   "AmovPercMstpSrasWrflDnon_bwa3_deploy";
      turnR =   "AmovPercMstpSrasWrflDnon_bwa3_deploy";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustLStandActions;
    class RifleAdjustLStandActions_bwa3_deploy : RifleAdjustLStandActions {
      stop =    "AadjPercMstpSrasWrflDleft_bwa3_deploy";
      default = "AadjPercMstpSrasWrflDleft_bwa3_deploy";
      AdjustL = "AadjPercMstpSrasWrflDleft_bwa3_deploy";
      turnL =   "AadjPercMstpSrasWrflDleft_bwa3_deploy";
      turnR =   "AadjPercMstpSrasWrflDleft_bwa3_deploy";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustRStandActions;
    class RifleAdjustRStandActions_bwa3_deploy : RifleAdjustRStandActions {
      stop =    "AadjPercMstpSrasWrflDright_bwa3_deploy";
      default = "AadjPercMstpSrasWrflDright_bwa3_deploy";
      AdjustRight = "AadjPercMstpSrasWrflDright_bwa3_deploy";
      turnL =   "AadjPercMstpSrasWrflDright_bwa3_deploy";
      turnR =   "AadjPercMstpSrasWrflDright_bwa3_deploy";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustFStandActions;
    class RifleAdjustFStandActions_bwa3_deploy : RifleAdjustFStandActions {
      stop =    "AadjPercMstpSrasWrflDup_bwa3_deploy";
      default = "AadjPercMstpSrasWrflDup_bwa3_deploy";
      AdjustF = "AadjPercMstpSrasWrflDup_bwa3_deploy";
      turnL =   "AadjPercMstpSrasWrflDup_bwa3_deploy";
      turnR =   "AadjPercMstpSrasWrflDup_bwa3_deploy";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustBStandActions;
    class RifleAdjustBStandActions_bwa3_deploy : RifleAdjustBStandActions {
      stop =    "AadjPercMstpSrasWrflDdown_bwa3_deploy";
      default = "AadjPercMstpSrasWrflDdown_bwa3_deploy";
      AdjustB = "AadjPercMstpSrasWrflDdown_bwa3_deploy";
      turnR =   "AadjPercMstpSrasWrflDdown_bwa3_deploy";
      turnL =   "AadjPercMstpSrasWrflDdown_bwa3_deploy";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustLKneelActions;
    class RifleAdjustLKneelActions_bwa3_deploy : RifleAdjustLKneelActions {
      stop =    "AadjPknlMstpSrasWrflDleft_bwa3_deploy";
      default = "AadjPknlMstpSrasWrflDleft_bwa3_deploy";
      turnL =   "AadjPknlMstpSrasWrflDleft_bwa3_deploy";
      turnR =   "AadjPknlMstpSrasWrflDleft_bwa3_deploy";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustRKneelActions;
    class RifleAdjustRKneelActions_bwa3_deploy : RifleAdjustRKneelActions {
      stop =    "AadjPknlMstpSrasWrflDright_bwa3_deploy";
      default = "AadjPknlMstpSrasWrflDright_bwa3_deploy";
      turnL =   "AadjPknlMstpSrasWrflDright_bwa3_deploy";
      turnR =   "AadjPknlMstpSrasWrflDright_bwa3_deploy";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustFKneelActions;
    class RifleAdjustFKneelActions_bwa3_deploy : RifleAdjustFKneelActions {
      stop =    "AadjPknlMstpSrasWrflDup_bwa3_deploy";
      default = "AadjPknlMstpSrasWrflDup_bwa3_deploy";
      turnL =   "AadjPknlMstpSrasWrflDup_bwa3_deploy";
      turnR =   "AadjPknlMstpSrasWrflDup_bwa3_deploy";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustBKneelActions;
    class RifleAdjustBKneelActions_bwa3_deploy : RifleAdjustBKneelActions {
      stop =    "AadjPknlMstpSrasWrflDdown_bwa3_deploy";
      default = "AadjPknlMstpSrasWrflDdown_bwa3_deploy";
      turnL =   "AadjPknlMstpSrasWrflDdown_bwa3_deploy";
      turnR =   "AadjPknlMstpSrasWrflDdown_bwa3_deploy";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleKneelActions;
    class RifleKneelActions_bwa3_deploy : RifleKneelActions {
      stop =    "AmovPknlMstpSrasWrflDnon_bwa3_deploy";
      default = "AmovPknlMstpSrasWrflDnon_bwa3_deploy";
      crouch =  "AmovPknlMstpSrasWrflDnon_bwa3_deploy"; // TODO: this might cause issues
      turnL =   "AmovPknlMstpSrasWrflDnon_bwa3_deploy";
      turnR =   "AmovPknlMstpSrasWrflDnon_bwa3_deploy";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleProneActions;
    class RifleProneActions_bwa3_deploy : RifleProneActions {
      stop =    "AmovPpneMstpSrasWrflDnon_bwa3_deploy";
      default = "AmovPpneMstpSrasWrflDnon_bwa3_deploy";
      turnL =   "AmovPpneMstpSrasWrflDnon_bwa3_deploy";
      turnR =   "AmovPpneMstpSrasWrflDnon_bwa3_deploy";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustFProneActions;
    class RifleAdjustFProneActions_bwa3_deploy : RifleAdjustFProneActions {
      stop =    "aadjppnemstpsraswrfldup_bwa3_deploy";
      default = "aadjppnemstpsraswrfldup_bwa3_deploy";
      turnL =   "aadjppnemstpsraswrfldup_bwa3_deploy";
      turnR =   "aadjppnemstpsraswrfldup_bwa3_deploy";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    //////////////////////////////////////////////////////////////////////

    class RifleStandActions_bwa3_rested : RifleStandActions {
      stop =    "AmovPercMstpSrasWrflDnon_bwa3_rested";
      default = "AmovPercMstpSrasWrflDnon_bwa3_rested";
      turnL =   "AmovPercMstpSrasWrflDnon_bwa3_rested";
      turnR =   "AmovPercMstpSrasWrflDnon_bwa3_rested";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustLStandActions_bwa3_rested : RifleAdjustLStandActions {
      stop =    "AadjPercMstpSrasWrflDleft_bwa3_rested";
      default = "AadjPercMstpSrasWrflDleft_bwa3_rested";
      AdjustL = "AadjPercMstpSrasWrflDleft_bwa3_rested";
      turnL =   "AadjPercMstpSrasWrflDleft_bwa3_rested";
      turnR =   "AadjPercMstpSrasWrflDleft_bwa3_rested";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustRStandActions_bwa3_rested : RifleAdjustRStandActions {
      stop =    "AadjPercMstpSrasWrflDright_bwa3_rested";
      default = "AadjPercMstpSrasWrflDright_bwa3_rested";
      AdjustRight = "AadjPercMstpSrasWrflDright_bwa3_rested";
      turnL =   "AadjPercMstpSrasWrflDright_bwa3_rested";
      turnR =   "AadjPercMstpSrasWrflDright_bwa3_rested";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustFStandActions_bwa3_rested : RifleAdjustFStandActions {
      stop =    "AadjPercMstpSrasWrflDup_bwa3_rested";
      default = "AadjPercMstpSrasWrflDup_bwa3_rested";
      AdjustF = "AadjPercMstpSrasWrflDup_bwa3_rested";
      turnL =   "AadjPercMstpSrasWrflDup_bwa3_rested";
      turnR =   "AadjPercMstpSrasWrflDup_bwa3_rested";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustBStandActions_bwa3_rested : RifleAdjustBStandActions {
      stop =    "AadjPercMstpSrasWrflDdown_bwa3_rested";
      default = "AadjPercMstpSrasWrflDdown_bwa3_rested";
      AdjustB = "AadjPercMstpSrasWrflDdown_bwa3_rested";
      turnR =   "AadjPercMstpSrasWrflDdown_bwa3_rested";
      turnL =   "AadjPercMstpSrasWrflDdown_bwa3_rested";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustLKneelActions_bwa3_rested : RifleAdjustLKneelActions {
      stop =    "AadjPknlMstpSrasWrflDleft_bwa3_rested";
      default = "AadjPknlMstpSrasWrflDleft_bwa3_rested";
      turnL =   "AadjPknlMstpSrasWrflDleft_bwa3_rested";
      turnR =   "AadjPknlMstpSrasWrflDleft_bwa3_rested";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustRKneelActions_bwa3_rested : RifleAdjustRKneelActions {
      stop =    "AadjPknlMstpSrasWrflDright_bwa3_rested";
      default = "AadjPknlMstpSrasWrflDright_bwa3_rested";
      turnL =   "AadjPknlMstpSrasWrflDright_bwa3_rested";
      turnR =   "AadjPknlMstpSrasWrflDright_bwa3_rested";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustFKneelActions_bwa3_rested : RifleAdjustFKneelActions {
      stop =    "AadjPknlMstpSrasWrflDup_bwa3_rested";
      default = "AadjPknlMstpSrasWrflDup_bwa3_rested";
      turnL =   "AadjPknlMstpSrasWrflDup_bwa3_rested";
      turnR =   "AadjPknlMstpSrasWrflDup_bwa3_rested";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustBKneelActions_bwa3_rested : RifleAdjustBKneelActions {
      stop =    "AadjPknlMstpSrasWrflDdown_bwa3_rested";
      default = "AadjPknlMstpSrasWrflDdown_bwa3_rested";
      turnL =   "AadjPknlMstpSrasWrflDdown_bwa3_rested";
      turnR =   "AadjPknlMstpSrasWrflDdown_bwa3_rested";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleKneelActions_bwa3_rested : RifleKneelActions {
      stop =    "AmovPknlMstpSrasWrflDnon_bwa3_rested";
      default = "AmovPknlMstpSrasWrflDnon_bwa3_rested";
      crouch =  "AmovPknlMstpSrasWrflDnon_bwa3_rested";
      turnL =   "AmovPknlMstpSrasWrflDnon_bwa3_rested";
      turnR =   "AmovPknlMstpSrasWrflDnon_bwa3_rested";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleProneActions_bwa3_rested : RifleProneActions {
      stop =    "AmovPpneMstpSrasWrflDnon_bwa3_rested";
      default = "AmovPpneMstpSrasWrflDnon_bwa3_rested";
      turnL =   "AmovPpneMstpSrasWrflDnon_bwa3_rested";
      turnR =   "AmovPpneMstpSrasWrflDnon_bwa3_rested";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustFProneActions_bwa3_rested : RifleAdjustFProneActions {
      stop =    "aadjppnemstpsraswrfldup_bwa3_rested";
      default = "aadjppnemstpsraswrfldup_bwa3_rested";
      turnL =   "aadjppnemstpsraswrfldup_bwa3_rested";
      turnR =   "aadjppnemstpsraswrfldup_bwa3_rested";
      turnSpeed = AGM_DEPLOY_TURNSPEED;
      limitFast = 1;
    };
  };
};

class CfgMovesMaleSdr : CfgMovesBasic { 
  class States {
    class AmovPercMstpSrasWrflDnon;
    class AmovPercMstpSrasWrflDnon_bwa3_deploy : AmovPercMstpSrasWrflDnon {
      aimPrecision = AGM_SWAY_DEPLOY;
      actions = "RifleStandActions_bwa3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"AmovPercMstpSrasWrflDnon_bwa3_deploy", 0.02};
      ConnectFrom[] = {"AmovPercMstpSrasWrflDnon_bwa3_deploy", 0.02};
      InterpolateFrom[] = {"AmovPercMstpSrasWrflDnon", 0.02};
      InterpolateTo[] = {"AmovPercMstpSrasWrflDnon", 0.02};
    };

    class aadjpercmstpsraswrfldup;
    class aadjpercmstpsraswrfldup_bwa3_deploy : aadjpercmstpsraswrfldup {
      aimPrecision = AGM_SWAY_DEPLOY;
      actions = "RifleAdjustFStandActions_bwa3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpercmstpsraswrfldup_bwa3_deploy", 0.02};
      ConnectFrom[] = {"aadjpercmstpsraswrfldup_bwa3_deploy", 0.02};
      InterpolateFrom[] = {"aadjpercmstpsraswrfldup", 0.02};
      InterpolateTo[] = {"aadjpercmstpsraswrfldup", 0.02};
    };

    class aadjpercmstpsraswrflddown;
    class aadjpercmstpsraswrflddown_bwa3_deploy : aadjpercmstpsraswrflddown {
      aimPrecision = AGM_SWAY_DEPLOY;
      actions = "RifleAdjustBStandActions_bwa3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpercmstpsraswrflddown_bwa3_deploy", 0.02};
      ConnectFrom[] = {"aadjpercmstpsraswrflddown_bwa3_deploy", 0.02};
      InterpolateFrom[] = {"aadjpercmstpsraswrflddown", 0.02};
      InterpolateTo[] = {"aadjpercmstpsraswrflddown", 0.02};
    };

    class aadjpercmstpsraswrfldright;
    class aadjpercmstpsraswrfldright_bwa3_deploy : aadjpercmstpsraswrfldright {
      aimPrecision = AGM_SWAY_DEPLOY;
      actions = "RifleAdjustRStandActions_bwa3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpercmstpsraswrfldright_bwa3_deploy", 0.02};
      ConnectFrom[] = {"aadjpercmstpsraswrfldright_bwa3_deploy", 0.02};
      InterpolateFrom[] = {"aadjpercmstpsraswrfldright", 0.02};
      InterpolateTo[] = {"aadjpercmstpsraswrfldright", 0.02};
    };

    class aadjpercmstpsraswrfldleft;
    class aadjpercmstpsraswrfldleft_bwa3_deploy : aadjpercmstpsraswrfldleft {
      aimPrecision = AGM_SWAY_DEPLOY;
      actions = "RifleAdjustLStandActions_bwa3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpercmstpsraswrfldleft_bwa3_deploy", 0.02};
      ConnectFrom[] = {"aadjpercmstpsraswrfldleft_bwa3_deploy", 0.02};
      InterpolateFrom[] = {"aadjpercmstpsraswrfldleft", 0.02};
      InterpolateTo[] = {"aadjpercmstpsraswrfldleft", 0.02};
    };

    class aadjpknlmstpsraswrfldup;
    class aadjpknlmstpsraswrfldup_bwa3_deploy : aadjpknlmstpsraswrfldup {
      aimPrecision = AGM_SWAY_DEPLOY;
      actions = "RifleAdjustFKneelActions_bwa3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpknlmstpsraswrfldup_bwa3_deploy", 0.02};
      ConnectFrom[] = {"aadjpknlmstpsraswrfldup_bwa3_deploy", 0.02};
      InterpolateFrom[] = {"aadjpknlmstpsraswrfldup", 0.02};
      InterpolateTo[] = {"aadjpknlmstpsraswrfldup", 0.02};
    };

    class amovpknlmstpsraswrfldnon;
    class amovpknlmstpsraswrfldnon_bwa3_deploy : amovpknlmstpsraswrfldnon {
      aimPrecision = AGM_SWAY_DEPLOY;
      actions = "RifleKneelActions_bwa3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"amovpknlmstpsraswrfldnon_bwa3_deploy", 0.02};
      ConnectFrom[] = {"amovpknlmstpsraswrfldnon_bwa3_deploy", 0.02};
      InterpolateFrom[] = {"amovpknlmstpsraswrfldnon", 0.02};
      InterpolateTo[] = {"amovpknlmstpsraswrfldnon", 0.02};
    };

    class aadjpknlmstpsraswrflddown;
    class aadjpknlmstpsraswrflddown_bwa3_deploy : aadjpknlmstpsraswrflddown {
      aimPrecision = AGM_SWAY_DEPLOY;
      actions = "RifleAdjustBKneelActions_bwa3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpknlmstpsraswrflddown_bwa3_deploy", 0.02};
      ConnectFrom[] = {"aadjpknlmstpsraswrflddown_bwa3_deploy", 0.02};
      InterpolateFrom[] = {"aadjpknlmstpsraswrflddown", 0.02};
      InterpolateTo[] = {"aadjpknlmstpsraswrflddown", 0.02};
    };

    class aadjpknlmstpsraswrfldleft;
    class aadjpknlmstpsraswrfldleft_bwa3_deploy : aadjpknlmstpsraswrfldleft {
      aimPrecision = AGM_SWAY_DEPLOY;
      actions = "RifleAdjustLKneelActions_bwa3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpknlmstpsraswrfldleft_bwa3_deploy", 0.02};
      ConnectFrom[] = {"aadjpknlmstpsraswrfldleft_bwa3_deploy", 0.02};
      InterpolateFrom[] = {"aadjpknlmstpsraswrfldleft", 0.02};
      InterpolateTo[] = {"aadjpknlmstpsraswrfldleft", 0.02};
    };

    class aadjpknlmstpsraswrfldright;
    class aadjpknlmstpsraswrfldright_bwa3_deploy : aadjpknlmstpsraswrfldright {
      aimPrecision = AGM_SWAY_DEPLOY;
      actions = "RifleAdjustRKneelActions_bwa3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpknlmstpsraswrfldright_bwa3_deploy", 0.02};
      ConnectFrom[] = {"aadjpknlmstpsraswrfldright_bwa3_deploy", 0.02};
      InterpolateFrom[] = {"aadjpknlmstpsraswrfldright", 0.02};
      InterpolateTo[] = {"aadjpknlmstpsraswrfldright", 0.02};
    };

    class aadjppnemstpsraswrfldup;
    class aadjppnemstpsraswrfldup_bwa3_deploy : aadjppnemstpsraswrfldup {
      aimPrecision = AGM_SWAY_DEPLOYPRONE;
      actions = "RifleAdjustFProneActions_bwa3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjppnemstpsraswrfldup_bwa3_deploy", 0.02};
      ConnectFrom[] = {"aadjppnemstpsraswrfldup_bwa3_deploy", 0.02};
      InterpolateFrom[] = {"aadjppnemstpsraswrfldup", 0.02};
      InterpolateTo[] = {"aadjppnemstpsraswrfldup", 0.02};
    };

    class amovppnemstpsraswrfldnon;
    class amovppnemstpsraswrfldnon_bwa3_deploy : amovppnemstpsraswrfldnon {
      aimPrecision = AGM_SWAY_DEPLOYPRONE;
      actions = "RifleProneActions_bwa3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"amovppnemstpsraswrfldnon_bwa3_deploy", 0.02};
      ConnectFrom[] = {"amovppnemstpsraswrfldnon_bwa3_deploy", 0.02};
      InterpolateFrom[] = {"amovppnemstpsraswrfldnon", 0.02};
      InterpolateTo[] = {"amovppnemstpsraswrfldnon", 0.02};
    };

    /////////////////////////////////////////////////////////////////////////////

        class AmovPercMstpSrasWrflDnon_bwa3_rested : AmovPercMstpSrasWrflDnon {
      aimPrecision = AGM_SWAY_RESTED;
      actions = "RifleStandActions_bwa3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"AmovPercMstpSrasWrflDnon_bwa3_rested", 0.02};
      ConnectFrom[] = {"AmovPercMstpSrasWrflDnon_bwa3_rested", 0.02};
      InterpolateFrom[] = {"AmovPercMstpSrasWrflDnon", 0.02};
      InterpolateTo[] = {"AmovPercMstpSrasWrflDnon", 0.02};
    };

    class aadjpercmstpsraswrfldup_bwa3_rested : aadjpercmstpsraswrfldup {
      aimPrecision = AGM_SWAY_RESTED;
      actions = "RifleAdjustFStandActions_bwa3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpercmstpsraswrfldup_bwa3_rested", 0.02};
      ConnectFrom[] = {"aadjpercmstpsraswrfldup_bwa3_rested", 0.02};
      InterpolateFrom[] = {"aadjpercmstpsraswrfldup", 0.02};
      InterpolateTo[] = {"aadjpercmstpsraswrfldup", 0.02};
    };

    class aadjpercmstpsraswrflddown_bwa3_rested : aadjpercmstpsraswrflddown {
      aimPrecision = AGM_SWAY_RESTED;
      actions = "RifleAdjustBStandActions_bwa3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpercmstpsraswrflddown_bwa3_rested", 0.02};
      ConnectFrom[] = {"aadjpercmstpsraswrflddown_bwa3_rested", 0.02};
      InterpolateFrom[] = {"aadjpercmstpsraswrflddown", 0.02};
      InterpolateTo[] = {"aadjpercmstpsraswrflddown", 0.02};
    };

    class aadjpercmstpsraswrfldright_bwa3_rested : aadjpercmstpsraswrfldright {
      aimPrecision = AGM_SWAY_RESTED;
      actions = "RifleAdjustRStandActions_bwa3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpercmstpsraswrfldright_bwa3_rested", 0.02};
      ConnectFrom[] = {"aadjpercmstpsraswrfldright_bwa3_rested", 0.02};
      InterpolateFrom[] = {"aadjpercmstpsraswrfldright", 0.02};
      InterpolateTo[] = {"aadjpercmstpsraswrfldright", 0.02};
    };

    class aadjpercmstpsraswrfldleft_bwa3_rested : aadjpercmstpsraswrfldleft {
      aimPrecision = AGM_SWAY_RESTED;
      actions = "RifleAdjustLStandActions_bwa3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpercmstpsraswrfldleft_bwa3_rested", 0.02};
      ConnectFrom[] = {"aadjpercmstpsraswrfldleft_bwa3_rested", 0.02};
      InterpolateFrom[] = {"aadjpercmstpsraswrfldleft", 0.02};
      InterpolateTo[] = {"aadjpercmstpsraswrfldleft", 0.02};
    };

    class aadjpknlmstpsraswrfldup_bwa3_rested : aadjpknlmstpsraswrfldup {
      aimPrecision = AGM_SWAY_RESTED;
      actions = "RifleAdjustFKneelActions_bwa3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpknlmstpsraswrfldup_bwa3_rested", 0.02};
      ConnectFrom[] = {"aadjpknlmstpsraswrfldup_bwa3_rested", 0.02};
      InterpolateFrom[] = {"aadjpknlmstpsraswrfldup", 0.02};
      InterpolateTo[] = {"aadjpknlmstpsraswrfldup", 0.02};
    };

    class amovpknlmstpsraswrfldnon_bwa3_rested : amovpknlmstpsraswrfldnon {
      aimPrecision = AGM_SWAY_RESTED;
      actions = "RifleKneelActions_bwa3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"amovpknlmstpsraswrfldnon_bwa3_rested", 0.02};
      ConnectFrom[] = {"amovpknlmstpsraswrfldnon_bwa3_rested", 0.02};
      InterpolateFrom[] = {"amovpknlmstpsraswrfldnon", 0.02};
      InterpolateTo[] = {"amovpknlmstpsraswrfldnon", 0.02};
    };

    class aadjpknlmstpsraswrflddown_bwa3_rested : aadjpknlmstpsraswrflddown {
      aimPrecision = AGM_SWAY_RESTED;
      actions = "RifleAdjustBKneelActions_bwa3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpknlmstpsraswrflddown_bwa3_rested", 0.02};
      ConnectFrom[] = {"aadjpknlmstpsraswrflddown_bwa3_rested", 0.02};
      InterpolateFrom[] = {"aadjpknlmstpsraswrflddown", 0.02};
      InterpolateTo[] = {"aadjpknlmstpsraswrflddown", 0.02};
    };

    class aadjpknlmstpsraswrfldleft_bwa3_rested : aadjpknlmstpsraswrfldleft {
      aimPrecision = AGM_SWAY_RESTED;
      actions = "RifleAdjustLKneelActions_bwa3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpknlmstpsraswrfldleft_bwa3_rested", 0.02};
      ConnectFrom[] = {"aadjpknlmstpsraswrfldleft_bwa3_rested", 0.02};
      InterpolateFrom[] = {"aadjpknlmstpsraswrfldleft", 0.02};
      InterpolateTo[] = {"aadjpknlmstpsraswrfldleft", 0.02};
    };

    class aadjpknlmstpsraswrfldright_bwa3_rested : aadjpknlmstpsraswrfldright {
      aimPrecision = AGM_SWAY_RESTED;
      actions = "RifleAdjustRKneelActions_bwa3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpknlmstpsraswrfldright_bwa3_rested", 0.02};
      ConnectFrom[] = {"aadjpknlmstpsraswrfldright_bwa3_rested", 0.02};
      InterpolateFrom[] = {"aadjpknlmstpsraswrfldright", 0.02};
      InterpolateTo[] = {"aadjpknlmstpsraswrfldright", 0.02};
    };

    class aadjppnemstpsraswrfldup_bwa3_rested : aadjppnemstpsraswrfldup {
      aimPrecision = AGM_SWAY_RESTEDPRONE;
      actions = "RifleAdjustFProneActions_bwa3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjppnemstpsraswrfldup_bwa3_rested", 0.02};
      ConnectFrom[] = {"aadjppnemstpsraswrfldup_bwa3_rested", 0.02};
      InterpolateFrom[] = {"aadjppnemstpsraswrfldup", 0.02};
      InterpolateTo[] = {"aadjppnemstpsraswrfldup", 0.02};
    };

    class amovppnemstpsraswrfldnon_bwa3_rested : amovppnemstpsraswrfldnon {
      aimPrecision = AGM_SWAY_RESTEDPRONE;
      actions = "RifleProneActions_bwa3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"amovppnemstpsraswrfldnon_bwa3_rested", 0.02};
      ConnectFrom[] = {"amovppnemstpsraswrfldnon_bwa3_rested", 0.02};
      InterpolateFrom[] = {"amovppnemstpsraswrfldnon", 0.02};
      InterpolateTo[] = {"amovppnemstpsraswrfldnon", 0.02};
    };
  };
};