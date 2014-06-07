// by commy2

_goggles = goggles player;

if (AGM_Goggles == _goggles) exitWith {};

_ppEffect = getText (configFile >> "CfgGlasses" >> _goggles >> "AGM_gogglesEffect");	//@todo use getArray instead

_ppEffect = if (_ppEffect == "") then {
	[1, 1, 0, [0, 0, 0, 0], [0, 0, 0, 1], [0, 0, 0, 1]]
} else {
	call compile _ppEffect
};

AGM_Goggles = _goggles;

AGM_Goggles_ppEffectGoggles ppEffectAdjust _ppEffect;
AGM_Goggles_ppEffectGoggles ppEffectCommit 0;

AGM_Goggles_ppEffectGoggles ppEffectAdjust [1, 1, 0, [0, 0, 0, 0], [0, 0, 0, 1], [0, 0, 0, 1]];
AGM_Goggles_ppEffectGoggles ppEffectCommit 30;
