/*
 * Author: commy2
 *
 * Execute a function on every machine. Function will also be called upon JIP (postInit).
 *
 * Argument:
 * 0: Function arguments (Array)
 * 1: Function to execute, has to be defined on the remote machine first (String)
 * 2: Namespace to save that variable in (Object or Namespace)
 * 3: Name. Will overwrite previously defined functions with that name (String)
 *
 * Return value:
 * Nothing.
 */

private ["_arguments", "_function", "_unit", "_name"];

AGM_Core_remoteFnc = _this;

_arguments = _this select 0;
_function = call compile (_this select 1);
_unit = _this select 2;
_name = _this select 3;

if (!isNil "AGM_Debug" && {"remote" in AGM_Debug}) then {
  diag_log text format ["[AGM]: execPersistentFnc: %1 call %2 id: %3", _arguments, _this select 1, _name];
};

// execute function on every currently connected machine
[_arguments, _this select 1, 2] call AGM_Core_fnc_execRemoteFnc;

// save persistent function for JIP
private ["_persistentFunctions", "_index"];

_persistentFunctions = _unit getVariable ["AGM_PersistentFunctions", []];

// find index to overwrite function with the same name, add to end otherwise
_index = count _persistentFunctions;
{
  if (_x select 2 == _name) exitWith {
    _index = _forEachIndex;
  };
} forEach _persistentFunctions;

// set new value
_persistentFunctions set [_index, [_arguments, _function, _name]];

// broadcast variable
if (typeName _unit == "NAMESPACE") then {
  AGM_PersistentFunctions = _persistentFunctions;
  publicVariable "AGM_PersistentFunctions";
} else {
  _unit setVariable ["AGM_PersistentFunctions", _persistentFunctions, true];
};
