class CfgPatches {
  class AGM_WeaponSelect {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, Extended_EventHandlers, AGM_Core};
    version = 1.0;
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_WeaponSelect {
    class AGM_WeaponSelect {
      file = "\AGM_weaponselect\functions";
      class getWeaponModes;
      class getWeaponMuzzles;
      class selectWeaponMode;
      class selectWeaponMuzzle;
      class selectBinocular;
      class putWeaponAway;
    };
  };
};

class AGM_Core_Default_Keys {
  class selectPistol {
    displayName = "Select Pistol";
    condition = "player == _vehicle";
    statement = "[handgunWeapon player] call AGM_WeaponSelect_fnc_selectWeaponMode";
    key = 2;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class selectRifle {
    displayName = "Select Rifle";
    condition = "player == _vehicle";
    statement = "[primaryWeapon player] call AGM_WeaponSelect_fnc_selectWeaponMode";
    key = 3;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class selectLauncher {
    displayName = "Select Launcher";
    condition = "player == _vehicle";
    statement = "[secondaryWeapon player] call AGM_WeaponSelect_fnc_selectWeaponMode";
    key = 5;
    shift = 0;
    control = 0;
    alt = 0;
  };
  /*class selectPistolMuzzle {
    displayName = "Select Pistol Muzzle";
    condition = "player == _vehicle";
    statement = "[handgunWeapon player] call AGM_WeaponSelect_fnc_selectWeaponMuzzle";
    disabled = 1;
    key = 7;
    shift = 0;
    control = 0;
    alt = 0;
  };*/
  class selectRifleMuzzle {
    displayName = "Select Grenade Launcher";
    condition = "player == _vehicle";
    statement = "[primaryWeapon player] call AGM_WeaponSelect_fnc_selectWeaponMuzzle";
    key = 4;
    shift = 0;
    control = 0;
    alt = 0;
  };
  /*class selectLauncherMuzzle {
    displayName = "Select Launcher Muzzle";
    condition = "player == _vehicle";
    statement = "[secondaryWeapon player] call AGM_WeaponSelect_fnc_selectWeaponMuzzle";
    disabled = 1;
    key = 8;
    shift = 0;
    control = 0;
    alt = 0;
  };*/
  class selectBinocular {
    displayName = "Select Binocular";
    condition = "player == _vehicle";
    statement = "call AGM_WeaponSelect_fnc_selectBinocular";
    key = 6;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class holsterWeapon {
    displayName = "Put Weapon Away";
    condition = "player == _vehicle";
    statement = "call AGM_WeaponSelect_fnc_putWeaponAway";
    key = 11;
    shift = 0;
    control = 0;
    alt = 0;
  };
};
