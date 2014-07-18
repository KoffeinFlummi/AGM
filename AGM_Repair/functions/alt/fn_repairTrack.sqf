/*
* Author: marc_book
*/
#define REPAIRTIMEENGINEER 7
#define REPAIRTIMENOENGINEER 10

_vehicle = _this select 0;
_repairSelection = _this select 1;
_repairSelectionName = _this select 2;
_caller = _this select 3;
_height = 0;
_error = "";

_wheels = nearestObjects [player, ["AGM_Repair_Track"], 4];

AGM_Repair_TrackAbort = {
	player playMoveNow "AmovPknlMstpSrasWrflDnon";
};

if(count _wheels <= 0) then {
	_error = _error + "<br/><br/>" + localize "STR_AGM_Repair_noTrack";
	_height = _height + 1;
};

if(_error != "") exitWith {
	[composeText [lineBreak, parseText _error], _height] call AGM_Core_fnc_displayTextStructured;
};

_repairtime = 0;
if(([player] call AGM_Repair_fnc_isEngineer)) then {
	hint "Is Engineer";
	_repairtime = REPAIRTIMEENGINEER;
} else {
	_repairtime = REPAIRTIMENOENGINEER;
};

if((damage player < 1) && (speed _vehicle == 0) && (count _wheels > 0)) then {
	player playMoveNow "AinvPknlMstpSnonWnonDr_medic5";
	[10,[_vehicle, _repairSelectionName, _wheels], "AGM_Repair_fnc_repairTrackCallback", localize "STR_AGM_Repair_Repairing", "AGM_Repair_TrackAbort"] call AGM_Core_fnc_progressBar;
};