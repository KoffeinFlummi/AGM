/*
Author: jodav

Description:
Restores previously saved gear

Arguments:
A player object, an array containing all gear

Return value:
An array containing all inventory items
*/

private ["_unit", "_allGear", "_headgear", "_goggles", "_uniform", "_uniformitems", "_vest", "_vestitems", "_backpack", "_backpackitems", "_primaryweapon", "_primaryweaponitems", "_primaryweaponmagazine", "_handgunweapon", "_handgunweaponitems", "_handgunweaponmagazine", "_assigneditems", "_binocular"];


_unit = _this select 0;
_allGear = _this select 1;

// remove all starting gear of a player
removeAllWeapons _unit;
removeGoggles _unit;
removeHeadgear _unit;
removeVest _unit;
removeUniform _unit;
removeAllAssignedItems _unit;
clearAllItemsFromBackpack _unit;
removeBackpack _unit;

_headgear = _allGear select 0;
_goggles = _allGear select 1;
_uniform = _allGear select 2;
_uniformitems = _allGear select 3;
_vest = _allGear select 4;
_vestitems = _allGear select 5;
_backpack = _allGear select 6;
_backpackitems = _allGear select 7;
_primaryweapon = _allGear select 8;
_primaryweaponitems = _allGear select 9;
_primaryweaponmagazine = _allGear select 10;
_secondaryweapon = _allGear select 11;
_secondaryweaponitems = _allGear select 12;
_secondaryweaponmagazine = _allGear select 13;
_handgunweapon = _allGear select 14;
_handgunweaponitems = _allGear select 15;
_handgunweaponmagazine = _allGear select 16;
_assigneditems = _allGear select 17;
_binocular = _allGear select 18;


// start restoring the items
if (_headgear != "") then {
  _unit addHeadgear _headgear;
};
if (_uniform != "") then {
  _unit forceAddUniform _uniform;
};
if (_vest != "") then {
  _unit addVest _vest;
};
if (_goggles != "") then {
  _unit addGoggles _goggles;
};

{
  _unit addItemToUniform _x;
}forEach _uniformitems;

{
  _unit addItemToVest _x;
}forEach _vestitems;


if(format["%1", _backpack] != "") then {
  _unit addBackpack _backpack;

  _backpa = unitBackpack _unit;
  clearMagazineCargoGlobal _backpa;
  clearWeaponCargoGlobal _backpa;
  clearItemCargoGlobal _backpa;
  {
    _unit addItemToBackpack _x;
  } forEach _backpackitems;
};


// primaryWeapon
if (_primaryweapon != "") then {
  {
    _unit addMagazine _x;
  } forEach _primaryweaponmagazine;

  _unit addWeapon _primaryweapon;

  {
    if (_x != "") then {
      _unit addPrimaryWeaponItem _x;
    };
  } forEach _primaryweaponitems;
};


// secondaryWeapon
if (_secondaryweapon != "") then {
  {
    _unit addMagazine _x;
  } forEach _secondaryweaponmagazine;

  _unit addWeapon _secondaryweapon;

  {
    if (_x != "") then {
      _unit addSecondaryWeaponItem _x;
    };
  } forEach _secondaryweaponitems;
};


// handgun
if (_handgunweapon != "") then {
  {
    _unit addMagazine _x;
  } forEach _handgunweaponmagazine;

  _unit addWeapon _handgunweapon;

  {
    if (_x != "") then {
      _unit addHandgunItem _x;
    };
  } forEach _handgunweaponitems;
};


_assignedItems = _assignedItems - [_binocular];

// items
{_unit linkItem _x} forEach _assignedItems;

_unit addWeapon _binocular;

if ("Laserdesignator" in assignedItems _unit) then {
  _unit selectWeapon "Laserdesignator";
  if (currentMagazine _unit == "") then {_unit addMagazine "Laserbatteries";};
};
