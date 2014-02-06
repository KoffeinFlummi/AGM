/*
 * Author: KoffeinFlummi
 *
 * Bandage the given unit.
 * 
 * Argument:
 * 0: Unit to be bandaged (Object)
 * 1: HitPoint to be healed (String; Example: "HitLeftShoulder")
 * 
 * Return value:
 * none
 */

#define BANDAGETIMEMEDIC 10
#define BANDAGETIMENONMEDIC 20
#define BANDAGEHEAL 0.3

private ["_unit", "_selection", "_healtime", "_damage", "_i"];

_unit = this select 0;
_selection = this select 1;

// DETERMINE IF UNIT IS MEDIC
if (true) then { // later
  _healtime = BANDAGETIMEMEDIC;
} else {
  _healtime = BANDAGETIMENONMEDIC;
};

player switchMove "Acts_TreatingWounded03"; // healing animation

// START COUNTDOWN RSC

//sleep _healtime;
_i = _healtime;
while {_i > 0} do {
  hint format ["%1", _i];
  _i = _i - 1;
  sleep 1;
};

// STOP COUNTDOWN RSC

_damage = _unit getHitPointDamage _selection - BANDAGEHEAL;
if (_damage < 0) then {_damage = 0;};
_unit setHitPointDamage [_selection, _damage];

player switchMove "AidlPknlMstpSlowWrflDnon_G01_combat";