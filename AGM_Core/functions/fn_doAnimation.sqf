/*
 * Author: commy2
 *
 * Execute an animation. This is used to not break things like the unconsciousness animation.
 *
 * Argument:
 * 0: Unit (Object)
 * 1: Animation (String)
 * 2: Priority of the animation. (Number, optional default: 0)
 *     0: PlayMove
 *     1: PlayMoveNow
 *     2: SwitchMove (no transitional animation, doesn't overwrite priority 1)
 *
 * Return value:
 * Nothing
 */

private ["_unit", "_animation", "_priority"/*, "_force"*/];

_unit = _this select 0;
_animation = _this select 1;
_priority = _this select 2;
/*_force = False;

// no animation given
if (isNil "_animation") exitWith {
  diag_log format ["[AGM] ERROR: No animation specified in %1", _fnc_scriptNameParent];
};

if (isNil "_priority") then {
  _priority = 0;
};
if (count _this > 3) then {
  _force = _this select 3;
};

// don't overwrite more important animations
if (_unit getVariable ["AGM_isUnconscious", false] && {!_force}) exitWith {
  if (_animation != "Unconscious") then {
    [_unit, "Unconscious", 2] call AGM_Core_fnc_doAnimation;
  };
};

// don't go unconscious if the unit isn't unconscious
if (_animation == "Unconscious" && {!(_unit getVariable ["AGM_isUnconscious", false])}) exitWith {};*/

// switchMove "" no longer works in dev 1.37
if (_animation == "") then {
  _animation = [_unit] call AGM_Core_fnc_getDefaultAnim;
};

switch (_priority) do {
  case 0 : {
    if (_unit == vehicle _unit) then {
      [_unit, format ["{_this playMove '%1'}", _animation], _unit] call AGM_Core_fnc_execRemoteFnc;
    } else {
      // Execute on all machines. PlayMove and PlayMoveNow are bugged: They have no global effects when executed on remote machines inside vehicles.
      [_unit, format ["{_this playMove '%1'}", _animation]] call AGM_Core_fnc_execRemoteFnc;
    };
  };
  case 1 : {
    if (_unit == vehicle _unit) then {
      [_unit, format ["{_this playMoveNow '%1'}", _animation], _unit] call AGM_Core_fnc_execRemoteFnc;
    } else {
      // Execute on all machines. PlayMove and PlayMoveNow are bugged: They have no global effects when executed on remote machines inside vehicles.
      [_unit, format ["{_this playMoveNow '%1'}", _animation]] call AGM_Core_fnc_execRemoteFnc;
    };
  };
  case 2 : {
    // Execute on all machines. SwitchMove has local effects.
    [_unit, format ["{_this switchMove '%1'}", _animation]] call AGM_Core_fnc_execRemoteFnc;
  };
  default {};
};

["Anim", [_priority, _animation]] call AGM_Debug_fnc_log;
