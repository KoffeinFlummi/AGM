class CfgPatches {
  class AGM_FastRoping {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction};
    version = "0.94.1";
    versionStr = "0.94.1";
    versionAr[] = {0,94,1};
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_FastRoping {
    class AGM_FastRoping {
      file = "\AGM_FastRoping\functions";
      class cutRopes;
      class deployRopes;
      class fastRope;
    };
  };
};

class CfgVehicles {
  class B_UAV_01_F; // don't ask.
  class AGM_FastRoping_Helper: B_UAV_01_F {
    scope = 1;
    model = "agm_fastroping\agm_fastroping_helper.p3d";
  };

  class Air;
  // Repair helicopters
  class Helicopter: Air {
    AGM_FastRoping = 1;
    AGM_FastRoping_Positions[] = {{2, 2.5, 0.25}, {-2, 2.5, 0.25}};
    class AGM_SelfActions {
      class AGM_FastRoping_deployRopes {
        displayName = "Deploy Ropes";
        distance = 4;
        condition = "!(AGM_Interaction_Target getVariable ['AGM_RopesDeployed', False]) and (getPos AGM_Interaction_Target select 2) > 10 and (getNumber (configFile >> 'CfgVehicles' >> typeOf AGM_Interaction_Target >> 'AGM_FastRoping')) == 1";
        statement = "[AGM_Interaction_Target] call AGM_FastRoping_fnc_deployRopes";
        showDisabled = 0;
        priority = 1;
        icon = "";
      };
      class AGM_FastRoping_fastRope {
        displayName = "Fast Rope";
        distance = 4;
        condition = "(AGM_Interaction_Target getVariable ['AGM_RopesDeployed', False])";
        statement = "[call AGM_Core_fnc_player, AGM_Interaction_Target] call AGM_FastRoping_fnc_fastRope";
        showDisabled = 0;
        priority = 1;
        icon = "";
      };
      class AGM_FastRoping_cutRopes {
        displayName = "Cut Ropes";
        distance = 4;
        condition = "(AGM_Interaction_Target getVariable ['AGM_RopesDeployed', False])";
        statement = "[AGM_Interaction_Target] call AGM_FastRoping_fnc_cutRopes";
        showDisabled = 0;
        priority = 1;
        icon = "";
      };
    };
  };
};

class CfgMovesBasic {
  class DefaultDie;
  class ManActions {
    AGM_FastRoping = "AGM_FastRoping";
  };
};
class CfgMovesMaleSdr: CfgMovesBasic {
  class States {
    class Crew;
    class AGM_FastRoping: Crew {
      file = "agm_fastroping\data\agm_fastroping.rtm";
      interpolateTo[] = {"Unconscious",1};
    };
  };
};
