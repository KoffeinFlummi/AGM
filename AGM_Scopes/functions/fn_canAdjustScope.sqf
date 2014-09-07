/*
 * Author: KoffeinFlummi
 *
 * Checks if a player can adjust his optic in the given way.
 *
 * Arguments:
 * 0: Horizontal adjustment
 * 1: Vertical adjustment
 *
 * Return Value:
 * Can adjustment be done? (Bool)
 */

private ["_weapons", "_zeroing", "_optic", "_maxHorizontal", "_maxVertical"];

_weapons = [
  primaryWeapon player,
  secondaryWeapon player,
  handgunWeapon player
];

if !(currentWeapon player in _weapons) exitWith {false};

_zeroing = AGM_Scopes_Adjustment select (_weapons find (currentWeapon player));
_zeroX = (_zeroing select 0) + (_this select 0);
_zeroY = (_zeroing select 1) + (_this select 1);

_optic = AGM_Scopes_Optics select (_weapons find (currentWeapon player));
_maxHorizontal = getArray (configFile >> "CfgWeapons" >> _optic >> "AGM_ScopeAdjust_Horizontal");
_maxVertical = getArray (configFile >> "CfgWeapons" >> _optic >> "AGM_ScopeAdjust_Vertical");

if (_zeroX < _maxHorizontal select 0 or _zeroX > _maxHorizontal select 1) exitWith {false};
if (_zeroY < _maxVertical select 0 or _zeroY > _maxVertical select 1) exitWith {false};

alive player && (vehicle player == player)
