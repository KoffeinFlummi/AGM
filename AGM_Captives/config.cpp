class CfgPatches {
  class AGM_Captives {
    units[] = {};
    weapons[] = {"AGM_CableTie"};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction};
    version = "0.94.1";
    versionStr = "0.94.1";
    versionAr[] = {0,94,1};
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_Captives {
    class AGM_Captives {
      file = "\AGM_Captives\functions";
      class animCaptiveLeaveVehicle;
      class animCaptiveStateIn;
      class animCaptiveStateOut;
      class canFriskPerson;
      class canLoadCaptiveIntoVehicle;
      class canUnloadCaptiveFromVehicle;
      class escortCaptive;
      class loadCaptiveIntoVehicle;
      class openFriskMenu;
      class setCaptive;
      class surrender;
      class unloadCaptiveFromVehicle;
    };
  };
};

//release escorted captive if when entering a vehicle, getting killed
class Extended_GetIn_EventHandlers {
  class All {
    class AGM_Captives_AutoDetachCaptive {
      getIn = "if (local (_this select 2) && {(_this select 2) getVariable ['AGM_isEscorting', false]}) then {(_this select 2) setVariable ['AGM_isEscorting', false, true]}";
    };
  };
};

class Extended_Killed_EventHandlers {
  class CAManBase {
    class AGM_Captives_AutoDetachCaptive {
      killed = "if ((_this select 2) getVariable ['AGM_isEscorting', false]) then {(_this select 2) setVariable ['AGM_isEscorting', false, true]}";
    };
  };
};

class AGM_Core_canInteractConditions {
  class AGM_Interaction_isNotEscorting {
    condition = "!(_player getVariable ['AGM_isEscorting', false])";
  };
  class AGM_Interaction_isNotCaptive {
    condition = "!(_player getVariable ['AGM_isCaptive', false])";
  };
  class AGM_Interaction_isNotSurrendering {
    condition = "!(_player getVariable ['AGM_isSurrender', false])";
  };
};

class CfgVehicles {
  class Man;
  class CAManBase: Man {
    class AGM_Actions {
      class AGM_SetCaptive {
        displayName = "$STR_AGM_Captives_SetCaptive";
        distance = 4;
        condition = "'AGM_CableTie' in items _player && {alive _target} && {!(_target getVariable ['AGM_isCaptive', false])}";
        statement = "[_target, true] call AGM_Captives_fnc_setCaptive";
        showDisabled = 0;
        priority = 2.4;
        icon = "\AGM_Captives\UI\handcuff_ca.paa";
        hotkey = "C";
      };
      class AGM_ReleaseCaptive {
        displayName = "$STR_AGM_Captives_ReleaseCaptive";
        distance = 4;
        condition = "_target getVariable ['AGM_isCaptive', false] && {isNull (attachedTo _target)}";
        statement = "[_target, false] call AGM_Captives_fnc_setCaptive";
        exceptions[] = {"AGM_Interaction_isNotEscorting"};
        showDisabled = 0;
        priority = 2.4;
        icon = "\AGM_Captives\UI\handcuff_ca.paa";
        hotkey = "R";
      };
      class AGM_EscortCaptive {
        displayName = "$STR_AGM_Captives_EscortCaptive";
        distance = 4;
        condition = "_target getVariable ['AGM_isCaptive', false] && {isNull (attachedTo _target)}";
        statement = "[_target, true] call AGM_Captives_fnc_escortCaptive";
        exceptions[] = {"AGM_Interaction_isNotEscorting"};
        showDisabled = 0;
        icon = "\AGM_Captives\UI\captive_ca.paa";
        priority = 2.3;
        hotkey = "E";
      };
      class AGM_StopEscorting {
        displayName = "$STR_AGM_Captives_StopEscorting";
        distance = 4;
        condition = "_target getVariable ['AGM_isCaptive', false] && {_target in attachedObjects _player}";
        statement = "[_target, false] call AGM_Captives_fnc_escortCaptive";
        exceptions[] = {"AGM_Interaction_isNotEscorting"};
        showDisabled = 0;
        icon = "\AGM_Captives\UI\captive_ca.paa";
        priority = 2.3;
        hotkey = "E";
      };
      class AGM_LoadCaptive {
        displayName = "$STR_AGM_Captives_LoadCaptive";
        distance = 4;
        condition = "[_player, _target, objNull] call AGM_Captives_fnc_canLoadCaptiveIntoVehicle";
        statement = "[_player, _target, objNull] call AGM_Captives_fnc_loadCaptiveIntoVehicle";
        exceptions[] = {"AGM_Interaction_isNotEscorting"};
        showDisabled = 0;
        icon = "\AGM_Captives\UI\captive_ca.paa";
        priority = 2.2;
        hotkey = "L";
      };
      class AGM_FriskPerson {
        displayName = "$STR_AGM_Captives_FriskPerson";
        distance = 2;
        condition = "[_player, _target] call AGM_Captives_fnc_canFriskPerson";
        statement = "[_player, _target] call AGM_Captives_fnc_openFriskMenu";
        showDisabled = 0;
        //icon = "";  //@todo
        priority = 3;
        hotkey = "F";
      };
    };

