/*
 * Author: KoffeinFlummi
 *
 * My very own setHitPointDamage since BIS's one is buggy when affecting a remote unit.
 * It also doesn't change the overall damage. This does.
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

if (local _unit) then {
  _selections = [
    "HitHead",
    "HitBody",
    "HitLeftArm",
    "HitRightArm",
    "HitLeftLeg",
    "HitRightLeg"
  ];

  if !(_selection in _selections) exitWith {
    _unit setHitPointDamage [_selection, _damage];
  };

  _damages = [
    (_unit getHitPointDamage "HitHead"), 
    (_unit getHitPointDamage "HitBody"),
    (_unit getHitPointDamage "HitLeftArm"), 
    (_unit getHitPointDamage "HitRightArm"),
    (_unit getHitPointDamage "HitLeftLeg"), 
    (_unit getHitPointDamage "HitRightLeg")
  ];

  _damageOld = damage _unit;
  _damageSumOld = 0;
  {
    _damageSumOld = _damageSumOld + _x;
  } forEach _damages;
  _damageSumOld = _damageSumOld max 0.001;

  {
    if (_x == _selection) then {
      _damages set [_forEachIndex, _damage];
    };
  } forEach _selections;

  _damageSumNew = 0;
  {
    _damageSumNew = _damageSumNew + _x;
  } forEach _damages;

  _damageNew = _damageOld * (_damageSumNew / _damageSumOld);
  diag_log _damageNew;

  if (_damageNew < _damageOld) then {_unit setDamage _damageNew;};
  {
    _unit setHitPointDamage [_x, (_damages select _forEachIndex)];
  } forEach _selections;
};

/*
if (local _unit) exitWith {
  _unit setHitPointDamage [_selection, _damage];
};
*/

[-2, {
  _unit = _this select 0;
  _selection = _this select 1;
  _damage = _this select 2;
  if (local _unit) then {
    _selections = [
      "HitHead",
      "HitBody",
      "HitLeftArm",
      "HitRightArm",
      "HitLeftLeg",
      "HitRightLeg"
    ];

    if !(_selection in _selections) exitWith {
      _unit setHitPointDamage [_selection, _damage];
    };

    _damages = [
      (_unit getHitPointDamage "HitHead"), 
      (_unit getHitPointDamage "HitBody"),
      (_unit getHitPointDamage "HitLeftArm"), 
      (_unit getHitPointDamage "HitRightArm"),
      (_unit getHitPointDamage "HitLeftLeg"), 
      (_unit getHitPointDamage "HitRightLeg")
    ];

    _damageOld = damage _unit;
    _damageSumOld = 0;
    {
      _damageSumOld = _damageSumOld + _x;
    } forEach _damages;
    _damageSumOld = _damageSumOld max 0.001;

    {
      if (_x == _selection) then {
        _damages set [_forEachIndex, _damage];
      };
    } forEach _selections;

    _damageSumNew = 0;
    {
      _damageSumNew = _damageSumNew + _x;
    } forEach _damages;

    _damageNew = _damageOld * (_damageSumNew / _damageSumOld);
    diag_log _damageNew;

    if (_damageNew < _damageOld) then {_unit setDamage _damageNew;};
    {
      _unit setHitPointDamage [_x, (_damages select _forEachIndex)];
    } forEach _selections;
  };
}, _this] call CBA_fnc_globalExecute;