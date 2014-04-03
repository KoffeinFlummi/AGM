class CfgPatches {
  class BWA3_Interaction {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, Extended_EventHandlers};
    version = 1.0;
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class BWA3_Interaction {
    class BWA3_Interaction {
        file = "\bwa3_interaction\functions";
      class openMenu {};
      class openMenuSelf {};
      class sortOptionsByPriority {};
    };
  };
};

class Extended_PostInit_EventHandlers {
  class BWA3_Interaction {
    Init = "call compile preProcessFileLineNumbers '\BWA3_Interaction\init.sqf'";
  };
};

class CfgVehicles {
  class Man;
  class Land_CargoBox_V1_F;

  class CAManBase: Man {
    class BWA3_Actions {
      class BWA3_JoinGroup {
        displayName = "$STR_BWA3_JoinGroup";
        distance = 4;
        condition = "playerSide == side cursorTarget && {group player != group cursorTarget}";
        statement = "[player] joinSilent group cursorTarget;";
        showDisabled = 1;
        priority = -1;
      };
    };

    class BWA3_SelfActions {
      class BWA3_LeaveGroup {
        displayName = "$STR_BWA3_LeaveGroup";
        condition = "count (units group player) > 1";
        statement = "_oldGroup = units group player; _newGroup = createGroup side player; [player] joinSilent _newGroup; {player reveal _x} forEach _oldGroup;";
        showDisabled = 1;
        priority = -1;
      };
      class BWA3_BecomeLeader {
        displayName = "$STR_BWA3_BecomeLeader";
        condition = "count (units group player) > 1 && {leader group player != player}";
        statement = "_newGroup = createGroup side player; (units group player) joinSilent _newGroup; _newGroup selectLeader player;";
        showDisabled = 1;
        priority = -1;
      };
    };
  };
};

#include <Menu_Config.hpp>
