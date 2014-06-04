// by commy2

_ppEffect = ppEffectCreate ["radialBlur", 1241];

_ppEffect ppEffectEnable true;
_ppEffect ppEffectForceInNVG true;
_ppEffect ppEffectAdjust [0.01, 0.01, 0.1, 0.1];
_ppEffect ppEffectCommit 0;

sleep 0.5;

_ppEffect ppEffectEnable false;
ppEffectDestroy _ppEffect;
