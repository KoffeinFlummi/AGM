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

if (player getVariable "AGM_Unconscious") exitWith {false};

if (inputAction "LockTargets" > 0 and currentWeapon player == primaryWeapon player) then {
  if (AGM_weaponRested) then {
    [] call AGM_Resting_fnc_unRestWeapon;
  } else {
    [] call AGM_Resting_fnc_restWeapon;
  };
  true
} else {
  false
};