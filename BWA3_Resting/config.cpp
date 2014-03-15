// PATCH CONFIG
class CfgPatches {
  class BWA3_Resting {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {Extended_EventHandlers, BWA3_Core};
    version = 1.0;
    author[] = {"KoffeinFlummi", "TaoSensai"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class BWA3_Resting {
    class BWA3_Resting {
      file = "BWA3_Resting\functions";
      class keyInput {};
      class restWeapon {};
      class unRestWeapon {};
    };
  };
};

class Extended_PostInit_EventHandlers {
  class BWA3_Resting {
    clientInit = "call compile preProcessFileLineNumbers '\BWA3_Resting\init.sqf'";
  };
};

class CfgWeapons {
  class Rifle_Long_Base_F;
  class arifle_MX_Base_F;

  class arifle_MX_SW_F : arifle_MX_Base_F {
    BWA3_Bipod = 1;
  };

  class LMG_Mk200_F : Rifle_Long_Base_F {
    BWA3_Bipod = 1;
  };
  class LMG_Zafir_F: Rifle_Long_Base_F {
    BWA3_Bipod = 1;
  };

  class LRR_base_F : Rifle_Long_Base_F {
    BWA3_Bipod = 1;
  };
  class GM6_base_F : Rifle_Long_Base_F {
    BWA3_Bipod = 1;
  };
};

// CODE BELOW TAKEN FROM TMR, PREFIXES EDITED FOR COMPATABILITY

#define BWA3_SWAY_DEPLOY 0.06
#define BWA3_SWAY_DEPLOYPRONE 0.03
#define BWA3_SWAY_RESTED 0.16
#define BWA3_SWAY_RESTEDPRONE 0.08
#define BWA3_DEPLOY_TURNSPEED 0.1

// Arma 3 doesn't respect turnSpeed.

class CfgMovesBasic {
  class Default;

