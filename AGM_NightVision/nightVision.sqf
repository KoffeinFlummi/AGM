//by commy2

while {true} do {
	AGM_NightVision_ppEffect ppEffectEnable false;
	AGM_NightVision_ppEffectNVGBrightness ppEffectEnable false;

	waitUntil {currentVisionMode player == 1};

	AGM_NightVision_ppEffect ppEffectEnable true;
	AGM_NightVision_ppEffectNVGBrightness ppEffectEnable true;

	waitUntil {currentVisionMode player != 1};
};
