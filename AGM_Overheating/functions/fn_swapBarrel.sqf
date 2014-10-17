// by commy2

private "_weapon";

_weapon = _this select 0;

if (stance player != "PRONE") then {
	[player, "amovpknlmstpsraswrfldnon", 1] call AGM_Core_fnc_doAnimation;
};
player playActionNow "GestureDismountMuzzle";
player playAction "GestureMountMuzzle";
playSound "AGM_BarrelSwap";

[10, [_weapon], "AGM_Overheating_fnc_swapBarrelCallback", localize "STR_AGM_Overheating_SwappingBarrel"] call AGM_Core_fnc_progressBar;
