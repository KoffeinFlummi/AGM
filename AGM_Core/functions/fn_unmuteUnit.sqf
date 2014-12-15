/*
 * Author: commy2
 *
 * Unmutes the unit.
 * 
 * Argument:
 * 0: Unit (Object)
 * 
 * Return value:
 * Nothing
 */

private ["_unit", "_speaker"];

_unit = _this select 0;

if (isNull _unit) exitWith {};

_speaker = _unit getVariable ["AGM_OriginalSpeaker", ""];
if (_speaker == "") exitWith {};

[_unit, format ["{_this setSpeaker '%1'}", _speaker], _unit, "AGM_Speaker"] call AGM_Core_fnc_execPersistentFnc;
