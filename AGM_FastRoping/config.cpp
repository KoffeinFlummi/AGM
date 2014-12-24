class CfgPatches {
  class AGM_FastRoping {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction};
    version = "0.95";
    versionStr = "0.95";
    versionAr[] = {0,95,0};
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_FastRoping {
    class AGM_FastRoping {
      file = "\AGM_FastRoping\functions";
      class createRope;
      class cutRopes;
      class deployRopes;
      class fastRope;
    };
  };
};

class CfgVehicles {
  //class AGM_FastRoping_Helper: B_UAV_01_F {
  class UAV_01_base_F;
  class AGM_FastRoping_Helper: UAV_01_base_F {
    scope = 1;
    model = "agm_fastroping\agm_fastroping_helper.p3d";
    isUav = 0;
  };

  class Air;
  class Helicopter: Air {
    AGM_FastRoping = 0;
    AGM_FastRoping_Positions[] = {};
    class AGM_SelfActions {
      class AGM_DeployRopes {
        displayName = "$STR_AGM_FastRoping_DeployRopes";
        enableInside = 1;
        condition = "(locked _vehicle <= 1) and !(_vehicle getVariable ['AGM_RopesDeployed', False]) and (getPos _vehicle select 2) > 5 and (getNumber (configFile >> 'CfgVehicles' >> typeOf _vehicle >> 'AGM_FastRoping')) == 1";
        statement = "[_vehicle] call AGM_FastRoping_fnc_deployRopes";
        showDisabled = 0;
        priority = 1;
        icon = "";
      };
      class AGM_FastRope {
        displayName = "$STR_AGM_FastRoping_FastRope";
        enableInside = 1;
        condition = "(locked _vehicle <= 1) and (_vehicle getVariable ['AGM_RopesDeployed', False]) and (vectorMagnitude (velocity _vehicle) < 4) and (count ([_vehicle getVariable ['AGM_RopesOccupied', []], {!_this}] call AGM_Core_fnc_filter) > 0)";
        statement = "[_player, _vehicle] call AGM_FastRoping_fnc_fastRope";
        showDisabled = 0;
        priority = 1;
        icon = "";
      };
      class AGM_CutRopes {
        displayName = "$STR_AGM_FastRoping_CutRopes";
        enableInside = 1;
        condition = "(_vehicle getVariable ['AGM_RopesDeployed', False]) and (count ([_vehicle getVariable ['AGM_RopesOccupied', []], {_this}] call AGM_Core_fnc_filter) == 0)";
        statement = "[_vehicle] call AGM_FastRoping_fnc_cutRopes";
        showDisabled = 0;
        priority = 1;
        icon = "";
      };
    };
  };
  class Plane: Air {
    AGM_FastRoping = 0;
    AGM_FastRoping_Positions[] = {};
    class AGM_SelfActions {
      class AGM_DeployRopes {
        displayName = "$STR_AGM_FastRoping_DeployRopes";
        enableInside = 1;
        condition = "(locked _vehicle <= 1) and !(_vehicle getVariable ['AGM_RopesDeployed', False]) and (getPos _vehicle select 2) > 5 and (getNumber (configFile >> 'CfgVehicles' >> typeOf _vehicle >> 'AGM_FastRoping')) == 1";
        statement = "[_vehicle] call AGM_FastRoping_fnc_deployRopes";
        showDisabled = 0;
        priority = 1;
        icon = "";
      };
      class AGM_FastRope {
        displayName = "$STR_AGM_FastRoping_FastRope";
        enableInside = 1;
        condition = "(locked _vehicle <= 1) and (_vehicle getVariable ['AGM_RopesDeployed', False]) and (vectorMagnitude (velocity _vehicle) < 4) and (count ([_vehicle getVariable ['AGM_RopesOccupied', []], {!_this}] call AGM_Core_fnc_filter) > 0)";
        statement = "[_player, _vehicle] call AGM_FastRoping_fnc_fastRope";
        showDisabled = 0;
        priority = 1;
        icon = "";
      };
      class AGM_CutRopes {
        displayName = "$STR_AGM_FastRoping_CutRopes";
        enableInside = 1;
        condition = "(_vehicle getVariable ['AGM_RopesDeployed', False]) and (count ([_vehicle getVariable ['AGM_RopesOccupied', []], {_this}] call AGM_Core_fnc_filter) == 0)";
        statement = "[_vehicle] call AGM_FastRoping_fnc_cutRopes";
        showDisabled = 0;
        priority = 1;
        icon = "";
      };
    };
  };

