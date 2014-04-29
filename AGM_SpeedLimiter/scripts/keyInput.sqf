// by commy2

_keyCode = [_this select 1, _this select 2, _this select 3, _this select 4] call AGM_Core_fnc_convertKeyCode;
_vehicle = vehicle player;
_isInput = false;

if (
	player == driver _vehicle &&
	{_vehicle isKindOf "Car" || {_vehicle isKindOf "Tank"}} &&
	{_keyCode == profileNamespace getVariable "AGM_Key_speedLimiter"}
) then {
	if (AGM_isSpeedLimiter) then {
		[localize "STR_AGM_SpeedLimiter_Off", true] call AGM_Core_fnc_displayText;
		AGM_isSpeedLimiter = false;
	} else {
		AGM_isSpeedLimiter = true;
		[localize "STR_AGM_SpeedLimiter_On", true] call AGM_Core_fnc_displayText;
		[_vehicle] spawn AGM_SpeedLimiter_speedLimiter;
	};
	_isInput = true;
};
_isInput
