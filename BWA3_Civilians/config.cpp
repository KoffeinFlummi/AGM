class CfgPatches {
  class BWA3_Civilians {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Characters_F_Civil};
    version = 1.0;
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class BWA3_Civilians {
    class BWA3_Civilians {
      file = "BWA3_Civilians\functions";
      class sendAway {};
      class getDown {};
    };
  };
};

class CfgVehicles {
  class CAManBase;

  class Civilian: CAManBase {
    class UserActions {
      // Documentation:
      // http://community.bistudio.com/wiki/UserActions

      class BWA3_SendAway {
        displayName = "<t color='#2222ff'>Send Away</t>";    // name in action menu
        displayNameDefault = "";      // name on screen (icons)
        priority = 4;                 // 0 (low) - 6 (high)
        position = "leaning_axis";    // memory point of model
        radius = 3;                   // minimum distance for the action to be available
        showWindow = false;           // show text/icon on screen
        onlyForPlayer = false;        // enable AI to be ordered to do something
        shortcut = "";                // key (CfgDefaultKeyMappings)
        condition = "alive this and this != player and (count (weapons this)) == 0";
        statement = "[this] call BWA3_Civilians_fnc_sendAway";
      };
      class BWA3_GetDown {
        displayName = "<t color='#2222ff'>Get Down!</t>";    // name in action menu
        displayNameDefault = "";      // name on screen (icons)
        priority = 4;                 // 0 (low) - 6 (high)
        position = "leaning_axis";    // memory point of model
        radius = 3;                   // minimum distance for the action to be available
        showWindow = false;           // show text/icon on screen
        onlyForPlayer = false;        // enable AI to be ordered to do something
        shortcut = "";                // key (CfgDefaultKeyMappings)
        condition = "alive this and this != player and (count (weapons this)) == 0";
        statement = "[this] call BWA3_Civilians_fnc_getDown";
      };
    };
  };
};