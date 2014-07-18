// by commy2

private ["_vehicle", "_part", "_isEngineer", "_time"];

_vehicle = _this select 0;
_part = _this select 1;

_isEngineer = [player] call AGM_Core_fnc_isEngineer;

_time = 10;
_time = _time + 10 * (_vehicle getHitPointDamage _part);
if !(_isEngineer) then {_time = _time + 10};

player playMoveNow "AinvPknlMstpSnonWnonDr_medic5";

_string = format [localize "STR_AGM_Repair_Repairing", _part];

[_time, [_vehicle, _part], "AGM_Repair_fnc_repairCallback", _string, "AGM_Repair_fnc_repairAbort"] call AGM_Core_fnc_progressBar;
