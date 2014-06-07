class CfgPatches {
  class AGM_Civilians {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction, A3_Characters_F};
    version = "0.9";
    versionStr = "0.9";
    versionAr[] = {0,9,0};
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_Civilians {
    class AGM_Civilians {
      file = "AGM_Civilians\functions";
      class sendAway {};
      class getDown {};
      //class setCaptive {};
    };
  };
};

class CfgVehicles {
  class Man;

  class CAManBase: Man {
    class AGM_Actions {
      class AGM_SendAway {
        displayName = "$STR_AGM_Civilians_SendAway";
        distance = 4;
        condition = "AGM_Interaction_Target isKindOf 'Civilian' and alive AGM_Interaction_Target and AGM_Interaction_Target != player and (count (weapons AGM_Interaction_Target)) == 0";
        statement = "[AGM_Interaction_Target] call AGM_Civilians_fnc_sendAway";
        showDisabled = 0;
        priority = -2.5;
      };
      class AGM_GetDown {
        displayName = "$STR_AGM_Civilians_GetDown";
        distance = 4;
        condition = "AGM_Interaction_Target isKindOf 'Civilian' and alive AGM_Interaction_Target and AGM_Interaction_Target != player and (count (weapons AGM_Interaction_Target)) == 0";
        statement = "[AGM_Interaction_Target] call AGM_Civilians_fnc_getDown";
        showDisabled = 0;
        priority = -2.6;
      };
      /*
      class AGM_SetCaptive {
        displayName = "Take Prisoner";
        distance = 4;
        condition = "AGM_Interaction_Target isKindOf 'Civilian' and alive AGM_Interaction_Target && {AGM_Interaction_Target != player} && {count (weapons AGM_Interaction_Target) == 0}";
        statement = "[[AGM_Interaction_Target, [0.5, 0.8] select (count weapons player > 0)], 'AGM_Civilians_fnc_setCaptive', AGM_Interaction_Target] call AGM_Core_fnc_execRemoteFnc";
        showDisabled = 0;
        priority = -2.7;
      };
      */
    };
  };
};
