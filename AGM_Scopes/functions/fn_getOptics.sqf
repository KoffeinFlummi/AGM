/*
 * Author: KoffeinFlummi
 *
 * Gets the optic classnames of all currently equipped weapons.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * [optic of primary, optic of secondary, optic of handgun]
 */

private ["_array"];

_array = [
  [primaryWeaponItems player, {getNumber (configFile >> "CfgWeapon" >> _this >> "ItemInfo" >> "type") == 201}] call AGM_Core_fnc_filter,
  [secondaryWeaponItems player, {getNumber (configFile >> "CfgWeapon" >> _this >> "ItemInfo" >> "type") == 201}] call AGM_Core_fnc_filter,
  [handgunItems player, {getNumber (configFile >> "CfgWeapon" >> _this >> "ItemInfo" >> "type") == 201}] call AGM_Core_fnc_filter
],

[_array, {if (count _this > 0) then {_this select 0} else {""}}] call AGM_Core_fnc_map
