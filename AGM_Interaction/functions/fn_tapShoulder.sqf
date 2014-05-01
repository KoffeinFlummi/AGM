// by commy2

_player = _this select 0;
_unit = _this select 1;

if (player == _player) exitWith {};

addCamShake [1, 0.5, 5];

_message = format ["%1 tapped you on your shoulder.", name _unit];

[_message] call AGM_Core_fnc_displayText;
