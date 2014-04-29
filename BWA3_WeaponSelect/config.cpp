class CfgPatches {
  class BWA3_WeaponSelect {
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
  class BWA3_WeaponSelect {
    class BWA3_WeaponSelect {
        file = "\bwa3_weaponselect\functions";
      class getWeaponModes {};
      class getWeaponMuzzles {};
      class selectWeaponMode {};
      class selectWeaponMuzzle {};
    };
  };
};

class Extended_PostInit_EventHandlers {
  class BWA3_WeaponSelect {
    clientInit = "execVM '\BWA3_WeaponSelect\init.sqf'";
  };
};

class BWA3_Core_Default_Keys {
  class selectPistol {
    key = 2;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class selectRifle {
    key = 3;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class selectLauncher {
    key = 5;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class selectPistolMuzzle {
    key = 7;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class selectRifleMuzzle {
    key = 4;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class selectLauncherMuzzle {
    key = 8;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class selectBinocular {
    key = 6;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class holsterWeapon {
    key = 11;
    shift = 0;
    control = 0;
    alt = 0;
  };
};
