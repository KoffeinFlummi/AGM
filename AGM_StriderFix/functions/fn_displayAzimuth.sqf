// by commy2

_this spawn {
	_vehicle = _this select 0;

	waitUntil {!isNull (uiNamespace getVariable "AGM_ctrlStrider")};

	waitUntil {
		if (player == commander _vehicle) then {
			disableSerialization;
			_ctrlAzimuth = uiNamespace getVariable "AGM_ctrlStrider";

			waitUntil {
				_dir = round (call AGM_Core_fnc_getTargetAzimuthAndInclination select 0);
				if (_dir == 360) then {_dir = 0};

				_dir = [_dir, 3] call AGM_Core_fnc_numberToDigitsString;
				_ctrlAzimuth ctrlSetText _dir;

				player != commander _vehicle
			};
		};
		vehicle player != _vehicle
	};
};
