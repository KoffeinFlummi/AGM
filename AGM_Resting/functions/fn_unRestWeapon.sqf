/*
 * Author: KoffeinFlummi
 *
 * Unrests the players weapon.
 *
 * Arguments:
 * None
 *
 * Return Values:
 * None
 */

#define RESTEDRECOIL 0.6
#define BIPODRECOIL 0.3
#define CAMSHAKE [1,0.5,5]

// UNREST THE WEAPON
addCamShake CAMSHAKE;
if (AGM_bipodDeployed) then {
  player setUnitRecoilCoefficient ((unitRecoilCoefficient player) / BIPODRECOIL);
  player switchMove ([(animationState player), "_bwa3_deploy", ""] call CBA_fnc_replace);
  _picture = format ["<img size='2' color='#ffffff' image='%1'/>", getText (configFile >> "CfgWeapons" >> currentWeapon player >>  "picture")];
  [formatText ["%1%2%3", parseText _picture, lineBreak, localize "STR_AGM_Resting_BipodUndeployed"], false] call AGM_Core_fnc_displayText;
} else {
  player setUnitRecoilCoefficient ((unitRecoilCoefficient player) / RESTEDRECOIL);
  player switchMove ([(animationState player), "_bwa3_rested", ""] call CBA_fnc_replace);
  _picture = format ["<img size='2' color='#ffffff' image='%1'/>", getText (configFile >> "CfgWeapons" >> currentWeapon player >>  "picture")];
  [formatText ["%1%2%3", parseText _picture, lineBreak, localize "STR_AGM_Resting_WeaponLifted"], false] call AGM_Core_fnc_displayText;
};

AGM_weaponRested = false;
AGM_bipodDeployed = false;