  class Actions {
    class RifleStandActions;
    class RifleStandActions_BWA3_deploy : RifleStandActions {
      stop =    "AmovPercMstpSrasWrflDnon_BWA3_deploy";
      default = "AmovPercMstpSrasWrflDnon_BWA3_deploy";
      turnL = "AmovPercMstpSrasWrflDnon_BWA3_deploy";
      turnR = "AmovPercMstpSrasWrflDnon_BWA3_deploy";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustLStandActions;
    class RifleAdjustLStandActions_BWA3_deploy : RifleAdjustLStandActions {
      stop =    "AadjPercMstpSrasWrflDleft_BWA3_deploy";
      default = "AadjPercMstpSrasWrflDleft_BWA3_deploy";
      AdjustL = "AadjPercMstpSrasWrflDleft_BWA3_deploy";
      turnL = "AadjPercMstpSrasWrflDleft_BWA3_deploy";
      turnR = "AadjPercMstpSrasWrflDleft_BWA3_deploy";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustRStandActions;
    class RifleAdjustRStandActions_BWA3_deploy : RifleAdjustRStandActions {
      stop =    "AadjPercMstpSrasWrflDright_BWA3_deploy";
      default = "AadjPercMstpSrasWrflDright_BWA3_deploy";
      AdjustRight = "AadjPercMstpSrasWrflDright_BWA3_deploy";
      turnL = "AadjPercMstpSrasWrflDright_BWA3_deploy";
      turnR = "AadjPercMstpSrasWrflDright_BWA3_deploy";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustFStandActions;
    class RifleAdjustFStandActions_BWA3_deploy : RifleAdjustFStandActions {
      stop =    "AadjPercMstpSrasWrflDup_BWA3_deploy";
      default = "AadjPercMstpSrasWrflDup_BWA3_deploy";
      AdjustF = "AadjPercMstpSrasWrflDup_BWA3_deploy";
      turnL = "AadjPercMstpSrasWrflDup_BWA3_deploy";
      turnR = "AadjPercMstpSrasWrflDup_BWA3_deploy";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustBStandActions;
    class RifleAdjustBStandActions_BWA3_deploy : RifleAdjustBStandActions {
      stop =    "AadjPercMstpSrasWrflDdown_BWA3_deploy";
      default = "AadjPercMstpSrasWrflDdown_BWA3_deploy";
      AdjustB = "AadjPercMstpSrasWrflDdown_BWA3_deploy";
      turnR = "AadjPercMstpSrasWrflDdown_BWA3_deploy";
      turnL = "AadjPercMstpSrasWrflDdown_BWA3_deploy";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustLKneelActions;
    class RifleAdjustLKneelActions_BWA3_deploy : RifleAdjustLKneelActions {
      stop =    "AadjPknlMstpSrasWrflDleft_BWA3_deploy";
      default = "AadjPknlMstpSrasWrflDleft_BWA3_deploy";
      turnL = "AadjPknlMstpSrasWrflDleft_BWA3_deploy";
      turnR = "AadjPknlMstpSrasWrflDleft_BWA3_deploy";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustRKneelActions;
    class RifleAdjustRKneelActions_BWA3_deploy : RifleAdjustRKneelActions {
      stop =    "AadjPknlMstpSrasWrflDright_BWA3_deploy";
      default = "AadjPknlMstpSrasWrflDright_BWA3_deploy";
      turnL = "AadjPknlMstpSrasWrflDright_BWA3_deploy";
      turnR = "AadjPknlMstpSrasWrflDright_BWA3_deploy";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustFKneelActions;
    class RifleAdjustFKneelActions_BWA3_deploy : RifleAdjustFKneelActions {
      stop =    "AadjPknlMstpSrasWrflDup_BWA3_deploy";
      default = "AadjPknlMstpSrasWrflDup_BWA3_deploy";
      turnL = "AadjPknlMstpSrasWrflDup_BWA3_deploy";
      turnR = "AadjPknlMstpSrasWrflDup_BWA3_deploy";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustBKneelActions;
    class RifleAdjustBKneelActions_BWA3_deploy : RifleAdjustBKneelActions {
      stop =    "AadjPknlMstpSrasWrflDdown_BWA3_deploy";
      default = "AadjPknlMstpSrasWrflDdown_BWA3_deploy";
      turnL = "AadjPknlMstpSrasWrflDdown_BWA3_deploy";
      turnR = "AadjPknlMstpSrasWrflDdown_BWA3_deploy";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleKneelActions;
    class RifleKneelActions_BWA3_deploy : RifleKneelActions {
      stop = "AmovPknlMstpSrasWrflDnon_BWA3_deploy";
      default = "AmovPknlMstpSrasWrflDnon_BWA3_deploy";
      crouch = "AmovPknlMstpSrasWrflDnon_BWA3_deploy";
      turnL = "AmovPknlMstpSrasWrflDnon_BWA3_deploy";
      turnR = "AmovPknlMstpSrasWrflDnon_BWA3_deploy";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleProneActions;
    class RifleProneActions_BWA3_deploy : RifleProneActions {
      stop = "AmovPpneMstpSrasWrflDnon_BWA3_deploy";
      default = "AmovPpneMstpSrasWrflDnon_BWA3_deploy";
      turnL = "AmovPpneMstpSrasWrflDnon_BWA3_deploy";
      turnR = "AmovPpneMstpSrasWrflDnon_BWA3_deploy";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustFProneActions;
    class RifleAdjustFProneActions_BWA3_deploy : RifleAdjustFProneActions {
      stop = "aadjppnemstpsraswrfldup_BWA3_deploy";
      default = "aadjppnemstpsraswrfldup_BWA3_deploy";
      turnL = "aadjppnemstpsraswrfldup_BWA3_deploy";
      turnR = "aadjppnemstpsraswrfldup_BWA3_deploy";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    //////////////////////////////////////////////////////////////////////

