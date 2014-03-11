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

_this spawn {
  _unit = this select 0;
  _selection = this select 1;

  // DETERMINE IF UNIT IS MEDIC
  _healtime = 0;
  if ([_unit] call BWA3_Medical_isMedic) then { // later
    _healtime = BANDAGETIMEMEDIC;
  } else {
    _healtime = BANDAGETIMENONMEDIC;
  };

  player playMoveNow "AinvPknlMstpSnonWnonDnon_medic1"; // healing animation

  // START COUNTDOWN RSC (this is just a placeholder)
  _i = _healtime;
  while {_i > 0} do {
    hintSilent format ["Bandaging %1:\n%2", _selection, _i];
    _i = _i - 1;
    sleep 1;
  };
  hintSilent format ["Bandaging %1:\nDone", _selection];
  sleep 1;
  hintSilent "";
  // STOP COUNTDOWN RSC

  _damage = (_unit getHitPointDamage _selection - BANDAGEHEAL) max 0;
  _unit setHitPointDamage [_selection, _damage];
};