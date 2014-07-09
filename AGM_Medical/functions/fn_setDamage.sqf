/*
 * Author: KoffeinFlummi
 *
 * Sets the structural damage of a unit without altering the hitPoints.
 * THIS NEEDS TO BE CALLED FROM THE PC WHERE THE UNIT IS LOCAL.
 *
 * Arguments:
 * 0: Unit
 * 1: Damage
 *
 * Return Value:
 * None
 */

_unit = _this select 0;
_damage = _this select 1;

_hitPoints = [
  (_unit getHitPointDamage "HitHead"),
  (_unit getHitPointDamage "HitBody"),
  (_unit getHitPointDamage "HitLeftArm"),
  (_unit getHitPointDamage "HitRightArm"),
  (_unit getHitPointDamage "HitLeftLeg"),
  (_unit getHitPointDamage "HitRightLeg")
];

_unit setDamage _damage;

_unit setHitPointDamage ["HitHead", (_hitPoints select 0)];
_unit setHitPointDamage ["HitBody", (_hitPoints select 1)];
_unit setHitPointDamage ["HitLeftArm", (_hitPoints select 2)];
_unit setHitPointDamage ["HitRightArm", (_hitPoints select 3)];
_unit setHitPointDamage ["HitLeftLeg", (_hitPoints select 4)];
_unit setHitPointDamage ["HitRightLeg", (_hitPoints select 5)];
