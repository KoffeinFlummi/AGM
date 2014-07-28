/*
 * Author: jodav
 *
 * removes the body
 *
 * Arguments:
 * The body
 *
 * Return Value:
 * None
 */

private ["_body", "_forceRemove", "_bodyRemoveTimer"];

_body = _this select 0;
_forceRemove = _this select 1;

_bodyRemoveTimer = 90;

if (AGM_Respawn_BodyRemoveTimer > 0) then {
  _bodyRemoveTimer = AGM_Respawn_BodyRemoveTimer;
};

// could be used for SpecOps missions.
if (_forceRemove) then {
  _bodyRemoveTimer = 2;
};

[_body, _bodyRemoveTimer] spawn {
  sleep (_this select 1);
  // hideBody takes ~20s till body is fully underground
  // a better hideBody would make this more aesthetic
  deleteVehicle (_this select 0);
};
