/*
 * Author: KoffeinFlummi
 * 
 * Sends a civilian crowd away (chance of failure).
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

player playActionNow "GestureGo";

if (count (weapons player) > 0) then {
  _chance = 0.8;
} else {
  _chance = 0.5;
};

{
  if (count (weapons _unit) == 0 and random 1 < _chance) then {
    _x doMove [(getPos _x select 0) + DISTANCE * (eyeDirection player select 0), (getPos _x select 1) + DISTANCE * (eyeDirection player select 1), 0];
  };
} foreach (_unit nearEntities ["Civilian", 10]);