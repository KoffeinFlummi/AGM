class CfgPatches {
  class AGM_Interaction {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, Extended_EventHandlers, AGM_Core};
    version = "0.9";
    versionStr = "0.9";
    versionAr[] = {0,9,0};
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_Interaction {
    class AGM_Interaction {
      file = "\AGM_interaction\functions";
      class openMenu;
      class openMenuSelf;
      class sortOptionsByPriority;
      class tapShoulder;
      class openDoor;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Interaction {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_Interaction\clientInit.sqf'";
  };
};

class AGM_Core_Default_Keys {
  class openInteractionMenu {
    displayName = "$STR_AGM_Interaction_InteractionMenu";
    condition = "true";
    statement = "if !dialog then {'' call AGM_Interaction_fnc_openMenu} else {closeDialog 0}";
    key = 221;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class openInteractionMenuSelf {
    displayName = "$STR_AGM_Interaction_InteractionMenuSelf";
    condition = "true";
    statement = "if !dialog then {'' call AGM_Interaction_fnc_openMenuSelf} else {closeDialog 0}";
    key = 221;
    shift = 0;
    control = 1;
    alt = 0;
  };
  class openDoor {
    displayName = "$STR_AGM_Interaction_OpenDoor";
    condition = "!AGM_Interaction_isOpeningDoor";
    statement = "call AGM_Interaction_fnc_openDoor";
    conditionUp = "AGM_Interaction_isOpeningDoor";
    statementUp = "AGM_Interaction_isOpeningDoor = false";
    key = 20;
    shift = 0;
    control = 0;
    alt = 1;
  };
  class tapShoulder {
    displayName = "$STR_AGM_Interaction_TapShoulder";
    condition = "alive AGM_Interaction_Target and !(AGM_Interaction_Target getVariable ['AGM_Unconscious', false])";
    statement = "[[player], 'AGM_Interaction_fnc_tapShoulder', AGM_Interaction_Target] call AGM_Core_fnc_execRemoteFnc";
    key = 20;
    shift = 1;
    control = 0;
    alt = 0;
  };
};

class CfgVehicles {
  class Man;

  class CAManBase: Man {
    class AGM_Actions {
      class AGM_JoinGroup {
        displayName = "$STR_AGM_Interaction_JoinGroup";
        distance = 4;
        condition = "playerSide == side AGM_Interaction_Target && {group player != group AGM_Interaction_Target}";
        statement = "[player] joinSilent group AGM_Interaction_Target;";
        showDisabled = 1;
        priority = -1;
      };
      class AGM_TapShoulder {
        displayName = "$STR_AGM_Interaction_TapShoulder";
        distance = 4;
        condition = "alive AGM_Interaction_Target and !(AGM_Interaction_Target getVariable ['AGM_Unconscious', false])";
        statement = "[[player], 'AGM_Interaction_fnc_tapShoulder', AGM_Interaction_Target] call AGM_Core_fnc_execRemoteFnc";
        showDisabled = 1;
        priority = 0.1;
      };
    };

    class AGM_SelfActions {
      class AGM_LeaveGroup {
        displayName = "$STR_AGM_Interaction_LeaveGroup";
        condition = "count (units group player) > 1";
        statement = "_oldGroup = units group player; _newGroup = createGroup side player; [player] joinSilent _newGroup; {player reveal _x} forEach _oldGroup;";
        showDisabled = 1;
        priority = -1;
      };
      class AGM_BecomeLeader {
        displayName = "$STR_AGM_Interaction_BecomeLeader";
        condition = "count (units group player) > 1 && {leader group player != player}";
        statement = "_newGroup = createGroup side player; (units group player) joinSilent _newGroup; _newGroup selectLeader player;";
        showDisabled = 1;
        priority = -1;
      };

      /* DANCE ANIMATION DOESN'T WORK :(
      class AGM_Dance {
        displayName = "$STR_AGM_Interaction_Dance";
        condition = "isClass (configFile >> 'CfgPatches' >> 'AGM_Movement') and !AGM_Dancing";
        statement = "AGM_Dancing = true; [-2, {_this switchMove 'TestDance';}, player] call CBA_fnc_globalExecute;";
        showDisabled = 0;
        priority = -1;
      };
      class AGM_StopDancing {
        displayName = "$STR_AGM_Interaction_StopDancing";
        condition = "AGM_Dancing";
        statement = "AGM_Dancing = false; [-2, {_this switchMove '';}, player] call CBA_fnc_globalExecute;";
        showDisabled = 0;
        priority = -1;
      };
      */

      class AGM_Gestures {
        displayName = "$STR_AGM_Interaction_Gestures";
        condition = "canStand player && {alive player}";
        statement = "'AGM_Gestures' call AGM_Interaction_fnc_openMenuSelf;";
        showDisabled = 1;
        priority = 0;

        /*class AGM_Gesture_Advance {
          displayName = "$STR_AGM_Interaction_Gestures_Attack";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow 'gestureAttack';";
          showDisabled = 1;
          priority = 2.0;
        };*/
        class AGM_Gesture_Advance {
          displayName = "$STR_AGM_Interaction_Gestures_Advance";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow 'gestureAdvance';";
          showDisabled = 1;
          priority = 1.9;
        };
        class AGM_Gesture_Go {
          displayName = "$STR_AGM_Interaction_Gestures_Go";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow (['gestureGo', 'gestureGoB'] select (floor random 2));";
          showDisabled = 1;
          priority = 1.8;
        };
        class AGM_Gesture_Follow {
          displayName = "$STR_AGM_Interaction_Gestures_Follow";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow 'gestureFollow';";
          showDisabled = 1;
          priority = 1.7;
        };
        /*class AGM_Gesture_Point {
          displayName = "$STR_AGM_Interaction_Gestures_Point";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow 'gesturePoint';";
          showDisabled = 1;
          priority = 1.6;
        };*/
        class AGM_Gesture_Up {
          displayName = "$STR_AGM_Interaction_Gestures_Up";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow 'gestureUp';";
          showDisabled = 1;
          priority = 1.5;
        };
        class AGM_Gesture_Cover {
          displayName = "$STR_AGM_Interaction_Gestures_Cover";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow 'gestureCover';";
          showDisabled = 1;
          priority = 1.4;
        };
        class AGM_Gesture_CeaseFire {
          displayName = "$STR_AGM_Interaction_Gestures_Cease_Fire";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow 'gestureCeaseFire';";
          showDisabled = 1;
          priority = 1.3;
        };
        class AGM_Gesture_Freeze {
          displayName = "$STR_AGM_Interaction_Gestures_Freeze";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow 'gestureFreeze';";
          showDisabled = 1;
          priority = 1.2;
        };
        class AGM_Gesture_Yes {
          displayName = "$STR_AGM_Interaction_Gestures_Yes";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow (['gestureYes', 'gestureNod'] select (floor random 2));";
          showDisabled = 1;
          priority = 1.1;
        };
        class AGM_Gesture_No {
          displayName = "$STR_AGM_Interaction_Gestures_No";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow 'gestureNo';";
          showDisabled = 1;
          priority = 1.0;
        };
        class AGM_Gesture_Hi {
          displayName = "$STR_AGM_Interaction_Gestures_Hi";
          condition = "canStand player && {alive player}";
          statement = "player playActionNow (['gestureHi', 'gestureHiB', 'gestureHiC'] select (floor random 3));";
          showDisabled = 1;
          priority = 0.9;
        };
      };

      class AGM_WeaponOnBack {
        displayName = "$STR_AGM_Interaction_WeaponOnBack";
        condition = "currentWeapon player != ''";
        statement = "player action ['SwitchWeapon', vehicle player, vehicle player, 99];";
        showDisabled = 0;
        priority = -2;
      };
    };
  };
};

#include <Menu_Config.hpp>
