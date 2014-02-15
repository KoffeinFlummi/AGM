/*
 * Author: KoffeinFlummi
 *
 * Releases the given unit.
 * 
 * Argument:
 * 0: Unit to be released (Object)
 * 
 * Return value:
 * none
 *
 * !!! NEEDS TO BE CALLED USING SPAWN !!!
 */

private ["_unit"];

if !(player getVariable "BWA3_Carrying") then {
  _unit = player getVariable "BWA3_Dragging";

  _unit setVariable ["BWA3_Treatable", true, true];
  player setVariable ["BWA3_Dragging", false, false];

  #define DRAGGINGMOVE "AcinPknlMstpSnonWnonDnon_AmovPknlMstpSnonWnonDnon"
  #define DRAGGEDMOVE "Static_Dead"

  detach _unit;

  player playMoveNow DRAGGINGMOVE;
  waitUntil {animationState player == DRAGGINGMOVE};

  _unit switchMove DRAGGEDMOVE;
} else {
  _unit = player getVariable "BWA3_Carrying";

  _unit setVariable ["BWA3_Treatable", true, true];
  player setVariable ["BWA3_Carrying", false, false];

  #define CARRYINGMOVE "AidlPercMstpSrasWrflDnon_G01_player"
  #define CARRIEDMOVE1 "AinjPfalMstpSnonWnonDnon_carried_Down"
  #define CARRIEDMOVE2 "Static_Dead";

  detach _unit;

  player playMoveNow CARRYINGMOVE;
  waitUntil {animationState player == CARRYINGMOVE};

  _unit switchMove CARRIEDMOVE1;
  _unit playMove CARRIEDMOVE2;
};