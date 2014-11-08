
class CfgPatches {
  class AGM_Disposable {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.94.1";
    versionStr = "0.94.1";
    versionAr[] = {0,94,1};
    author[] = {"commy2"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_Disposable {
    class AGM_Disposable {
      file = "\AGM_Disposable\functions";
      class replaceATWeapon;
      class takeLoadedATWeapon;
      class updateInventoryDisplay;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Disposable {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_Disposable\clientInit.sqf'";
  };
};

class Extended_FiredBIS_EventHandlers {
  class CAManBase {
    class AGM_Disposable_ReplaceFiredATWeapon {
      firedBIS = "if (local (_this select 0)) then {_this call AGM_Disposable_fnc_replaceATWeapon};";
    };
  };
};

// handle preloaded missile
class Extended_Init_EventHandlers {
  class CAManBase {
    class AGM_Disposable_UpdateInventoryDisplay {
      init = "if (local (_this select 0)) then {_this spawn {[_this select 0, secondaryWeapon (_this select 0)] call AGM_Disposable_fnc_takeLoadedATWeapon}};";
    };
  };
};

class Extended_Take_EventHandlers {
  class CAManBase {
    class AGM_Disposable_UpdateInventoryDisplay {
      take = "if (local (_this select 0)) then {[_this select 0, _this select 2] call AGM_Disposable_fnc_takeLoadedATWeapon; [_this select 0, findDisplay 602] call AGM_Disposable_fnc_updateInventoryDisplay};";
    };
  };
};

class Extended_Put_EventHandlers {
  class CAManBase {
    class AGM_Disposable_UpdateInventoryDisplay {
      put = "if (local (_this select 0)) then {[_this select 0, findDisplay 602] call AGM_Disposable_fnc_updateInventoryDisplay};";
    };
  };
};

class CfgWeapons {
  class Launcher_Base_F;
  class launch_NLAW_F: Launcher_Base_F {
    author = "$STR_AGM_Core_AGMTeam";
    AGM_UsedTube = "AGM_launch_NLAW_Used_F";      // The class name of the used tube.
    magazines[] = {"AGM_PreloadedMissileDummy"};  // The dummy magazine
  };
  class AGM_launch_NLAW_Used_F: launch_NLAW_F {   // the used tube should be a sub class of the disposable launcher
    author = "$STR_AGM_Core_AGMTeam";
    displayName = "$STR_AGM_Disposable_UsedTube";
    descriptionShort = "$STR_AGM_Disposable_UsedTubeDescription";
    magazines[] = {"AGM_UsedTube_F"};             // This will disable the used launcher class from being fired again.
    //picture = "";              @todo
    //model = "";                @todo
    weaponPoolAvailable = 0;
  };
};

class CfgMagazines {
  class NLAW_F;
  class AGM_PreloadedMissileDummy: NLAW_F {              // The dummy magazine
    author = "$STR_AGM_Core_AGMTeam";
    scope = 1;
    picture = "\AGM_Core\UI\blank_CO.paa";
    weaponPoolAvailable = 0;
    mass = 0;
  };
  class AGM_UsedTube_F: NLAW_F {
    author = "$STR_AGM_Core_AGMTeam";
    displayName = "$STR_AGM_Disposable_UsedTube";
    descriptionShort = "$STR_AGM_Disposable_UsedTubeDescription";
    displayNameShort = "-";
    count = 0;
    weaponPoolAvailable = 0;
    modelSpecial = "";
  };
};
