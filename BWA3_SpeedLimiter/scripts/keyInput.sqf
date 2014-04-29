// by commy2

_keyCode = [_this select 1, _this select 2, _this select 3, _this select 4] call BWA3_Core_fnc_convertKeyCode;
_vehicle = vehicle player;
_isInput = false;

if (
	player == driver _vehicle &&
	{_vehicle isKindOf "Car" || {_vehicle isKindOf "Tank"}} &&
	{_keyCode == profileNamespace getVariable "BWA3_Key_speedLimiter"}
) then {
	if (BWA3_isSpeedLimiter) then {
		[localize "STR_BWA3_SpeedLimiter_Off", true] call BWA3_Core_fnc_displayText;
		BWA3_isSpeedLimiter = false;
	} else {
		BWA3_isSpeedLimiter = true;
		[localize "STR_BWA3_SpeedLimiter_On", true] call BWA3_Core_fnc_displayText;
		[_vehicle] spawn BWA3_SpeedLimiter_speedLimiter;
	};
	_isInput = true;
};
_isInput
