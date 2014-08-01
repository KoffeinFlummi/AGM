/*
Author: jodav

Description:
Restores previously saved gear

Arguments:
A player object, an array containing all gear

Return value:
An array containing all inventory items
*/

private ["_unit", "_allGear", "_headgear", "_goggles", "_uniform", "_uniformitems", "_vest", "_vestitems", "_backpack", "_backpackitems", "_primaryweapon", "_primaryweaponitems", "_primaryweaponmagazine", "_handgunweapon", "_handgunweaponitems", "_handgunweaponmagazine", "_assigneditems"];


_unit = _this select 0;
_allGear = _this select 1;

// remove all starting gear of a player
removeallweapons _unit;
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


// start restoring the items
_unit addHeadgear _headgear;
_unit addUniform _uniform;
_unit addVest _vest;
_unit addGoggles _goggles;

{
    _unit addItemToUniform _x;
}foreach _uniformitems;

{
    _unit addItemToVest _x;
}foreach _vestitems;


if(format["%1", _backpack] != "") then {
    _unit addbackpack _backpack;
    {
        _unit addItemToBackpack _x;
    } foreach _backpackitems;
};


// primaryWeapon
{
    _unit addMagazine _x;
} foreach _primaryweaponmagazine;

if (_primaryweapon != "") then {
    _unit addweapon _primaryweapon;
};

{
    _unit addPrimaryWeaponItem _x;
} foreach _primaryweaponitems;


// secondaryWeapon
{
    _unit addMagazine _x;
} foreach _secondaryweaponmagazine;

if (_secondaryweapon != "") then {
    _unit addweapon _secondaryweapon;
};

{
    _unit addSecondaryWeaponItem _x;
} foreach _secondaryweaponitems;


// handgun
{
    _unit addMagazine _x;
} foreach _handgunweaponmagazine;

if (_handgunweapon != "") then {
    _unit addweapon _handgunweapon;
};

{
    _unit addHandgunItem _x;
} foreach _handgunweaponitems;


// items
{
    _unit linkItem _x;
} foreach _assigneditems;
