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
  ["Bipod undeployed.", false] call AGM_Core_fnc_displayText;
} else {
  player setUnitRecoilCoefficient ((unitRecoilCoefficient player) / RESTEDRECOIL);
  player switchMove ([(animationState player), "_bwa3_rested", ""] call CBA_fnc_replace);
  ["Weapon lifted.", false] call AGM_Core_fnc_displayText;
};

AGM_weaponRested = false;
AGM_bipodDeployed = false;