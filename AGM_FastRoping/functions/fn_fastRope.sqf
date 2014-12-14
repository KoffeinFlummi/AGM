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

#define ROPELENGTH 35

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
_unit disableCollisionWith _helper;

[time, _unit, _vehicle, _index, _rope1, _rope2, _helper] spawn {
  _time = _this select 0;
  _unit = _this select 1;
  _vehicle = _this select 2;
  _index = _this select 3;
  _rope1 = _this select 4;
  _rope2 = _this select 5;
  _helper = _this select 6;

  _unit allowDamage False;
  moveOut _unit;
  waitUntil {vehicle _unit == _unit};

  _helper setVectorUp [0,0,1];
  _unit attachTo [_helper, [0,0,0]];

  _vector = (getPos _unit) vectorFromTo (getPos _vehicle);
  _unit setVectorDir _vector;

  [[_rope1, _rope2], "{ropeUnwind [_this select 0, 6, 35];ropeUnwind [_this select 1, 6, 0];}", _helper] call AGM_Core_fnc_execRemoteFnc;

  sleep 0.1;
  _unit allowDamage True;
  _unit switchMove "AGM_FastRoping";

  sleep 2;
  waitUntil {(isTouchingGround _helper) or (time >= (_time + ROPELENGTH / 6)) or (vectorMagnitude (velocity _vehicle) > 5)};

  detach player;
  player switchMove "";
  player setVectorUp [0,0,1];

  [[_rope1, _rope2], "{ropeUnwind [_this select 0, 12, 2];ropeUnwind [_this select 1, 12, 33];}", _helper] call AGM_Core_fnc_execRemoteFnc;

  waitUntil {(ropeLength _rope1) < 2};

  _occupied = _vehicle getVariable "AGM_RopesOccupied";
  _occupied set [_index, False];
  _vehicle setVariable ["AGM_RopesOccupied", _occupied, True];
}
