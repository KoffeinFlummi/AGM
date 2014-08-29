/*
 * Author: KoffeinFlummi
 *
 * Adjusts the direction of a shell.
 *
 * Arguments:
 * -> arguments of the FiredBIS EH
 *
 * Return Value:
 * None
 */

private ["_unit", "_weaponType", "_ammoType", "_magazineType", "_round", "_FCSMagazines", "_FCSElevation", "_offset"];

_unit = _this select 0;
_weaponType = _this select 1;
_ammoType = _this select 4;
_magazineType = _this select 5;
_round = _this select 6;

_FCSMagazines = _unit getVariable "AGM_FCSMagazines";
_FCSElevation = _unit getVariable "AGM_FCSElevation";

if (player != gunner _unit) exitWith {};
if !(_magazineType in _FCSMagazines) exitWith {};

// GET ELEVATION OFFSET OF CURRENT MAGAZINE
_offset = 0;
{
  if (_x == _magazineType) exitWith {
    _offset = _FCSElevation select _forEachIndex;
  };
} forEach _FCSMagazines;

[_round, (_unit getVariable "AGM_FCSAzimuth"), _offset, 0] call AGM_Core_fnc_changeProjectileDirection;
