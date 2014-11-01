// by commy2

private ["_unit", "_tube"];

_unit = _this select 0;
_tube = getText (configFile >> "CfgWeapons" >> _this select 1 >> "AGM_UsedTube");

if (_tube == "") exitWith {};

private "_items";

_items = secondaryWeaponItems _unit;

_unit addWeapon _tube;
_unit selectWeapon _tube;
{
  if (_x != "") then {_unit addSecondaryWeaponItem _x};
} forEach _items;
