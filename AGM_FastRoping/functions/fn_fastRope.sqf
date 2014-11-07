/*
 * Author: KoffeinFlummi
 *
 * Starts fast roping for a certain unit
 *
 * Arguments:
 * 0: Unit
 * 1: Helicopter
 *
 * Return Value:
 * None
 */

#define ROPELENGTH 40
#define SPEED 4

_unit = _this select 0;
_vehicle = _this select 1;

_ropes = _vehicle getVariable "AGM_Ropes";
_occupied = _vehicle getVariable "AGM_RopesOccupied";

_index = -1;
for "_i" from 0 to ((count _occupied) - 1) do {
  if !(_occupied select _i) exitWith {
    _index = _i;
  };
};

_occupied set [_index, True];
_vehicle setVariable ["AGM_RopesOccupied", _occupied, True];

_rope = _ropes select _index;
_rope1 = _rope select 0;
_rope2 = _rope select 1;
_helper = _rope select 2;
player disableCollisionWith _helper;

_unit setPos [0,0,0];
_unit allowDamage False;
_helper setVectorUp [0,0,1];
_unit attachTo [_helper, [0,0,-1.35]];

ropeUnwind [_rope1, SPEED, ROPELENGTH];
ropeUnwind [_rope2, SPEED, 0];

[time, _unit, _vehicle, _index, _rope1, _rope2, _helper] spawn {
  _time = _this select 0;
  _unit = _this select 1;
  _vehicle = _this select 2;
  _index = _this select 3;
  _rope1 = _this select 4;
  _rope2 = _this select 5;
  _helper = _this select 6;

  sleep 0.1;
  _unit allowDamage True;
  _unit switchMove "AGM_FastRoping";

  sleep 2;
  waitUntil {(isTouchingGround _helper) or (time >= (_time + ROPELENGTH / SPEED))};
  detach player;
  player switchMove "";

  ropeUnwind [_rope1, 999999, 2.5];
  ropeUnwind [_rope2, 999999, ROPELENGTH - 2.5];

  _occupied = _vehicle getVariable "AGM_RopesOccupied";
  _occupied set [_index, False];
  _vehicle setVariable ["AGM_RopesOccupied", _occupied, True];
}
