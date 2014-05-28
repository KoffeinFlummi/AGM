_target = _this select 0;
_caller = _this select 1;

if(fuel _target < 1) then {
	if((items _caller) find "AGM_UAV_Batterie" > -1) then {
		_caller removeItem "AGM_UAV_Batterie";
		player playMoveNow "AinvPknlMstpSnonWnonDr_medic5";
		[10,[_target], "AGM_UAV_refuelCallback", localize "STR_AGM_Uav_Batterie_Refuel"] call AGM_Core_fnc_progressBar;
	} else {hint localize "STR_AGM_NoBattery"};
} else {hint localize "STR_AGM_Full"};