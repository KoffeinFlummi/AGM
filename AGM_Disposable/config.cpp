
class CfgPatches {
  class AGM_Disposable {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.931";
    versionStr = "0.931";
    versionAr[] = {0,931,0};
    author[] = {"commy2"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_Disposable {
    class AGM_Disposable {
      file = "\AGM_Disposable\functions";
      class canToggleTopDownAttack;
      class lockTarget;
      class replaceATWeapon;
      class takeLoadedATWeapon;
      class toggleTopDownAttack;
      class topDownAttack;
    };
  };
};

class Extended_Init_EventHandlers {
  class CAManBase {
    class AGM_InitLockTargetMode {
      clientInit = "call compile preprocessFileLineNumbers '\AGM_Disposable\initUnit.sqf'";
    };
  };
};

class Extended_Fired_EventHandlers {
  class CAManBase {
    /*class AGM_FiredReplaceATWeapon {
      Fired = "if (local (_this select 0) && {getText (configFile >> 'CfgWeapons' >> _this select 1 >> 'AGM_UsedTube') != ''}) then {_this call AGM_Disposable_fnc_replaceATWeapon};";
    };*/
    class AGM_TopDownAttack {
      Fired = "if (local (_this select 0)) then {_this call AGM_Disposable_fnc_topDownAttack};";
    };
  };
};

/*class Extended_Take_EventHandlers {
  class CAManBase {
    class AGM_TakeLoadedATWeapon {
      Take = "if (getText (configFile >> 'CfgWeapons' >> _this select 2 >> 'AGM_LauncherClass') != '') then {_this call AGM_Disposable_fnc_takeLoadedATWeapon};";
    };
  };
};*/

class AGM_Core_Default_Keys {
  class toggleTopDownAttack {
    displayName = "Toggle Top Down Attack";
    condition = "call AGM_Disposable_fnc_canToggleTopDownAttack";
    statement = "call AGM_Disposable_fnc_toggleTopDownAttack";
    key = 25;
    shift = 0;
    control = 0;
    alt = 0;
  };
};

class CfgSounds {
  class AGM_Sound_Locked1 {
    sound[] = {"\A3\Sounds_F\weapons\Rockets\locked_3", 0.316228, 2.5, 200};
    titles[] = {};
  };
  class AGM_Sound_Locked2 {
    sound[] = {"\A3\Sounds_F\weapons\Rockets\locked_1", 0.316228, 1, 200};
    titles[] = {};
  };
};

#include <Optics.hpp>

class CfgWeapons {
  class Launcher_Base_F;
  class launch_NLAW_F: Launcher_Base_F {
    AGM_UsedTube = "AGM_launch_NLAW_Used_F";      // The class name of the already fired launcher.
  };
  /*class AGM_launch_NLAW_Loaded_F: launch_NLAW_F { // This is a loaded launcher. If you put this in a crate or a vehicles cargo it will be converted to the real launcher and a magazine.
    AGM_LauncherClass = "launch_NLAW_F";          // Launcher you get when picking up the loaded class
    AGM_LauncherMagazine = "NLAW_F";              // Magazine you get when picking up the loaded launcher, note: the magazine has to have a mass of 0 until BIS adds a command to give a magazine to a weapon directly.
  };
  class AGM_launch_NLAW_Used_F: launch_NLAW_F {
    //displayName = "";       // @todo String table
    //descriptionShort = "";  // @todo String table
    magazines[] = {"AGM_UsedTube_F"};              // This will disable the used launcher class from being fired again.
    //picture = "";              @todo
    //model = "";                @todo
  };*/

  class launch_Titan_base: Launcher_Base_F {
    AGM_enableTopDownAttack = 0;
    AGM_lockTargetMode = 0;
  };
  class launch_Titan_short_base: launch_Titan_base {
    AGM_enableTopDownAttack = 1;
    AGM_lockTargetMode = 1;
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
