class CfgPatches {
  class AGM_Backblast {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, Extended_EventHandlers};
    version = 1.0;
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Backblast {
    Init = "execVM '\AGM_Backblast\init.sqf'";
  };
};

class Extended_FiredNear_EventHandlers {
  class CAManBase {
    class AGM_FiredNear_LauncherBackblast {
      FiredNear = "if (local (_this select 0) && {getNumber (configfile >> 'CfgWeapons' >> (_this select 3) >> 'AGM_Backblast_Damage') > 0}) then {_this call AGM_Backblast_launcherBackblast}";
    };
    class AGM_FiredNear_TankDangerZone {
      FiredNear = "if (local (_this select 0) && {getNumber (configfile >> 'CfgWeapons' >> (_this select 3) >> 'AGM_DangerZone_Damage') > 0}) then {_this call AGM_Backblast_tankDangerZone}";
    };
  };
};

class CfgWeapons {
  class Launcher;

  class Launcher_Base_F: Launcher {
    AGM_Backblast_Angle = 60;
    AGM_Backblast_Range = 10;
    AGM_Backblast_Damage = 0.5;
  };

  class launch_Titan_base: Launcher_Base_F {
    AGM_Backblast_Angle = 40;
    AGM_Backblast_Range = 6;
    AGM_Backblast_Damage = 0.2;
  };
  class launch_Titan_short_base: launch_Titan_base {
    AGM_Backblast_Angle = 40;
    AGM_Backblast_Range = 6;
    AGM_Backblast_Damage = 0.4;
  };

  class launch_NLAW_F: Launcher_Base_F {
    AGM_Backblast_Angle = 40;
    AGM_Backblast_Range = 15;
    AGM_Backblast_Damage = 0.5;
  };
  class launch_RPG32_F: Launcher_Base_F {
    AGM_Backblast_Angle = 60;
    AGM_Backblast_Range = 20;
    AGM_Backblast_Damage = 0.5;
  };

  class CannonCore;

  class cannon_120mm: CannonCore {
    AGM_DangerZone_Angle = 90;
    AGM_DangerZone_Range = 50;
    AGM_DangerZone_Damage = 1.0;
  };
};
