// by commy2

waitUntil {
	_vehicle = vehicle player;
	waitUntil {
		if (currentVisionMode player == 1) then {
			setAperture ((_vehicle getVariable ["BWA3_NVGBrightness", 50]) / 10 + 0.1);
		} else {
			setAperture -1;
		};
		vehicle player != _vehicle
	};
	false
};
