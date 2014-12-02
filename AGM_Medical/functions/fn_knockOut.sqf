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

if (_unit getVariable ["AGM_isUnconscious", False]) exitWith {};

// If an AI unit shoots a player, hand it off to him to calculate things.
// Puts less strain on the server.
if (!(local _unit) and ([_unit] call AGM_Core_fnc_isPlayer)) exitWith {
  [_this, "AGM_Medical_fnc_knockOut", _unit] call AGM_Core_fnc_execRemoteFnc;
};

_unit setVariable ["AGM_Unconscious", True, True]; // deprecated since 0.95
_unit setVariable ["AGM_isUnconscious", True, True];
_unit setVariable ["AGM_canTreat", False, True];

if (_unit == player) then {
  player setVariable ["tf_globalVolume", 0.4];
  player setVariable ["tf_voiceVolume", 0, True];
  player setVariable ["tf_unable_to_use_radio", True, True];

  player setVariable ["acre_sys_core_isDisabled", True, True];
  player setVariable ["acre_sys_core_globalVolume", 0.4];

  if (visibleMap) then {openMap false};
  closeDialog 0;
  call AGM_Interaction_fnc_hideMenu;

  [True, True] call AGM_Core_fnc_disableUserInput;
};

[_unit, "AGM_Unconscious", True] call AGM_Core_fnc_setCaptivityStatus;

_unit disableAI "MOVE";
_unit disableAI "ANIM";
_unit disableAI "TARGET";
_unit disableAI "AUTOTARGET";
_unit disableAI "FSM";

// play appropriate anim
if (vehicle _unit != _unit) then {
  _unit setVariable ["AGM_OriginalAnim", animationState _unit, True];
  [
    _player,
    ((configFile >> "CfgMovesMaleSdr" >> "States" >> animationState _unit >> "interpolateTo") call BIS_fnc_getCfgData) select 0,
    1,
    True
  ] call AGM_Core_fnc_doAnimation;
} else {
  _unit setVariable ["AGM_OriginalAnim", "AmovPpneMstpSnonWnonDnon", True];
  _unit spawn {
    waitUntil {isTouchingGround _this};
    waitUntil {!([_this] call AGM_Core_fnc_inTransitionAnim)};
    [_this, "Unconscious", 1, True] call AGM_Core_fnc_doAnimation;
    sleep 2;
    if (animationState _this != "Unconscious") then {
      [_this, "Unconscious", 2, True] call AGM_Core_fnc_doAnimation;
    };
  };
};

// wake up unit after certain amount of time
_wakeUpTimer = [_unit, _duration] spawn {};
if (_unit getVariable ["AGM_Medical_AutomaticWakeup", AGM_Medical_AutomaticWakeup > 0]) then {
  _wakeUpTimer = [_unit, _duration] spawn {
    _unit = _this select 0;
    _duration = _this select 1;
    if (_duration != -1) then {
      sleep _duration;
    } else {
      sleep (60 * (1 + (random 8)) * ((damage _unit) max 0.5));
    };
    [_unit] call AGM_Medical_fnc_wakeUp;
  };
};
_unit setVariable ["AGM_WakeUpTimer", _wakeUpTimer];

// kill unit if the max uncon. time module option is used
_unconsciousnessTimer = [_unit] spawn {
  _unit = _this select 0;
  if (AGM_Medical_MaxUnconsciousnessTime >= 0) then {
    sleep AGM_Medical_MaxUnconsciousnessTime;
    if !(scriptDone (_unit getVariable "AGM_WakeUpTimer")) then {
      terminate (_unit getVariable "AGM_WakeUpTimer");
    };
    _unit setDamage 1;
  };
};
_unit setVariable ["AGM_UnconsciousnessTimer", _unconsciousnessTimer];

[_unit, "AGM_knockedOut", [_unit]] call AGM_Core_fnc_callCustomEventHandlers;
