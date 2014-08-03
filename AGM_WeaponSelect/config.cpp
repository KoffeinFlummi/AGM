class CfgPatches {
  class AGM_WeaponSelect {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"commy2", "KoffeinFlummi", "CAA-Picard"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_WeaponSelect {
    class AGM_WeaponSelect {
      file = "\AGM_WeaponSelect\functions";
      class canSwitchWeapon;
      class canSwitchWeaponVehicle;
      class countMagazinesForGrenadeMuzzle;
      class displayGrenadeTypeAndNumber;
      class getWeaponModes;
      class getWeaponMuzzles;
      class selectGrenadeFrag;
      class selectGrenadeOther;
      class selectWeaponMode;
      class selectWeaponMuzzle;
      class selectBinocular;
      class selectWeaponVehicle;
      class selectMagazineVehicle;
      class setNextGrenadeMuzzle;
      class putWeaponAway;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_WeaponSelect {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_WeaponSelect\clientInit.sqf'";
  };
};

class AGM_Core_Default_Keys {
  class selectPistol {
    displayName = "$STR_AGM_WeaponSelect_SelectPistol";
    condition = "[_vehicle] call AGM_WeaponSelect_fnc_canSwitchWeapon";
    statement = "[handgunWeapon player] call AGM_WeaponSelect_fnc_selectWeaponMode";
    key = 2;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class selectRifle {
    displayName = "$STR_AGM_WeaponSelect_SelectRifle";
    condition = "[_vehicle] call AGM_WeaponSelect_fnc_canSwitchWeapon";
    statement = "[primaryWeapon player] call AGM_WeaponSelect_fnc_selectWeaponMode";
    key = 3;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class selectLauncher {
    displayName = "$STR_AGM_WeaponSelect_SelectLauncher";
    condition = "[_vehicle] call AGM_WeaponSelect_fnc_canSwitchWeapon";
    statement = "[secondaryWeapon player] call AGM_WeaponSelect_fnc_selectWeaponMode";
    key = 5;
    shift = 0;
    control = 0;
    alt = 0;
  };
  /*class selectPistolMuzzle {
    displayName = "Select Pistol Muzzle";
    condition = "[_vehicle] call AGM_WeaponSelect_fnc_canSwitchWeapon";
    statement = "[handgunWeapon player] call AGM_WeaponSelect_fnc_selectWeaponMuzzle";
    disabled = 1;
    key = 7;
    shift = 0;
    control = 0;
    alt = 0;
  };*/
  class selectRifleMuzzle {
    displayName = "$STR_AGM_WeaponSelect_SelectRifleMuzzle";
    condition = "[_vehicle] call AGM_WeaponSelect_fnc_canSwitchWeapon";
    statement = "[primaryWeapon player] call AGM_WeaponSelect_fnc_selectWeaponMuzzle";
    key = 4;
    shift = 0;
    control = 0;
    alt = 0;
  };
  /*class selectLauncherMuzzle {
    displayName = "Select Launcher Muzzle";
    condition = "[_vehicle] call AGM_WeaponSelect_fnc_canSwitchWeapon";
    statement = "[secondaryWeapon player] call AGM_WeaponSelect_fnc_selectWeaponMuzzle";
    disabled = 1;
    key = 8;
    shift = 0;
    control = 0;
    alt = 0;
  };*/
  class selectBinocular {
    displayName = "$STR_AGM_WeaponSelect_SelectBinocular";
    condition = "[_vehicle] call AGM_WeaponSelect_fnc_canSwitchWeapon";
    statement = "call AGM_WeaponSelect_fnc_selectBinocular";
    key = 6;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class selectGrenadeFrag {
    displayName = "$STR_AGM_WeaponSelect_SelectGrenadeFrag";
    condition = "[_vehicle] call AGM_WeaponSelect_fnc_canSwitchWeapon";
    statement = "call AGM_WeaponSelect_fnc_selectGrenadeFrag";
    key = 7;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class selectGrenadeOther {
    displayName = "$STR_AGM_WeaponSelect_SelectGrenadeOther";
    condition = "[_vehicle] call AGM_WeaponSelect_fnc_canSwitchWeapon";
    statement = "call AGM_WeaponSelect_fnc_selectGrenadeOther";
    key = 8;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class holsterWeapon {
    displayName = "$STR_AGM_WeaponSelect_HolsterWeapon";
    condition = "[_vehicle] call AGM_WeaponSelect_fnc_canSwitchWeapon";
    statement = "call AGM_WeaponSelect_fnc_putWeaponAway";
    key = 11;
    shift = 0;
    control = 0;
    alt = 0;
  };

  class engineOn {
    displayName = "$STR_AGM_WeaponSelect_EngineOn";
    condition = "[_vehicle] call AGM_WeaponSelect_fnc_canSwitchWeaponVehicle && {player == driver _vehicle} && {!isEngineOn _vehicle}";
    statement = "_vehicle engineOn true";
    key = 3;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class engineOff {
    displayName = "$STR_AGM_WeaponSelect_EngineOff";
    condition = "[_vehicle] call AGM_WeaponSelect_fnc_canSwitchWeaponVehicle && {player == driver _vehicle} && {isEngineOn _vehicle}";
    statement = "_vehicle engineOn false";
    key = 2;
    shift = 0;
    control = 0;
    alt = 0;
  };

  class selectMaingun {
    displayName = "$STR_AGM_WeaponSelect_SelectMainGun";
    condition = "[_vehicle] call AGM_WeaponSelect_fnc_canSwitchWeaponVehicle";
    statement = "[_vehicle, 0] call AGM_WeaponSelect_fnc_selectWeaponVehicle";
    key = 3;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class selectMachineGun {
    displayName = "$STR_AGM_WeaponSelect_SelectMachineGun";
    condition = "[_vehicle] call AGM_WeaponSelect_fnc_canSwitchWeaponVehicle";
    statement = "[_vehicle, 1] call AGM_WeaponSelect_fnc_selectWeaponVehicle";
    key = 4;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class selectMissile {
    displayName = "$STR_AGM_WeaponSelect_SelectMissiles";
    condition = "[_vehicle] call AGM_WeaponSelect_fnc_canSwitchWeaponVehicle";
    statement = "[_vehicle, 2] call AGM_WeaponSelect_fnc_selectWeaponVehicle";
    key = 5;
    shift = 0;
    control = 0;
    alt = 0;
  };
};

class AGM_Core_Options {
  class enableQuickSelect {
    displayName = "$STR_AGM_WeaponSelect_EnableQuickSelect";
    default = 1;
  };
};
