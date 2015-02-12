// by commy2

private "_player";

_player = _this select 0;

[_player, "{if (local _this && {!isServer}) then {findDisplay 46 closeDisplay 0}}", _player] call AGM_Core_fnc_execRemoteFnc;
