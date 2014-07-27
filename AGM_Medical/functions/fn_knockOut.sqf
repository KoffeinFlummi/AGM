/*
 * By: KoffeinFlummi
 *
 * Knocks the given player out by ragdollizing him and stopping all movement, thereby making it impossible to differentiate between a dead and unconcious player.
 *
 * Arguments:
 * 0: Unit to be knocked out (Object)
 *
 * Return Values:
 * None
 */

private ["_unit", "_newGroup"];

_unit = _this select 0;
_duration = -1;
if (count _this > 1) then {
  _duration = _this select 1;
};
if !(isPlayer _unit or _unit getVariable ["AGM_AllowUnconscious", false]) exitWith {_unit setDamage 1;};

_unit setVariable ["AGM_Unconscious", true, true];
_unit setVariable ["AGM_CanTreat", false, true];

if (_unit == player) then {
  player setVariable ["tf_globalVolume", 0.4];
  player setVariable ["tf_voiceVolume", 0, true];
  player setVariable ["tf_unable_to_use_radio", true, true];

  player setVariable ["acre_sys_core_isDisabled", true, true];
  player setVariable ["acre_sys_core_globalVolume", 0.4];

  [true, true] call AGM_Core_fnc_disableUserInput;
};

[_unit, "AGM_Unconscious", true] call AGM_Interaction_fnc_setCaptivityStatus;

_unit disableAI "MOVE";
_unit disableAI "ANIM";
_unit disableAI "TARGET";
_unit disableAI "AUTOTARGET";
_unit disableAI "FSM";

if (vehicle _unit != _unit && {animationState _unit != "Unconscious"}) then {   // don't lock into unconsciousness state after waking up
  _unit setVariable ["AGM_OriginalAnim", animationState _unit, true];
  [player, format ["{_this playMoveNow '%1'}", ((configfile >> 'CfgMovesMaleSdr' >> 'States' >> animationState _unit >> 'interpolateTo') call BIS_fnc_getCfgData) select 0], 2] call AGM_Core_fnc_execRemoteFnc;
} else {
  _unit setVariable ["AGM_OriginalAnim", "amovppnemstpsnonwnondnon", true];
};

_unit spawn {
  waitUntil {isTouchingGround _this};
  waitUntil {!([_this] call AGM_Core_fnc_inTransitionAnim)};
  _this playMoveNow "Unconscious";
};

_wakeUpTimer = [_unit, _duration] spawn {
  _unit = _this select 0;
  _duration = _this select 1;
  if (random 1 > 0.2 or _duration != -1) then {
    if (_duration != -1) then {
      sleep _duration;
    } else {
      sleep (60 * (1 + (random 8)) * ((damage _unit) max 0.3));
    };
    [_unit] call AGM_Medical_fnc_wakeUp;
  };
};
_unit setVariable ["AGM_WakeUpTimer", _wakeUpTimer];

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
