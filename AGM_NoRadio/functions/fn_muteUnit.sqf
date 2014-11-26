// by commy2

private ["_unit", "_speaker", "_id"];

_unit = _this select 0;

_speaker = speaker _unit;
if (_speaker == "AGM_NoVoice") exitWith {};

_id = _unit getVariable ["AGM_PersistentID_Speaker", -1];

_id = [_unit, "{_this setSpeaker 'AGM_NoVoice'}", _id] call AGM_Core_fnc_execPersistentFnc;

_unit setVariable ["AGM_OriginalSpeaker", _speaker, true];
_unit setVariable ["AGM_PersistentID_Speaker", _id, true];
