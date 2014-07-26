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

  _unit setVariable ["AGM_Treatable", false, true];
  player setVariable ["AGM_Dragging", _unit, false];
  player setVariable ["AGM_CanTreat", false, false];

  // Everything but the rifle animation is fucked
  if (primaryWeapon player == "") then {
    player addWeapon "AGM_FakePrimaryWeapon";
  };
  player selectWeapon (primaryWeapon player);

  player playMoveNow "AcinPknlMstpSrasWrflDnon";

  sleep 1.8;

  _unit attachTo [player, [0, 1.1, 0.092]];
  [-2, {
    _this setDir 180;
    _this setPos (getPos _this);
    _this switchMove "AinjPpneMrunSnonWnonDb_still";
  }, _unit] call CBA_fnc_globalExecute;

  waitUntil {sleep 0.5; vehicle player != player or isNull (player getVariable "AGM_Dragging") or !(alive player) or !(alive _unit) or (player getVariable "AGM_Unconscious") or !(_unit getVariable "AGM_Unconscious")};
  if (isNull (player getVariable "AGM_Dragging")) exitWith {};
  [player getVariable "AGM_Dragging"] call AGM_Medical_fnc_release;
};
