// by gpgpgpgp

private ["_fence", "_t"];

_t = _this select 0;
_fence = _this select 1;

if (cadetMode) then {player groupChat localize "STR_AGM_CuttingFenceChat"};

player playMoveNow "AinvPknlMstpSnonWnonDr_medic5";

if (_t > 4.5) then {
	playSound "AGM_wirecutter_sound_long";
} else {
	playSound "AGM_wirecutter_sound";
};

[_t, [_fence], "AGM_Wirecutter_fnc_cutDownFenceCallback", localize "STR_AGM_CuttingFence", "AGM_Wirecutter_fnc_cutDownFenceAbort"] call AGM_Core_fnc_progressBar;
