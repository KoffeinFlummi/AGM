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

private ["_body", "_forceRemove"];

_body = _this select 0;
_forceRemove = _this select 1;

bodyRemoveTimer = 90;

if (AGM_Respawn_BodyRemoveTimer > 0) then {
  bodyRemoveTimer = AGM_Respawn_BodyRemoveTimer;
};

// could be used for SpecOps missions.
if (_forceRemove) then {
  bodyRemoveTimer = 2;
};

_body spawn {
  sleep bodyRemoveTimer;
  // hideBody takes ~20s till body is fully underground
  // a better hideBody would make this more aesthetic
  deleteVehicle _this;
};
