// by commy2

_vehicle = _this select 0;

waitUntil {
	if (player == commander _vehicle) then {
		disableSerialization;
		_ctrlAzimuth = uiNamespace getVariable "AGM_ctrlStrider";

		waitUntil {
			_dir = round (call AGM_Core_fnc_getDirectionVector select 0);
			if (_dir == 360) then {_dir = 0};

			_dir = [_dir, 3] call AGM_Core_fnc_numberToDigitsString;
			_ctrlAzimuth ctrlSetText _dir;

			player != commander _vehicle
		};
	};
	vehicle player != _vehicle
};
