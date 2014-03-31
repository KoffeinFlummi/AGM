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

#define DRAGGINGMOVE "AcinPknlMstpSrasWrflDnon"
#define DRAGGEDMOVE "AinjPpneMrunSnonWnonDb_still"

_this spawn {
  _unit = _this select 0;

  _unit setVariable ["BWA3_Treatable", false, true];
  player setVariable ["BWA3_Dragging", _unit, false];
  player setVariable ["BWA3_CanTreat", false, false];

  player playMoveNow DRAGGINGMOVE;
  waitUntil {animationState player == DRAGGINGMOVE};

  _unit attachTo [player, [0, 1.1, 0.092]];
  [-2, {
    _this setDir 180;
  }, _unit] call CBA_fnc_globalExecute;
  _unit setPos (getPos _unit); // force Arma to synchronize direction

  [-2, {
    _this switchMove DRAGGEDMOVE;
  }, _unit] call CBA_fnc_globalExecute;

  waitUntil {sleep 1; vehicle player != player or isNull (player getVariable "BWA3_Dragging") or damage player >= 1 or damage _unit >= 1};
  if (isNull (player getVariable "BWA3_Dragging")) exitWith {};

  detach _unit;
  [-2, {
    _this switchMove "Unconscious";
  }, _unit] call CBA_fnc_globalExecute;

  if (vehicle player == player) then {
    [-2, {
      _this switchMove "";
    }, player] call CBA_fnc_globalExecute;
  };

  _unit setVariable ["BWA3_Treatable", true, true];

  [-2, {
    if (local _this) then {
      0 spawn {
        _this enableSimulation true;
        sleep 3.8;
        _this enableSimulation false;
      };
    };
  }, _unit] call CBA_fnc_globalExecute;
};