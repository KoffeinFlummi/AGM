/*
By: KoffeinFlummi

Diagnoses a unit and make treatment options available.

Arguments:
0: Unit that is diagnosed (Object)

Return value:
none
*/

_unit = _this select 0;

_string = "Hands: " + str(floor ((_unit getHitPointDamage "HitHands") * 100) / 100) + "\n" +
          "Legs: " + str(floor ((_unit getHitPointDamage "HitLegs") * 100) / 100) + "\n" +
          "---------------\n" +
          "Head: " + str(floor ((_unit getHitPointDamage "HitHead") * 100) / 100) + "\n" +
          "Body: " + str(floor ((_unit getHitPointDamage "HitBody") * 100) / 100) + "\n" +
          "LeftShoulder: " + str(floor ((_unit getHitPointDamage "HitLeftShoulder") * 100) / 100) + "\n" +
          "LeftArm: " + str(floor ((_unit getHitPointDamage "HitLeftArm") * 100) / 100) + "\n" +
          "LeftForeArm: " + str(floor ((_unit getHitPointDamage "HitLeftForeArm") * 100) / 100) + "\n" +
          "RightShoulder: " + str(floor ((_unit getHitPointDamage "HitRightShoulder") * 100) / 100) + "\n" +
          "RightArm: " + str(floor ((_unit getHitPointDamage "HitRightArm") * 100) / 100) + "\n" +
          "RightForeArm: " + str(floor ((_unit getHitPointDamage "HitRightForeArm") * 100) / 100) + "\n" +
          "LeftUpLeg: " + str(floor ((_unit getHitPointDamage "HitLeftUpLeg") * 100) / 100) + "\n" +
          "LeftLeg: " + str(floor ((_unit getHitPointDamage "HitLeftLeg") * 100) / 100) + "\n" +
          "LeftFoot: " + str(floor ((_unit getHitPointDamage "HitLeftFoot") * 100) / 100) + "\n" +
          "RightUpLeg: " + str(floor ((_unit getHitPointDamage "HitRightUpLeg") * 100) / 100) + "\n" +
          "RightLeg: " + str(floor ((_unit getHitPointDamage "HitRightLeg") * 100) / 100) + "\n" +
          "RightFoot: " + str(floor ((_unit getHitPointDamage "HitRightFoot") * 100) / 100) + "\n" +
          "---------------\n" +
          "Damage: " + str(damage _unit);

hintSilent _string;