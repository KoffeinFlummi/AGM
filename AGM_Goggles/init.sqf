// by commy2

sleep 0.1;

AGM_ppEffectGoggles = ppEffectCreate ["colorCorrections", 1234];
AGM_ppEffectGoggles ppEffectEnable true;

player addEventHandler ["init", {call AGM_Goggles_fnc_gogglesEffect}];
player addEventHandler ["respawn", {call AGM_Goggles_fnc_gogglesEffect}];
player addEventHandler ["put", {call AGM_Goggles_fnc_gogglesEffect}];
player addEventHandler ["take", {call AGM_Goggles_fnc_gogglesEffect}];

call AGM_Goggles_fnc_gogglesEffect;
