// by commy2

private ["_vehicle", "_part", "_name", "_string"];

_vehicle = _this select 0;
_part = _this select 1;

[[_vehicle, _part], "{(_this select 0) setHitPointDamage [_this select 1, 0]}", _vehicle] call AGM_Core_fnc_execRemoteFnc;

player playMoveNow "AmovPknlMstpSrasWrflDnon";

_name = [_part] call AGM_Repair_fnc_getHitPointName;
_string = format [localize "STR_AGM_Repair_Repaired", _name];

[_string] call AGM_Core_fnc_displayTextStructured;
