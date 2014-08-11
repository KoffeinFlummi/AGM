// by commy2

private ["_vehicle", "_part", "_isEngineer", "_time", "_name", "_string", "_spareWheel"];

_vehicle = _this select 0;
_part = _this select 1;

_isEngineer = [player] call AGM_Core_fnc_isEngineer;

_time = 10;
_time = _time + 10 * (_vehicle getHitPointDamage _part);
if !(_isEngineer) then {_time = _time + 10};

player playMoveNow "AinvPknlMstpSnonWnonDr_medic5";

_name = [_part] call AGM_Repair_fnc_getHitPointName;
_string = format [localize "STR_AGM_Repair_Repairing", _name];

_spareWheel = [player] call AGM_Repair_fnc_getNearestWheel;
if (isNull _spareWheel) exitWith {};

[player, _spareWheel] call AGM_Core_fnc_claim;

[_time, [_vehicle, _part, _spareWheel], "AGM_Repair_fnc_repairWheelCallback", _string, "AGM_Repair_fnc_repairWheelAbort"] call AGM_Core_fnc_progressBar;
[_vehicle] call AGM_Core_fnc_closeDialogIfTargetMoves;
[_spareWheel] call AGM_Core_fnc_closeDialogIfTargetMoves;
