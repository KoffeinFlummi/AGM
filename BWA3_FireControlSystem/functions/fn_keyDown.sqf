/*
 * Author: KoffeinFlummi
 *
 * Starts watching the target for sideways correction.
 *
 * Arguments:
 * none
 *
 * Return Value:
 * none
 */

if ((_this select 1) != 15 or BWA3_FCSEnabled) exitWith {false};

_vehicle = vehicle player;

BWA3_FCSEnabled = true;
BWA3_FCSTime = time;
_distance = [5, 5000, 0] call BWA3_Core_fnc_getTargetDistance; // maximum distance: 5000m, 5m precision
_weaponDirection = _vehicle weaponDirection (currentWeapon _vehicle);
BWA3_FCSPosition = [
  (getPos _vehicle select 0) + _distance * (_weaponDirection select 0),
  (getPos _vehicle select 1) + _distance * (_weaponDirection select 1),
  (getPos _vehicle select 2) + _distance * (_weaponDirection select 2)
];

true