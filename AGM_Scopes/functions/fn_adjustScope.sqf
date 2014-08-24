/*
 * Author: KoffeinFlummi
 *
 * Changes the adjustment for the current scope
 *
 * Arguments:
 * 0: Horizontal adjustment
 * 1: Vertical adjustment
 *
 * Return Value:
 * True
 */

_weapons = [
  primaryWeapon player,
  secondaryWeapon player,
  handgunWeapon player;
];

_zeroing = AGM_Scopes_Adjustment select (_weapons find (currentWeapon player));
_zeroing set [0, (_zeroing select 0) + (_this select 0)];
_zeroing set [1, (_zeroing select 1) + (_this select 1)];

AGM_Scopes_Adjustment set [_weapons find (currentWeapon player), _zeroing];

_hint = "Current Zeroing: ";
if (_zeroing select 0 < 0) then {
  _hint = _hint + format ["%1 Right", _zeroing select 0];
} else {
  _hint = _hint + format ["%1 Left", -1 * _zeroing select 0];
};
_hint = _hint + ", ";
if (_zeroing select 1 < 0) then {
  _hint = _hint + format ["%1 Up", _zeroing select 1];
} else {
  _hint = _hint + format ["%1 Down", -1 * _zeroing select 1];
};

hintSilent _hint;

true
