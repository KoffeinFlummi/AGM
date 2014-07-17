class CfgPatches {
  class AGM_Reload {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_Reload {
    class AGM_Reload {
      file = "\AGM_Reload\functions";
      class checkAmmo;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Reload {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_Reload\clientInit.sqf'";
  };
};

class AGM_Core_Default_Keys {
  class checkAmmo {
    displayName = "$STR_AGM_Reload_checkAmmo";
    condition = "player == _vehicle || {_vehicle isKindOf 'StaticWeapon'}";
    statement = "[currentWeapon _vehicle, _vehicle, false] call AGM_Reload_fnc_checkAmmo";
    key = 19;
    shift = 0;
    control = 1;
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
