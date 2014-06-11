// TMR: Small Arms - Recoil initialization and functions
// (C) 2013 Ryan Schultz. See LICENSE.
// Edited prefixes for compatability in AGM_Realism by KoffeinFlummi
// Edited by commy2

#define BASE_POWER 0.40
#define BASE_TIME 0.19
#define BASE_FREQ 13
#define RECOIL_COEF 40

private ["_unit", "_weapon", "_ammo", "_powerMod", "_timeMod", "_freqMod", "_powerCoef", "_camshake"];

_unit = _this select 0;
_weapon = _this select 1;
_ammo = _this select 4;

if (_weapon == handgunWeapon _unit) exitWith {};

_powerMod = ([0, -0.1, -0.1, 0, -0.2] select (["STAND", "CROUCH", "PRONE", "UNDEFINED", ""] find stance _unit)) + ([0, -1, 0, -1] select (["INTERNAL", "EXTERNAL", "GUNNER", "GROUP"] find cameraView));
_timeMod = 0;
_freqMod = 0;

_powerCoef = 0;
if (vehicle player != player) then {
  _powerCoef = getNumber (configFile >> "CfgWeapons" >> _weapon >> "AGM_Recoil_shakeMultiplier");
  _powerCoef = _powerCoef * getNumber (configFile >> "CfgAmmo" >> _ammo >> "AGM_Recoil_shakeMultiplier");
} else {
  if (stance _unit == "PRONE") then {
    _recoil = getText (configFile >> "CfgWeapons" >> _weapon >> "recoilProne");
    if (currentWeaponMode _unit != _weapon) then {
      _recoil = getText (configFile >> "CfgWeapons" >> _weapon >> (currentWeaponMode _unit) >> "recoilProne");
    };
    _powerCoef = (getArray (configFile >> "CfgRecoils" >> _recoil)) select 1;
  } else {
    _recoil = getText (configFile >> "CfgWeapons" >> _weapon >> "recoil");
    if (currentWeaponMode _unit != _weapon) then {
      _recoil = getText (configFile >> "CfgWeapons" >> _weapon >> (currentWeaponMode _unit) >> "recoil");
    };
    _powerCoef = (getArray (configFile >> "CfgRecoils" >> _recoil)) select 1;
  };

  _powerCoef = (call compile (format ["%1", _powerCoef])) * RECOIL_COEF;
};

if (!(isNil "AGM_weaponRested") and {AGM_weaponRested}) then {_powerMod = _powerMod - 0.07};
if (!(isNil "AGM_bipodDeployed") and {AGM_bipodDeployed}) then {_powerMod = _powerMod - 0.11};

_camshake = [
    _powerCoef * (BASE_POWER + _powerMod) max 0,
    BASE_TIME + _timeMod max 0,
    BASE_FREQ + _freqMod max 0
];

if (!isNil "AGM_Debug" && {AGM_Debug == "Recoil"}) then {
    systemChat str _camshake;
    copyToClipboard format ["addcamshake %1", _camshake];
};

addcamshake _camshake;
