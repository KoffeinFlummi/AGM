/*
 * Author: KoffeinFlummi
 *
 * Start carrying the given unit.
 * 
 * Argument:
 * 0: Unit to be carried (Object)
 * 
 * Return value:
 * none
 */

#define CARRYINGMOVE "AcinPercMstpSrasWrflDnon"
#define CARRIEDMOVE "AinjPfalMstpSnonWnonDf_carried"

_this spawn {
  _unit = _this select 0;

  _unit setVariable ["BWA3_Treatable", false, true];
  player setVariable ["BWA3_Carrying", _unit, false];

  _unit attachTo [player, [0.1, -0.1, -1.25], "LeftShoulder"];
  _unit setDir 15;

  player playMoveNow "AcinPercMstpSrasWrflDnon";
  _unit playMoveNow "AinjPfalMstpSnonWnonDf_carried";
};