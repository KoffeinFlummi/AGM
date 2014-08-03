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

  if (vehicle _unit != _unit) exitWith {};

  [-2, {
    if (vehicle (_this select 0) == (_this select 0)) then {
      (_this select 0) switchMove DRAGGINGMOVE;
    };
    if ((_this select 1) getVariable "AGM_Unconscious") then {
      (_this select 1) switchMove DRAGGEDMOVE;
    };
  }, [player, _unit]] call CBA_fnc_globalExecute;

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
