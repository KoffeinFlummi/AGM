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
 */

#define DRAGGINGMOVE ""
#define DRAGGEDMOVE "Unconscious"

_this spawn {
  _unit = _this select 0;

  if isNull (player getVariable "BWA3_Carrying") then {
    _unit = player getVariable "BWA3_Dragging";

    _unit setVariable ["BWA3_Treatable", true, true];
    player setVariable ["BWA3_Dragging", objNull, false];
  } else {
    _unit = player getVariable "BWA3_Carrying";

    _unit setVariable ["BWA3_Treatable", true, true];
    player setVariable ["BWA3_Carrying", objNull, false];
  };

  detach _unit;

  [-2, {
    (_this select 0) switchMove DRAGGINGMOVE;
    (_this select 1) switchMove DRAGGEDMOVE;
  }, [player, _unit]] call CBA_fnc_globalExecute;

  player setVariable ["BWA3_CanTreat", true, false];

  _unit enableSimulation true;
  sleep 3.8;
  _unit enableSimulation false;
};