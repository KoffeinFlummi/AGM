// by commy2

private ["_unit", "_weapon", "_magazine"];

_unit = _this select 0;
_weapon = _this select 1;
_magazine = _this select 5;

if (_weapon != "Throw") exitWith {};

[_magazine, {_x == _magazine} count magazines _unit] call AGM_WeaponSelect_fnc_displayGrenadeTypeAndNumber;
