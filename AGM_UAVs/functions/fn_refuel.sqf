_target = _this select 0;
_caller = _this select 1;

if(fuel _target < 1) then {
  if((items _caller) find "AGM_UAVBattery" > -1) then {
    _caller removeItem "AGM_UAVBattery";
    player playMoveNow "AinvPknlMstpSnonWnonDr_medic5";
    [10,[_target], "AGM_UAVs_fnc_refuelCallback", localize "STR_AGM_UAVs_Battery_Recharge"] call AGM_Core_fnc_progressBar;
  } else {hintSilent localize "STR_AGM_UAVs_NoBattery"};
} else {hintSilent localize "STR_AGM_UAVs_Full"};