/*
By: KoffeinFlummi

Diagnoses a unit and make treatment options available.

Arguments:
0: Unit that is diagnosed (Object)

Return value:
none
*/

#define DIAGNOSEMOVE "AinvPknlMstpSnonWnonDnon_medic1"

_this spawn {
  _unit = _this select 0;

  player playMoveNow DIAGNOSEMOVE;

  // wait for animation to finish without using absolute times or event handlers
  waitUntil {sleep 0.5; animationState player == DIAGNOSEMOVE};
  waitUntil {sleep 0.5; animationState player != DIAGNOSEMOVE};

  // this is going to be replaced with some fancy UI at some point. maybe. possibly.
  _string = parseText format ["Hands: %1<br />Legs: %2<br />-----------<br />Head: %3<br />Body: %4<br />LeftShoulder: %5<br />LeftArm: %6<br />LeftForeArm: %7<br />RightShoulder: %8<br />RightArm: %9<br />RightForeArm: %10<br />LeftUpLeg: %11<br />LeftLeg: %12<br />LeftFoot: %13<br />RightUpLeg: %14<br />RightLeg: %15<br />RightFoot: %16<br />-----------<br />Total Damage: %17",
    floor ((_unit getHitPointDamage "HitHands") * 100) / 100,
    floor ((_unit getHitPointDamage "HitLegs") * 100) / 100,
    floor ((_unit getHitPointDamage "HitHead") * 100) / 100,
    floor ((_unit getHitPointDamage "HitBody") * 100) / 100,
    floor ((_unit getHitPointDamage "HitLeftShoulder") * 100) / 100,
    floor ((_unit getHitPointDamage "HitLeftArm") * 100) / 100,
    floor ((_unit getHitPointDamage "HitLeftForeArm") * 100) / 100,
    floor ((_unit getHitPointDamage "HitRightShoulder") * 100) / 100,
    floor ((_unit getHitPointDamage "HitRightArm") * 100) / 100,
    floor ((_unit getHitPointDamage "HitRightForeArm") * 100) / 100,
    floor ((_unit getHitPointDamage "HitLeftUpLeg") * 100) / 100,
    floor ((_unit getHitPointDamage "HitLeftLeg") * 100) / 100,
    floor ((_unit getHitPointDamage "HitLeftFoot") * 100) / 100,
    floor ((_unit getHitPointDamage "HitRightUpLeg") * 100) / 100,
    floor ((_unit getHitPointDamage "HitRightLeg") * 100) / 100,
    floor ((_unit getHitPointDamage "HitRightFoot") * 100) / 100,
    floor ((damage _unit) * 100) / 100
  ];

  hintSilent _string;
};