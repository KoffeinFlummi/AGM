// by commy2

_weapon = _this select 0;

if (stance player != "PRONE") then {
	player playMoveNow "amovpknlmstpsraswrfldnon";
};
player playActionNow "GestureDismountMuzzle";
player playAction "GestureMountMuzzle";

[10, [_weapon], "AGM_Overheating_swapBarrelCallback", localize "STR_AGM_Overheating_SwappingBarrel"] call AGM_Core_fnc_progressBar;
