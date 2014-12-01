// by gpgpgpgp, edited by commy2

private ["_fence", "_t"];

_t = _this select 0;
_fence = _this select 1;

if (cadetMode) then {
  {
    [AGM_player, "{_this groupChat localize 'STR_AGM_CuttingFenceChat'}", _x] call AGM_Core_fnc_execRemoteFnc;
  } forEach units group AGM_player;
};

if !([AGM_player] call AGM_Core_fnc_isEngineer) then {
  _t = _t + 5;
};

[AGM_player, "AinvPknlMstpSnonWnonDr_medic5", 0] call AGM_Core_fnc_doAnimation;

if (_t > 4.5) then {
  playSound "AGM_wirecutter_sound_long";
} else {
  playSound "AGM_wirecutter_sound";
};

[_t, [_fence], "AGM_Wirecutter_fnc_cutDownFenceCallback", localize "STR_AGM_CuttingFence", "AGM_Wirecutter_fnc_cutDownFenceAbort"] call AGM_Core_fnc_progressBar;
