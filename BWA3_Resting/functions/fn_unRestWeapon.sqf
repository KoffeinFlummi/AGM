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

BWA3_weaponRested = false;

// UNREST THE WEAPON
addCamShake CAMSHAKE;
if (getNumber(configFile >> "CfgWeapons" >> (currentWeapon player) >> "BWA3_Bipod") == 1) then {
  player setUnitRecoilCoefficient ((unitRecoilCoefficient player) / BIPODRECOIL);
  player switchMove format ["%1", [(animationState player), "_bwa3_deploy", ""] call CBA_fnc_replace];
  ["Bipod undeployed.", false] spawn BWA3_Hint_displayText;
} else {
  player setUnitRecoilCoefficient ((unitRecoilCoefficient player) / RESTEDRECOIL);
  player switchMove format ["%1", [(animationState player), "_bwa3_rested", ""] call CBA_fnc_replace];
  ["Weapon lifted.", false] spawn BWA3_Hint_displayText;
};