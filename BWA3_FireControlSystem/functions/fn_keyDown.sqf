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
_key  = _this select 1;
_shft = [0, 1] select (_this select 2);
_ctrl = [0, 1] select (_this select 3);
_alt  = [0, 1] select (_this select 4);

_keyLase   = getNumber(configFile >> "BWA3_Realism_Keys" >> "BWA3_LaseTarget" >> "key");
_ctrlLase  = getNumber(configFile >> "BWA3_Realism_Keys" >> "BWA3_LaseTarget" >> "ctrl");
_altLase   = getNumber(configFile >> "BWA3_Realism_Keys" >> "BWA3_LaseTarget" >> "alt");
_shiftLase = getNumber(configFile >> "BWA3_Realism_Keys" >> "BWA3_LaseTarget" >> "shift");
if (_key != _keyLase or _ctrl != _ctrlLase or _shft != _shiftLase or _alt != _altLase) exitWith {false};
if (BWA3_FCSEnabled) exitWith {false};

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