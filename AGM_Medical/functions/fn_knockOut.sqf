/*
 * By: KoffeinFlummi
 *
 * Knocks the given player out.
 *
 * Arguments:
 * 0: Unit to be knocked out
 * 1: Duration of knockout (optional)
 *    (if not set or set to -1, value depending on damage is chosen)
 *
 * Return Values:
 * None
 */

private ["_unit", "_duration", "_deadman", "_newGroup", "_wakeUpTimer", "_unconsciousnessTimer"];

_unit = _this select 0;
_duration = -1;
if (count _this > 1) then {
  _duration = _this select 1;
};

//if (_unit getVariable ["AGM_isCaptive", False]) exitWith {_unit setDamage 1};
if (_unit getVariable ["AGM_isUnconscious", False]) exitWith {};

// If an AI unit shoots a player, hand it off to him to calculate things.
// Puts less strain on the server.
if (!(local _unit) and ([_unit] call AGM_Core_fnc_isPlayer)) exitWith {
  [_this, "AGM_Medical_fnc_knockOut", _unit] call AGM_Core_fnc_execRemoteFnc;
};

if (!([_unit] call AGM_Core_fnc_isPlayer) && {vehicle _unit != _unit}) exitWith {};

_unit setVariable ["AGM_Unconscious", True, True]; // deprecated since 0.95
_unit setVariable ["AGM_isUnconscious", True, True];
_unit setVariable ["AGM_canTreat", False, True];

_unit setVariable ["tf_globalVolume", 0.4];
_unit setVariable ["tf_voiceVolume", 0, True];
_unit setVariable ["tf_unable_to_use_radio", True, True];

_unit setVariable ["acre_sys_core_isDisabled", True, True];
_unit setVariable ["acre_sys_core_globalVolume", 0.4];

if (_unit == AGM_player) then {
  if (visibleMap) then {openMap false};
  closeDialog 0;
  call AGM_Interaction_fnc_hideMenu;

  [True, True] call AGM_Core_fnc_disableUserInput;
};

[_unit, "AGM_Unconscious", True] call AGM_Core_fnc_setCaptivityStatus;

_unit disableAI "MOVE";
//_unit disableAI "ANIM";
_unit disableAI "TARGET";
_unit disableAI "AUTOTARGET";
_unit disableAI "FSM";
_unit disableConversation true;

if !(_unit getVariable ["AGM_NoRadio_isMuted", false]) then {
  [_unit] call AGM_Core_fnc_muteUnit;
};

// play appropriate anim
[[_unit], "AGM_Medical_fnc_animUnconscious", 2] call AGM_Core_fnc_execRemoteFnc;

// wake up unit after certain amount of time
if (_duration != -1 or _unit getVariable ["AGM_Medical_AutomaticWakeup", AGM_Medical_AutomaticWakeup]) then {
  _wakeUpTimer = [_unit, _duration] spawn {
    _unit = _this select 0;
    _duration = _this select 1;
    if (_duration != -1) then {
      sleep _duration;
    } else {
      sleep (60 * (1 + (random 8)) * ((damage _unit) max 0.5));
    };
    if (!isNull _unit && {alive _unit}) then {
      [_unit] call AGM_Medical_fnc_wakeUp;
    };
  };
};
_unit setVariable ["AGM_WakeUpTimer", _wakeUpTimer];

// kill unit if the max uncon. time module option is used
_unconsciousnessTimer = [_unit] spawn {
  _unit = _this select 0;
  if (_unit getVariable ["AGM_Medical_MaxUnconsciousnessTime", AGM_Medical_MaxUnconsciousnessTime] >= 0) then {
    sleep (_unit getVariable ["AGM_Medical_MaxUnconsciousnessTime", AGM_Medical_MaxUnconsciousnessTime]);
    if !(scriptDone (_unit getVariable "AGM_WakeUpTimer")) then {
      terminate (_unit getVariable "AGM_WakeUpTimer");
    };
    _unit setDamage 1;
  };
};
_unit setVariable ["AGM_UnconsciousnessTimer", _unconsciousnessTimer];

[_unit, "knockedOut", [_unit]] call AGM_Core_fnc_callCustomEventHandlersGlobal;
