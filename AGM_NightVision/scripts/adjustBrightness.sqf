// by commy2

waitUntil {
	waitUntil {currentVisionMode player == 1};


	_ppEffectNVG = ppEffectCreate ["FilmGrain", 1235];
	_ppEffectNVG ppEffectEnable true;

	_ppEffectNVG ppEffectAdjust [0.25, 2.5, 2.5, 2.5, 2.5, false];
	_ppEffectNVG ppEffectCommit 0;



	_ppEffectNVGBrightness = ppEffectCreate ["ColorCorrections", 1236];

	_ppEffectNVGBrightness ppEffectEnable true;

	_ppEffectNVGBrightness ppEffectAdjust [1, 1, 0, [0, 0, 0, 0], [0, 0, 0, 1], [0, 0, 0, 1]];

	_ppEffectNVGBrightness ppEffectCommit 0;
	_ppEffectNVGBrightness ppEffectForceInNVG true;



	waitUntil {

		_ppEffectNVGBrightness ppEffectAdjust [1, 1, ((player getVariable ["AGM_NVGBrightness", 50]) - 50) / 400, [0, 0, 0, 0], [0, 0, 0, 1], [0, 0, 0, 1]];
		_ppEffectNVGBrightness ppEffectCommit 0;


		currentVisionMode player != 1
	};


	ppEffectDestroy _ppEffectNVG;
	ppEffectDestroy _ppEffectNVGBrightness;

	false

};

