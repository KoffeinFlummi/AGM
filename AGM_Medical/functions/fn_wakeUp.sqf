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

_unit enableAI "MOVE";
_unit enableAI "ANIM";
_unit enableAI "TARGET";
_unit enableAI "AUTOTARGET";
_unit enableAI "FSM";

_unit setVariable ["AGM_Unconscious", false, true];
_unit setVariable ["AGM_CanTreat", true, true];

_position = getPosASL _unit;

[_unit] joinSilent (_unit getVariable ["AGM_Group", grpNull]);

[-2, {
  if (_this == player) then {
    player setVariable ["tf_globalVolume", 1];
    player setVariable ["tf_voiceVolume", 1, true];
    player setVariable ["tf_unable_to_use_radio", false, true];

    player setVariable ["acre_sys_core_isDisabled", false, true];
    player setVariable ["acre_sys_core_globalVolume", 1];

    [false] call AGM_Core_fnc_disableUserInput;
  };
  if (local _this) then {
    _this enableSimulation true;
    _this setCaptive false;
  };
  _this switchMove "";
  _this switchMove "amovppnemstpsnonwnondnon";
}, _unit] call CBA_fnc_globalExecute;

[_unit, _position] spawn {
  _unit = _this select 0;
  _position = _this select 1;
  waitUntil {simulationEnabled _unit};
  _unit setPosASL _position;
};
_unit setCaptive false;
