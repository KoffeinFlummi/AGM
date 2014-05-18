/*
 * Author: commy2
 *
 * Compiles a loop that executes pieces of code when the corresponding conditions change their return value. The loop will exit when the exit condition is true.
 * 
 * Argument:
 * 0: The script name (String)
 * 1: The code that is executed before the loop begins. (Code or String)
 * 2: The loop will sleep for this long. In seconds. (Number)
 * 3: Each time any of these functions change their return value, the function with the same index is called. (Array of Codes or Strings)
 * 4: Functions that are called, when the condition with the same index changes its value. (Array of Codes or Strings)
 * 5: Exit condition. If this returns false, the loop will exit and the exit code is called. (Code or String)
 * 6: The code that is executed after the loop ends. (Code or String)
 * 
 * Return value:
 * Nothing
 */

private ["_scriptName", "_initCode", "_period", "_updateConditions", "_updateFunctions", "_exitCondition", "_exitCode", "_header", "_code", "_variable", "_condition", "_function"];

_scriptName = _this select 0;
_initCode = _this select 1;
_period = _this select 2;
_updateConditions = _this select 3;
_updateFunctions = _this select 4;
_exitCondition = _this select 5;
_exitCode = _this select 6;

_header = format ["%1 = {%2;", _scriptName, [_initCode] call AGM_Core_fnc_codeToString];

_code = "waitUntil {";

if (_period > 0) then {
	_code = _code + format ["sleep %1;", _period];
};

{
	_variable = format ["_variable_ID%1", _forEachIndex];
	_condition = [_updateConditions select _forEachIndex] call AGM_Core_fnc_codeToString;
	_function = [_x] call AGM_Core_fnc_codeToString;

	_header = _header + format ["%1 = %2; [%1] call {%3};", _variable, _condition, _function];
	_code = _code + format ["if (%1 != %2) then {%1 = %2; [%1] call {%3};};", _variable, _condition, _function];
} forEach _updateFunctions;

_code = format ["%1%2%3}; %4};", _header, _code, [_exitCondition] call AGM_Core_fnc_codeToString, [_exitCode] call AGM_Core_fnc_codeToString];

call compile _code;
