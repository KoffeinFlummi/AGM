// by commy2

AGM_NightVision_ppEffect = ppEffectCreate ["FilmGrain", 1235];
AGM_NightVision_ppEffect ppEffectAdjust [0.25, 2.5, 2.5, 2.5, 2.5, false];
AGM_NightVision_ppEffect ppEffectCommit 0;

AGM_NightVision_ppEffectNVGBrightness = ppEffectCreate ["ColorCorrections", 1236];
AGM_NightVision_ppEffectNVGBrightness ppEffectForceInNVG true;
AGM_NightVision_ppEffectNVGBrightness ppEffectAdjust [1, 1, 0, [0, 0, 0, 0], [0, 0, 0, 1], [0, 0, 0, 1]];
AGM_NightVision_ppEffectNVGBrightness ppEffectCommit 0;

AGM_NightVision_ppEffectMuzzleFlash = ppEffectCreate ["ColorCorrections", 1237];
AGM_NightVision_ppEffectMuzzleFlash ppEffectEnable true;
AGM_NightVision_ppEffectMuzzleFlash ppEffectForceInNVG true;
AGM_NightVision_ppEffectMuzzleFlash ppEffectAdjust [1, 1, 0, [0, 0, 0, 0], [0, 0, 0, 1], [0, 0, 0, 1]];
AGM_NightVision_ppEffectMuzzleFlash ppEffectCommit 0;

0 spawn compile preprocessFileLineNumbers "\AGM_NightVision\nightVision.sqf";
