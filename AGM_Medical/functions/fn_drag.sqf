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

#define DRAGGINGACTION "grabDrag"
#define DRAGGEDMOVE "AinjPpneMrunSnonWnonDb_still"

_this spawn {
  _unit = _this select 0;

  _unit setVariable ["AGM_Treatable", false, true];
  player setVariable ["AGM_Dragging", _unit, false];
  player setVariable ["AGM_CanTreat", false, false];

  player playActionNow DRAGGINGACTION;

  sleep 1.8;

  _unit attachTo [player, [0, 1.1, 0.092]];
  [-2, {
    _this setDir 180;
    _this setPos (getPos _this);
    _this switchMove DRAGGEDMOVE;
  }, _unit] call CBA_fnc_globalExecute;

  waitUntil {sleep 1; vehicle player != player or isNull (player getVariable "AGM_Dragging") or damage player >= 1 or damage _unit >= 1};
  if (isNull (player getVariable "AGM_Dragging")) exitWith {};
  [(player getVariable "AGM_Dragging")] call AGM_Medical_fnc_release;
};