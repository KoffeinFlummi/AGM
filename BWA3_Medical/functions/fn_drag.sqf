/*
 * Author: KoffeinFlummi
 *
 * Start dragging the given unit.
 * 
 * Argument:
 * 0: Unit to be dragged (Object)
 * 
 * Return value:
 * none
 */

_this spawn {
  _unit = _this select 0;

  _unit setVariable ["BWA3_Treatable", false, true];
  player setVariable ["BWA3_Dragging", _unit, false];
  player setVariable ["BWA3_CanTreat", false, false];

  #define DRAGGINGMOVE "AcinPknlMstpSrasWrflDnon"
  #define DRAGGEDMOVE "AinjPpneMrunSnonWnonDb_grab"

  player playMoveNow DRAGGINGMOVE;
  waitUntil {animationState player == DRAGGINGMOVE};

  _unit attachTo [player, [0, 1.1, 0.092]];
  _unit setDir 180;

  _unit playMoveNow DRAGGEDMOVE;

  waitUntil {sleep 1; vehicle player != player};
  if (isNull (player getVariable "BWA3_Dragging")) exitWith {};

  detach _unit;
  [-2, {
    _this switchMove "Unconscious";
  }, _unit] call CBA_fnc_globalExecute;
};