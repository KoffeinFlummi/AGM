// by commy2

if (isClass (configFile >> "CfgPatches" >> "AGM_Goggles")) exitWith {};

AGM_GogglesOld_ppEffectGoggles = ppEffectCreate ["ColorCorrections", 1234];
AGM_GogglesOld_ppEffectGoggles ppEffectEnable true;

player addEventHandler ["Init", {call AGM_GogglesOld_fnc_gogglesEffect}];
player addEventHandler ["Respawn", {call AGM_GogglesOld_fnc_gogglesEffect}];
player addEventHandler ["Put", {call AGM_GogglesOld_fnc_gogglesEffect}];
player addEventHandler ["Take", {call AGM_GogglesOld_fnc_gogglesEffect}];

AGM_GogglesOld = goggles player;

0 spawn {
	sleep 0.1;
	call AGM_GogglesOld_fnc_gogglesEffect;
};
