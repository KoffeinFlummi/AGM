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

 player globalChat "key input detected";

if (inputAction "LockTargets" > 0) then {
  player globalChat "locktargets key detected";
  if (BWA3_weaponRested) then {
    player globalChat "resting weapon";
    [] call BWA3_Resting_fnc_unRestWeapon;
  } else {
    player globalChat "unresting weapon";
    [] call BWA3_Resting_fnc_restWeapon;
  };
};