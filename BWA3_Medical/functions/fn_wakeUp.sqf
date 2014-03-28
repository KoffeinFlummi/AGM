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

_unit enableSimulation true;

_unit enableAI "MOVE";
_unit enableAI "ANIM";
_unit enableAI "TARGET";
_unit enableAI "AUTOTARGET";
_unit enableAI "FSM";

[-2, {
  if (_this == player) then {
    [1, "BLACK", 1, 1] call BIS_fnc_FadeEffect;
  };
  _this switchMove "amovppnemstpsnonwnondnon";
}, _unit] call CBA_fnc_globalExecute;

_unit setPos _position;
if (captiveNum _unit == 213) then {
  _unit setCaptive false;
};