  class Helicopter_Base_F;
  class Helicopter_Base_H: Helicopter_Base_F {};

  // Ghosthawk
  class Heli_Transport_01_base_F: Helicopter_Base_H {
  AGM_FastRoping = 1;
  AGM_FastRoping_Positions[] = {{1.2, 2.5, 0.25}, {-1.1, 2.5, 0.25}};
  };

  // Chinook
  class B_Heli_Transport_03_base_F: Helicopter_Base_H {
  AGM_FastRoping = 1;
  AGM_FastRoping_Positions[] = {{0, 1, -1.9}, {0, -5, 0.5}};
  };

  // Wildcat
  class I_Heli_light_03_base_F: Helicopter_Base_F {
  AGM_FastRoping = 1;
  AGM_FastRoping_Positions[] = {{1.2, 2.5, 0.25}, {-1.1, 2.5, 0.25}};
  };

  // Merlin
  class Heli_Transport_02_base_F: Helicopter_Base_H {
  AGM_FastRoping = 1;
  AGM_FastRoping_Positions[] = {{1.4, 2.5, 0.25}, {-1.2, 2.5, 0.25}};
  };

  // Kasatka
  class Heli_Light_02_base_F: Helicopter_Base_H {
  AGM_FastRoping = 1;
  AGM_FastRoping_Positions[] = {{1.4, 1.4, 0.05}, {-1.4, 1.4, 0.05}};
  };

  // Kajman
  class Heli_Attack_02_base_F: Helicopter_Base_F {
  AGM_FastRoping = 1;
  AGM_FastRoping_Positions[] = {{1.4, 1.4, 0}, {-1.2, 1.4, 0}};
  };
  // RHS US Pack
  // UH60
  class rhs_uh60m: Helicopter_Base_H {
  AGM_FastRoping = 1;
  AGM_FastRoping_Positions[] = {{1.2, 2.5, 0.25}, {-1.1, 2.5, 0.25}};
  };
  // UH60 Desert
  class rhs_uh60m_d: Helicopter_Base_H {
  AGM_FastRoping = 1;
  AGM_FastRoping_Positions[] = {{1.2, 2.5, 0.25}, {-1.1, 2.5, 0.25}}
  };
  // Chinook
  class rhs_ch47f: Helicopter_Base_H {
  AGM_FastRoping = 1;
  AGM_FastRoping_Positions[] = {{0, 1, -1.9}, {0, -5, 0.5}};
  };
  // Chinook light
  class rhs_ch47f_light: Helicopter_Base_H {
  AGM_FastRoping = 1;
  AGM_FastRoping_Positions[] = {{0, 1, -1.9}, {0, -5, 0.5}};
  };
  // US Helicopter
  // Chinook
  class ch_47f: Helicopter_Base_H {
  AGM_FastRoping = 1;
  AGM_FastRoping_Positions[] = {{0, 1, -1.9}, {0, -5, 0.5}};
  };
  // chinook desert
  class ch_47F_des: Helicopter_Base_H {
  AGM_FastRoping = 1;
  AGM_FastRoping_Positions[] = {{0, 1, -1.9}, {0, -5, 0.5}};
  };
  // Huey (old)
  class UH1H: Helicopter_Base_F {
  AGM_FastRoping = 1;
  AGM_FastRoping_Positions[] = {{1.2, 2.5, 0.25}, {-1.1, 2.5, 0.25}}
  };
  // Huey (modern)
  class UH1Y: Helicopter_Base_F {
  AGM_FastRoping = 1;
  AGM_FastRoping_Positions[] = {{1.2, 2.5, 0.25}, {-1.1, 2.5, 0.25}}
  };
  // blackhawk
  class UH60M: Helicopter_Base_H {
  AGM_FastRoping = 1;
  AGM_FastRoping_Positions[] = {{1.2, 2.5, 0.25}, {-1.1, 2.5, 0.25}}
  };
  // Blackhawk green
  class UH60M: Helicopter_Base_H {
  AGM_FastRoping = 1;
  AGM_FastRoping_Positions[] = {{1.2, 2.5, 0.25}, {-1.1, 2.5, 0.25}}
  };
  // Pavehawk
  class USAF_HH60G: Helicopter_Base_H {
  AGM_FastRoping = 1;
  AGM_FastRoping_Positions[] = {{1.2, 2.5, 0.25}, {-1.1, 2.5, 0.25}}
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
