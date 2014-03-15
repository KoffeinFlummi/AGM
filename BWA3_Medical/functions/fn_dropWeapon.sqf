/*
 * Author: KoffeinFlummi
 *
 * Drops the current weapon of a given unit
 *
 * Arguments:
 * 0: Unit to drop his weapon (Object)
 *
 * Return Value:
 * none
 */

private ["_unit", "_weapon", "_attachments", "_dropHelper"];

_unit = _this select 0;
_weapon = currentWeapon _unit;
_magazine = currentMagazine _unit;

if (_weapon == "") exitWith {};

_array = toArray (currentMagazineDetail player);
_string = "";
_i = _array find 40;
while {_i < (_array find 47)} do {
  _string = _string + toString([_array select _i]);
  _i = _i + 1;
};
_ammoCount = parseNumber _string;

if (_weapon == primaryWeapon _unit) then {
  _attachments = primaryWeaponItems _unit;
};
if (_weapon == secondaryWeapon _unit) then {
  _attachments = secondaryWeaponItems _unit;
};
if (_weapon == handgunWeapon _unit) then {
  _attachments = handgunItems _unit;
};

_unit removeWeapon _weapon;

_dropHelper = (createGroup (side _unit)) createUnit [(typeOf _unit), getPos _unit, [], 0, "FORM"];
_dropHelper setPos (getPos _unit);

removeAllWeapons _dropHelper;
removeBackpack _dropHelper;
_dropHelper addBackpack "B_Kitbag_rgr";
_dropHelper addMagazine [_magazine, _ammoCount];
_dropHelper addWeapon _weapon;

//removeUniform _dropHelper;
//removeVest _dropHelper;
removeBackpack _dropHelper;
removeGoggles _dropHelper;
removeHeadgear _dropHelper;
removeAllAssignedItems _dropHelper;

if (_weapon == primaryWeapon _unit) then {
  {_dropHelper addPrimaryWeaponItem _x} forEach _attachments;
};
if (_weapon == secondaryWeapon _unit) then {
  {_dropHelper addsecondaryWeaponItem _x} forEach _attachments;
};
if (_weapon == handgunWeapon _unit) then {
  {_dropHelper addhandgunItem _x} forEach _attachments;
};

_dropHelper setHitPointDamage ["HitHead", 1];
//hideObject _dropHelper;