/*
 * Author: commy2
 *
 * Check what kind of weapon the given class name is. (primary, secondary or handgun)
 *
 * Argument:
 * 0: Class name of the weapon (String)
 *
 * Return value:
 * Slot index of the given class name, 1: primary, 2: secondary, 3: handgun, else: -1 (Number)
 */

private ["_weapon", "_type", "_index"];

_weapon = _this select 0;

_type = [getNumber (configFile >> "CfgWeapons" >> _weapon >> "type")] call AGM_Core_fnc_binarizeNumber;

_index = 0;
while {!(_type select _index) && {_index < 16}} do {
  _index = _index + 1;
};

switch (_index) do {
  case 0 : {1};
  case 1 : {3};
  case 2 : {2};
  default {-1};
}