    class RifleStandActions_BWA3_rested : RifleStandActions {
      stop =    "AmovPercMstpSrasWrflDnon_BWA3_rested";
      default = "AmovPercMstpSrasWrflDnon_BWA3_rested";
      turnL = "AmovPercMstpSrasWrflDnon_BWA3_rested";
      turnR = "AmovPercMstpSrasWrflDnon_BWA3_rested";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustLStandActions_BWA3_rested : RifleAdjustLStandActions {
      stop =    "AadjPercMstpSrasWrflDleft_BWA3_rested";
      default = "AadjPercMstpSrasWrflDleft_BWA3_rested";
      AdjustL = "AadjPercMstpSrasWrflDleft_BWA3_rested";
      turnL = "AadjPercMstpSrasWrflDleft_BWA3_rested";
      turnR = "AadjPercMstpSrasWrflDleft_BWA3_rested";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustRStandActions_BWA3_rested : RifleAdjustRStandActions {
      stop =    "AadjPercMstpSrasWrflDright_BWA3_rested";
      default = "AadjPercMstpSrasWrflDright_BWA3_rested";
      AdjustRight = "AadjPercMstpSrasWrflDright_BWA3_rested";
      turnL = "AadjPercMstpSrasWrflDright_BWA3_rested";
      turnR = "AadjPercMstpSrasWrflDright_BWA3_rested";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustFStandActions_BWA3_rested : RifleAdjustFStandActions {
      stop =    "AadjPercMstpSrasWrflDup_BWA3_rested";
      default = "AadjPercMstpSrasWrflDup_BWA3_rested";
      AdjustF = "AadjPercMstpSrasWrflDup_BWA3_rested";
      turnL = "AadjPercMstpSrasWrflDup_BWA3_rested";
      turnR = "AadjPercMstpSrasWrflDup_BWA3_rested";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustBStandActions_BWA3_rested : RifleAdjustBStandActions {
      stop =    "AadjPercMstpSrasWrflDdown_BWA3_rested";
      default = "AadjPercMstpSrasWrflDdown_BWA3_rested";
      AdjustB = "AadjPercMstpSrasWrflDdown_BWA3_rested";
      turnR = "AadjPercMstpSrasWrflDdown_BWA3_rested";
      turnL = "AadjPercMstpSrasWrflDdown_BWA3_rested";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustLKneelActions_BWA3_rested : RifleAdjustLKneelActions {
      stop =    "AadjPknlMstpSrasWrflDleft_BWA3_rested";
      default = "AadjPknlMstpSrasWrflDleft_BWA3_rested";
      turnL = "AadjPknlMstpSrasWrflDleft_BWA3_rested";
      turnR = "AadjPknlMstpSrasWrflDleft_BWA3_rested";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustRKneelActions_BWA3_rested : RifleAdjustRKneelActions {
      stop =    "AadjPknlMstpSrasWrflDright_BWA3_rested";
      default = "AadjPknlMstpSrasWrflDright_BWA3_rested";
      turnL = "AadjPknlMstpSrasWrflDright_BWA3_rested";
      turnR = "AadjPknlMstpSrasWrflDright_BWA3_rested";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustFKneelActions_BWA3_rested : RifleAdjustFKneelActions {
      stop =    "AadjPknlMstpSrasWrflDup_BWA3_rested";
      default = "AadjPknlMstpSrasWrflDup_BWA3_rested";
      turnL = "AadjPknlMstpSrasWrflDup_BWA3_rested";
      turnR = "AadjPknlMstpSrasWrflDup_BWA3_rested";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustBKneelActions_BWA3_rested : RifleAdjustBKneelActions {
      stop =    "AadjPknlMstpSrasWrflDdown_BWA3_rested";
      default = "AadjPknlMstpSrasWrflDdown_BWA3_rested";
      turnL = "AadjPknlMstpSrasWrflDdown_BWA3_rested";
      turnR = "AadjPknlMstpSrasWrflDdown_BWA3_rested";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleKneelActions_BWA3_rested : RifleKneelActions {
      stop = "AmovPknlMstpSrasWrflDnon_BWA3_rested";
      default = "AmovPknlMstpSrasWrflDnon_BWA3_rested";
      crouch = "AmovPknlMstpSrasWrflDnon_BWA3_rested";
      turnL = "AmovPknlMstpSrasWrflDnon_BWA3_rested";
      turnR = "AmovPknlMstpSrasWrflDnon_BWA3_rested";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleProneActions_BWA3_rested : RifleProneActions {
      stop = "AmovPpneMstpSrasWrflDnon_BWA3_rested";
      default = "AmovPpneMstpSrasWrflDnon_BWA3_rested";
      turnL = "AmovPpneMstpSrasWrflDnon_BWA3_rested";
      turnR = "AmovPpneMstpSrasWrflDnon_BWA3_rested";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };

    class RifleAdjustFProneActions_BWA3_rested : RifleAdjustFProneActions {
      stop = "aadjppnemstpsraswrfldup_BWA3_rested";
      default = "aadjppnemstpsraswrfldup_BWA3_rested";
      turnL = "aadjppnemstpsraswrfldup_BWA3_rested";
      turnR = "aadjppnemstpsraswrfldup_BWA3_rested";
      turnSpeed = BWA3_DEPLOY_TURNSPEED;
      limitFast = 1;
    };
  };
};

class CfgMovesMaleSdr : CfgMovesBasic { 
  class States {
    class AmovPercMstpSrasWrflDnon;
    class AmovPercMstpSrasWrflDnon_BWA3_deploy : AmovPercMstpSrasWrflDnon {
      aimPrecision = BWA3_SWAY_DEPLOY;
      actions = "RifleStandActions_BWA3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"AmovPercMstpSrasWrflDnon_BWA3_deploy", 0.02};
      ConnectFrom[] = {"AmovPercMstpSrasWrflDnon_BWA3_deploy", 0.02};
      InterpolateFrom[] = {"AmovPercMstpSrasWrflDnon", 0.02};
      InterpolateTo[] = {"AmovPercMstpSrasWrflDnon", 0.02};
    };

    class aadjpercmstpsraswrfldup;
    class aadjpercmstpsraswrfldup_BWA3_deploy : aadjpercmstpsraswrfldup {
      aimPrecision = BWA3_SWAY_DEPLOY;
      actions = "RifleAdjustFStandActions_BWA3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpercmstpsraswrfldup_BWA3_deploy", 0.02};
      ConnectFrom[] = {"aadjpercmstpsraswrfldup_BWA3_deploy", 0.02};
      InterpolateFrom[] = {"aadjpercmstpsraswrfldup", 0.02};
      InterpolateTo[] = {"aadjpercmstpsraswrfldup", 0.02};
    };

    class aadjpercmstpsraswrflddown;
    class aadjpercmstpsraswrflddown_BWA3_deploy : aadjpercmstpsraswrflddown {
      aimPrecision = BWA3_SWAY_DEPLOY;
      actions = "RifleAdjustBStandActions_BWA3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpercmstpsraswrflddown_BWA3_deploy", 0.02};
      ConnectFrom[] = {"aadjpercmstpsraswrflddown_BWA3_deploy", 0.02};
      InterpolateFrom[] = {"aadjpercmstpsraswrflddown", 0.02};
      InterpolateTo[] = {"aadjpercmstpsraswrflddown", 0.02};
    };

    class aadjpercmstpsraswrfldright;
    class aadjpercmstpsraswrfldright_BWA3_deploy : aadjpercmstpsraswrfldright {
      aimPrecision = BWA3_SWAY_DEPLOY;
      actions = "RifleAdjustRStandActions_BWA3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpercmstpsraswrfldright_BWA3_deploy", 0.02};
      ConnectFrom[] = {"aadjpercmstpsraswrfldright_BWA3_deploy", 0.02};
      InterpolateFrom[] = {"aadjpercmstpsraswrfldright", 0.02};
      InterpolateTo[] = {"aadjpercmstpsraswrfldright", 0.02};
    };

    class aadjpercmstpsraswrfldleft;
    class aadjpercmstpsraswrfldleft_BWA3_deploy : aadjpercmstpsraswrfldleft {
      aimPrecision = BWA3_SWAY_DEPLOY;
      actions = "RifleAdjustLStandActions_BWA3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpercmstpsraswrfldleft_BWA3_deploy", 0.02};
      ConnectFrom[] = {"aadjpercmstpsraswrfldleft_BWA3_deploy", 0.02};
      InterpolateFrom[] = {"aadjpercmstpsraswrfldleft", 0.02};
      InterpolateTo[] = {"aadjpercmstpsraswrfldleft", 0.02};
    };

    class aadjpknlmstpsraswrfldup;
    class aadjpknlmstpsraswrfldup_BWA3_deploy : aadjpknlmstpsraswrfldup {
      aimPrecision = BWA3_SWAY_DEPLOY;
      actions = "RifleAdjustFKneelActions_BWA3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpknlmstpsraswrfldup_BWA3_deploy", 0.02};
      ConnectFrom[] = {"aadjpknlmstpsraswrfldup_BWA3_deploy", 0.02};
      InterpolateFrom[] = {"aadjpknlmstpsraswrfldup", 0.02};
      InterpolateTo[] = {"aadjpknlmstpsraswrfldup", 0.02};
    };

    class amovpknlmstpsraswrfldnon;
    class amovpknlmstpsraswrfldnon_BWA3_deploy : amovpknlmstpsraswrfldnon {
      aimPrecision = BWA3_SWAY_DEPLOY;
      actions = "RifleKneelActions_BWA3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"amovpknlmstpsraswrfldnon_BWA3_deploy", 0.02};
      ConnectFrom[] = {"amovpknlmstpsraswrfldnon_BWA3_deploy", 0.02};
      InterpolateFrom[] = {"amovpknlmstpsraswrfldnon", 0.02};
      InterpolateTo[] = {"amovpknlmstpsraswrfldnon", 0.02};
    };

    class aadjpknlmstpsraswrflddown;
    class aadjpknlmstpsraswrflddown_BWA3_deploy : aadjpknlmstpsraswrflddown {
      aimPrecision = BWA3_SWAY_DEPLOY;
      actions = "RifleAdjustBKneelActions_BWA3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpknlmstpsraswrflddown_BWA3_deploy", 0.02};
      ConnectFrom[] = {"aadjpknlmstpsraswrflddown_BWA3_deploy", 0.02};
      InterpolateFrom[] = {"aaadjpknlmstpsraswrflddown", 0.02};
      InterpolateTo[] = {"aadjpknlmstpsraswrflddown", 0.02};
    };

    class aadjpknlmstpsraswrfldleft;
    class aadjpknlmstpsraswrfldleft_BWA3_deploy : aadjpknlmstpsraswrfldleft {
      aimPrecision = BWA3_SWAY_DEPLOY;
      actions = "RifleAdjustLKneelActions_BWA3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpknlmstpsraswrfldleft_BWA3_deploy", 0.02};
      ConnectFrom[] = {"aadjpknlmstpsraswrfldleft_BWA3_deploy", 0.02};
      InterpolateFrom[] = {"aadjpknlmstpsraswrfldleft", 0.02};
      InterpolateTo[] = {"aadjpknlmstpsraswrfldleft", 0.02};
    };

    class aadjpknlmstpsraswrfldright;
    class aadjpknlmstpsraswrfldright_BWA3_deploy : aadjpknlmstpsraswrfldright {
      aimPrecision = BWA3_SWAY_DEPLOY;
      actions = "RifleAdjustRKneelActions_BWA3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpknlmstpsraswrfldright_BWA3_deploy", 0.02};
      ConnectFrom[] = {"aadjpknlmstpsraswrfldright_BWA3_deploy", 0.02};
      InterpolateFrom[] = {"aadjpknlmstpsraswrfldright", 0.02};
      InterpolateTo[] = {"aadjpknlmstpsraswrfldright", 0.02};
    };

    class aadjppnemstpsraswrfldup;
    class aadjppnemstpsraswrfldup_BWA3_deploy : aadjppnemstpsraswrfldup {
      aimPrecision = BWA3_SWAY_DEPLOYPRONE;
      actions = "RifleAdjustFProneActions_BWA3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjppnemstpsraswrfldup_BWA3_deploy", 0.02};
      ConnectFrom[] = {"aadjppnemstpsraswrfldup_BWA3_deploy", 0.02};
      InterpolateFrom[] = {"aadjppnemstpsraswrfldup", 0.02};
      InterpolateTo[] = {"aadjppnemstpsraswrfldup", 0.02};
    };

