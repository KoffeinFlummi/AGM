/*
 * Author: KoffeinFlummi
 *
 * Handles key input for weapon resting.
 *
 * Arguments:
 * 0: something
 * 1: dik code
 * 2: something
 * 3: more something
 * 
 * Return Values:
 * None 
 *
 */

if (inputAction "LockTargets" > 0) then {
  if (BWA3_weaponRested) then {
    [] call BWA3_Resting_fnc_unRestWeapon;
  } else {
    [] call BWA3_Resting_fnc_restWeapon;
  };
};