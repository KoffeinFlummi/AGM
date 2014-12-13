/*
 * Author: commy2
 *
 * Mutes the unit. It won't trigger auto generated chat messages either.
 * 
 * Argument:
 * 0: Unit (Object)
 * 
 * Return value:
 * Nothing
 */

private ["_unit", "_speaker", "_id"];

_unit = _this select 0;

if (isNull _unit) exitWith {};

_speaker = speaker _unit;
if (_speaker == "AGM_NoVoice") exitWith {};

_id = _unit getVariable ["AGM_PersistentID_Speaker", -1];

_id = [_unit, "{_this setSpeaker 'AGM_NoVoice'}", _id] call AGM_Core_fnc_execPersistentFnc;

_unit setVariable ["AGM_OriginalSpeaker", _speaker, true];
_unit setVariable ["AGM_PersistentID_Speaker", _id, true];
