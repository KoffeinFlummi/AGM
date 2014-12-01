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

private ["_unit", "_speaker", "_id"];

_unit = _this select 0;

_speaker = _unit getVariable ["AGM_OriginalSpeaker", speaker _unit];


_id = _unit getVariable ["AGM_PersistentID_Speaker", -1];

_id = [_unit, format ["{_this setSpeaker '%1'}", _speaker], _id] call AGM_Core_fnc_execPersistentFnc;


_unit setVariable ["AGM_PersistentID_Speaker", _id, true];
