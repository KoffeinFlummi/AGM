/*
 * By: KoffeinFlummi
 * 
 * Wakes an unconscious player up.
 * 
 * Arguments:
 * 0: Unconscious unit (Object)
 * 
 * Return Values:
 * None
 */

private ["_unit", "_position"];

_unit = _this select 0;
_position = getPos _unit;

_unit enableAI "MOVE";
_unit enableAI "ANIM";
_unit enableAI "TARGET";
_unit enableAI "AUTOTARGET";
_unit enableAI "FSM";

_unit setVariable ["AGM_Unconscious", false, true];
_unit setVariable ["AGM_CanTreat", true, true];

[_unit] joinSilent (_unit getVariable ["AGM_Group", grpNull]);

[-2, {
  if (_this == player) then {
    [1, "BLACK", 1, 1] call BIS_fnc_FadeEffect;
    4209 cutText ["", "PLAIN", 0, false];
  };
  if (local _this) then {
    _this enableSimulation true;
    _this setCaptive false;
  };
  _this switchMove "";
  _this switchMove "amovppnemstpsnonwnondnon";
}, _unit] call CBA_fnc_globalExecute;

_unit setPos _position;
_unit setCaptive false;