
class CfgPatches {
  class AGM_Reload {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_UI_F, Extended_EventHandlers, AGM_Core, AGM_Interaction};
    version = "0.9";
    versionStr = "0.9";
    versionAr[] = {0,9,0};
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Reload {
    clientInit = "execVM '\AGM_Reload\init.sqf'";
  };
};

class AGM_Core_Default_Keys {
  class checkAmmo {
    displayName = "$STR_AGM_Reload_checkAmmo";
    condition = "player == _vehicle";
    statement = "[currentWeapon player] spawn AGM_Reload_CheckAmmo";
    key = 19;
    shift = 1;
    control = 0;
    alt = 0;
  };
};

class CfgActions {
  class LoadMagazine;
  class LoadEmptyMagazine : LoadMagazine {
    show = 0;
    textDefault = "";
  };
};

class RscControlsGroup;
class RscText;
class RscInGameUI {
  class RscUnitInfo {
    // Soldier only
    class WeaponInfoControlsGroupLeft: RscControlsGroup {
      class controls {
        class CA_AmmoCount: RscText {
          sizeEx = 0;
        };
      };
    };
    // Vehicles only
    /*class WeaponInfoControlsGroupRight: RscControlsGroup {
      class controls {
        class CA_AmmoCount: RscText {
          sizeEx = 0;
        };
      };
    };*/
  };
};
