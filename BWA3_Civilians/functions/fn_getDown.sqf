/*
 * Author: KoffeinFlummi
 * 
 * Forces a civilian to the ground. (chance of failure).
 * 
 * Arguments:
 * 0: Unit to be sent away (Object)
 *
 * Return value:
 * none
*/

#define DISTANCE 50

private ["_unit", "_chance", "_x"];

_unit = _this select 0;

player playActionNow "GestureGo"; // put something else here.

if (count (weapons player) > 0) then {
  _chance = 0.8;
} else {
  _chance = 0.5;
};

{
  if (count (weapons _unit) == 0 and random 1 < _chance) then {
    _x stop true;
    _x setUnitPos "DOWN";
  };
} foreach (_unit nearEntities ["Civilian", 10]);