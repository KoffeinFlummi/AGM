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

  #define DRAGGINGMOVE "AcinPknlMstpSrasWrflDnon"
  #define DRAGGEDMOVE "AinjPpneMrunSnonWnonDb_grab"

  player playMoveNow DRAGGINGMOVE;
  waitUntil {animationState player == DRAGGINGMOVE};

  _unit attachTo [player, [0, 1.1, 0.092]];
  _unit setDir 180;

  _unit playMoveNow DRAGGEDMOVE;
};