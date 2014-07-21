// by commy2

_goggles = goggles player;

if (AGM_GogglesOld == _goggles) exitWith {};

_ppEffect = getText (configFile >> "CfgGlasses" >> _goggles >> "AGM_GogglesEffect");	//@todo use getArray instead

_ppEffect = if (_ppEffect == "") then {
	[1, 1, 0, [0, 0, 0, 0], [0, 0, 0, 1], [0, 0, 0, 1]]
} else {
	call compile _ppEffect
};

AGM_GogglesOld = _goggles;

AGM_GogglesOld_ppEffectGoggles ppEffectAdjust _ppEffect;
AGM_GogglesOld_ppEffectGoggles ppEffectCommit 0;

AGM_GogglesOld_ppEffectGoggles ppEffectAdjust [1, 1, 0, [0, 0, 0, 0], [0, 0, 0, 1], [0, 0, 0, 1]];
AGM_GogglesOld_ppEffectGoggles ppEffectCommit 30;
