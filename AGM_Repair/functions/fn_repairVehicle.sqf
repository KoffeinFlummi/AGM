/*
* Author: marc_book
*/
_vehicle = _this select 0;
_repairSelection = _this select 1;
_repairSelectionName = _this select 2;
_caller = _this select 3;

AGM_Repair_VehicleAbort = {
	player playMoveNow "AmovPknlMstpSrasWrflDnon";
};

if(('ToolKit' in items player) && (damage player < 1) && (speed _vehicle == 0)) then {
	player playMoveNow "AinvPknlMstpSnonWnonDr_medic5";
	[10,[_vehicle, _repairSelectionName], "AGM_Repair_fnc_repairCallback", localize "STR_AGM_Repair_Repairing", "AGM_Repair_VehicleAbort"] call AGM_Core_fnc_progressBar;
};