    class amovppnemstpsraswrfldnon;
    class amovppnemstpsraswrfldnon_BWA3_deploy : amovppnemstpsraswrfldnon {
      aimPrecision = BWA3_SWAY_DEPLOYPRONE;
      actions = "RifleProneActions_BWA3_deploy";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"amovppnemstpsraswrfldnon_BWA3_deploy", 0.02};
      ConnectFrom[] = {"amovppnemstpsraswrfldnon_BWA3_deploy", 0.02};
      InterpolateFrom[] = {"amovppnemstpsraswrfldnon", 0.02};
      InterpolateTo[] = {"amovppnemstpsraswrfldnon", 0.02};
    };

    /////////////////////////////////////////////////////////////////////////////

        class AmovPercMstpSrasWrflDnon_BWA3_rested : AmovPercMstpSrasWrflDnon {
      aimPrecision = BWA3_SWAY_RESTED;
      actions = "RifleStandActions_BWA3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"AmovPercMstpSrasWrflDnon_BWA3_rested", 0.02};
      ConnectFrom[] = {"AmovPercMstpSrasWrflDnon_BWA3_rested", 0.02};
      InterpolateFrom[] = {"AmovPercMstpSrasWrflDnon", 0.02};
      InterpolateTo[] = {"AmovPercMstpSrasWrflDnon", 0.02};
    };

