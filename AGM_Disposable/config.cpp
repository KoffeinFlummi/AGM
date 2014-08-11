
class CfgPatches {
  class AGM_Disposable {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.93";
    versionStr = "0.93";
    versionAr[] = {0,93,0};
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
    };
  };
};

class Extended_Fired_EventHandlers {
  class CAManBase {
    class BWA3_FiredReplaceATWeapon {
      Fired = "if (local (_this select 0) && {getText (configFile >> 'CfgWeapons' >> _this select 1 >> 'AGM_UsedTube') != ''}) then {_this call AGM_Disposable_fnc_replaceATWeapon}";
    };
  };
};

class Extended_Take_EventHandlers {
  class CAManBase {
    class AGM_TakeLoadedATWeapon {
      Take = "if (getText (configFile >> 'CfgWeapons' >> _this select 2 >> 'AGM_LauncherClass') != '') then {_this call AGM_Disposable_fnc_takeLoadedATWeapon}";
    };
  };
};

class CfgWeapons {
  class Launcher_Base_F;
  class launch_NLAW_F: Launcher_Base_F {
    AGM_UsedTube = "AGM_launch_NLAW_Used_F";      // The class name of the already fired launcher.
  };
  class AGM_launch_NLAW_Loaded_F: launch_NLAW_F { // This is a loaded launcher. If you put this in a crate or a vehicles cargo it will be converted to the real launcher and a magazine.
    AGM_LauncherClass = "launch_NLAW_F";          // Launcher you get when picking up the loaded class
    AGM_LauncherMagazine = "NLAW_F";              // Magazine you get when picking up the loaded launcher, note: the magazine has to have a mass of 0 until BIS adds a command to give a magazine to a weapon directly.
  };
  class AGM_launch_NLAW_Used_F: launch_NLAW_F {
    //displayName = "";       // @todo String table
    //descriptionShort = "";  // @todo String table
    magazines[] = {"AGM_UsedTube_F"};              // This will disable the used launcher class from being fired again.
    //picture = "";              @todo
    //model = "";                @todo
  };
};

class CfgMagazines {
  class CA_LauncherMagazine;
  class NLAW_F: CA_LauncherMagazine {
    mass = 0;                                     // Unfortunately, the magazine has to have a mass of 0 until BIS adds a command to give a magazine to a weapon directly.
  };
  class AGM_UsedTube_F: NLAW_F {
    displayname = "Used Tube";
    descriptionshort = "Used disposable rocket launcher";
    count = 0;
    displayNameShort = "-";
    modelSpecial = "";
  };
};

//@todo edit the weapon crates and vehicle cargo inventories. The loadout of the soldiers can stay as is.
