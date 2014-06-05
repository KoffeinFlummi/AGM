// by commy2

private ["_weapon", "_animation"];

_weapon = _this select 0;

_animation = getText (configFile >> "CfgWeapons" >> _weapon >> "reloadAction");

player playActionNow _animation;

[2.5, [_weapon], "AGM_Overheating_fnc_checkTemperatureCallback", localize "STR_AGM_Overheating_CheckingTemperature"] call AGM_Core_fnc_progressBar;
