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

_this spawn {
  _unit = _this select 0;

  _unit setVariable ["AGM_Treatable", false, true];
  player setVariable ["AGM_Carrying", _unit, false];
  player setVariable ["AGM_CanTreat", false, false];

  // Everything but the rifle animation is fucked
  if (primaryWeapon player == "") then {
    player addWeapon "AGM_FakePrimaryWeapon";
  };
  player selectWeapon (primaryWeapon player);

  player playMoveNow "AcinPercMstpSnonWnonDnon";

  sleep 7;

  // Patient woke up while picking up, abandon ship.
  if !(_unit getVariable "AGM_Unconscious") exitWith {
    _unit setVariable ["AGM_Treatable", true, true];
    player setVariable ["AGM_Carrying", objNull, false];
    player setVariable ["AGM_CanTreat", true, false];
    player removeWeapon "AGM_FakePrimaryWeapon";
    [-2, {
      (_this select 0) switchMove "";
    }, [player]] call CBA_fnc_globalExecute;
  };

  _unit attachTo [player, [0.1, -0.1, -1.25], "LeftShoulder"];
  [-2, {
    _this setDir 15;
    _this setPos (getPos _this);
    _this switchMove "AinjPfalMstpSnonWnonDf_carried_dead";
  }, _unit] call CBA_fnc_globalExecute;

  waitUntil {sleep 0.5; vehicle player != player or isNull (player getVariable "AGM_Carrying") or !(alive player) or !(alive _unit) or (player getVariable "AGM_Unconscious") or !(_unit getVariable "AGM_Unconscious")};
  if (isNull (player getVariable "AGM_Carrying")) exitWith {};
  [player getVariable "AGM_Carrying"] call AGM_Medical_fnc_release;
};
