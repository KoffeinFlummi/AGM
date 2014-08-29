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

private ["_picture"];

// UNREST THE WEAPON
addCamShake CAMSHAKE;
if (AGM_bipodDeployed) then {
  player setUnitRecoilCoefficient ((unitRecoilCoefficient player) / BIPODRECOIL);
  [player, ([(animationState player), "_agm_deploy", ""] call CBA_fnc_replace), 2] call AGM_Core_fnc_doAnimation;
  _picture = getText (configFile >> "CfgWeapons" >> currentWeapon player >>  "picture");
  [localize "STR_AGM_Resting_BipodUndeployed", _picture] call AGM_Core_fnc_displayTextPicture;
} else {
  player setUnitRecoilCoefficient ((unitRecoilCoefficient player) / RESTEDRECOIL);
  [player, ([(animationState player), "_agm_rested", ""] call CBA_fnc_replace), 2] call AGM_Core_fnc_doAnimation;
  _picture = getText (configFile >> "CfgWeapons" >> currentWeapon player >>  "picture");
  [localize "STR_AGM_Resting_WeaponLifted", _picture] call AGM_Core_fnc_displayTextPicture;
};

AGM_weaponRested = false;
AGM_bipodDeployed = false;

