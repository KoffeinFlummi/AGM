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

      class BWA3_Gestures {
        displayName = "$STR_BWA3_Gestures";
        condition = "canStand player && {alive player}";
        statement = "'BWA3_Gestures' call BWA3_Interaction_fnc_openMenuSelf;";
        showDisabled = 1;
        priority = 0;

        /*class BWA3_Gesture_Advance {
          displayName = "$STR_BWA3_Gestures_Attack";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow 'gestureAttack';";
          showDisabled = 1;
          priority = 2.0;
        };*/
        class BWA3_Gesture_Advance {
          displayName = "$STR_BWA3_Gestures_Advance";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow 'gestureAdvance';";
          showDisabled = 1;
          priority = 1.9;
        };
        class BWA3_Gesture_Go {
          displayName = "$STR_BWA3_Gestures_Go";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow (['gestureGo', 'gestureGoB'] select (floor random 2));";
          showDisabled = 1;
          priority = 1.8;
        };
        class BWA3_Gesture_Follow {
          displayName = "$STR_BWA3_Gestures_Follow";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow 'gestureFollow';";
          showDisabled = 1;
          priority = 1.7;
        };
        class BWA3_Gesture_Point {
          displayName = "$STR_BWA3_Gestures_Point";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow 'gesturePoint';";
          showDisabled = 1;
          priority = 1.6;
        };
        class BWA3_Gesture_Up {
          displayName = "$STR_BWA3_Gestures_Up";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow 'gestureUp';";
          showDisabled = 1;
          priority = 1.5;
        };
        class BWA3_Gesture_Cover {
          displayName = "$STR_BWA3_Gestures_Cover";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow 'gestureCover';";
          showDisabled = 1;
          priority = 1.4;
        };
        class BWA3_Gesture_CeaseFire {
          displayName = "$STR_BWA3_Gestures_Cease_Fire";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow 'gestureCeaseFire';";
          showDisabled = 1;
          priority = 1.3;
        };
        class BWA3_Gesture_Freeze {
          displayName = "$STR_BWA3_Gestures_Freeze";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow 'gestureFreeze';";
          showDisabled = 1;
          priority = 1.2;
        };
        class BWA3_Gesture_Yes {
          displayName = "$STR_BWA3_Gestures_Yes";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow (['gestureYes', 'gestureNod'] select (floor random 2));";
          showDisabled = 1;
          priority = 1.1;
        };
        class BWA3_Gesture_No {
          displayName = "$STR_BWA3_Gestures_No";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow 'gestureNo';";
          showDisabled = 1;
          priority = 1.0;
        };
        class BWA3_Gesture_Hi {
          displayName = "$STR_BWA3_Gestures_Hi";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow (['gestureHi', 'gestureHiB', 'gestureHiC'] select (floor random 3));";
          showDisabled = 1;
          priority = 0.9;
        };
      };

      class BWA3_WeaponOnBack {
        displayName = "$STR_BWA3_WeaponOnBack";
        condition = "currentWeapon player != ''";
        statement = "player action ['SwitchWeapon', vehicle player, vehicle player, 99];";
        showDisabled = 0;
        priority = -2;
      };
    };
  };
};

#include <Menu_Config.hpp>
