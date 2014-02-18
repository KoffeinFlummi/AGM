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
 *
 */

#define RESTEDRECOIL 0.6
#define BIPODRECOIL 0.3
#define CAMSHAKE [1,0.5,5]

BWA3_weaponRested = false;

// UNREST THE WEAPON
player setUnitRecoilCoefficient ((unitRecoilCoefficient player) / RESTEDRECOIL);
addCamShake CAMSHAKE;
player switchMove format ["%1", [(animationState player), "_BWA3_rested", ""] call CBA_fnc_replace];
hintSilent "Weapon unrested.";