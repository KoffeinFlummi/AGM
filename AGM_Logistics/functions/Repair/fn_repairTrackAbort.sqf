// by commy2

private "_spareTrack";

_spareTrack = _this select 2;

[AGM_player, "AmovPknlMstpSrasWrflDnon", 1] call AGM_Core_fnc_doAnimation;

[objNull, _spareTrack] call AGM_Core_fnc_claim;