    class aadjpercmstpsraswrfldup_BWA3_rested : aadjpercmstpsraswrfldup {
      aimPrecision = BWA3_SWAY_RESTED;
      actions = "RifleAdjustFStandActions_BWA3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpercmstpsraswrfldup_BWA3_rested", 0.02};
      ConnectFrom[] = {"aadjpercmstpsraswrfldup_BWA3_rested", 0.02};
      InterpolateFrom[] = {"aadjpercmstpsraswrfldup", 0.02};
      InterpolateTo[] = {"aadjpercmstpsraswrfldup", 0.02};
    };

    class aadjpercmstpsraswrflddown_BWA3_rested : aadjpercmstpsraswrflddown {
      aimPrecision = BWA3_SWAY_RESTED;
      actions = "RifleAdjustBStandActions_BWA3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpercmstpsraswrflddown_BWA3_rested", 0.02};
      ConnectFrom[] = {"aadjpercmstpsraswrflddown_BWA3_rested", 0.02};
      InterpolateFrom[] = {"aadjpercmstpsraswrflddown", 0.02};
      InterpolateTo[] = {"aadjpercmstpsraswrflddown", 0.02};
    };

    class aadjpercmstpsraswrfldright_BWA3_rested : aadjpercmstpsraswrfldright {
      aimPrecision = BWA3_SWAY_RESTED;
      actions = "RifleAdjustRStandActions_BWA3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpercmstpsraswrfldright_BWA3_rested", 0.02};
      ConnectFrom[] = {"aadjpercmstpsraswrfldright_BWA3_rested", 0.02};
      InterpolateFrom[] = {"aadjpercmstpsraswrfldright", 0.02};
      InterpolateTo[] = {"aadjpercmstpsraswrfldright", 0.02};
    };

