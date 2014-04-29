class CfgPatches {
  class AGM_WeaponSelect {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, Extended_EventHandlers};
    version = 1.0;
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_WeaponSelect {
    class AGM_WeaponSelect {
      file = "\bwa3_weaponselect\functions";
      class getWeaponModes {};
      class getWeaponMuzzles {};
      class selectWeaponMode {};
      class selectWeaponMuzzle {};
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_WeaponSelect {
    clientInit = "execVM '\AGM_WeaponSelect\init.sqf'";
  };
};

class AGM_Core_Default_Keys {
  class selectPistol {
    displayName = "Select Pistol";
    key = 2;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class selectRifle {
    displayName = "Select Rifle";
    key = 3;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class selectLauncher {
    displayName = "Select Launcher";
    key = 5;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class selectPistolMuzzle {
    displayName = "Select Pistol Muzzle";
    disabled = 1;
    key = 7;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class selectRifleMuzzle {
    displayName = "Select Grenade Launcher";
    key = 4;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class selectLauncherMuzzle {
    displayName = "Select Launcher Muzzle";
    disabled = 1;
    key = 8;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class selectBinocular {
    displayName = "Select Binocular";
    key = 6;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class holsterWeapon {
    displayName = "Put Away";
    key = 11;
    shift = 0;
    control = 0;
    alt = 0;
  };
};
