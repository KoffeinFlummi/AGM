/*
 * Author: commy2
 *
 * Execute a function on a remote machine in mp.
 * 
 * Argument:
 * 0: Function arguments (Array)
 * 1: Function to execute, has to be defined on the remote machine first (String)
 * 2: The function will be executed where this unit is local. If none then execute on all machines. (optional, Object)
 * 
 * Return value:
 * Nothing
 */

private ["_arguments", "_function", "_unit", "_ownerID"];

AGM_Core_remoteFnc = + _this;

_this resize 3;

_arguments = _this select 0;
_function = call compile (_this select 1);
_unit = _this select 2;

if (isNil "_unit") exitWith {
	_arguments call _function;
	publicVariable "AGM_Core_remoteFnc";
};

if (local _unit) then {
	_arguments call _function;
} else {
	if (isServer) then {
		_ownerID = owner _unit;
		_ownerID publicVariableClient "AGM_Core_remoteFnc";
	} else {
		publicVariableServer "AGM_Core_remoteFnc";
	};
};
