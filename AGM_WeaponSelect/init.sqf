// by commy2

if (getNumber(configFile >> "AGM_Realism_Settings" >> "enableWeaponQuickSelect") == 1) then {
  AGM_WeaponSelect_getWeaponModes = compile preProcessFileLineNumbers "\AGM_WeaponSelect\functions\WeaponSelect_getWeaponModes.sqf";
  AGM_WeaponSelect_getWeaponMuzzles = compile preProcessFileLineNumbers "\AGM_WeaponSelect\functions\WeaponSelect_getWeaponMuzzles.sqf";
  AGM_WeaponSelect_keyInput = compile preProcessFileLineNumbers "\AGM_WeaponSelect\functions\WeaponSelect_keyInput.sqf";
  AGM_WeaponSelect_keyRelease = compile preProcessFileLineNumbers "\AGM_WeaponSelect\functions\WeaponSelect_keyRelease.sqf";
  AGM_WeaponSelect_selectWeaponMode = compile preProcessFileLineNumbers "\AGM_WeaponSelect\functions\WeaponSelect_selectWeaponMode.sqf";
  AGM_WeaponSelect_selectWeaponMuzzle = compile preProcessFileLineNumbers "\AGM_WeaponSelect\functions\WeaponSelect_selectWeaponMuzzle.sqf";

  AGM_WeaponSelect_keyDown = false;

  0 spawn {
    sleep 0.1;
    waitUntil {!isNull (findDisplay 46)};
    (findDisplay 46) displayAddEventHandler ["KeyDown", "[_this select 1, _this select 2, _this select 3, _this select 4] call AGM_WeaponSelect_keyInput"];
    (findDisplay 46) displayAddEventHandler ["KeyUp", "_this select 1 call AGM_WeaponSelect_keyRelease"];
  };
};
