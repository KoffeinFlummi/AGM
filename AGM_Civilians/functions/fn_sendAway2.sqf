// by commy2

#define DISTANCE 50
#define RADIUS 10

private ["_unit", "_chance", "_x"];

_unit = _this select 0;

player playActionNow "GestureGo";

_chance = [0.5, 0.8] select (count (weapons player) > 0);

_position = getPosATL _unit;
_direction = eyeDirection player;

_unit setUnitPos "AUTO";
_unit doMove [
	(_position select 0) + DISTANCE * (_direction select 0),
	(_position select 1) + DISTANCE * (_direction select 1),
	0
];




{
  if (count (weapons _unit) == 0 and random 1 < _chance) then {
    [[_x, player], "AGM_sendAway", true, false] spawn BIS_fnc_MP;
  };
} foreach (_unit nearEntities ["Civilian", RADIUS]);




//cursorTarget setCaptive 1; cursorTarget playMoveNow "AmovPercMstpSsurWnonDnon"
