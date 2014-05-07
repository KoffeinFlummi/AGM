// by commy2

private ["_unit", "_message"];

_unit = _this select 0;

if (_unit == player) exitWith {};

enableCamShake true;
addCamShake [1, 0.5, 5];

_message = format ["%1 tapped you on your shoulder.", name _unit];

[_message] call AGM_Core_fnc_displayText;
