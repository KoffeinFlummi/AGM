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

  player removeWeapon "AGM_FakePrimaryWeapon";

  if isNull (player getVariable "AGM_Carrying") then {
    _unit = player getVariable "AGM_Dragging";

    _unit setVariable ["AGM_Treatable", true, true];
    player setVariable ["AGM_Dragging", objNull, false];
  } else {
    _unit = player getVariable "AGM_Carrying";

    _unit setVariable ["AGM_Treatable", true, true];
    player setVariable ["AGM_Carrying", objNull, false];
  };

  detach _unit;
  player setVariable ["AGM_CanTreat", true, false];

  player removeAction (player getVariable "AGM_Medical_ReleaseID");

  if (vehicle _unit != _unit) exitWith {};

  if (vehicle player == player) then {
    [player, DRAGGINGMOVE, 2] call AGM_Core_fnc_doAnimation;
  };
  if (_unit getVariable "AGM_Unconscious") {
    [_unit, DRAGGEDMOVE, 2] call AGM_Core_fnc_doAnimation;
  };

  /*[-2, {
    if (local _this) then {
      _this spawn {
        _this enableSimulation true;
        sleep 3.8;
        if (_this getVariable "AGM_Unconscious") then {
          _this enableSimulation false;
        };
      };
    };
  }, _unit] call CBA_fnc_globalExecute;*/
};
