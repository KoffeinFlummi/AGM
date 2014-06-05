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

[_unit] joinSilent (_unit getVariable ["AGM_Group", grpNull]);

[-2, {
  if (_this == player) then {
    AGM_UnconsciousCC ppEffectEnable false;
    AGM_UnconsciousCC ppEffectCommit 1;
    AGM_UnconsciousRB ppEffectEnable false;
    AGM_UnconsciousRB ppEffectCommit 1;
    3 fadeSound 1;
    3 fadeSpeech 1;
    player setVariable ["tf_globalVolume", 1];
    player setVariable ["tf_voiceVolume", 1, true];
    player setVariable ["tf_unable_to_use_radio", false, true];
  };
  if (local _this) then {
    _this enableSimulation true;
    _this setCaptive false;
  };
  _this switchMove "";
  _this switchMove "amovppnemstpsnonwnondnon";
}, _unit] call CBA_fnc_globalExecute;

_unit spawn {
  waitUntil {simulationEnabled _this};
  _this setPosASL (_this getVariable "AGM_Position");
};
_unit setCaptive false;