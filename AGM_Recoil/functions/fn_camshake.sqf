// TMR: Small Arms - Recoil initialization and functions
// (C) 2013 Ryan Schultz. See LICENSE.
// Edited prefixes for compatability in AGM_Realism by KoffeinFlummi
// Edited by commy2

#define BASE_POWER 0.40
#define BASE_TIME 0.19
#define BASE_FREQ 13

private ["_unit", "_weapon", "_ammo", "_powerMod", "_timeMod", "_freqMod", "_powerCoef", "_camshake"];

_unit = _this select 0;
_weapon = _this select 1;
_ammo = _this select 4;

//if (_weapon == primaryWeapon _unit) then {
if (true) then {
    _powerMod = [0, -0.1, -0.2, 0, -0.2] select (["STAND", "CROUCH", "PRONE", "UNDEFINED", ""] find stance _unit);
    _timeMod = 0;
    _freqMod = 0;

    _powerCoef = getNumber (configFile >> "CfgWeapons" >> _weapon >> "AGM_Recoil_shakeMultiplier");
    _powerCoef = _powerCoef * getNumber (configFile >> "CfgAmmo" >> _ammo >> "AGM_Recoil_shakeMultiplier");

    if (AGM_weaponRested) then {_powerMod = _powerMod - 0.07};
    if (AGM_bipodDeployed) then {_powerMod = _powerMod - 0.11};

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
};
