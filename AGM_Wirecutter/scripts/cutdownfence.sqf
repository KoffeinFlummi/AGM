// by gpgpgpgp

private ["_fence", "_t"];
_t = _this select 0;
_fence = _this select 1;
AGM_Wirecutter_isCutting = true;
if (cadetMode) then {player groupChat localize "STR_AGM_CuttingFenceChat"};
player playMoveNow "AinvPknlMstpSnonWnonDr_medic5";
if(_t>4.5)then{playSound "AGM_wirecutter_sound_long";}else{playSound "AGM_wirecutter_sound";};
[_t,[_fence], "AGM_Wirecutter_CutdownFenceCallback", localize "STR_AGM_CuttingFence"] call AGM_Core_fnc_progressBar;