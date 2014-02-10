class CfgPatches {
  class BWA3_Backblast {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, Extended_EventHandlers};
    version = 1.0;
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgMods {
  class BWA3_Backblast {
    dir = "BWA3_Backblast";
    name = "BWA3: Backblast Module";
    picture = "";
    hidePicture = "true";
    hideName = "true";
    actionName = "Github";
    action = "https://github.com/KoffeinFlummi/BWA3_Realism";
  };
};

class CfgFunctions {
  class BWA3_Backblast {
    class BWA3_Backblast {
        file = "bwa3_backblast\functions";
      class launcherBackblast {};
    };
  };
};

class Extended_FiredNear_EventHandlers {
  class CAManBase {
    class BWA3_FiredNear {
      FiredNear = "if (local (_this select 0) && {getNumber (configfile >> 'CfgWeapons' >> (_this select 3) >> 'BWA3_Backblast_Damage') > 0}) then {_this call BWA3_Backblast_fnc_launcherBackblast}";
    };
  };
};

class CfgWeapons {
  class Launcher_Base_F {
    BWA3_Backblast_Angle = 60;
    BWA3_Backblast_Range = 10;
    BWA3_Backblast_Damage = 0.5;
  };
  
  class launch_Titan_base: Launcher_Base_F {
    BWA3_Backblast_Angle = 40;
    BWA3_Backblast_Range = 6;
    BWA3_Backblast_Damage = 0.2;
  };
  class launch_Titan_short_base: launch_Titan_base {
    BWA3_Backblast_Angle = 40;
    BWA3_Backblast_Range = 6;
    BWA3_Backblast_Damage = 0.4;
  };
  
  class launch_NLAW_F: Launcher_Base_F {
    BWA3_Backblast_Angle = 40;
    BWA3_Backblast_Range = 15;
    BWA3_Backblast_Damage = 0.5;
  };
  class launch_RPG32_F: Launcher_Base_F {
    BWA3_Backblast_Angle = 60;
    BWA3_Backblast_Range = 20;
    BWA3_Backblast_Damage = 0.5;
  };
};
