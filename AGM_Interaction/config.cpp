class CfgPatches {
  class AGM_Interaction {
    units[] = {};
    weapons[] = {"AGM_CableTie"};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_Interaction {
    class AGM_Interaction {
      file = "\AGM_interaction\functions";
      class addInteraction;
      class addInteractionSelf;
      class canInteractWith;
      class canLoadCaptiveIntoVehicle;
      class canTapShoulder;
      class canUnloadCaptiveFromVehicle;
      class escortCaptive;
      class getCaptivityStatus;
      class getDown;
      class isInRange;
      class joinTeam;
      class loadCaptiveIntoVehicle;
      class module;
      class openDoor;
      class openMenu;
      class openMenuSelf;
      class openSelectMenu;
      class removeInteraction;
      class removeInteractionSelf;
      class removeTag;
      class sendAway;
      class setCaptive;
      class setCaptivityStatus;
      class sortOptionsByPriority;
      class surrender;
      class tapShoulder;
      class unloadCaptiveFromVehicle;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Interaction {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_Interaction\clientInit.sqf'";
  };
};

//release escorted captive if when entering a vehicle
class Extended_GetIn_EventHandlers {
  class AllVehicles {
    class AGM_DetachCaptive {
      clientGetIn = "if (player == _this select 2 && {player getVariable ['AGM_isEscorting', false]}) then {player setVariable ['AGM_isEscorting', false, true]}";
    };
  };
};

class AGM_Core_Default_Keys {
  class openInteractionMenu {
    displayName = "$STR_AGM_Interaction_InteractionMenu";
    condition = "alive player && {!(player getVariable ['AGM_Unconscious', false])}";
    statement = "if (!dialog) then {'' call AGM_Interaction_fnc_openMenu} else {closeDialog 0}";
    exceptions[] = {"AGM_Drag_isNotDragging", "AGM_Medical_canTreat", "AGM_Interaction_isNotEscorting"};
    key = 221;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class openInteractionMenuSelf {
    displayName = "$STR_AGM_Interaction_InteractionMenuSelf";
    condition = "!(player getVariable ['AGM_Unconscious', false])";
    statement = "if (!dialog) then {'' call AGM_Interaction_fnc_openMenuSelf} else {closeDialog 0}";
    exceptions[] = {"AGM_Drag_isNotDragging", "AGM_Medical_canTreat", "AGM_Interaction_isNotEscorting"};
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
    key = 57;
    shift = 0;
    control = 1;
    alt = 0;
  };
  class tapShoulder {
    displayName = "$STR_AGM_Interaction_TapShoulder";
    condition = "[player, cursorTarget] call AGM_Interaction_fnc_canTapShoulder";
    statement = "[player, cursorTarget] call AGM_Interaction_fnc_tapShoulder";
    key = 20;
    shift = 1;
    control = 0;
    alt = 0;
  };
};

class AGM_Core_Options {
  class showPlayerNames {
    displayName = "$STR_AGM_Interaction_ShowPlayerNames";
    default = 1;
  };
  class showPlayerRanks {
    displayName = "$STR_AGM_Interaction_ShowPlayerRanks";
    default = 1;
  };
};

class AGM_Parameters {
  AGM_Interaction_PlayerNamesViewDistance = 5;
};

class AGM_Core_canInteractConditions {
  class AGM_Interaction_isNotEscorting {
    condition = "!(player getVariable ['AGM_isEscorting', false])";
  };
  class AGM_Interaction_isNotCaptive {
    condition = "!(player getVariable ['AGM_isCaptive', false])";
  };
  class AGM_Interaction_isNotSurrendering {
    condition = "!(player getVariable ['AGM_isSurrender', false])";
  };
};

class CfgMovesBasic;
class CfgMovesMaleSdr: CfgMovesBasic {
  /*class Actions {     // This is ReadOnlyVerified
    class RifleStandSaluteActions;
    class AGM_RifleStandSaluteActions: RifleStandSaluteActions {
      getOver = "";
    };
  };*/
  class States {
    class CutSceneAnimationBase;
    class AmovPercMstpSnonWnonDnon_EaseIn: CutSceneAnimationBase {
      //actions = "AGM_RifleStandSaluteActions";
      head = "headDefault";
      static = 1;
      disableWeapons = 0;
      forceAim = 0;
      InterpolateTo[] = {"AmovPercMstpSnonWnonDnon_EaseOut",0.02,"Unconscious",0.1};
    };
    class AmovPercMstpSnonWnonDnon_Ease: AmovPercMstpSnonWnonDnon_EaseIn {
      looped = 0;
      InterpolateTo[] = {"Unconscious",0.1};
    };
    class AmovPercMstpSnonWnonDnon_EaseOut: AmovPercMstpSnonWnonDnon_EaseIn {
      InterpolateTo[] = {"AmovPercMstpSnonWnonDnon_EaseIn",0.02,"Unconscious",0.1};
    };
  };
};

#define MACRO_ADDITEM(ITEM,COUNT) class _xx_##ITEM { \
  name = #ITEM; \
  count = COUNT; \
};

class CfgVehicles {
  class Man;
  class CAManBase: Man {
    class AGM_Actions {
      class AGM_TeamManagement {
        displayName = "$STR_AGM_Interaction_TeamManagement";
        distance = 4;
        condition = "alive AGM_Interaction_Target && {!isPlayer AGM_Interaction_Target} && {AGM_Interaction_Target in units group player}";
        statement = "'AGM_TeamManagement' call AGM_Interaction_fnc_openMenu;";
        showDisabled = 0;
        priority = 3.2;

        class AGM_JoinTeamRed {
          displayName = "$STR_AGM_Interaction_JoinTeamRed";
          distance = 4;
          condition = "alive AGM_Interaction_Target && {!isPlayer AGM_Interaction_Target} && {AGM_Interaction_Target in units group player}";
          statement = "[AGM_Interaction_Target, 'RED'] call AGM_Interaction_fnc_joinTeam";
          showDisabled = 1;
          priority = 2.4;
        };
        class AGM_JoinTeamGreen {
          displayName = "$STR_AGM_Interaction_JoinTeamGreen";
          distance = 4;
          condition = "alive AGM_Interaction_Target && {!isPlayer AGM_Interaction_Target} && {AGM_Interaction_Target in units group player}";
          statement = "[AGM_Interaction_Target, 'GREEN'] call AGM_Interaction_fnc_joinTeam";
          showDisabled = 1;
          priority = 2.3;
        };
        class AGM_JoinTeamBlue {
          displayName = "$STR_AGM_Interaction_JoinTeamBlue";
          distance = 4;
          condition = "alive AGM_Interaction_Target && {!isPlayer AGM_Interaction_Target} && {AGM_Interaction_Target in units group player}";
          statement = "[AGM_Interaction_Target, 'BLUE'] call AGM_Interaction_fnc_joinTeam";
          showDisabled = 1;
          priority = 2.2;
        };
        class AGM_JoinTeamYellow {
          displayName = "$STR_AGM_Interaction_JoinTeamYellow";
          distance = 4;
          condition = "alive AGM_Interaction_Target && {!isPlayer AGM_Interaction_Target} && {AGM_Interaction_Target in units group player}";
          statement = "[AGM_Interaction_Target, 'YELLOW'] call AGM_Interaction_fnc_joinTeam";
          showDisabled = 1;
          priority = 2.1;
        };

        class AGM_LeaveTeam {
          displayName = "$STR_AGM_Interaction_LeaveTeam";
          distance = 4;
          condition = "alive AGM_Interaction_Target && {!isPlayer AGM_Interaction_Target} && {AGM_Interaction_Target in units group player} && {assignedTeam player != 'MAIN'}";
          statement = "[AGM_Interaction_Target, 'MAIN'] call AGM_Interaction_fnc_joinTeam";
          showDisabled = 1;
          priority = 2.5;
        };
      };

      class AGM_TapShoulder {
        displayName = "$STR_AGM_Interaction_TapShoulder";
        distance = 4;
        condition = "[player, AGM_Interaction_Target] call AGM_Interaction_fnc_canTapShoulder";
        statement = "[player, AGM_Interaction_Target] call AGM_Interaction_fnc_tapShoulder";
        showDisabled = 1;
        priority = 2.8;
      };
      class AGM_JoinGroup {
        displayName = "$STR_AGM_Interaction_JoinGroup";
        distance = 4;
        condition = "playerSide == side AGM_Interaction_Target && {group player != group AGM_Interaction_Target}";
        statement = "[player] joinSilent group AGM_Interaction_Target;";
        showDisabled = 0;
        priority = 2.6;
      };

      class AGM_GetDown {
        displayName = "$STR_AGM_Interaction_GetDown";
        distance = 4;
        condition = "[AGM_Interaction_Target] call AGM_Interaction_fnc_canInteractWith";
        statement = "[AGM_Interaction_Target] call AGM_Interaction_fnc_getDown";
        showDisabled = 0;
        priority = 2.2;
      };
      class AGM_SendAway {
        displayName = "$STR_AGM_Interaction_SendAway";
        distance = 4;
        condition = "[AGM_Interaction_Target] call AGM_Interaction_fnc_canInteractWith";
        statement = "[AGM_Interaction_Target] call AGM_Interaction_fnc_sendAway";
        showDisabled = 0;
        priority = 2.0;
      };

      class AGM_SetCaptive {
        displayName = "$STR_AGM_Interaction_SetCaptive";
        distance = 4;
        //condition = "[AGM_Interaction_Target, false] call AGM_Interaction_fnc_canInteractWith && {!(AGM_Interaction_Target getVariable ['AGM_isCaptive', false])}";
        condition = "'AGM_CableTie' in items player && {!(AGM_Interaction_Target getVariable ['AGM_isCaptive', false])}";
        statement = "[AGM_Interaction_Target, true] call AGM_Interaction_fnc_setCaptive";
        showDisabled = 0;
        priority = 2.4;
      };
      class AGM_ReleaseCaptive {
        displayName = "$STR_AGM_Interaction_ReleaseCaptive";
        distance = 4;
        condition = "[AGM_Interaction_Target, false] call AGM_Interaction_fnc_canInteractWith && {AGM_Interaction_Target getVariable ['AGM_isCaptive', false]} && {isNull attachedTo AGM_Interaction_Target}";
        statement = "[AGM_Interaction_Target, false] call AGM_Interaction_fnc_setCaptive";
        exceptions[] = {"AGM_Interaction_isNotEscorting"};
        showDisabled = 0;
        priority = 2.4;
      };
      class AGM_EscortCaptive {
        displayName = "$STR_AGM_Interaction_EscortCaptive";
        distance = 4;
        condition = "[AGM_Interaction_Target, false] call AGM_Interaction_fnc_canInteractWith && {AGM_Interaction_Target getVariable ['AGM_isCaptive', false]} && {isNull attachedTo AGM_Interaction_Target}";
        statement = "[AGM_Interaction_Target, true] call AGM_Interaction_fnc_escortCaptive";
        exceptions[] = {"AGM_Interaction_isNotEscorting"};
        showDisabled = 0;
        priority = 2.3;
      };
      class AGM_StopEscorting {
        displayName = "$STR_AGM_Interaction_StopEscorting";
        distance = 4;
        condition = "[AGM_Interaction_Target, false] call AGM_Interaction_fnc_canInteractWith && {AGM_Interaction_Target getVariable ['AGM_isCaptive', false]} && {AGM_Interaction_Target in attachedObjects player}";
        statement = "[AGM_Interaction_Target, false] call AGM_Interaction_fnc_escortCaptive";
        exceptions[] = {"AGM_Interaction_isNotEscorting"};
        showDisabled = 0;
        priority = 2.3;
      };
      class AGM_LoadCaptive {
        displayName = "Load Captive into Vehicle";
        distance = 4;
        condition = "[player, AGM_Interaction_Target, objNull] call AGM_Interaction_fnc_canLoadCaptiveIntoVehicle";
        statement = "[player, AGM_Interaction_Target, objNull] call AGM_Interaction_fnc_loadCaptiveIntoVehicle";
        exceptions[] = {"AGM_Interaction_isNotEscorting"};
        showDisabled = 0;
        priority = 2.2;
      };

      class AGM_Pardon {
        displayName = "$STR_AGM_Interaction_Pardon";
        distance = 4;
        condition = "rating AGM_Interaction_Target < -2000 && {alive AGM_Interaction_Target} && {playerSide == side group AGM_Interaction_Target}";
        statement = "[AGM_Interaction_Target, '{_this addRating -rating _this}', AGM_Interaction_Target] call AGM_Core_fnc_execRemoteFnc";
        showDisabled = 0;
        priority = 2.5;
      };
    };

    class AGM_SelfActions {
      class AGM_TeamManagement {
        displayName = "$STR_AGM_Interaction_TeamManagement";
        condition = "true";
        statement = "'AGM_TeamManagement' call AGM_Interaction_fnc_openMenuSelf;";
        showDisabled = 1;
        priority = 3.2;

        class AGM_JoinTeamRed {
          displayName = "$STR_AGM_Interaction_JoinTeamRed";
          condition = "true";
          statement = "[player, 'RED'] call AGM_Interaction_fnc_joinTeam";
          showDisabled = 1;
          priority = 2.4;
        };
        class AGM_JoinTeamGreen {
          displayName = "$STR_AGM_Interaction_JoinTeamGreen";
          condition = "true";
          statement = "[player, 'GREEN'] call AGM_Interaction_fnc_joinTeam";
          showDisabled = 1;
          priority = 2.3;
        };
        class AGM_JoinTeamBlue {
          displayName = "$STR_AGM_Interaction_JoinTeamBlue";
          condition = "true";
          statement = "[player, 'BLUE'] call AGM_Interaction_fnc_joinTeam";
          showDisabled = 1;
          priority = 2.2;
        };
        class AGM_JoinTeamYellow {
          displayName = "$STR_AGM_Interaction_JoinTeamYellow";
          condition = "true";
          statement = "[player, 'YELLOW'] call AGM_Interaction_fnc_joinTeam";
          showDisabled = 1;
          priority = 2.1;
        };

        class AGM_LeaveTeam {
          displayName = "$STR_AGM_Interaction_LeaveTeam";
          condition = "assignedTeam player != 'MAIN'";
          statement = "[player, 'MAIN'] call AGM_Interaction_fnc_joinTeam";
          showDisabled = 1;
          priority = 2.5;
        };

        class AGM_BecomeLeader {
          displayName = "$STR_AGM_Interaction_BecomeLeader";
          condition = "count (units group player) > 1 && {leader group player != player}";
          statement = "_newGroup = createGroup side player; (units group player) joinSilent _newGroup; _newGroup selectLeader player;";
          showDisabled = 1;
          priority = 1.0;
        };
        class AGM_LeaveGroup {
          displayName = "$STR_AGM_Interaction_LeaveGroup";
          condition = "count (units group player) > 1";
          statement = "_oldGroup = units group player; _newGroup = createGroup side player; [player] joinSilent _newGroup; {player reveal _x} forEach _oldGroup;";
          showDisabled = 1;
          priority = 1.2;
        };
      };

      /* DANCE ANIMATION DOESN'T WORK :(
      class AGM_Dance {
        displayName = "$STR_AGM_Interaction_Dance";
        condition = "isClass (configFile >> 'CfgPatches' >> 'AGM_Movement') and !AGM_Dancing";
        statement = "AGM_Dancing = true; [-2, {_this switchMove 'TestDance';}, player] call CBA_fnc_globalExecute;";
        showDisabled = 0;
        priority = -1.2;
      };
      class AGM_StopDancing {
        displayName = "$STR_AGM_Interaction_StopDancing";
        condition = "AGM_Dancing";
        statement = "AGM_Dancing = false; [-2, {_this switchMove '';}, player] call CBA_fnc_globalExecute;";
        showDisabled = 0;
        priority = -1.2;
      };
      */

      class AGM_Gestures {
        displayName = "$STR_AGM_Interaction_Gestures";
        condition = "canStand player";
        statement = "'AGM_Gestures' call AGM_Interaction_fnc_openMenuSelf;";
        showDisabled = 1;
        priority = 3.5;

        /*class AGM_Gesture_Advance {
          displayName = "$STR_AGM_Interaction_Gestures_Attack";
          condition = "canStand player";
          statement = "player playActionNow 'gestureAttack';";
          showDisabled = 1;
          priority = 2.0;
        };*/
        class AGM_Gesture_Advance {
          displayName = "$STR_AGM_Interaction_Gestures_Advance";
          condition = "canStand player";
          statement = "player playActionNow 'gestureAdvance';";
          showDisabled = 1;
          priority = 1.9;
        };
        class AGM_Gesture_Go {
          displayName = "$STR_AGM_Interaction_Gestures_Go";
          condition = "canStand player";
          statement = "player playActionNow (['gestureGo', 'gestureGoB'] select (floor random 2));";
          showDisabled = 1;
          priority = 1.8;
        };
        class AGM_Gesture_Follow {
          displayName = "$STR_AGM_Interaction_Gestures_Follow";
          condition = "canStand player";
          statement = "player playActionNow 'gestureFollow';";
          showDisabled = 1;
          priority = 1.7;
        };
        /*class AGM_Gesture_Point {
          displayName = "$STR_AGM_Interaction_Gestures_Point";
          condition = "canStand player";
          statement = "player playActionNow 'gesturePoint';";
          showDisabled = 1;
          priority = 1.6;
        };*/
        class AGM_Gesture_Up {
          displayName = "$STR_AGM_Interaction_Gestures_Up";
          condition = "canStand player";
          statement = "player playActionNow 'gestureUp';";
          showDisabled = 1;
          priority = 1.5;
        };
        class AGM_Gesture_Cover {
          displayName = "$STR_AGM_Interaction_Gestures_Cover";
          condition = "canStand player";
          statement = "player playActionNow 'gestureCover';";
          showDisabled = 1;
          priority = 1.4;
        };
        class AGM_Gesture_CeaseFire {
          displayName = "$STR_AGM_Interaction_Gestures_Cease_Fire";
          condition = "canStand player";
          statement = "player playActionNow 'gestureCeaseFire';";
          showDisabled = 1;
          priority = 1.3;
        };
        class AGM_Gesture_Freeze {
          displayName = "$STR_AGM_Interaction_Gestures_Freeze";
          condition = "canStand player";
          statement = "player playActionNow 'gestureFreeze';";
          showDisabled = 1;
          priority = 1.2;
        };
        class AGM_Gesture_Yes {
          displayName = "$STR_AGM_Interaction_Gestures_Yes";
          condition = "canStand player";
          statement = "player playActionNow (['gestureYes', 'gestureNod'] select (floor random 2));";
          showDisabled = 1;
          priority = 1.1;
        };
        class AGM_Gesture_No {
          displayName = "$STR_AGM_Interaction_Gestures_No";
          condition = "canStand player";
          statement = "player playActionNow 'gestureNo';";
          showDisabled = 1;
          priority = 1.0;
        };
        class AGM_Gesture_Hi {
          displayName = "$STR_AGM_Interaction_Gestures_Hi";
          condition = "canStand player";
          statement = "player playActionNow (['gestureHi', 'gestureHiB', 'gestureHiC'] select (floor random 3));";
          showDisabled = 1;
          priority = 0.9;
        };
      };
      class AGM_StopEscortingSelf {
        displayName = "$STR_AGM_Interaction_StopEscorting";
        condition = "[AGM_Interaction_Target, false] call AGM_Interaction_fnc_canInteractWith && {AGM_Interaction_Target getVariable ['AGM_isCaptive', false]} && {AGM_Interaction_Target in attachedObjects player}";
        statement = "[AGM_Interaction_Target, false] call AGM_Interaction_fnc_escortCaptive";
        exceptions[] = {"AGM_Interaction_isNotEscorting"};
        showDisabled = 0;
        priority = 2.3;
      };
      class AGM_LoadCaptiveSelf {
        displayName = "Load Captive into Vehicle";
        condition = "[player, objNull, objNull] call AGM_Interaction_fnc_canLoadCaptiveIntoVehicle";
        statement = "[player, objNull, objNull] call AGM_Interaction_fnc_loadCaptiveIntoVehicle";
        exceptions[] = {"AGM_Interaction_isNotEscorting"};
        showDisabled = 0;
        priority = 2.2;
      };

      /*class AGM_WeaponOnBack {
        displayName = "$STR_AGM_Interaction_WeaponOnBack";
        condition = "currentWeapon player != ''";
        statement = "player action ['SwitchWeapon', vehicle player, vehicle player, 99];";
        showDisabled = 0;
        priority = -2;
      };*/
    };
  };

  class LandVehicle;
  class Car: LandVehicle {
    class AGM_Actions {
      class AGM_LoadCaptive {
        displayName = "Load Captive into Vehicle";
        distance = 4;
        condition = "[player, objNull, AGM_Interaction_Target] call AGM_Interaction_fnc_canLoadCaptiveIntoVehicle";
        statement = "[player, objNull, AGM_Interaction_Target] call AGM_Interaction_fnc_loadCaptiveIntoVehicle";
        exceptions[] = {"AGM_Interaction_isNotEscorting"};
        showDisabled = 0;
        priority = 1.2;
      };
      class AGM_UnloadCaptive {
        displayName = "Unload Captive from Vehicle";
        distance = 4;
        condition = "[player, AGM_Interaction_Target] call AGM_Interaction_fnc_canUnloadCaptiveFromVehicle";
        statement = "[player, AGM_Interaction_Target] call AGM_Interaction_fnc_unloadCaptiveFromVehicle";
        showDisabled = 0;
        priority = 1.2;
      };
    };
    class AGM_SelfActions {};
  };
  class Tank: LandVehicle {
    class AGM_Actions {
      class AGM_LoadCaptive {
        displayName = "Load Captive into Vehicle";
        distance = 4;
        condition = "[player, objNull, AGM_Interaction_Target] call AGM_Interaction_fnc_canLoadCaptiveIntoVehicle";
        statement = "[player, objNull, AGM_Interaction_Target] call AGM_Interaction_fnc_loadCaptiveIntoVehicle";
        exceptions[] = {"AGM_Interaction_isNotEscorting"};
        showDisabled = 0;
        priority = 1.2;
      };
      class AGM_UnloadCaptive {
        displayName = "Unload Captive from Vehicle";
        distance = 4;
        condition = "[player, AGM_Interaction_Target] call AGM_Interaction_fnc_canUnloadCaptiveFromVehicle";
        statement = "[player, AGM_Interaction_Target] call AGM_Interaction_fnc_unloadCaptiveFromVehicle";
        showDisabled = 0;
        priority = 1.2;
      };
    };
    class AGM_SelfActions {};
  };
  class Air;
  class Helicopter: Air {
    class AGM_Actions {
      class AGM_LoadCaptive {
        displayName = "Load Captive into Vehicle";
        distance = 4;
        condition = "[player, objNull, AGM_Interaction_Target] call AGM_Interaction_fnc_canLoadCaptiveIntoVehicle";
        statement = "[player, objNull, AGM_Interaction_Target] call AGM_Interaction_fnc_loadCaptiveIntoVehicle";
        exceptions[] = {"AGM_Interaction_isNotEscorting"};
        showDisabled = 0;
        priority = 1.2;
      };
      class AGM_UnloadCaptive {
        displayName = "Unload Captive from Vehicle";
        distance = 4;
        condition = "[player, AGM_Interaction_Target] call AGM_Interaction_fnc_canUnloadCaptiveFromVehicle";
        statement = "[player, AGM_Interaction_Target] call AGM_Interaction_fnc_unloadCaptiveFromVehicle";
        showDisabled = 0;
        priority = 1.2;
      };
    };
    class AGM_SelfActions {};
  };

  /*
  // BLUFOR Uniforms
  class SoldierWB: CAManBase {};
  class B_Soldier_base_F: SoldierWB {
    modelSides[] = {3,2,1,0};
    // allowedUniformSides = {3,2,1,0}; this doesn't seem to do anything (or i'm doing it wrong)
  };
  class B_Helipilot_F: B_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class B_helicrew_F: B_Helipilot_F {
    modelSides[] = {3,2,1,0};
  };
  class B_Pilot_F: B_Helipilot_F {
    modelSides[] = {3,2,1,0};
  };
  class B_RangeMaster_F: B_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class B_Soldier_02_f: B_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class B_Soldier_03_f: B_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class B_Soldier_04_f: B_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class B_Soldier_05_f: B_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class B_soldier_survival_F: B_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class B_Story_Protagonist_F: B_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class B_Story_SF_Captain_F: B_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class B_Soldier_diver_base_F: B_Soldier_base_F {};
  class B_diver_F: B_Soldier_diver_base_F {
    modelSides[] = {3,2,1,0};
  };

  // INDEP / FIA Uniforms
  class SoldierGB: CAManBase {};
  class I_Soldier_base_F: SoldierGB {
    modelSides[] = {3,2,1,0};
  };
  class I_officer_F: I_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class I_Soldier_03_f: I_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class I_Soldier_04_f: I_Soldier_base_F {
    modelSides[] = {3,2,1,0};
  };
  class I_Soldier_diver_base_F: I_Soldier_base_F {};
  class I_diver_F: I_Soldier_diver_base_F {
    modelSides[] = {3,2,1,0};
  };

  class I_G_Soldier_base_F: SoldierGB {
    modelSides[] = {3,2,1,0};
  };
  class I_G_engineer_F: I_G_Soldier_base_F {}; // WHY BOHEMIA? WHY?
  class B_G_engineer_F: I_G_engineer_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_medic_F: I_G_Soldier_base_F {};
  class B_G_medic_F: I_G_medic_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_officer_F: I_G_Soldier_base_F {};
  class B_G_officer_F: I_G_officer_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Soldier_A_F: I_G_Soldier_base_F {};
  class B_G_Soldier_A_F: I_G_Soldier_A_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Soldier_AR_F: I_G_Soldier_base_F {};
  class B_G_Soldier_AR_F: I_G_Soldier_AR_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Soldier_exp_F: I_G_Soldier_base_F {};
  class B_G_Soldier_exp_F: I_G_Soldier_exp_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Soldier_F: I_G_Soldier_base_F {};
  class B_G_Soldier_F: I_G_Soldier_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Story_SF_Captain_F: B_G_Soldier_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Soldier_GL_F: I_G_Soldier_base_F {};
  class B_G_Soldier_GL_F: I_G_Soldier_GL_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Soldier_LAT_F: I_G_Soldier_base_F {};
  class B_G_Soldier_LAT_F: I_G_Soldier_LAT_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Soldier_lite_F: I_G_Soldier_base_F {};
  class B_G_Soldier_lite_F: I_G_Soldier_lite_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Soldier_M_F: I_G_Soldier_base_F {};
  class B_G_Soldier_M_F: I_G_Soldier_M_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Soldier_SL_F: I_G_Soldier_base_F {};
  class B_G_Soldier_SL_F: I_G_Soldier_SL_F {
    modelSides[] = {3,2,1,0};
  };
  class I_G_Soldier_TL_F: I_G_Soldier_base_F {};
  class B_G_Soldier_TL_F: I_G_Soldier_TL_F {
    modelSides[] = {3,2,1,0};
  };
  */

  class StaticWeapon: LandVehicle {
    class AGM_Actions {};
    class AGM_SelfActions {};
  };

  class StaticMortar;
  class Mortar_01_base_F: StaticMortar {
    class AGM_Actions {};
    class AGM_SelfActions {};
  };

  class Module_F;
  class AGM_ModuleInteraction: Module_F {
    author = "AGM Team";
    category = "AGM";
    displayName = "Interaction";
    function = "AGM_Interaction_fnc_module";
    scope = 2;
    isGlobal = 1;
    icon = "\AGM_Interaction\UI\IconInteraction_ca.paa";
    class Arguments {
      class PlayerNamesViewDistance {
        displayName = "Player Names View Dist.";
        description = "Distance in meters at which player names are shown. Default: 5";
        defaultValue = 5;
      };
    };
  };

  class Box_NATO_Support_F;
  class AGM_Box_Misc: Box_NATO_Support_F {
    class TransportItems {
      MACRO_ADDITEM(AGM_CableTie,24)
    };
  };
};

class CfgWeapons {
  class ItemCore;
  class InventoryItem_Base_F;

  class AGM_CableTie: ItemCore {
    displayName = "$STR_AGM_Interaction_CableTie_Name";
    descriptionShort = "$STR_AGM_Interaction_CableTie_Description";
    model = "\AGM_Interaction\agm_cabletie.p3d";
    picture = "\AGM_Interaction\UI\agm_cabletie_x_ca.paa";
    scope = 2;
    class ItemInfo: InventoryItem_Base_F {
      mass = 1;
      type = 401;
    };
  };
};

#include <Menu_Config.hpp>
