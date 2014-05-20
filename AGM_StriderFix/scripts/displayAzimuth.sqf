// by commy2

disableSerialization;

_ctrlAzimuth = _this select 0;

_vehicle = vehicle player;

waitUntil {
	_dir = round (call BWA3_fnc_getDirectionVector select 0);
	if (_dir == 360) then {_dir = 0};

	_dir = [_dir, 3] call AGM_Core_fnc_numberToDigitsString;
	_ctrlAzimuth ctrlSetText _dir;

	vehicle player != _vehicle
};
