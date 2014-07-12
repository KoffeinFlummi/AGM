/*
* Author: marc_book
*/
_vehicle = _this select 0;
_repairSelection = _this select 1;
_repairSelectionName = _this select 2;
_caller = _this select 3;

_wheels = nearestObjects [player, ["Land_Tyre_F"], 4];

if((damage player < 1) && (speed _vehicle == 0) && (count _wheels > 0)) then {
	player playMoveNow "AinvPknlMstpSnonWnonDr_medic5";
	[10,[_vehicle, _repairSelectionName, _wheels], "AGM_Repair_fnc_repairWheelCallback", localize "STR_AGM_Repair_Repairing"] call AGM_Core_fnc_progressBar;
};