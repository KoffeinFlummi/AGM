class CfgPatches {
  class AGM_Civilians {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_Civilians {
    class AGM_Civilians {
      file = "AGM_Civilians\functions";
      class canInteractWith;
      class escortCaptive;
      class getDown;
      class sendAway;
      class setCaptive;
    };
  };
};

class CfgVehicles {
  class Man;
  class CAManBase: Man {
    class AGM_Actions {

      class AGM_GetDown {
        displayName = "$STR_AGM_Civilians_GetDown";
        distance = 4;
        condition = "[AGM_Interaction_Target] call AGM_Civilians_fnc_canInteractWith";
        statement = "[AGM_Interaction_Target] call AGM_Civilians_fnc_getDown";
        showDisabled = 0;
        priority = 2.2;
      };

      class AGM_EscortCaptive {
        displayName = "$STR_AGM_Civilian_EscortCaptive";
        distance = 4;
        condition = "[AGM_Interaction_Target] call AGM_Civilians_fnc_canInteractWith";
        statement = "[AGM_Interaction_Target] call AGM_Civilians_fnc_escortCaptive";
        showDisabled = 0;
        priority = 2.3;
      };

      class AGM_SetCaptive {
        displayName = "$STR_AGM_Civilian_SetCaptive";
        distance = 4;
        condition = "[AGM_Interaction_Target] call AGM_Civilians_fnc_canInteractWith";
        statement = "[AGM_Interaction_Target] call AGM_Civilians_fnc_setCaptive";
        showDisabled = 0;
        priority = 2.3;
      };

      class AGM_SendAway {
        displayName = "$STR_AGM_Civilians_SendAway";
        distance = 4;
        condition = "[AGM_Interaction_Target] call AGM_Civilians_fnc_canInteractWith";
        statement = "[AGM_Interaction_Target] call AGM_Civilians_fnc_sendAway";
        showDisabled = 0;
        priority = 2.4;
      };
    };
  };
};
