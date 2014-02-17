/*
BWA3 script, by commy2
this code is property of the ArmA 3 Bundeswehr modification
ask us nicely at http://www.bwmod.de/ if you want to re-use any of this script
we don't support changed code based on this work
*/

waitUntil {
	_vehicle = vehicle player;
	_NVGBrightness = _vehicle getVariable "BWA3_NVGBrightness";
	if (isNil "_NVGBrightness") then {
		_vehicle setVariable ["BWA3_NVGBrightness", 50, false];
	};

	waitUntil {
		if (currentVisionMode player == 1) then {
			_NVGBrightness = (_vehicle getVariable "BWA3_NVGBrightness") / 10 + 0.1;
			setAperture _NVGBrightness;
		} else {
			setAperture -1;
		};
		vehicle player != _vehicle
	};
	false
};
