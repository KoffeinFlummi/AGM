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

#define BANDAGETIMEMEDIC 4
#define BANDAGETIMENONMEDIC 8
#define BANDAGEHEAL 0.55

_this spawn {
  _unit = _this select 0;
  _selection = _this select 1;

  // DETERMINE IF UNIT IS MEDIC
  _healtime = 0;
  if ([player] call BWA3_Medical_fnc_isMedic) then { // later
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

  _damage = ((_unit getHitPointDamage _selection) - 0.4) max 0;
  _unit setHitPointDamage [_selection, _damage];

  _fullyHealed = true;
  {
    if (_unit getHitPointDamage _x > 0.01) exitWith {_fullyHealed = false;};
  } forEach ["HitHead","HitBody","HitLeftShoulder","HitLeftArm","HitLeftForeArm","HitRightShoulder","HitRightArm","HitRightForeArm","HitLeftUpLeg","HitLeftLeg","HitLeftFoot","HitRightUpLeg","HitRightLeg","HitRightFoot"];
  if (_fullyHealed) then {
    _unit setDamage 0;
  };
};