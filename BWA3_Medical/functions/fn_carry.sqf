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
 *
 * !!! NEEDS TO BE CALLED USING spawn !!!
 */

private ["_unit"];

_unit = _this select 0;

_unit setVariable ["BWA3_Treatable", false, true];
player setVariable ["BWA3_Carrying", _unit, false];

#define CARRYINGMOVE "AcinPercMstpSnonWnonDnon"
#define CARRIEDMOVE "AinjPfalMstpSnonWnonDf_carried_dead"

player playMoveNow CARRYINGMOVE;
_unit playMoveNow CARRIEDMOVE;
waitUntil {animationState player == CARRYINGMOVE};

_unit attachTo [player, [0.1, -0.1, -1.25], "LeftShoulder"];
_unit setDir 15;