    class AGM_SelfActions {
      class AGM_StopEscortingSelf {
        displayName = "$STR_AGM_Captives_StopEscorting";
        condition = "(_player getVariable ['AGM_escortedUnit', objNull]) getVariable ['AGM_isCaptive', false] && {(_player getVariable ['AGM_escortedUnit', objNull]) in attachedObjects _player}";
        statement = "[_player getVariable ['AGM_escortedUnit', objNull], false] call AGM_Captives_fnc_escortCaptive;";
        exceptions[] = {"AGM_Interaction_isNotEscorting"};
        showDisabled = 0;
        priority = 2.3;
        hotkey = "C";
      };
      /*class AGM_LoadCaptiveSelf {
        displayName = "$STR_AGM_Captives_LoadCaptive";
        condition = "[_player, objNull, objNull] call AGM_Captives_fnc_canLoadCaptiveIntoVehicle";
        statement = "[_player, objNull, objNull] call AGM_Captives_fnc_loadCaptiveIntoVehicle";
        exceptions[] = {"AGM_Interaction_isNotEscorting"};
        showDisabled = 0;
        priority = 2.2;
        hotkey = "K";
      };*/
    };
  };

  #define MACRO_LOADUNLOADCAPTIVE \
    class AGM_Actions { \
      class AGM_LoadCaptive { \
        displayName = "$STR_AGM_Captives_LoadCaptive"; \
        distance = 4; \
        condition = "[_player, objNull, _target] call AGM_Captives_fnc_canLoadCaptiveIntoVehicle"; \
        statement = "[_player, objNull, _target] call AGM_Captives_fnc_loadCaptiveIntoVehicle"; \
        exceptions[] = {"AGM_Interaction_isNotEscorting"}; \
        showDisabled = 0; \
        priority = 1.2; \
        hotkey = "L"; \
      }; \
      class AGM_UnloadCaptive { \
        displayName = "$STR_AGM_Captives_UnloadCaptive"; \
        distance = 4; \
        condition = "[_player, _target] call AGM_Captives_fnc_canUnloadCaptiveFromVehicle"; \
        statement = "[_player, _target] call AGM_Captives_fnc_unloadCaptiveFromVehicle"; \
        showDisabled = 0; \
        priority = 1.2; \
        hotkey = "C"; \
      }; \
    };

  class LandVehicle;
  class Car: LandVehicle {
    MACRO_LOADUNLOADCAPTIVE
  };
  class Tank: LandVehicle {
    MACRO_LOADUNLOADCAPTIVE
  };

  class Air;
  class Helicopter: Air {
    MACRO_LOADUNLOADCAPTIVE
  };
  class Plane: Air {
    MACRO_LOADUNLOADCAPTIVE
  };

  class Ship;
  class Ship_F: Ship {
    MACRO_LOADUNLOADCAPTIVE
  };

  class StaticWeapon: LandVehicle {
    MACRO_LOADUNLOADCAPTIVE
  };

  class StaticMortar;
  class Mortar_01_base_F: StaticMortar {
    MACRO_LOADUNLOADCAPTIVE
  };

  #define MACRO_ADDITEM(ITEM,COUNT) class _xx_##ITEM { \
    name = #ITEM; \
    count = COUNT; \
  };

  class Box_NATO_Support_F;
  class AGM_Box_Misc: Box_NATO_Support_F {
    class TransportItems {
      MACRO_ADDITEM(AGM_CableTie,24)
    };
  };
};

class CfgWeapons {
  class AGM_ItemCore;
  class InventoryItem_Base_F;

  class AGM_CableTie: AGM_ItemCore {
    displayName = "$STR_AGM_Captives_CableTie";
    descriptionShort = "$STR_AGM_Captives_CableTieDescription";
    model = "\AGM_Captives\agm_cabletie.p3d";
    picture = "\AGM_Captives\UI\agm_cabletie_x_ca.paa";
    scope = 2;
    class ItemInfo: InventoryItem_Base_F {
      mass = 1;
    };
  };
};

class CfgMovesBasic;
class CfgMovesMaleSdr: CfgMovesBasic {
  class States {
    class CutSceneAnimationBase;
    class AmovPercMstpSnonWnonDnon_EaseIn: CutSceneAnimationBase {
      head = "headDefault";
      static = 1;
      disableWeapons = 0;
      forceAim = 0;
      InterpolateTo[] = {"AmovPercMstpSnonWnonDnon_EaseOut",0.02,"Unconscious",0.1};
    };
    class AmovPercMstpSnonWnonDnon_Ease: AmovPercMstpSnonWnonDnon_EaseIn {
      looped = 1;
      InterpolateTo[] = {"Unconscious",0.1};
    };
    class AmovPercMstpSnonWnonDnon_EaseOut: AmovPercMstpSnonWnonDnon_EaseIn {
      InterpolateTo[] = {"AmovPercMstpSnonWnonDnon_EaseIn",0.02,"Unconscious",0.1};
    };

    class AmovPercMstpSnonWnonDnon_AmovPercMstpSsurWnonDnon: CutSceneAnimationBase {
      InterpolateTo[] = {"Unconscious",0.01,"AmovPercMstpSsurWnonDnon_AmovPercMstpSnonWnonDnon",0.1};
    };

    class AmovPercMstpSsurWnonDnon: AmovPercMstpSnonWnonDnon_AmovPercMstpSsurWnonDnon {
      looped = 1;
      InterpolateTo[] = {"Unconscious",0.01};
    };

    class AmovPercMstpSsurWnonDnon_AmovPercMstpSnonWnonDnon: AmovPercMstpSnonWnonDnon_AmovPercMstpSsurWnonDnon {
      InterpolateTo[] = {"Unconscious",0.01,"AmovPercMstpSnonWnonDnon_AmovPercMstpSsurWnonDnon",0.1};
    };
  };
};
