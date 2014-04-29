/*
 * Author: KoffeinFlummi
 *
 * Weapon Resting Initialization
 *
 */

AGM_weaponRested = false;
AGM_restedPosition = [0,0,0];

0 spawn {
  waituntil {!isNull (findDisplay 46)};
  (findDisplay 46) displayAddEventHandler ["KeyDown", {_this call AGM_Resting_fnc_keyInput;}];
};