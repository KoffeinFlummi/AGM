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
// apply different animation for sway etc.
hint "Weapon unrested.";