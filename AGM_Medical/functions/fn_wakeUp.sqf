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
    [_this, "AGM_Unconscious", false] call AGM_Interaction_fnc_setCaptivityStatus;
    if !(scriptDone (_this getVariable "AGM_WakeUpTimer")) then {
      terminate (_this getVariable "AGM_WakeUpTimer");
    };
    if !(scriptDone (_this getVariable "AGM_UnconsciousnessTimer")) then {
      terminate (_this getVariable "AGM_UnconsciousnessTimer");
    };
  };

  _this switchMove "";
  _this switchMove (_this getVariable "AGM_OriginalAnim");
}, _unit] call CBA_fnc_globalExecute;
