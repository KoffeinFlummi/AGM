_target = _this select 0;
_caller = _this select 1;

player playMoveNow "AinvPknlMstpSnonWnonDr_medic5";

AGM_UAVs_refuelAbort = {
	player playMoveNow "AmovPknlMstpSrasWrflDnon";
};

[10,[_target,_caller], "AGM_UAVs_fnc_refuelCallback", localize "STR_AGM_UAVs_Battery_Recharge", "AGM_UAVs_refuelAbort"] call AGM_Core_fnc_progressBar;
[_target] call AGM_Core_fnc_closeDialogIfTargetMoves;
