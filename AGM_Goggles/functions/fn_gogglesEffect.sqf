// by commy2

_goggles = goggles player;
_ppEffect = getText (configFile >> "CfgGlasses" >> _goggles >> "AGM_gogglesEffect");

if (_ppEffect == "") then {
	AGM_ppEffectGoggles ppEffectAdjust [1, 1, 0, [0, 0, 0, 0], [0, 0, 0, 1], [0, 0, 0, 1]];
} else {
	AGM_ppEffectGoggles ppEffectAdjust call compile _ppEffect;
};

AGM_ppEffectGoggles ppEffectCommit 0;
