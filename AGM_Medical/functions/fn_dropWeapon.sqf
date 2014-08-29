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

_magazineDetail = toArray (currentMagazineDetail player);
_index = (_magazineDetail find 40) + 1;
_end = _magazineDetail find 47;

_ammoCount = [];
while {_index < _end} do {
	_ammoCount pushBack (_magazineDetail select _index);
	_index = _index + 1;
};
_ammoCount = parseNumber toString _ammoCount;

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

