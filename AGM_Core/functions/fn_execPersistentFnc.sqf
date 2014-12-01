/*
 * Author: commy2
 *
 * Execute a function on every machine. Function will also be called upon JIP (postInit).
 *
 * Argument:
 * 0: Function arguments (Array)
 * 1: Function to execute, has to be defined on the remote machine first (String)
 * 2: ID. Used to overwrite a previously set function (Number, optional default: -1)
 *
 * Return value:
 * ID. Used to overwrite the saved function later, so JIP will only recieve the updated version.
 */

private ["_arguments", "_function", "_id"];

AGM_Core_remoteFnc = _this;

_arguments = _this select 0;
_function = call compile (_this select 1);
_id = _this select 2;

// execute function on every machine
_arguments call _function;

AGM_Core_remoteFnc set [2, 0];
publicVariable "AGM_Core_remoteFnc";

// save persistent function for JIP
private "_persistentFnc";
_persistentFnc = missionNamespace getVariable ["AGM_Core_persistentFnc", []];

if (isNil "_id" || {_id < 0}) then {_id = count _persistentFnc};
_persistentFnc set [_id, [_arguments, _function]];

AGM_Core_persistentFnc = _persistentFnc;
publicVariable "AGM_Core_persistentFnc";

_id
