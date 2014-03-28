/*
 * Author: KoffeinFlummi
 *
 * My very own setHitPointDamage since BIS's one is buggy when affecting a remote unit.
 *
 * Arguments:
 * 0: Unit
 * 1: Selection
 * 2: damage
 *
 * Return Value:
 * -
 */

_unit = _this select 0;
_selection = _this select 1;
_damage = _this select 2;

if (local _unit) exitWith {
  _unit setHitPointDamage [_selection, _damage];
};


[-2, {

  _unit = _this select 0;
  _selection = _this select 1;
  _damage = _this select 2;
  if (local _unit) then {
    _unit setHitPointDamage [_selection, _damage];
  };

}, [_this]] call CBA_fnc_globalExecute;