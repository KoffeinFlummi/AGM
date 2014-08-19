/*
 * Author: commy2
 *
 * Execute an animation. This is used to not break things like the unconsciousness animation.
 * 
 * Argument:
 * 0: Unit (Object)
 * 1: Animation (String)
 * 2: Priority of the animation. (Number, optional default: 0)
 * 		Mode 0: execute on this machine only
 * 		Mode 1: execute on server
 * 		Mode 2: execute on all clients + server
 * 
 * Return value:
 * Nothing
 */

private ["_unit", "_animation", "_priority"];

_unit = _this select 0;
_animation = _this select 1;
_priority = _this select 2;

if (isNil "_priority") then {
	_priority = 0;
};

// down overwrite more important animations
if (_unit getVariable ["AGM_Unconscious", false]) exitWith {};

switch (_priority) do {
	case 0 : {
		if (_unit == vehicle _unit) then {
			[_unit, format ["{_this playMove '%1'}", _animation], _unit] call AGM_Core_fnc_execRemoteFnc;
		} else {
			// execute on all machines. PlayMove and PlayMoveNow are bugged: They have no global effects when executed on remote machines inside vehicles
			[_unit, format ["{_this playMove '%1'}", _animation]] call AGM_Core_fnc_execRemoteFnc;
		};
	};
	case 1 : {
		if (_unit == vehicle _unit) then {
			[_unit, format ["{_this playMoveNow '%1'}", _animation], _unit] call AGM_Core_fnc_execRemoteFnc;
		} else {
			// execute on all machines. PlayMove and PlayMoveNow are bugged: They have no global effects when executed on remote machines inside vehicles
			[_unit, format ["{_this playMoveNow '%1'}", _animation]] call AGM_Core_fnc_execRemoteFnc;
		};
	};
	case 2 : {
		[_unit, format ["{_this switchMove '%1'}", _animation]] call AGM_Core_fnc_execRemoteFnc;
	};
	default {};
};
