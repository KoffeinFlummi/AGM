/*
BWA3 function, by commy2
this code is property of the ArmA 3 Bundeswehr modification
ask us nicely at http://www.bwmod.de/ if you want to re-use any of this script
we don't support changed code based on this work
*/

_goggles = goggles player;
_ppEffect = getText (configFile >> "CfgGlasses" >> _goggles >> "BWA3_gogglesEffect");

if (_ppEffect == "") then {
	BWA3_ppEffectGoggles ppEffectAdjust [1, 1, 0, [0, 0, 0, 0], [0, 0, 0, 1], [0, 0, 0, 1]];
	BWA3_ppEffectGoggles ppEffectCommit 0;
} else {
	BWA3_ppEffectGoggles ppEffectAdjust call compile _ppEffect;
	BWA3_ppEffectGoggles ppEffectCommit 0;
};
