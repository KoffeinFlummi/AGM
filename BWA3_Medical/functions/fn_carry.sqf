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

#define CARRYINGMOVE "AcinPercMstpSnonWnonDnon"
#define CARRIEDMOVE "AinjPfalMstpSnonWnonDf_carried_dead"

_this spawn {
  _unit = _this select 0;
  
  _unit setVariable ["BWA3_Treatable", false, true];
  player setVariable ["BWA3_Carrying", _unit, false];
  player setVariable ["BWA3_CanTreat", false, false];

  player playMoveNow CARRYINGMOVE;
  waitUntil {animationState player == CARRYINGMOVE};

  _unit attachTo [player, [0.1, -0.1, -1.25], "LeftShoulder"];
  _unit setDir 15;
  _unit setPos (getPos _unit); // force Arma to synchronize direction

  [-2, {
    _this switchMove CARRIEDMOVE;
  }, _unit] call CBA_fnc_globalExecute;

  waitUntil {sleep 1; vehicle player != player};
  if (isNull (player getVariable "BWA3_Carrying")) exitWith {};

  detach _unit;
  [-2, {
    _this switchMove "Unconscious";
  }, _unit] call CBA_fnc_globalExecute;

  _unit enableSimulation true;
  sleep 3.8;
  _unit enableSimulation false;
};