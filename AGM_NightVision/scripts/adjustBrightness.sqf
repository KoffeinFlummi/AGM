// by commy2

waitUntil {
	waitUntil {currentVisionMode vehicle player == 1};

	_ppEffectNVG = ppEffectCreate ["FilmGrain", 1235];
	_ppEffectNVG ppEffectEnable true;
	_ppEffectNVG ppEffectAdjust [0.25, 2.5, 2.5, 2.5, 2.5, false];
	_ppEffectNVG ppEffectCommit 0;

	waitUntil {
		_vehicle = vehicle player;
		setAperture ((_vehicle getVariable ["AGM_NVGBrightness", 50]) / 10 + 0.1);
		currentVisionMode _vehicle != 1
	};

	ppEffectDestroy _ppEffectNVG;
	setAperture -1;
	false
};
