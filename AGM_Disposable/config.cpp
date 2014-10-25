
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
    };
  };
};

class Extended_Fired_EventHandlers {
  class CAManBase {
    class AGM_ReplaceFiredATWeapon {
      Fired = "if (local (_this select 0)) then {_this call AGM_Disposable_fnc_replaceATWeapon};";
    };
  };
};

class CfgWeapons {
  class Launcher_Base_F;
  class launch_NLAW_F: Launcher_Base_F {
    AGM_UsedTube = "AGM_launch_NLAW_Used_F";      // The class name of the used tube.
  };
  class AGM_launch_NLAW_Used_F: launch_NLAW_F {   // the used tube should be a sub class of the disposable launcher
    displayName = "$STR_AGM_Disposable_UsedTube";
    descriptionShort = "$STR_AGM_Disposable_UsedTubeDescription";
    magazines[] = {"AGM_UsedTube_F"};              // This will disable the used launcher class from being fired again.
    //picture = "";              @todo
    //model = "";                @todo
  };
};

class CfgMagazines {
  class NLAW_F;
  class AGM_UsedTube_F: NLAW_F {
    displayName = "$STR_AGM_Disposable_UsedTube";
    descriptionShort = "$STR_AGM_Disposable_UsedTubeDescription";
    count = 0;
    displayNameShort = "-";
    modelSpecial = "";
  };
};