    class aadjpercmstpsraswrfldleft_BWA3_rested : aadjpercmstpsraswrfldleft {
      aimPrecision = BWA3_SWAY_RESTED;
      actions = "RifleAdjustLStandActions_BWA3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpercmstpsraswrfldleft_BWA3_rested", 0.02};
      ConnectFrom[] = {"aadjpercmstpsraswrfldleft_BWA3_rested", 0.02};
      InterpolateFrom[] = {"aadjpercmstpsraswrfldleft", 0.02};
      InterpolateTo[] = {"aadjpercmstpsraswrfldleft", 0.02};
    };

    class aadjpknlmstpsraswrfldup_BWA3_rested : aadjpknlmstpsraswrfldup {
      aimPrecision = BWA3_SWAY_RESTED;
      actions = "RifleAdjustFKneelActions_BWA3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpknlmstpsraswrfldup_BWA3_rested", 0.02};
      ConnectFrom[] = {"aadjpknlmstpsraswrfldup_BWA3_rested", 0.02};
      InterpolateFrom[] = {"aadjpknlmstpsraswrfldup", 0.02};
      InterpolateTo[] = {"aadjpknlmstpsraswrfldup", 0.02};
    };

    class amovpknlmstpsraswrfldnon_BWA3_rested : amovpknlmstpsraswrfldnon {
      aimPrecision = BWA3_SWAY_RESTED;
      actions = "RifleKneelActions_BWA3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"amovpknlmstpsraswrfldnon_BWA3_rested", 0.02};
      ConnectFrom[] = {"amovpknlmstpsraswrfldnon_BWA3_rested", 0.02};
      InterpolateFrom[] = {"amovpknlmstpsraswrfldnon", 0.02};
      InterpolateTo[] = {"amovpknlmstpsraswrfldnon", 0.02};
    };

