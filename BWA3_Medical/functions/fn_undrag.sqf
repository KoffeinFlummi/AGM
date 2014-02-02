/*
 * Author: KoffeinFlummi
 *
 * Start dragging the given unit.
 * 
 * Argument:
 * none
 * 
 * Return value:
 * none
 */

private ["_unit"];

_unit = player getVariable "BWA3_Dragging";

_unit setVariable ["BWA3_Treatable", true, true];
player setVariable ["BWA3_Dragging", Null, false];

#define DRAGGINGMOVE "AmovPknlMstpSrasWrflDnon"
#define DRAGGEDMOVE "AinjPpneMstpSnonWrflDnon"

detach _unit;

player playMoveNow DRAGGINGMOVE;
waitUntil {animationState player == DRAGGINGMOVE};

_unit switchMove DRAGGEDMOVE;