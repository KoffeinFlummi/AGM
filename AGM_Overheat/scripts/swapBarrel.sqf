// by commy2

_weapon = _this select 0;

player playMoveNow "amovpknlmstpsraswrfldnon";
player playActionNow "GestureDismountMuzzle";
player playAction "GestureMountMuzzle";

[6, [_weapon], "AGM_Overheat_swapBarrelCallback", localize "STR_AGM_SwappingBarrel"] call AGM_Core_fnc_progressBar;
