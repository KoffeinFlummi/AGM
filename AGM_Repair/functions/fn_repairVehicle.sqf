/*
* Author: marc_book
*/
#define REPAIRTIMEENGINEER 7
#define REPAIRTIMENOENGINEER 10

_vehicle = _this select 0;
_repairSelection = _this select 1;
_repairSelectionName = _this select 2;
_caller = _this select 3;

AGM_Repair_VehicleAbort = {
	player playMoveNow "AmovPknlMstpSrasWrflDnon";
};

_repairtime = 0;
if(([player] call AGM_Repair_fnc_isEngineer)) then {
	hint "Is Engineer";
	_repairtime = REPAIRTIMEENGINEER;
} else {
	_repairtime = REPAIRTIMENOENGINEER;
};

if(('ToolKit' in items player) && (damage player < 1) && (speed _vehicle == 0)) then {
	player playMoveNow "AinvPknlMstpSnonWnonDr_medic5";
	[_repairtime, [_vehicle, _repairSelectionName], "AGM_Repair_fnc_repairCallback", localize "STR_AGM_Repair_Repairing", "AGM_Repair_VehicleAbort"] call AGM_Core_fnc_progressBar;
};