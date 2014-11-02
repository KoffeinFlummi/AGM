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
_player = call AGM_Core_fnc_player;

// Hand it off to local unit
if !(local _unit) exitWith {
  [_this, "AGM_Medical_fnc_wakeUp", _unit] call AGM_Core_fnc_execRemoteFnc;
};

_unit enableAI "MOVE";
_unit enableAI "ANIM";
_unit enableAI "TARGET";
_unit enableAI "AUTOTARGET";
_unit enableAI "FSM";

_unit setVariable ["AGM_Unconscious", False, True]; // deprecated since 0.95
_unit setVariable ["AGM_isUnconscious", False, True];
_unit setVariable ["AGM_canTreat", True, True];

if (_unit == _player) then {
  _player setVariable ["tf_globalVolume", 1];
  _player setVariable ["tf_voiceVolume", 1, True];
  _player setVariable ["tf_unable_to_use_radio", False, True];

  _player setVariable ["acre_sys_core_isDisabled", False, True];
  _player setVariable ["acre_sys_core_globalVolume", 1];

  [False] call AGM_Core_fnc_disableUserInput;
};

[_unit, "AGM_Unconscious", False] call AGM_Core_fnc_setCaptivityStatus;

if !(scriptDone (_unit getVariable "AGM_WakeUpTimer")) then {
  terminate (_unit getVariable "AGM_WakeUpTimer");
};
if !(scriptDone (_unit getVariable "AGM_UnconsciousnessTimer")) then {
  terminate (_unit getVariable "AGM_UnconsciousnessTimer");
};

[_unit, _unit getVariable "AGM_OriginalAnim", 2, True] call AGM_Core_fnc_doAnimation;

[_unit, "AGM_Medical_wokeUp", [_unit]] call AGM_Core_fnc_callCustomEventHandlers;