    class aadjpknlmstpsraswrflddown_BWA3_rested : aadjpknlmstpsraswrflddown {
      aimPrecision = BWA3_SWAY_RESTED;
      actions = "RifleAdjustBKneelActions_BWA3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpknlmstpsraswrflddown_BWA3_rested", 0.02};
      ConnectFrom[] = {"aadjpknlmstpsraswrflddown_BWA3_rested", 0.02};
      InterpolateFrom[] = {"aaadjpknlmstpsraswrflddown", 0.02};
      InterpolateTo[] = {"aadjpknlmstpsraswrflddown", 0.02};
    };

    class aadjpknlmstpsraswrfldleft_BWA3_rested : aadjpknlmstpsraswrfldleft {
      aimPrecision = BWA3_SWAY_RESTED;
      actions = "RifleAdjustLKneelActions_BWA3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpknlmstpsraswrfldleft_BWA3_rested", 0.02};
      ConnectFrom[] = {"aadjpknlmstpsraswrfldleft_BWA3_rested", 0.02};
      InterpolateFrom[] = {"aadjpknlmstpsraswrfldleft", 0.02};
      InterpolateTo[] = {"aadjpknlmstpsraswrfldleft", 0.02};
    };

    class aadjpknlmstpsraswrfldright_BWA3_rested : aadjpknlmstpsraswrfldright {
      aimPrecision = BWA3_SWAY_RESTED;
      actions = "RifleAdjustRKneelActions_BWA3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjpknlmstpsraswrfldright_BWA3_rested", 0.02};
      ConnectFrom[] = {"aadjpknlmstpsraswrfldright_BWA3_rested", 0.02};
      InterpolateFrom[] = {"aadjpknlmstpsraswrfldright", 0.02};
      InterpolateTo[] = {"aadjpknlmstpsraswrfldright", 0.02};
    };

    class aadjppnemstpsraswrfldup_BWA3_rested : aadjppnemstpsraswrfldup {
      aimPrecision = BWA3_SWAY_RESTEDPRONE;
      actions = "RifleAdjustFProneActions_BWA3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"aadjppnemstpsraswrfldup_BWA3_rested", 0.02};
      ConnectFrom[] = {"aadjppnemstpsraswrfldup_BWA3_rested", 0.02};
      InterpolateFrom[] = {"aadjppnemstpsraswrfldup", 0.02};
      InterpolateTo[] = {"aadjppnemstpsraswrfldup", 0.02};
    };

    class amovppnemstpsraswrfldnon_BWA3_rested : amovppnemstpsraswrfldnon {
      aimPrecision = BWA3_SWAY_RESTEDPRONE;
      actions = "RifleProneActions_BWA3_rested";
      aiming = "aimingLying";
      speed = 0.01;
      onLandEnd = true;
      onLandBeg = true;

      ConnectTo[] = {"amovppnemstpsraswrfldnon_BWA3_rested", 0.02};
      ConnectFrom[] = {"amovppnemstpsraswrfldnon_BWA3_rested", 0.02};
      InterpolateFrom[] = {"amovppnemstpsraswrfldnon", 0.02};
      InterpolateTo[] = {"amovppnemstpsraswrfldnon", 0.02};
    };
  };
};